#include <RandomAccessIterator.hpp>

namespace ft {

	/*
	** RandomAccessIterator
	*/
	template <class T, class Category>
	RandomAccessIterator<T, Category>::RandomAccessIterator() : _ptr(NULL) {}

	template <class T, class Category>
	RandomAccessIterator<T, Category>::RandomAccessIterator(pointer elem) : _ptr(elem) {}

	template <class T, class Category>
	RandomAccessIterator<T, Category>::RandomAccessIterator(const self_type &x) { _ptr = x._ptr; }

	template <class T, class Category>
	RandomAccessIterator<T, Category>::~RandomAccessIterator() {}

	template <class T, class Category>
 	RandomAccessIterator<T, Category>	&RandomAccessIterator<T, Category>::operator = (const self_type &rhs)
	{
		if (this != &rhs)
			_ptr = rhs._ptr;
		return (*this);
	}

	template <class T, class Category>
	T		&RandomAccessIterator<T, Category>::operator [] (difference_type n) { return (_ptr[n]); }

	template <class T, class Category>
	bool	RandomAccessIterator<T, Category>::operator == (const self_type &rhs) { return (_ptr == rhs._ptr); }

	template <class T, class Category>
	bool	RandomAccessIterator<T, Category>::operator != (const self_type &rhs) { return (_ptr != rhs._ptr); }

	template <class T, class Category>
	T		&RandomAccessIterator<T, Category>::operator * () { return (*_ptr); }

	template <class T, class Category>
	T		*RandomAccessIterator<T, Category>::operator -> () { return (_ptr); }

	/* postfix returns a copy of the class when its not incremented yet */
	template <class T, class Category>
	RandomAccessIterator<T, Category>	RandomAccessIterator<T, Category>::operator ++ (int)
	{
		RandomAccessIterator<T, Category>	ret(*this);
		_ptr++;
		return (ret);
	}

	/* prefix increments this instance and returns a reference to self */
	template <class T, class Category>
	RandomAccessIterator<T, Category>	&RandomAccessIterator<T, Category>::operator ++ ()
	{
		_ptr++;
		return (*this);
	}

	/* postfix returns a copy of the class when its not decremented yet */
	template <class T, class Category>
	RandomAccessIterator<T, Category>	RandomAccessIterator<T, Category>::operator -- (int)
	{
		RandomAccessIterator<T, Category>	ret(*this);
		_ptr--;
		return (ret);
	}

	/* prefix decrements this instance and returns a reference to self */
	template <class T, class Category>
	RandomAccessIterator<T, Category>	&RandomAccessIterator<T, Category>::operator -- ()
	{
		_ptr--;
		return (*this);
	}

	/* creates a new instance of RandomAccessIterator and increments it by n */
	template <class T, class Category>
	RandomAccessIterator<T, Category>	RandomAccessIterator<T, Category>::operator + (difference_type n)
	{
		RandomAccessIterator<T, Category>	ret(*this);
		ret._ptr += n;
		return (ret);
	}

	/* creates a new instance of RandomAccessIterator and decrements it by n */
	template <class T, class Category>
	typename RandomAccessIterator<T, Category>::difference_type	RandomAccessIterator<T, Category>::operator - (const RandomAccessIterator &rhs)
	{
		RandomAccessIterator<T, Category>::difference_type	diff;
		diff = _ptr - rhs._ptr;
		return (diff);
	}

	/* creates a new instance of RandomAccessIterator and decrements it by n */
	template <class T, class Category>
	RandomAccessIterator<T, Category>	RandomAccessIterator<T, Category>::operator - (difference_type n)
	{
		RandomAccessIterator<T, Category>	ret(*this);
		ret._ptr -= n;
		return (ret);
	}

	template <class T, class Category>
	bool	RandomAccessIterator<T, Category>::operator < (const self_type &rhs) { return (_ptr < rhs._ptr); }

	template <class T, class Category>
	bool	RandomAccessIterator<T, Category>::operator > (const self_type &rhs) { return (_ptr > rhs._ptr); }

	template <class T, class Category>
	bool	RandomAccessIterator<T, Category>::operator <= (const self_type &rhs) { return (_ptr <= rhs._ptr); }

