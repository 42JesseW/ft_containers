#ifndef RANDOM_ACCESS_ITERATOR_H

# define RANDOM_ACCESS_ITERATOR_H

# include <iterator>

namespace ft {

	/* https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */

	template <class T, class Category = std::random_access_iterator_tag>
	class RandomAccessIterator
	{
	public:
		typedef T						value_type;
		typedef value_type&				reference;
		typedef value_type*				pointer;
		typedef size_t					size_type;
		typedef ptrdiff_t 				difference_type;
		typedef Category				iterator_category;
		typedef RandomAccessIterator	self_type;

	protected:
		pointer							_ptr;

	public:
		/* constructors */
		RandomAccessIterator();
		explicit RandomAccessIterator(pointer elem);
		RandomAccessIterator(const self_type &x);

		/* destructors */
		virtual ~RandomAccessIterator();

        /* operators */
        self_type&		operator = (const self_type &rhs);
        bool			operator == (const self_type &rhs);
        bool			operator != (const self_type &rhs);
        reference		operator * ();
        pointer			operator -> ();
        self_type		operator ++ (int);	// overload postfix ++
        self_type&		operator ++ ();		// overload prefix ++
        self_type		operator -- (int);	// overload postfix --
        self_type&		operator -- ();		// overload prefix --
        self_type		operator + (difference_type n);
        difference_type	operator - (const self_type &rhs);
        self_type		operator - (difference_type n);
        bool			operator < (const self_type &rhs);
        bool			operator > (const self_type &rhs);
        bool			operator <= (const self_type &rhs);
		bool			operator >= (const self_type &rhs);
		self_type		operator += (difference_type n);
		self_type		operator -= (difference_type n);
		reference       operator [] (difference_type n);

		/* getters */
		pointer			getPointer(void) const;

	};

	template <class T, class Category>
    typename RandomAccessIterator<T, Category>::self_type   operator +
        (typename RandomAccessIterator<T, Category>::difference_type n, RandomAccessIterator<T, Category> it)
    {
        return (it + n);
    }

	template <class T, class Category = std::random_access_iterator_tag>
	class ConstRandomAccessIterator : public RandomAccessIterator<T>
	{
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
		typedef const value_type&			const_reference;
		typedef const value_type*			const_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t 					difference_type;
		typedef Category					iterator_category;
		typedef ConstRandomAccessIterator	self_type;

	public:
		/* constructors */
		ConstRandomAccessIterator();
		explicit ConstRandomAccessIterator(pointer elem);
		ConstRandomAccessIterator(const self_type &x);

		/* destructors */
		virtual ~ConstRandomAccessIterator();

		/* operators */
		self_type&		operator = (const self_type &rhs);
		self_type&		operator = (const RandomAccessIterator<T> &rhs);
		const_reference	operator [] (difference_type n);
		const_reference	operator * ();
		const_pointer 	operator -> ();

	};

	template <class T, class Category = std::random_access_iterator_tag>
	class RevRandomAccessIterator
	{
	public:
		typedef T						value_type;
		typedef value_type&				reference;
		typedef value_type*				pointer;
		typedef size_t					size_type;
		typedef ptrdiff_t 				difference_type;
		typedef Category				iterator_category;
		typedef RevRandomAccessIterator	self_type;

	protected:
		pointer							_ptr;

	public:
		/* constructors */
		RevRandomAccessIterator();
		explicit RevRandomAccessIterator(pointer elem);
		RevRandomAccessIterator(const self_type &x);

		/* destructors */
		virtual ~RevRandomAccessIterator();

		/* operators */
        self_type&	    operator = (const self_type &rhs);
        bool		    operator == (const self_type &rhs);
        bool		    operator != (const self_type &rhs);
        reference	    operator * ();
        pointer		    operator -> ();
        self_type	    operator ++ (int);	// overload postfix ++
        self_type&	    operator ++ ();		// overload prefix ++
        self_type	    operator -- (int);	// overload postfix --
        self_type&	    operator -- ();		// overload prefix --
		self_type	    operator + (difference_type n);
		self_type	    operator - (difference_type n);
		bool		    operator < (const self_type &rhs);
		bool		    operator > (const self_type &rhs);
		bool		    operator <= (const self_type &rhs);
		bool		    operator >= (const self_type &rhs);
		self_type	    operator += (difference_type n);
		self_type	    operator -= (difference_type n);
		reference	    operator [] (difference_type n);

		/* getters */
		pointer			getPointer(void) const;
	};

    template <class T, class Category>
    typename RevRandomAccessIterator<T, Category>::self_type   operator +
            (typename RevRandomAccessIterator<T, Category>::difference_type n, RevRandomAccessIterator<T, Category> it)
    {
        return (it - n);
    }

	template <class T, class Category = std::random_access_iterator_tag>
	class ConstRevRandomAccessIterator : public RevRandomAccessIterator<T>
	{
	public:
		typedef T								value_type;
		typedef value_type&						reference;
		typedef value_type*						pointer;
		typedef const value_type&				const_reference;
		typedef const value_type*				const_pointer;
		typedef size_t							size_type;
		typedef ptrdiff_t 						difference_type;
		typedef Category						iterator_category;
		typedef ConstRevRandomAccessIterator	self_type;

	public:
		/* constructors */
		ConstRevRandomAccessIterator();
		explicit ConstRevRandomAccessIterator(pointer elem);
		ConstRevRandomAccessIterator(const self_type &x);

		/* destructors */
		virtual ~ConstRevRandomAccessIterator();

		/* operators */
		self_type&		operator = (const self_type &rhs);
		self_type&		operator = (const RevRandomAccessIterator<T> &rhs);
		const_reference	operator [] (difference_type n);
		const_reference	operator * ();
		const_pointer 	operator -> ();

	};

}

# include <RandomAccessIterator.ipp>

#endif
