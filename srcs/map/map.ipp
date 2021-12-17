#include <map.hpp>

namespace ft {

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) :
        _size(0),
        _key_comp(comp),
        _allocator(alloc),
        _root(NULL) // TODO check for nullptr (c++11) in the codebase
    {

    }

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::~map(void)
    {
        
    }

    template <class Key, class T, class Compare, class Alloc>
    bool                                                    map<Key, T, Compare, Alloc>::empty() const
    {
        return (_size == 0);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type         map<Key, T, Compare, Alloc>::size() const
    {
        return (_size);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type         map<Key, T, Compare, Alloc>::max_size() const
    {
        return (_allocator.max_size());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::allocator_type    map<Key, T, Compare, Alloc>::get_allocator() const
    {
        return (_allocator);
    }

//    template <class Key, class T, class Compare, class Alloc>
//    std::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>     map<Key, T, Compare, Alloc>::insert(const value_type &val)
//    {
//        // TODO fix the insert! :)
//    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::key_compare       map<Key, T, Compare, Alloc>::key_comp() const
    {
        return (_key_comp);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::value_compare     map<Key, T, Compare, Alloc>::value_comp() const
    {
        return (value_compare(_key_comp));
    }
}
