#include <vector.hpp>

namespace ft {

	/* Constructs an empty container, with no elements. */
	template <class T, class Allocator>
	vector<T, Allocator>::vector(const allocator_type& alloc) : _allocator(alloc)
	{
		_size = 0;
		_capacity = 0;
		_array = NULL;
	}

	/* Constructs a container with n elements. Each element is a copy of val. */
	template <class T, class Allocator>
	vector<T, Allocator>::vector(
			size_type n,
			const value_type& val,
			const allocator_type& alloc
	) : _allocator(alloc)
	{
        _array = _safe_alloc(n);
        _capacity = n;
        for (size_type i = 0; i < n; ++i)
            _allocator.construct(_array + i, val);
		_size = n;
	}

	/* Constructs a container with a copy of each of the elements in x, in the same order. */
	template <class T, class Allocator>
	vector<T, Allocator>::vector(const vector<T, Allocator> &x) : _allocator(x.get_allocator())
	{
		_array = _safe_alloc(x.capacity());
		_capacity = x.capacity();
		for (size_type i = 0; i < x.size(); ++i)
			_allocator.construct(_array + i, x[i]);
		_size = x.size();
	}

	/*
	** This destroys all container elements, and deallocates all the storage capacity
	** allocated by the vector using its allocator.
	*/
	template <class T, class Allocator>
	vector<T, Allocator>::~vector()
	{
		_allocator.deallocate(_array, _capacity);
	}

	/*  Assigns new contents to the container, replacing its current contents, and modifying its size accordingly. */
	template <class T, class Allocator>
	vector<T, Allocator>&							vector<T, Allocator>::operator = (const vector <T, Allocator> &rhs)
	{
		if (this != &rhs)
		{
			if (rhs.size() > _capacity || rhs.size() < _size)	// TODO testcase (3)
				this->resize(rhs.size());
			for (size_type i = 0; i < rhs.size(); ++i)
				_allocator.construct(_array + i, rhs[i]);
			_size = rhs.size();
			std::allocator<int>::template rebind<float>::other allocator;
		}
		return (*this);
	}

