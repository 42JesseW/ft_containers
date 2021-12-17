#include <stack.hpp>
#include <stack>
#include <gtest/gtest.h>

class StackConstruction : public ::testing::Test
{
public:
	int					_test_size;
	int					_test_val;

protected:
	std::stack<int, std::vector<int>>		*_their_stack;
	ft::stack<int>							*_my_stack;

	void	SetUp() override {
		_their_stack	= nullptr;
		_my_stack		= nullptr;
		_test_size		= 100;
		_test_val		= 20;
	}

	virtual ~StackConstruction() {
		delete	_their_stack;
		delete	_my_stack;
	}

	void	check_members_equal() {
		EXPECT_EQ(_their_stack->size(), _my_stack->size());
		EXPECT_EQ(_their_stack->empty(), _my_stack->empty());
	}

	virtual void	check_array_data_equal() {
		check_members_equal();
		std::stack<int>	their_tmp;
		ft::stack<int>	my_tmp;

		while (!_my_stack->empty()) {
			their_tmp.push(_their_stack->top());
			_their_stack->pop();
			my_tmp.push(_my_stack->top());
			_my_stack->pop();
			EXPECT_EQ(my_tmp.top(), their_tmp.top());
		}
		size_t	inital_size = their_tmp.size();
		while (_my_stack->size() != inital_size) {
			_their_stack->push(their_tmp.top());
			their_tmp.pop();
			_my_stack->push(my_tmp.top());
			my_tmp.pop();
		}
	}
};

/*
** ( CONSTRUCTOR )
*/

TEST_F(StackConstruction, ConstructDefault) {
	_their_stack	= new std::stack<int, std::vector<int>>();
	_my_stack		= new ft::stack<int>();
	check_members_equal();
}

TEST_F(StackConstruction, FromContainer) {
	std::vector<int>	their_vec(_test_size, _test_val);
	ft::vector<int>		my_vec(_test_size, _test_val);

	_their_stack	= new std::stack<int, std::vector<int>>(their_vec);
	_my_stack		= new ft::stack<int, ft::vector<int>>(my_vec);
	check_array_data_equal();
}
