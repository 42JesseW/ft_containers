#ifndef REVERSE_ITERATOR_H

# define REVERSE_ITERATOR_H

# include <iterator>
# include <stdexcept>
/* if the <typeinfo> header is not included, every use of the keyword typeid makes the program ill-formed */
# include <typeinfo>
# include <IteratorTraits.hpp>

namespace ft {

    template <class Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename iterator_traits<Iterator>::value_type          value_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
        typedef typename iterator_traits<Iterator>::reference           reference;

    private:
        /*
        ** The base iterator is an iterator of the same type as the one used to construct
        ** the reverse_iterator, but pointing to the element next to the one the reverse_iterator
        ** is currently pointing to (a reverse_iterator has always an offset of -1 with respect to
        ** its base iterator).
        */
        iterator_type   _base;

    public:
        /* constructors */
        reverse_iterator();
        explicit reverse_iterator(iterator_type it);
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it._base){}

        /* operators */
        reference           operator * () const;
        reference           operator [] (difference_type n) const;
        pointer             operator -> () const;
        reverse_iterator&   operator -= (difference_type n);
        reverse_iterator&   operator -- ();
        reverse_iterator    operator -- (int);
        reverse_iterator    operator - (difference_type n) const;
        reverse_iterator&   operator += (difference_type n);
        reverse_iterator&   operator ++ ();
        reverse_iterator    operator ++ (int);
        reverse_iterator    operator + (difference_type n) const;

        /* members */
        iterator_type       base() const;

    };

    /*
    ** Non-member function overloads
    */
    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operators/ */
    template <class Iterator>
    bool    operator == (const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base().getPointer() == rhs.base().getPointer());
    }

    template <class Iterator>
    bool    operator != (const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base().getPointer() != rhs.base().getPointer());
    }

    template <class Iterator>
    bool    operator <  (const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base().getPointer() < rhs.base().getPointer());
    }

    template <class Iterator>
    bool    operator <= (const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base().getPointer() <= rhs.base().getPointer());
    }

    template <class Iterator>
    bool    operator >  (const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base().getPointer() > rhs.base().getPointer());
    }

    template <class Iterator>
    bool    operator >= (const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base().getPointer() >= rhs.base().getPointer());
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator_plus-free */
    template <class Iterator>
    reverse_iterator<Iterator> operator + (
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it)
    {
        return (rev_it + n);
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator_minus-free */
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator - (
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base().getPointer() - rhs.base().getPointer());
    }

}

# include <ReverseIterator.ipp>

#endif
