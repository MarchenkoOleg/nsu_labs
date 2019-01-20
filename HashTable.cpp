//
// Created by march on 22.09.2018.
//
#include "HashTable.h"



size_t HashTable::Hash(const Key &k) const {
    size_t hash = 0;
    for (int i = 0; i < k.length(); ++i) {
        hash += (size_t)(k[i] - 'A');
    }
    return hash % capacity;
}

void HashTable::rehashing() {
    std::vector<std::list<Tmp>> buf = data;
    data.clear();
    _size = 0;
    capacity *= PARTS;
    data.resize(capacity, std::list<Tmp>());
    for (size_t i = 0; i < (capacity / PARTS); ++i) {
        std::list<Tmp> &lst = buf.at(i);
        if (!lst.empty()) {
            for (auto it = lst.begin(); it != lst.end(); ++it) {
                insert(it->key, it->val);
            }
        }
    }
}

HashTable::HashTable() {
    data.resize(DEFAULT_CAPACITY, std::list<Tmp>());
}

HashTable::~HashTable() = default;

HashTable::HashTable(const HashTable &b)
        : capacity(b.capacity), _size(b._size), data(b.data) {}

void HashTable::swap(HashTable &b) {
    std::swap(b._size, _size);
    std::swap(b.capacity, capacity);
    std::swap(b.data, data);
}

size_t HashTable::size() const { return _size; }

bool HashTable::empty() const { return _size == 0; }

Value &HashTable::at(const Key &k) {
    std::list<Tmp> &l = data.at(Hash(k));
    // std::find
    for (std::list<Tmp>::iterator it = l.begin(); it != l.end(); ++it) {
        if (it->key == k) {
            return (it->val);
        }
    }
    throw; //?? std::runtime_error
}

bool HashTable::contains(const Key &k) const {
    std::list<Tmp> l = data.at(Hash(k));
    if (!l.empty()) {
        for (std::list<Tmp>::iterator it = l.begin(); it != l.end(); ++it) {
            if (it->key == k) {
                return true;
            }
        }
    }
    return false;
}

bool HashTable::erase(const Key &k) {
    std::list<Tmp> &l = data.at(Hash(k));
    if (!l.empty()) {
        //??
        for (std::list<Tmp>::iterator it = l.begin(); it != l.end(); ++it) {
            if (it->key == k) {
                l.erase(it);
                return true;
            }
        }
    }
    return false;
}

const Value &HashTable::at(const Key &k) const {
    unsigned pos = Hash(k);
    std::list<Tmp> lst = data.at(pos);
    for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (it->key == k) {
            return (it->val);
        }
    }
    throw std::out_of_range("fuck up");
}

void HashTable::clear() {
    _size = 0;
    capacity = DEFAULT_CAPACITY;
    data.clear();
}

Value &HashTable::operator[](const Key &k) {
    unsigned pos = Hash(k);
    std::list<Tmp> &lst = data.at(pos);
    if (!lst.empty()) {
        for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
            if (it->key == k) {
                return (it->val);
            }
        }
    }
    Value v;
    Value &val = v;
    insert(k, val);
    return val;
}

bool HashTable::insert(const Key &k, const Value &v) {
    unsigned pos = Hash(k);
    std::list<Tmp> &lst = data.at(pos);
    if (!lst.empty()) {
        for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
            if (it->key == k) {
                it->val = v;
                return true;
            }
        }
    }
    (data[pos]).push_front(Tmp(k, v));
    _size++;
    if (_size > (capacity / PARTS)) {
        rehashing();
    }
    return true;
}

HashTable &HashTable::operator=(const HashTable &b) {
    if (this != &b) {
        if (b._size != _size) {
            data.clear();
            data.resize(capacity, std::list<Tmp>());
            _size = b._size;
            capacity = b.capacity;
        }
        std::copy(b.data.begin(), b.data.begin() + b.capacity, data.begin());
    }
    return *this;
}

bool operator==(const HashTable &a, const HashTable &b) {
    if (a.capacity != b.capacity || a._size != b._size) {
        return false;
    }
    for (size_t i = 0; i < a.capacity; ++i) {
        std::list<Tmp> lst = a.data.at(i);
        if (!lst.empty()) {
            for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
                if (!b.contains(it->key)) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool operator!=(const HashTable &a, const HashTable &b) { return !(a == b); }