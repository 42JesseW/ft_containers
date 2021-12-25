#include <stack.hpp>

namespace ft {

    template <class T, class Container>
    stack<T, Container>::stack(const container_type &ctnr) : _container(ctnr) {}

    template <class T, class Container>
    typename stack<T, Container>::size_type         stack<T, Container>::size() const {
        return (_container.size());
    }

    template <class T, class Container>
    bool                                            stack<T, Container>::empty() const {
        return (_container.empty());
    }

    template <class T, class Container>
    typename stack<T, Container>::value_type&       stack<T, Container>::top() {
        return (_container.back());
    }

    template <class T, class Container>
    const typename stack<T, Container>::value_type& stack<T, Container>::top() const {
        return (_container.back());
    }

    template <class T, class Container>
    void                                            stack<T, Container>::push(const value_type &val) {
        _container.push_back(val);
    }

    template <class T, class Container>
    void                                            stack<T, Container>::pop() {
        _container.pop_back();
    }
}