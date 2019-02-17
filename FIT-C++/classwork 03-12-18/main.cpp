#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <forward_list>
#include <algorithm>
#include <iterator>
/*
template <class T>
class list {
public:
    class iterator {
    public:
        T operator*() {}
        iterator& operator++() {}
        iterator&operator++(int) {}
    };
};
*/

template <class It>
struct iterator_traits1 {
    typedef typename It::category category;
};

template <class It>
struct iterator_traits1<It*> {
    typedef random_access_tag category;
};

template <class It>
void our_advance(It& iter, int n) {
    our_advance(iter, n, iterator_traits1<It>::category);
}

struct bidirectional_tag {};
struct random_access_tag {};

template<class It>
void our_advance(It& iter, int n, bidirectional_tag) {
    if(n > 0) {
        while(n --> 0)
            ++iter;
    } else {
        while( n++ < 0)
            --iter;
    }
}

template<class It>
void our_advance(It& iter, int n, random_access_tag) {
    iter += n;
}

int main() {
    std::vector<int> v = {6,0,3,1,7,6,9};
    std::vector<int>::iterator it = v.begin();

    std::list<int> l;
    std::list<int>::iterator it2 = l.begin();

    auto test_it = v.begin();
    std::advance(test_it, 3);
    std::cout << *test_it << std::endl;
    std::cout
//    std::sort(v.begin(), v.end());

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "; "));

    std::forward_list<int> lf;
    std::forward_list<int>::iterator it3 = lf.begin();

//    it3++;

    return 0;
}