//
// Created by march on 21.01.2019.
//

#ifndef INC_17209_MARCHENKO_HASHTABLE_TEMPLATEHASHTABLE_H
#define INC_17209_MARCHENKO_HASHTABLE_TEMPLATEHASHTABLE_H

#include <list>
#include <vector>
#include <stdexcept>

template <typename KEY, typename VALUE>
class TemplateHashTable {
public:
    TemplateHashTable();
    ~TemplateHashTable();

    TemplateHashTable(const TemplateHashTable &b);
    void swap(TemplateHashTable &b);
    TemplateHashTable &operator=(const TemplateHashTable &b);
    void clear();
    bool erase(const KEY &k);
    bool insert(const KEY &k, const VALUE &v);
    bool contains(const KEY &k) const;
    VALUE &operator[](const KEY &k);
    VALUE &at(const KEY &k);
    const VALUE &at(const KEY &k) const;
    size_t size() const;
    bool empty() const;
    template <typename KEY1, typename VALUE1>
    friend bool operator==(const TemplateHashTable<KEY1, VALUE1> &a, const TemplateHashTable<KEY1, VALUE1> &b);
    template <typename KEY1, typename VALUE1>
    friend bool operator!=(const TemplateHashTable<KEY1, VALUE1> &a, const TemplateHashTable<KEY1, VALUE1> &b);

private:
    struct Node {
        KEY key;
        VALUE val;
        Node
        (const KEY &k, const VALUE &v) : key(k), val(v) {}
    };
    static const size_t default_capacity = 15;
    static const size_t parts = 2;
    size_t _size = 0;
    size_t capacity = default_capacity;
    size_t Hash(const KEY &k) const;
    void rehashing();
    std::vector<std::list<Node>> data;
};

template <typename KEY, typename VALUE>
TemplateHashTable<KEY, VALUE>::TemplateHashTable() {
    data.resize(default_capacity, std::list<Node>());
}

template <typename KEY, typename VALUE>
TemplateHashTable<KEY, VALUE>::~TemplateHashTable() = default;

template <typename KEY, typename VALUE>
TemplateHashTable<KEY, VALUE>::TemplateHashTable(const TemplateHashTable &b)
        : capacity(b.capacity), _size(b._size), data(b.data) {}

template <typename KEY, typename VALUE>
void TemplateHashTable<KEY, VALUE>::swap(TemplateHashTable &b) {
    std::swap(b._size, _size);
    std::swap(b.capacity, capacity);
    std::swap(b.data, data);
}

template <typename KEY, typename VALUE>
size_t TemplateHashTable<KEY, VALUE>::size() const { return _size; }

template <typename KEY, typename VALUE>
bool TemplateHashTable<KEY, VALUE>::empty() const { return _size == 0; }

template <typename KEY, typename VALUE>
VALUE &TemplateHashTable<KEY, VALUE>::at(const KEY &k) {
    std::list<Node> &l = data.at(Hash(k));
    // std::find
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (it->key == k) {
            return (it->val);
        }
    }
    throw std::runtime_error("error");
}

template <typename KEY, typename VALUE>
bool TemplateHashTable<KEY, VALUE>::contains(const KEY &k) const {
    std::list<Node> l = data.at(Hash(k));
    if (!l.empty()) {
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (it->key == k) {
                return true;
            }
        }
    }
    return false;
}

template <typename KEY, typename VALUE>
bool TemplateHashTable<KEY, VALUE>::erase(const KEY &k) {
    auto &l = data.at(Hash(k));
    if (!l.empty()) {
        //??
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (it->key == k) {
                l.erase(it);
                return true;
            }
        }
    }
    return false;
}

template <typename KEY, typename VALUE>
const VALUE &TemplateHashTable<KEY, VALUE>::at(const KEY &k) const {
    unsigned pos = Hash(k);
    std::list<Node> lst = data.at(pos);
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (it->key == k) {
            return (it->val);
        }
    }
    throw std::runtime_error("error");
}

template <typename KEY, typename VALUE>
void TemplateHashTable<KEY, VALUE>::clear() {
    _size = 0;
    capacity = default_capacity;
    data.clear();
}

template <typename KEY, typename VALUE>
VALUE &TemplateHashTable<KEY, VALUE>::operator[](const KEY &k) {
    unsigned pos = Hash(k);
    std::list<Node> &lst = data.at(pos);
    if (!lst.empty()) {
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            if (it->key == k) {
                return (it->val);
            }
        }
    }
    VALUE v;
    VALUE &val = v;
    insert(k, val);
    return val;
}

template <typename KEY, typename VALUE>
bool TemplateHashTable<KEY, VALUE>::insert(const KEY &k, const VALUE &v) {
    unsigned pos = Hash(k);
    std::list<Node> &lst = data.at(pos);
    if (!lst.empty()) {
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            if (it->key == k) {
                it->val = v;
                return true;
            }
        }
    }
    (data[pos]).push_front(Node(k, v));
    _size++;
    if (_size > (capacity / parts)) {
        rehashing();
    }
    return true;
}

template <typename KEY, typename VALUE>
TemplateHashTable<KEY, VALUE> &TemplateHashTable<KEY, VALUE>::operator=(const TemplateHashTable &b) {
    if (this != &b) {
        if (b._size != _size) {
            data.clear();
            data.resize(capacity, std::list<Node>());
            _size = b._size;
            capacity = b.capacity;
        }
        std::copy(b.data.begin(), b.data.begin() + b.capacity, data.begin());
    }
    return *this;
}


template <typename KEY1, typename VALUE1>
bool operator==(const TemplateHashTable<KEY1, VALUE1> &a, const TemplateHashTable<KEY1, VALUE1> &b) {
    if (a.capacity != b.capacity || a._size != b._size) {
        return false;
    }
    for (size_t i = 0; i < a.capacity; ++i) {
        std::list<typename TemplateHashTable<KEY1, VALUE1>::Node> lst;
        lst = a.data.at(i);
        if (!lst.empty()) {
            for (auto it = lst.begin(); it != lst.end(); ++it) {
                if (!b.contains(it->key)) {
                    return false;
                }
            }
        }
    }
    return true;
}

template <typename KEY1, typename VALUE1>
bool operator!=(const TemplateHashTable<KEY1, VALUE1> &a, const TemplateHashTable<KEY1, VALUE1> &b) { return !(a == b); }


template <typename KEY, typename VALUE>
size_t TemplateHashTable<KEY, VALUE>::Hash(const KEY &k) const {
    size_t hash = 0;
    for (int i = 0; i < k.length(); ++i) {
        hash += (size_t)(k[i] - 'A');
    }
    return hash % capacity;
}

template <typename KEY, typename VALUE>
void TemplateHashTable<KEY, VALUE>::rehashing() {
    std::vector<std::list<Node>> buf = data;
    data.clear();
    _size = 0;
    capacity *= parts;
    data.resize(capacity, std::list<Node>());
    for (size_t i = 0; i < (capacity / parts); ++i) {
        std::list<Node> &lst = buf.at(i);
        if (!lst.empty()) {
            for (auto it = lst.begin(); it != lst.end(); ++it) {
                insert(it->key, it->val);
            }
        }
    }
}


#endif //INC_17209_MARCHENKO_HASHTABLE_TEMPLATEHASHTABLE_H