	/* Returns a reference to the element at position n in the vector container. */
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference		vector<T, Allocator>::operator [] (size_type n)
	{
		return (_array[n]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference	vector<T, Allocator>::operator [] (size_type n) const
	{
		return (_array[n]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator			vector<T, Allocator>::begin()
	{
		return (iterator(_array));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::begin() const
	{
		return (const_iterator(_array));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator			vector<T, Allocator>::end()
	{
		return (iterator(_array + _size));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::end() const
	{
		return (const_iterator(_array + _size));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rbegin()
	{
		return (reverse_iterator(_array + (_size - 1)));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator	vector<T, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(_array + (_size - 1)));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator			vector<T, Allocator>::rend()
	{
		return (reverse_iterator(_array - 1));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator	vector<T, Allocator>::rend() const
	{
		return (const_reverse_iterator(_array - 1));
	}

	/* Returns the number of elements in the vector. */
	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::size() const
	{
		return (_size);
	}

	/* Returns the maximum number of elements that the vector can hold. */
	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::max_size() const
	{
		return (_allocator.max_size());
	}

	/* Resizes the container so that it contains n elements. */
	template <class T, class Allocator>
	void											vector<T, Allocator>::resize(size_type n, value_type val)
	{
		if (n > _allocator.max_size())
			throw std::length_error("vector");
		if (n < _size)
		{
			for (size_type i = n; i < _size; ++i)
				_allocator.destroy(_array + i);
		}
		else
		{
			if (n > _capacity)
				this->reserve(n);
            for (size_type i = _size; i < n; ++i)
                _allocator.construct(_array + i, val);
		}
		_size = n;
	}

	/* Returns the size of the storage space currently allocated for the vector, expressed in terms of elements. */
	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::capacity() const
	{
		return (_capacity);
	}

	/* Returns whether the vector is empty (i.e. whether its size is 0). */
	template <class T, class Allocator>
	bool											vector<T, Allocator>::empty() const
	{
		return (_size == 0);
	}

	/* Requests that the vector capacity be at least enough to contain n elements. */
	template <class T, class Allocator>
	void											vector<T, Allocator>::reserve(size_type n)
	{
	    pointer _new_array;

		if (n > _allocator.max_size())
			throw std::length_error("vector");
		if (n > _capacity)
		{
			_new_array = _safe_alloc(n);
			for (size_type i = 0; i < _size; ++i)
				_allocator.construct(_new_array + i, _array[i]);
			for (size_type i = 0; i < _size; ++i)
				_allocator.destroy(_array + i);
			_allocator.deallocate(_array, _capacity);
			_array = _new_array;
			_capacity = n;
		}
	}

	/* Returns a reference to the element at position n in the vector with boundary check */
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference		vector<T, Allocator>::at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("Index out of range");
		return (_array[n]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference	vector<T, Allocator>::at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("Index out of range");
		return (_array[n]);
	}

	/* Returns a reference to the first element in the vector. */
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference		vector<T, Allocator>::front()
	{
		return (*_array);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference	vector<T, Allocator>::front() const
	{
		return (*_array);
	}

	/* Returns a reference to the last element in the vector. */
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference		vector<T, Allocator>::back()
	{
		return (_array[_size - 1]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference	vector<T, Allocator>::back() const
	{
		return (_array[_size - 1]);
	}

	/*  Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly. */
	template <class T, class Allocator>
	void											vector<T, Allocator>::assign(size_type n, const value_type& val)
	{
		for (size_type i = 0; i < _size; ++i)
			_allocator.destroy(_array + i);
		if (n > _capacity)
		{
			_allocator.deallocate(_array, _capacity);
			_array = _safe_alloc(n);
			_capacity = n;
		}
		_size = n;
		for (size_type i = 0; i < _size; ++i)
			_allocator.construct(_array + i, val);
	}

	/*
	** Adds a new element at the end of the vector, after its current last element.
	** The content of val is copied (or moved) to the new element.
	*/
	template <class T, class Allocator>
	void											vector<T, Allocator>::push_back(const value_type& val)
	{
		if (_size == _capacity)
			this->reserve((!_capacity) ? 1 : _capacity * 2);
		++_size;
		_allocator.construct(_array + (_size - 1), val);
	}

	/*  Removes the last element in the vector, effectively reducing the container size by one. */
	template <class T, class Allocator>
	void											vector<T, Allocator>::pop_back()
	{
		--_size;
		_allocator.destroy(_array + (_size));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator			vector<T, Allocator>::insert(iterator position, const value_type &val)
	{
		iterator		start;
		iterator		it;
		difference_type idx;
		bool			at_end;

		idx = position - begin();
		at_end = (position == end());
		if (_size == _capacity)
			this->reserve(_capacity * 2);
		++_size;
		if (at_end)
		{
			_allocator.construct(_array + (_size - 1), val);
			return (end() - 1);
		}
		start = begin() + idx;
		it = start + 1;
		while (it != end())
		{
			_allocator.construct(_array + (it - begin()), *(it - 1));
			++it;
		}
		_allocator.construct(_array + (start - begin()), val);
		return (start);
	}

	template <class T, class Allocator>
	void											vector<T, Allocator>::insert(iterator position, size_type n, const value_type &val)
	{
		iterator		start;
		iterator		end;
		difference_type	idx;

		_size += n;
		idx = position - begin();
		/* check for extra needed capacity */
		if (_size > _capacity)
			this->reserve(_get_next_capacity());
		/* if insert is not at end, move all elements before it first */
		if (idx != (_size - n))
		{
			end = begin() + idx + (n * 2);
			start = begin() + idx + n;
			while (start != end)
			{
				_allocator.construct(_array + (start - begin()), *(start - n));
				++start;
			}
		}
		/* insert new elements */
		end = begin() + idx + n;
		start = begin() + idx;
		while (start != end)
		{
            _allocator.construct(_array + (start - begin()), val);
			++start;
		}
	}

	/*  Removes from the vector either a single element (position) or a range of elements ([first,last)). */
	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator		vector<T, Allocator>::erase(iterator position)
	{
		vector<T, Allocator>    tmp;
        difference_type         idx;

        if (position == end() - 1)
        {
            pop_back();
            return (end());
        }
        idx = position - begin();
		for (size_type size = _size; size != idx; --size)
        {
		    tmp.push_back(this->back());
		    this->pop_back();
        }
		this->pop_back();
		while (!tmp.empty())
        {
		    this->push_back(tmp.back());
		    tmp.pop_back();
        }
		return (iterator(begin() + idx));
	}

	// TODO use --fsanitize=address for compilation
	/*  Removes from the vector either a single element (position) or a range of elements ([first,last)). */
	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator		vector<T, Allocator>::erase(iterator first, iterator last)
	{
		vector<T, Allocator>    tmp;
		difference_type         idx;
		size_type               n;

		if (first == last)
		    return (erase(first));
		n = last - first;
		idx = last - begin();
		/* pop everything from self to tmp */
		for (size_type size = _size; size != idx; --size)
        {
		    tmp.push_back(this->back());
		    this->pop_back();
        }
		for (int idx = n; idx > 0; --idx)
		    this->pop_back();
        while (!tmp.empty())
        {
            this->push_back(tmp.back());
            tmp.pop_back();
        }
		return (iterator(begin() + (idx - n)));
	}

	/*
	** Exchanges the content of the container by the content of x, which is another vector object
	** of the same type. Sizes may differ. For iterator / pointer validity:
	** https://www.cplusplus.com/reference/vector/vector/swap/ -> Iterator validity
	*/
	template <class T, class Allocator>
	void											vector<T, Allocator>::swap(vector<T, Allocator> &x)
	{
		size_type 	tmp;
		pointer		tmp_p;

		tmp_p = x._array;
		x._array = _array;
		_array = tmp_p;
		tmp = x._size;
		x._size = _size;
		_size = tmp;
		tmp = x._capacity;
		x._capacity = _capacity;
		_capacity = tmp;
	}

	/*  Removes all elements from the vector (which are destroyed), leaving the container with a size of 0. */
	template <class T, class Allocator>
	void											vector<T, Allocator>::clear()
	{
		for (size_type i = 0; i < _size; ++i)
			_allocator.destroy(_array + i);
		_size = 0;
	}

	/* Returns a copy of the allocator object associated with the vector. */
	template <class T, class Allocator>
	typename vector<T, Allocator>::allocator_type	vector<T, Allocator>::get_allocator() const
	{
		return (_allocator);
	}

    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type        vector<T, Allocator>::_get_next_capacity()
    {
        double  capacity_diff;

        capacity_diff = static_cast<double>(_size) / static_cast<double>(_capacity);
        return ((!_capacity) ? _size : _capacity * static_cast<int>(std::ceil(capacity_diff)));
    }

    /*
    ** catch any exception thrown including std::bad_alloc and clean up the vector, then retrow
    ** https://stackoverflow.com/questions/36737602/why-three-points-in-catch-block-is-exist
    */
    template <class T, class Allocator>
    typename vector<T, Allocator>::pointer          vector<T, Allocator>::_safe_alloc(size_type n)
    {
        pointer new_array;

        try {
            new_array = _allocator.allocate(n);
        }
        catch (...) {
            clear();
            _allocator.deallocate(_array, _capacity);
            throw ;
        }
        return (new_array);
    }

}
