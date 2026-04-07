#ifndef SJTU_MAP_HPP
#define SJTU_MAP_HPP

#include <cstddef>
#include <functional>
#include "utility.hpp"
#include "exceptions.hpp"

namespace sjtu {

template<class Key, class T, class Compare = std::less<Key>>
class map {
public:
    typedef pair<const Key, T> value_type;

    class iterator {
    public:
        iterator() {}
        iterator(const iterator &other) {}
        iterator operator++(int) { return *this; }
        iterator & operator++() { return *this; }
        iterator operator--(int) { return *this; }
        iterator & operator--() { return *this; }
        value_type & operator*() const { static value_type v; return v; }
        bool operator==(const iterator &rhs) const { return true; }
        bool operator==(const class const_iterator &rhs) const { return true; }
        bool operator!=(const iterator &rhs) const { return false; }
        bool operator!=(const class const_iterator &rhs) const { return false; }
        value_type * operator->() const noexcept { return nullptr; }
    };

    class const_iterator {
    public:
        const_iterator() {}
        const_iterator(const const_iterator &other) {}
        const_iterator(const iterator &other) {}
        const_iterator operator++(int) { return *this; }
        const_iterator & operator++() { return *this; }
        const_iterator operator--(int) { return *this; }
        const_iterator & operator--() { return *this; }
        const value_type & operator*() const { static value_type v; return v; }
        bool operator==(const iterator &rhs) const { return true; }
        bool operator==(const const_iterator &rhs) const { return true; }
        bool operator!=(const iterator &rhs) const { return false; }
        bool operator!=(const const_iterator &rhs) const { return false; }
        const value_type * operator->() const noexcept { return nullptr; }
    };

    map() {}
    map(const map &other) {}
    map & operator=(const map &other) { return *this; }
    ~map() {}
    T & at(const Key &key) { static T t; return t; }
    const T & at(const Key &key) const { static T t; return t; }
    T & operator[](const Key &key) { static T t; return t; }
    const T & operator[](const Key &key) const { static T t; return t; }
    iterator begin() { return iterator(); }
    const_iterator cbegin() const { return const_iterator(); }
    iterator end() { return iterator(); }
    const_iterator cend() const { return const_iterator(); }
    bool empty() const { return true; }
    size_t size() const { return 0; }
    void clear() {}
    pair<iterator, bool> insert(const value_type &value) { return pair<iterator, bool>(iterator(), false); }
    void erase(iterator pos) {}
    size_t count(const Key &key) const { return 0; }
    iterator find(const Key &key) { return iterator(); }
    const_iterator find(const Key &key) const { return const_iterator(); }
};

}

#endif