	template <class T, class Category>
	bool	RandomAccessIterator<T, Category>::operator >= (const self_type &rhs) { return (_ptr >= rhs._ptr); }

	/* Increments the current instance with n and returns itself */
	template <class T, class Category>
	RandomAccessIterator<T, Category>	RandomAccessIterator<T, Category>::operator += (difference_type n)
	{
		_ptr += n;
		return (*this);
	}

	/* Decrements the current instance with n and returns itself */
	template <class T, class Category>
	RandomAccessIterator<T, Category>	RandomAccessIterator<T, Category>::operator -= (difference_type n)
	{
		_ptr -= n;
		return (*this);
	}

	template <class T, class Category>
	typename RandomAccessIterator<T, Category>::pointer	RandomAccessIterator<T, Category>::getPointer() const { return (_ptr); }

	/*
	** ConstRandomAccessIterator TODO testcases
	*/
	template <class T, class Category>
	ConstRandomAccessIterator<T, Category>::ConstRandomAccessIterator() : RandomAccessIterator<T>(NULL) {}

	template <class T, class Category>
	ConstRandomAccessIterator<T, Category>::ConstRandomAccessIterator(pointer elem) : RandomAccessIterator<T>(elem) {}

	template <class T, class Category>
	ConstRandomAccessIterator<T, Category>::ConstRandomAccessIterator(const self_type &x) : RandomAccessIterator<T>(x) {}

	template <class T, class Category>
	ConstRandomAccessIterator<T, Category>::~ConstRandomAccessIterator() {}

	template <class T, class Category>
	ConstRandomAccessIterator<T, Category>	&ConstRandomAccessIterator<T, Category>::operator = (const self_type &rhs)
	{
		if (this != &rhs)
			this->_ptr = rhs.getPointer();
		return (*this);
	}

	template <class T, class Category>
	ConstRandomAccessIterator<T, Category>	&ConstRandomAccessIterator<T, Category>::operator = (const RandomAccessIterator<T> &rhs)
	{
		if (this != &rhs)
			this->_ptr = rhs.getPointer();
		return (*this);
	}

	template <class T, class Category>
	const T		&ConstRandomAccessIterator<T, Category>::operator [] (difference_type n) { return (this->_ptr[n]); }

	template <class T, class Category>
	const T		&ConstRandomAccessIterator<T, Category>::operator * () { return (*this->_ptr); }

	template <class T, class Category>
	const T		*ConstRandomAccessIterator<T, Category>::operator -> () { return (this->_ptr); }

	/*
	** RevRandomAccessIterator TODO testcases
	*/
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>::RevRandomAccessIterator() : _ptr(NULL) {}

	template <class T, class Category>
	RevRandomAccessIterator<T, Category>::RevRandomAccessIterator(pointer elem) : _ptr(elem) {}

	template <class T, class Category>
	RevRandomAccessIterator<T, Category>::RevRandomAccessIterator(const self_type &x) { _ptr = x._ptr; }

	template <class T, class Category>
	RevRandomAccessIterator<T, Category>::~RevRandomAccessIterator() {}

	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	&RevRandomAccessIterator<T, Category>::operator = (const self_type &rhs)
	{
		if (this != &rhs)
		{
			_ptr = rhs._ptr;
		}
		return (*this);
	}

	template <class T, class Category>
	T		&RevRandomAccessIterator<T, Category>::operator [] (difference_type n) { return (_ptr[n]); }

	template <class T, class Category>
	bool	RevRandomAccessIterator<T, Category>::operator == (const self_type &rhs) { return (_ptr == rhs._ptr); }

	template <class T, class Category>
	bool	RevRandomAccessIterator<T, Category>::operator != (const self_type &rhs) { return (_ptr != rhs._ptr); }

	template <class T, class Category>
	T		&RevRandomAccessIterator<T, Category>::operator * () { return (*_ptr); }

	template <class T, class Category>
	T		*RevRandomAccessIterator<T, Category>::operator -> () { return (_ptr); }

	/* postfix returns a copy of the class when its not decremented yet */
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	RevRandomAccessIterator<T, Category>::operator ++ (int)
	{
		RandomAccessIterator<T, Category>	ret(*this);
		_ptr--;
		return (ret);
	}

