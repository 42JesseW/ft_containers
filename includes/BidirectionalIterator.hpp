#ifndef BIDIRECTIONAL_ITERATOR_H

# define BIDIRECTIONAL_ITERATOR_H

# include <RandomAccessIterator.hpp>

/* https://www.cplusplus.com/reference/iterator/BidirectionalIterator/ */
namespace ft {

    template <class T, class Category = std::bidirectional_iterator_tag>
    class BidirectionalIterator : public RandomAccessIterator<T, Category>
    {
    public:
        typedef T                                   value_type;
        typedef value_type&                         reference;
        typedef value_type*                         pointer;
        typedef size_t                              size_type;
        typedef RandomAccessIterator<T, Category>   iter;
        typedef BidirectionalIterator               self_type;

    public:
        /* constructors */
        BidirectionalIterator();
        explicit BidirectionalIterator(pointer elem);
        BidirectionalIterator(const self_type &x);

        /* destructors */
        virtual ~BidirectionalIterator();

        /* operators */
        self_type&  operator = (const self_type &rhs);
        bool        operator == (const self_type &rhs);
        bool        operator != (const self_type &rhs);
        reference   operator * ();
        pointer     operator -> ();
        self_type   operator ++ (int);
        self_type&  operator ++ ();
        self_type   operator -- (int);
        self_type&  operator -- ();

    };

    template <class T, class Category = std::bidirectional_iterator_tag>
    class ConstBidirectionalIterator : public ConstRandomAccessIterator<T, Category>
    {
    public:
        typedef T                                       value_type;
        typedef value_type&                             reference;
        typedef value_type*                             pointer;
        typedef size_t                                  size_type;
        typedef ConstRandomAccessIterator<T, Category>  iter;
        typedef ConstBidirectionalIterator              self_type;

    public:
        /* constructors */
        ConstBidirectionalIterator();
        explicit ConstBidirectionalIterator(pointer elem);
        ConstBidirectionalIterator(const self_type &x);

        /* destructors */
        virtual ~ConstBidirectionalIterator();

        /* operators */
        self_type&  operator = (const self_type &rhs);
        self_type&  operator = (const BidirectionalIterator<T, Category> &rhs);
        reference   operator * ();
        pointer     operator -> ();

    };

}

# include <BidirectionalIterator.ipp>

#endif
