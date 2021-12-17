#ifndef STACK_H
# define STACK_H

# include <vector.hpp>

namespace ft {

	/* https://www.cplusplus.com/reference/stack/stack/ */
	template <class T, class Container = vector<T> >
	class stack
	{
	public:
		/* member types */
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t			size_type;

	protected:
		container_type			_container;

	public:
		/* constructors */
		explicit stack (const container_type& ctnr = container_type());

		/* capacity */
		size_type				size() const;
		bool					empty() const;

		/* element access */
		value_type&				top();
		const value_type&		top() const;
		void					push(const value_type& val);
		void					pop();

	};

	/* relational operators */
	template <class T, class Container>
	bool	operator == (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs._container == rhs._container);
	}

	template <class T, class Container>
	bool	operator != (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs._container != rhs._container);
	}

	template <class T, class Container>
	bool	operator <  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs._container < rhs._container);
	}

	template <class T, class Container>
	bool	operator <= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs._container <= rhs._container);
	}

	template <class T, class Container>
	bool	operator >  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs._container > rhs._container);
	}

	template <class T, class Container>
	bool	operator >= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs._container >= rhs._container);
	}

}

# include <stack.ipp>

#endif
