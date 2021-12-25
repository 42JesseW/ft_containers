#include <ReverseIterator.hpp>

namespace ft {

    template <class Iterator>
    reverse_iterator<Iterator>::reverse_iterator() : _base(Iterator())
    {

    }

    template <class Iterator>
    reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : _base(it)
    {

    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::iterator_type  reverse_iterator<Iterator>::base() const
    {
        return (_base);
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator* */
    template <class Iterator>
    typename reverse_iterator<Iterator>::reference      reverse_iterator<Iterator>::operator * () const
    {
        iterator_type   result(_base);

        result--;
        return (*result);
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator[] */
    template <class Iterator>
    typename reverse_iterator<Iterator>::reference      reverse_iterator<Iterator>::operator [] (difference_type n) const
    {
        const std::type_info&   info = typeid(iterator_category);

        /* Iterator can only be of types bidirectional or random-access */
        if (info == typeid(std::bidirectional_iterator_tag))
        {
            iterator_type   it(_base);

            while ((n--) >= 0)
                --it;
            return (*it);
        }
        else if (info == typeid(std::random_access_iterator_tag))
            return (*(_base - n - 1));
        else
            throw std::runtime_error("Unsupported iterator category");
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator-> */
    template <class Iterator>
    typename reverse_iterator<Iterator>::pointer        reverse_iterator<Iterator>::operator -> () const
    {
        return (&(*(_base - 1)));
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator-= */
    template <class Iterator>
    reverse_iterator<Iterator>&                         reverse_iterator<Iterator>::operator -= (difference_type n)
    {
        const std::type_info&   info = typeid(iterator_category);

        if (info != typeid(std::random_access_iterator_tag))
            throw std::runtime_error("Unsupported iterator category");
        return (_base.operator+=(n));
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator-- */
    template <class Iterator>
    reverse_iterator<Iterator>&                         reverse_iterator<Iterator>::operator -- ()
    {
        _base++;
        return (*this);
    }

    template <class Iterator>
    reverse_iterator<Iterator>                         reverse_iterator<Iterator>::operator -- (int)
    {
        reverse_iterator<Iterator>  result(*this);

        _base++;
        return (result);
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator- */
    template <class Iterator>
    reverse_iterator<Iterator>                          reverse_iterator<Iterator>::operator - (difference_type n) const
    {
        const std::type_info&   info = typeid(iterator_category);

        if (info != typeid(std::random_access_iterator_tag))
            throw std::runtime_error("Unsupported iterator category");
        return (reverse_iterator<Iterator>(_base + n));
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator+= */
    template <class Iterator>
    reverse_iterator<Iterator>&                         reverse_iterator<Iterator>::operator += (difference_type n)
    {
        const std::type_info&   info = typeid(iterator_category);

        if (info != typeid(std::random_access_iterator_tag))
            throw std::runtime_error("Unsupported iterator category");
        return (_base.operator-=(n));
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator++ */
    template <class Iterator>
    reverse_iterator<Iterator>&                         reverse_iterator<Iterator>::operator ++ ()
    {
        _base--;
        return (*this);
    }

    template <class Iterator>
    reverse_iterator<Iterator>                         reverse_iterator<Iterator>::operator ++ (int)
    {
        reverse_iterator<Iterator>  result(*this);

        _base--;
        return (result);
    }

    /* http://www.cplusplus.com/reference/iterator/reverse_iterator/operator+ */
    template <class Iterator>
    reverse_iterator<Iterator>                          reverse_iterator<Iterator>::operator + (difference_type n) const
    {
        const std::type_info&   info = typeid(iterator_category);

        if (info != typeid(std::random_access_iterator_tag))
            throw std::runtime_error("Unsupported iterator category");
        return (reverse_iterator<Iterator>(_base - n));
    }
}
