#include <BidirectionalIterator.hpp>

namespace ft {

    template <class T, class Category>
    BidirectionalIterator<T, Category>::BidirectionalIterator() : RandomAccessIterator<T, Category>(NULL)
    {

    }

    template <class T, class Category>
    BidirectionalIterator<T, Category>::BidirectionalIterator(pointer elem) : RandomAccessIterator<T, Category>(elem)
    {

    }

    template <class T, class Category>
    BidirectionalIterator<T, Category>::BidirectionalIterator(const self_type &x) : RandomAccessIterator<T, Category>(x)
    {

    }

    template <class T, class Category>
    BidirectionalIterator<T, Category>::~BidirectionalIterator()
    {

    }

    template <class T, class Category>
    BidirectionalIterator<T, Category>& BidirectionalIterator<T, Category>::operator = (const self_type &rhs)
    {

        if (this != &rhs)
            this->_ptr = rhs.getPointer();
        return (*this);
    }

    template <class T, class Category>
    bool                                BidirectionalIterator<T, Category>::operator == (const self_type &rhs)
    {
        return (iter::operator==(rhs));
    }

    template <class T, class Category>
    bool                                BidirectionalIterator<T, Category>::operator != (const self_type &rhs)
    {
        return (iter::operator!=(rhs));
    }

    template <class T, class Category>
    typename BidirectionalIterator<T, Category>::reference BidirectionalIterator<T, Category>::operator * ()
    {
        return (iter::operator*());
    }

    template <class T, class Category>
    typename BidirectionalIterator<T, Category>::pointer BidirectionalIterator<T, Category>::operator -> ()
    {
        return (iter::operator->());
    }

    template <class T, class Category>
    BidirectionalIterator<T, Category>                  BidirectionalIterator<T, Category>::operator ++ (int)
    {
        BidirectionalIterator<T, Category>  result(*this);

        ++this->_ptr;
        return (result);
    }

    template <class T, class Category>
    BidirectionalIterator<T, Category>&                 BidirectionalIterator<T, Category>::operator ++ ()
    {
        ++this->_ptr;
        return (*this);
    }

    template <class T, class Category>
    BidirectionalIterator<T, Category>                  BidirectionalIterator<T, Category>::operator -- (int)
    {
        BidirectionalIterator<T, Category>  result(*this);

        --this->_ptr;
        return (result);
    }

    template <class T, class Category>
    BidirectionalIterator<T, Category>&                 BidirectionalIterator<T, Category>::operator -- ()
    {
        --this->_ptr;
        return (*this);
    }
}
