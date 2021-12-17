#ifndef ITERATOR_TRAITS_H

# define ITERATOR_TRAITS_H

namespace ft {

	/*
	** [enable_if]
	** Typedef {type} if a condition is true using template specialization.
	** and SFINAE (Substitution Failure is not an error).
	** // TODO https://www.cplusplus.com/reference/type_traits/enable_if/
	*/

	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };

	template <class T>
	struct has_iterator_category
	{
	private:
		typedef char							true_type;
		typedef int								false_type;

		/* No need to implement function. sizeof() checks return type size */
		template <class U> static true_type     test(typename U::iterator_category* = 0);
		template <class U> static false_type    test(...);

	public:
		static const bool   has_category = (sizeof(true_type) == sizeof(test<T>(0)));
	};

	template <class T>
    class iterator_check : public enable_if<has_iterator_category<T>::has_category, T> {};

	template <class Iterator>
	class iterator_traits
    {
    public:
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;

    };

}

#endif
