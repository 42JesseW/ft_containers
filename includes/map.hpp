#ifndef MAP_H

# define MAP_H

# include <utility>
# include <memory>
# include <functional>

# include <ReverseIterator.hpp>
# include <BidirectionalIterator.hpp>

namespace ft {

    // TODO implement pair:			https://www.cplusplus.com/reference/utility/pair/
    // TODO implement make_pair:	https://www.cplusplus.com/reference/utility/make_pair/

    /* https://www.cplusplus.com/reference/map/map/ */
    template <class Key,
              class T,
              class Compare = std::less<Key>,
              class Alloc   = std::allocator<std::pair<const Key, T> >>
    class map
    {
    public:
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef std::pair<const key_type, mapped_type>      value_type;
        typedef Compare                                     key_compare;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef BidirectionalIterator<value_type>           iterator;
        typedef BidirectionalIterator<const value_type>     const_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ptrdiff_t                                   difference_type;
        typedef size_t                                      size_type;

        /*
        ** A function object that is used to compare two `value_type` objects
        ** https://www.cplusplus.com/reference/map/map/value_comp/
        **
        ** Must inherit from binary_function because C++98
        ** https://www.cplusplus.com/reference/functional/binary_function/
        */
        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
        protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {}

        public:
            typedef bool    result_type;

            bool    operator () (const value_type& x, const value_type& y) const
            {
                /* .first is the key in the `value_type` object since we're comparing keys */
                return comp(x.first, y.first);
            }
        };

    private:
        /* internal node class used to store the key value pair */
        class node
        {
        public:
            typedef typename Alloc::template rebind<node>::other    allocator_type;

        private:
            node            *_left;
            node            *_right;
            value_type      _data;
            allocator_type  _allocator;

        public:
            void    setLeft(node *left) { _left = left; }
            void    setRight(node *right) { _right = right; }

            node    *getLeft() { return (_left); }
            node    *getRight() { return (_right); }
        };

    private:
        size_type                   _size;
        key_compare                 _key_comp;
        allocator_type              _allocator;
        node                        *_root;

    public:
        /* constructors */
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
//        map (const map& x);
//        template <class InputIterator>
//        map (InputIterator first, InputIterator last,
//             const key_compare& comp = key_compare(),
//             const allocator_type& alloc = allocator_type());

        /* destructor */
        virtual ~map(void);

        /* capacity */
        bool                        empty() const;
        size_type                   size() const;
        size_type                   max_size() const;

        /* modifiers */
        std::pair<iterator,bool>    insert (const value_type& val);

        /* observers */
        key_compare                 key_comp() const;
        value_compare               value_comp() const;

        /* allocator */
        allocator_type              get_allocator() const;

    };

}

# include <map.ipp>

#endif
