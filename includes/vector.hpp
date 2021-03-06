#ifndef VECTOR_H
# define VECTOR_H

# include <memory>
# include <algorithm>
# include <cmath>
# include <iostream>
# include <stdexcept>
# include <IteratorTraits.hpp>
# include <ReverseIterator.hpp>
# include <RandomAccessIterator.hpp>

namespace ft {

    /* https://www.cplusplus.com/reference/vector/vector/ */
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        /* member types */
        typedef T                                       value_type;
        typedef Allocator                               allocator_type;
        typedef T&                                      reference;
        typedef const T&                                const_reference;
        typedef T*                                      pointer;
        typedef const T*                                const_pointer;
        typedef RandomAccessIterator<T>                 iterator;
        typedef RandomAccessIterator<const T>           const_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ptrdiff_t                               difference_type;
        typedef size_t                                  size_type;

    private:
        size_type                                       _size;
        size_type                                       _capacity;
        allocator_type                                  _allocator;
        pointer                                         _array;

    public:

        // https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean

        /* constructors */
        explicit vector(const allocator_type& alloc = allocator_type());
        explicit vector(size_type n,
                        const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type());

        /*
        ** Constructs a container with as many elements as the range [first,last), with
        ** each element constructed from its corresponding element in that range, in the
        ** same order.
        */
        template <class InputIterator>
        vector(InputIterator first,
               InputIterator last,
               typename iterator_check<InputIterator>::type* = 0,
               const allocator_type& alloc = allocator_type()) : _size(0), _allocator(alloc)
        {
            difference_type    size;

            size = last - first;
            _array = _allocator.allocate(size);
            _capacity = size;
            assign(first, last);
        }

        vector(const vector &x);

        /* destructors */
        virtual ~vector(void);

        /* operators */
        vector&         operator = (const vector &rhs);
        reference       operator [] (size_type n);
        const_reference operator [] (size_type n) const;

        /* iterators */
        iterator                            begin();
        const_iterator                      begin() const;
        iterator                            end();
        const_iterator                      end() const;
        reverse_iterator                    rbegin();
        const_reverse_iterator              rbegin() const;
        reverse_iterator                    rend();
        const_reverse_iterator              rend() const;

        /* capacity */
        size_type                           size() const;
        size_type                           max_size() const;
        void                                resize(size_type n, value_type val = value_type());
        size_type                           capacity() const;
        bool                                empty() const;
        void                                reserve (size_type n);

        /* element access */
        reference                           at(size_type n);
        const_reference                     at(size_type n) const;
        reference                           front();
        const_reference                     front() const;
        reference                           back();
        const_reference                     back() const;

        /* modifiers */
        template <class InputIterator>
        void                                assign(InputIterator first,
                                                   InputIterator last,
                                                   typename iterator_check<InputIterator>::type* = 0)
        {
            clear();
            reserve(last - first);
            for (; first != last; ++first)
                push_back(*first);
        }
        void                                assign(size_type n, const value_type& val);
        void                                push_back(const value_type& val);
        void                                pop_back();
        iterator                            insert(iterator position, const value_type& val);
        void                                insert(iterator position, size_type n, const value_type& val);
        template <class InputIterator>
        void                                insert(iterator position,
                                                   InputIterator first,
                                                   InputIterator last,
                                                   typename iterator_check<InputIterator>::type* = 0)
        {
			vector<T>	temp;
			size_type	n;
			size_type	insert_idx;

			insert_idx = position - begin();
			if (insert_idx < _size)
			{
				difference_type push_back_amount = _size - insert_idx;
				for (int i = 0; i < push_back_amount; i++) {
					temp.push_back(back());
					pop_back();
				}
			}

			n = last - first;
			/* check for extra needed capacity */
			if (_size + n > _capacity)
				this->reserve(_get_next_capacity());

			/* insert new values at pos {idx} */
			for (;first != last; first++) {
				push_back(*first);
			}

			/* insert old elements */
			while (!temp.empty()) {
				push_back(temp.back());
				temp.pop_back();
			}
        }
        iterator                            erase(iterator position);
        iterator                            erase(iterator first, iterator last);
        void                                swap(vector& x);
        void                                clear();

        /* allocator */
        allocator_type                      get_allocator() const;

    private:
        size_type                           _get_next_capacity();
        pointer                             _safe_alloc(size_type n);

    };

    /* relational operators */
    template <class T, class Allocator>
    bool    operator == (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        if (!(lhs.size() == rhs.size()))
            return (false);
        // TODO reimplement equal https://www.cplusplus.com/reference/algorithm/equal/
        return (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    
    template <class T, class Allocator>
    bool    operator != (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return (!(lhs == rhs));
    }
    
    template <class T, class Allocator>
    bool    operator <  (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        //  TODO reimplement lexicographical compare https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
        return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Allocator>
    bool    operator <= (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return (!(rhs < lhs));
    }

    /* if lhs > rhs == true then rhs < lhs is also true */
    template <class T, class Allocator>
    bool    operator >  (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return (rhs < lhs);
    }
    
    template <class T, class Allocator>
    bool    operator >= (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return (!(lhs < rhs));
    }

}

# include <vector.ipp>

#endif

