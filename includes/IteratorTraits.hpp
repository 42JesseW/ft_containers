namespace ft {

	/*
	** [enable_if]
	** Typedef {type} if a condition is true using template specialization.
	** and SFINAE (Substitution Failure is not an error).
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
		template <class U> static true_type		test(typename U::iterator_category* = 0);
		template <class U> static false_type	test(...);

	public:
		static const bool   has_category = (sizeof(true_type) == sizeof(test<T>(0)));
	};

	template <class T>
	struct iterator_traits : public enable_if<has_iterator_category<T>::has_category, T> {};

}