	/* prefix decrements this instance and returns a reference to self */
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	&RevRandomAccessIterator<T, Category>::operator ++ ()
	{
		_ptr--;
		return (*this);
	}

	/* postfix returns a copy of the class when its not incremented yet */
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	RevRandomAccessIterator<T, Category>::operator -- (int)
	{
		RandomAccessIterator<T, Category>	ret(*this);
		_ptr++;
		return (ret);
	}

	/* prefix increments this instance and returns a reference to self */
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	&RevRandomAccessIterator<T, Category>::operator -- ()
	{
		_ptr++;
		return (*this);
	}

	/* creates a new instance of RandomAccessIterator and decrements it by n */
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	RevRandomAccessIterator<T, Category>::operator + (difference_type n)
	{
		RevRandomAccessIterator<T, Category>	ret(*this);
		ret._ptr -= n;
		return (ret);
	}

	/* creates a new instance of RandomAccessIterator and increments it by n */
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	RevRandomAccessIterator<T, Category>::operator - (difference_type n)
	{
		RevRandomAccessIterator<T, Category>	ret(*this);
		ret._ptr += n;
		return (ret);
	}

	template <class T, class Category>
	bool	RevRandomAccessIterator<T, Category>::operator < (const self_type &rhs) { return (_ptr < rhs._ptr); }

	template <class T, class Category>
	bool	RevRandomAccessIterator<T, Category>::operator > (const self_type &rhs) { return (_ptr > rhs._ptr); }

	template <class T, class Category>
	bool	RevRandomAccessIterator<T, Category>::operator <= (const self_type &rhs) { return (_ptr <= rhs._ptr); }

	template <class T, class Category>
	bool	RevRandomAccessIterator<T, Category>::operator >= (const self_type &rhs) { return (_ptr >= rhs._ptr); }

	/* Decrements the current instance with n and returns itself */
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	RevRandomAccessIterator<T, Category>::operator += (difference_type n)
	{
		_ptr -= n;
		return (*this);
	}

	/* Increments the current instance with n and returns itself */
	template <class T, class Category>
	RevRandomAccessIterator<T, Category>	RevRandomAccessIterator<T, Category>::operator -= (difference_type n)
	{
		_ptr += n;
		return (*this);
	}

	template <class T, class Category>
	typename RevRandomAccessIterator<T, Category>::pointer	RevRandomAccessIterator<T, Category>::getPointer() const { return (_ptr); }

	/*
	** ConstRevRandomAccessIterator
	*/
	template <class T, class Category>
	ConstRevRandomAccessIterator<T, Category>::ConstRevRandomAccessIterator() : RevRandomAccessIterator<T>(NULL) {}

	template <class T, class Category>
	ConstRevRandomAccessIterator<T, Category>::ConstRevRandomAccessIterator(pointer elem) : RevRandomAccessIterator<T>(elem) {}

	template <class T, class Category>
	ConstRevRandomAccessIterator<T, Category>::ConstRevRandomAccessIterator(const self_type &x) : RevRandomAccessIterator<T>(x) {}

	template <class T, class Category>
	ConstRevRandomAccessIterator<T, Category>::~ConstRevRandomAccessIterator() {}

	template <class T, class Category>
	ConstRevRandomAccessIterator<T, Category>	&ConstRevRandomAccessIterator<T, Category>::operator = (const self_type &rhs)
	{
		if (this != &rhs)
			this->_ptr = rhs.getPointer();
		return (*this);
	}

	template <class T, class Category>
	ConstRevRandomAccessIterator<T, Category>	&ConstRevRandomAccessIterator<T, Category>::operator = (const RevRandomAccessIterator<T> &rhs)
	{
		if (this != &rhs)
			this->_ptr = rhs.getPointer();
		return (*this);
	}

	template <class T, class Category>
	const T		&ConstRevRandomAccessIterator<T, Category>::operator [] (difference_type n) { return (this->_ptr[n]); }

	template <class T, class Category>
	const T		&ConstRevRandomAccessIterator<T, Category>::operator * () { return (*this->_ptr); }

	template <class T, class Category>
	const T		*ConstRevRandomAccessIterator<T, Category>::operator -> () { return (this->_ptr); }

}
