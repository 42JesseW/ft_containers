#include <vector.hpp>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>

/*
** ( CONSTRUCTOR )
*/

class VectorConstruction : public ::testing::Test
{
public:
	int					_test_size;
	int					_test_val;

protected:
	std::vector<int>	*_their_vector;
	ft::vector<int>		*_my_vector;

	void	SetUp() override {
		_their_vector	= nullptr;
		_my_vector		= nullptr;
		_test_size		= 100;
		_test_val		= 20;
	}

    virtual void TearDown() override {
		delete	_their_vector;
		delete	_my_vector;
	}

	void	check_members_equal() {
		EXPECT_EQ(_their_vector->size(), _my_vector->size());
		//EXPECT_EQ(_their_vector->capacity(), _my_vector->capacity());
		EXPECT_EQ(_their_vector->get_allocator(), _my_vector->get_allocator());
	}

	virtual void	check_array_data_equal() {
		check_members_equal();
		for (size_t i = 0; i < _my_vector->size(); i++)
			EXPECT_EQ(_their_vector->at(i), _my_vector->at(i));
	}
};


TEST_F(VectorConstruction, ConstructDefault) {
	_their_vector	= new std::vector<int>();
	_my_vector		= new ft::vector<int>();
	check_members_equal();
}


TEST_F(VectorConstruction, ConstructFill) {
	_their_vector	= new std::vector<int>(_test_size);
	_my_vector		= new ft::vector<int>(_test_size);
	check_array_data_equal();
	delete _their_vector;
    delete _my_vector;
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	check_array_data_equal();
}


TEST_F(VectorConstruction, ConstructRange) {
	std::vector<int>	range_vec_std(_test_size, _test_val);
	ft::vector<int>		range_vec_ft(_test_size, _test_val);

	_their_vector	= new std::vector<int>(range_vec_std.begin() + 2, range_vec_std.end() - 3);
	_my_vector		= new ft::vector<int>(range_vec_ft.begin() + 2, range_vec_ft.end() - 3);
	check_members_equal();
	check_array_data_equal();
}


TEST_F(VectorConstruction, ConstructCopy) {
	std::vector<int>	copy_vec_std(_test_size, _test_val);
	ft::vector<int>		copy_vec_ft(_test_size, _test_val);

	_their_vector	= new std::vector<int>(copy_vec_std);
	_my_vector		= new ft::vector<int>(copy_vec_ft);
	check_members_equal();
	check_array_data_equal();
}

/*
** ( OPERATOR )
*/
class VectorOperator : public VectorConstruction
{

};

TEST_F(VectorOperator, OutOfBounds) {
    int value;

	EXPECT_EXIT( value = (*_my_vector)[0], ::testing::KilledBySignal(SIGSEGV), "");
	EXPECT_EXIT( value = _my_vector->at(0), ::testing::KilledBySignal(SIGSEGV), "");
	_my_vector = new ft::vector<int>(_test_size);
	EXPECT_THROW( value = _my_vector->at(_test_size + 1), std::out_of_range);
    (void)value;
}

TEST_F(VectorOperator, Assignment) {
	std::vector<int>	assign_vec_std_one(_test_size, _test_val);
	ft::vector<int>		assign_vec_ft_one(_test_size, _test_val);

	_their_vector	= new std::vector<int>(_test_size * 0.5);
	_my_vector		= new ft::vector<int>(_test_size * 0.5);
	*_their_vector	= assign_vec_std_one;
	*_my_vector		= assign_vec_ft_one;
	check_array_data_equal();
    delete _their_vector;
    delete _my_vector;
    std::vector<int>	assign_vec_std_two(_test_size, _test_val);
    ft::vector<int>		assign_vec_ft_two(_test_size, _test_val);
    _their_vector	= new std::vector<int>(_test_size);
    _my_vector		= new ft::vector<int>(_test_size);
    *_their_vector	= assign_vec_std_two;
    *_my_vector		= assign_vec_ft_two;
    check_array_data_equal();
    delete _their_vector;
    delete _my_vector;
    std::vector<int>	assign_vec_std_three(_test_size * 0.5, _test_val);
    ft::vector<int>		assign_vec_ft_three(_test_size * 0.5, _test_val);
    _their_vector	= new std::vector<int>(_test_size);
    _my_vector		= new ft::vector<int>(_test_size);
    *_their_vector	= assign_vec_std_three;
    *_my_vector		= assign_vec_ft_three;
    check_array_data_equal();
}

/*
** ( ITERATORS )
*/
class VectorIterator : public VectorConstruction
{

};

TEST_F(VectorIterator, ValueChecksConst)
{
    ft::vector<int>         my_assign_vec(_test_size);
    std::vector<int>        their_assing_vec(_test_size);

    std::iota(my_assign_vec.begin(), my_assign_vec.end(), 0);
    std::iota(their_assing_vec.begin(), their_assing_vec.end(), 0);
    auto _c_their_vector    = new const std::vector<int>(their_assing_vec.begin(), their_assing_vec.end());
    auto _c_my_vector	    = new const ft::vector<int>(my_assign_vec.begin(), my_assign_vec.end());

    std::vector<int>::const_iterator    their_it(_c_their_vector->begin());
    ft::vector<int>::const_iterator     my_it(_c_my_vector->begin());
    for (int idx = 0; idx < _test_size; idx++) {
        EXPECT_EQ(*their_it, *my_it);
        their_it++;
        my_it++;
    }
    delete _c_my_vector;
    delete _c_their_vector;
}

TEST_F(VectorIterator, ValueChecksConstReverse)
{
    ft::vector<int>         my_assign_vec(_test_size);
    std::vector<int>        their_assing_vec(_test_size);

    std::iota(my_assign_vec.begin(), my_assign_vec.end(), 0);
    std::iota(their_assing_vec.begin(), their_assing_vec.end(), 0);
    auto _c_their_vector    = new const std::vector<int>(their_assing_vec.begin(), their_assing_vec.end());
    auto _c_my_vector	    = new const ft::vector<int>(my_assign_vec.begin(), my_assign_vec.end());

    typedef std::vector<int>::const_iterator    their_iter_t;
    typedef ft::vector<int>::const_iterator     my_iter_t;

    their_iter_t                                their_it(_c_their_vector->end());
    my_iter_t                                   my_it(_c_my_vector->end());
    std::reverse_iterator<their_iter_t>         their_it_rev(their_it);
    ft::reverse_iterator<my_iter_t>             my_it_rev(my_it);
    for (int idx = 0; idx < _test_size; idx++) {
        EXPECT_EQ(*their_it_rev, *my_it_rev);
        their_it_rev++;
        my_it_rev++;
    }
    delete _c_my_vector;
    delete _c_their_vector;
}


/*
** ( CAPACITY )
*/
class VectorCapacity : public VectorConstruction
{

};

TEST_F(VectorCapacity, Members) {
	_their_vector	= new std::vector<int>();
	_my_vector		= new ft::vector<int>();

	for (int i = 0; i < 100; i++)
	{
		_their_vector->push_back(i);
		_my_vector->push_back(i);
		check_members_equal();
	}
}

TEST_F(VectorCapacity, Resize) {
	_their_vector	= new std::vector<int>();
	_my_vector		= new ft::vector<int>();

	EXPECT_THROW(_their_vector->resize(_their_vector->max_size() + 1), std::length_error);
	EXPECT_THROW(_my_vector->resize(_my_vector->max_size() + 1), std::length_error);
	_their_vector->resize(_test_size);
	_my_vector->resize(_test_size);
	std::iota(_their_vector->begin(), _their_vector->end(), 0);
	std::iota(_my_vector->begin(), _my_vector->end(), 0);
	check_members_equal();
	_their_vector->resize(_test_size * 0.5);
	_my_vector->resize(_test_size * 0.5);
	check_array_data_equal();
	_their_vector->resize(_test_size * 2, 5);
	_my_vector->resize(_test_size * 2, 5);
	check_array_data_equal();
}

TEST_F(VectorCapacity, Reserve) {
	_their_vector	= new std::vector<int>();
	_my_vector		= new ft::vector<int>();

	EXPECT_THROW(_their_vector->reserve(_their_vector->max_size() + 1), std::length_error);
	EXPECT_THROW(_my_vector->reserve(_my_vector->max_size() + 1), std::length_error);
	_their_vector->reserve(_test_size * 0.5);
	_my_vector->reserve(_test_size * 0.5);
	std::iota(_their_vector->begin(), _their_vector->end(), 0);
	std::iota(_my_vector->begin(), _my_vector->end(), 0);
	_their_vector->reserve(_test_size);
	_my_vector->reserve(_test_size);
	check_array_data_equal();
}

/*
** ( ELEMENT ACCESS )
*/
class VectorElementAccess : public VectorConstruction
{

};

TEST_F(VectorElementAccess, at) {

}

TEST_F(VectorElementAccess, front) {

}

TEST_F(VectorElementAccess, back) {

}

/*
** ( MODIFIERS )
*/
class VectorModifiers : public VectorConstruction
{

};

TEST_F(VectorModifiers, assignFill) {
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);

	_their_vector->assign(_test_size * 0.5, _test_val * 0.5);
	_my_vector->assign(_test_size * 0.5, _test_val * 0.5);
	check_array_data_equal();
	_their_vector->assign(_test_size * 2, _test_val * 2);
	_my_vector->assign(_test_size * 2, _test_val * 2);
	check_array_data_equal();
}

TEST_F(VectorModifiers, assignRange) {
    auto *their_vec = new std::vector<std::string>();
    auto *my_vec    = new ft::vector<std::string>();

    std::vector<std::string>    fillWith(_test_size);
    for (size_t i = 0; i < fillWith.size(); ++i)
        fillWith[i] = std::to_string(i);
    their_vec->assign(fillWith.begin(), fillWith.end());
    my_vec->assign(fillWith.begin(), fillWith.end());
    for (size_t i = 0; i < my_vec->size(); ++i)
        EXPECT_EQ(their_vec->at(i), my_vec->at(i));
    EXPECT_EQ(their_vec->size(), my_vec->size());
    EXPECT_EQ(their_vec->capacity(), my_vec->capacity());
    EXPECT_EQ(their_vec->get_allocator(), my_vec->get_allocator());
}

TEST_F(VectorModifiers, pop_back) {
	_their_vector	= new std::vector<int>();
	_my_vector		= new ft::vector<int>();

	_their_vector->resize(_test_size);
	_my_vector->resize(_test_size);
	std::iota(_their_vector->begin(), _their_vector->end(), 0);
	std::iota(_my_vector->begin(), _my_vector->end(), 0);
	for (int i = 0; i < _test_size * 0.5; i++)
	{
		_their_vector->pop_back();
		_my_vector->pop_back();
	}
	check_array_data_equal();
}

TEST_F(VectorModifiers, push_back) {
    _their_vector	= new std::vector<int>();
    _my_vector		= new ft::vector<int>();

    for (int j = 0; j < 4; j++) {
        for (size_t i = 0; i < (_test_size * 0.5); i++) {
            _my_vector->push_back(i);
            _their_vector->push_back(i);
        }
        for (size_t i = 0; i < (_test_size * 0.25); i++) {
            _my_vector->pop_back();
            _their_vector->pop_back();
        }
    }
    check_array_data_equal();
}

TEST_F(VectorModifiers, insertSingle) {
	_their_vector	= new std::vector<int>(3);
	_my_vector		= new ft::vector<int>(3);
	std::vector<int>::iterator	their_it;
	ft::vector<int>::iterator	my_it;

	their_it = _their_vector->insert(_their_vector->begin(), _test_val * 0.5);
	my_it = _my_vector->insert(_my_vector->begin(), _test_val * 0.5);
	EXPECT_EQ(*their_it, *my_it);
	their_it = _their_vector->insert(_their_vector->begin() + 1, _test_val * 0.5);
	my_it = _my_vector->insert(_my_vector->begin() + 1, _test_val * 0.5);
	EXPECT_EQ(*their_it, *my_it);
	their_it = _their_vector->insert(_their_vector->end(), _test_val * 0.5);
	my_it = _my_vector->insert(_my_vector->end(), _test_val * 0.5);
	EXPECT_EQ(*their_it, *my_it);
	check_array_data_equal();
}

TEST_F(VectorModifiers, insertFill) {
	_their_vector = new std::vector<int>(3);
	_my_vector = new ft::vector<int>(3);

	_their_vector->insert(_their_vector->begin(), 2, _test_val * 0.5);
	_my_vector->insert(_my_vector->begin(), 2, _test_val * 0.5);
	check_array_data_equal();
	_their_vector->insert(_their_vector->begin() + 2, 2, _test_val * 2);
	_my_vector->insert(_my_vector->begin() + 2, 2, _test_val * 2);
	check_array_data_equal();
	_their_vector->insert(_their_vector->end(), 2, _test_val * 3);
	_my_vector->insert(_my_vector->end(), 2, _test_val * 3);
	check_array_data_equal();
}

TEST_F(VectorModifiers, insertrange) {
	_their_vector       = new std::vector<int>(_test_size * 0.25);
	_my_vector          = new ft::vector<int>(_test_size * 0.25);
    std::vector<int>    their_fillWith(_test_size);
    ft::vector<int>     my_fillWith(_test_size);

    std::iota(their_fillWith.begin(), their_fillWith.end(), 0);
    std::iota(my_fillWith.begin(), my_fillWith.end(), 0);
    _their_vector->insert(_their_vector->begin(), their_fillWith.begin(), their_fillWith.begin() + (_test_size * 0.5));
    _my_vector->insert(_my_vector->begin(), my_fillWith.begin(), my_fillWith.begin() + (_test_size * 0.5));
//    check_array_data_equal();
    _their_vector->insert(_their_vector->begin(), their_fillWith.begin(), their_fillWith.end());
//    _my_vector->insert(_my_vector->begin() + (_test_size * 0.5), my_fillWith.begin(), my_fillWith.begin() + (_test_size * 0.25));
//    check_array_data_equal();
//   _their_vector->insert(_their_vector->end(), their_fillWith.begin(), their_fillWith.end());
//    _my_vector->insert(_my_vector->end(), my_fillWith.begin(), my_fillWith.end());
//    check_array_data_equal();
}

TEST_F(VectorModifiers, eraseSingle) {
    ft::vector<std::string>             my_vec(_test_size);
    std::vector<std::string>            their_vec(_test_size);
    ft::vector<std::string>::iterator   my_it;
    std::vector<std::string>::iterator  their_it;
    std::string                         s;

    for (int i = 0; i < _test_size; i++)
    {
        their_vec[i] = std::to_string(i);
        my_vec[i] = std::to_string(i);
    }
    my_it = my_vec.erase(my_vec.begin());
    their_it = their_vec.erase(their_vec.begin());
    EXPECT_EQ(*my_it, *their_it);
    EXPECT_EQ(their_vec.size(), my_vec.size());
    EXPECT_EQ(their_vec.capacity(), my_vec.capacity());
    EXPECT_EQ(their_vec.get_allocator(), my_vec.get_allocator());
    my_it = my_vec.erase(my_vec.begin() + (_test_size * 0.5));
    their_it = their_vec.erase(their_vec.begin() + (_test_size * 0.5));
    EXPECT_EQ(*my_it, *their_it);
    EXPECT_EQ(their_vec.size(), my_vec.size());
    EXPECT_EQ(their_vec.capacity(), my_vec.capacity());
    EXPECT_EQ(their_vec.get_allocator(), my_vec.get_allocator());
    my_it = my_vec.erase(my_vec.end() - 1);
    their_it = their_vec.erase(their_vec.end() - 1);
    EXPECT_TRUE(my_it == my_vec.end());
    EXPECT_TRUE(their_it == their_vec.end());
    EXPECT_EQ(their_vec.size(), my_vec.size());
    EXPECT_EQ(their_vec.capacity(), my_vec.capacity());
    EXPECT_EQ(their_vec.get_allocator(), my_vec.get_allocator());
}

TEST_F(VectorModifiers, eraseRange) {
    ft::vector<std::string>             my_vec(_test_size);
    std::vector<std::string>            their_vec(_test_size);
    ft::vector<std::string>::iterator   my_it;
    std::vector<std::string>::iterator  their_it;

    for (int i = 0; i < _test_size; i++)
    {
        their_vec[i] = std::to_string(i);
        my_vec[i] = std::to_string(i);
    }
    my_it = my_vec.erase(my_vec.begin(), my_vec.begin() + (_test_size * 0.25));
    their_it = their_vec.erase(their_vec.begin(), their_vec.begin() + (_test_size * 0.25));
    EXPECT_EQ(*my_it, *their_it);
    EXPECT_EQ(their_vec.size(), my_vec.size());
    EXPECT_EQ(their_vec.capacity(), my_vec.capacity());
    EXPECT_EQ(their_vec.get_allocator(), my_vec.get_allocator());
    my_it = my_vec.erase(my_vec.begin() + (_test_size * 0.25), my_vec.begin() + (_test_size * 0.5));
    their_it = their_vec.erase(their_vec.begin() + (_test_size * 0.25), their_vec.begin() + (_test_size * 0.5));
    EXPECT_EQ(*my_it, *their_it);
    EXPECT_EQ(their_vec.size(), my_vec.size());
    EXPECT_EQ(their_vec.capacity(), my_vec.capacity());
    EXPECT_EQ(their_vec.get_allocator(), my_vec.get_allocator());
    my_it = my_vec.erase(my_vec.begin(), my_vec.begin() + (_test_size * 0.5));
    their_it = their_vec.erase(their_vec.begin(), their_vec.begin() + (_test_size * 0.5));
    EXPECT_EQ(*my_it, *their_it);
    EXPECT_EQ(their_vec.size(), my_vec.size());
    EXPECT_EQ(their_vec.capacity(), my_vec.capacity());
    EXPECT_EQ(their_vec.get_allocator(), my_vec.get_allocator());
}

TEST_F(VectorModifiers, swap) {
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	std::vector<int>	their_vec;
	ft::vector<int>		my_vec;

	their_vec.reserve(_test_val * 0.5);
	my_vec.reserve(_test_val * 0.5);
	std::iota(their_vec.begin(), their_vec.end(), 0);
	std::iota(my_vec.begin(), my_vec.end(), 0);
	_their_vector->swap(their_vec);
	_my_vector->swap(my_vec);
	for (auto it = their_vec.begin(); it != their_vec.begin(); ++it)
		EXPECT_EQ(their_vec.at(it - their_vec.begin()), my_vec.at(it - their_vec.begin()));
	check_array_data_equal();
}

TEST_F(VectorModifiers, clear) {
	_their_vector	= new std::vector<int>();
	_my_vector		= new ft::vector<int>();
	_their_vector->clear();
	_my_vector->clear();
	check_array_data_equal();
	delete _their_vector;
	delete _my_vector;
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	_their_vector->clear();
	_my_vector->clear();
	check_array_data_equal();
}

/*
** ( RELATIONAL OPERATORS )
*/
class RelationalOperator : public VectorConstruction
{

};

TEST_F(RelationalOperator, Equal) {
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	std::vector<int>	their_vec(_test_size, _test_val);
	ft::vector<int>		my_vec(_test_size, _test_val);
	EXPECT_EQ(*_their_vector == their_vec, *_my_vector == my_vec);
	their_vec[0] = 50;
	my_vec[0] = 50;
	EXPECT_EQ(*_their_vector == their_vec, *_my_vector == my_vec);
	their_vec[0] = _test_val;
	my_vec[0] = _test_val;
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector == their_vec, *_my_vector == my_vec);
	their_vec.push_back(10);
	their_vec.push_back(_test_val);
	my_vec.push_back(10);
	my_vec.push_back(_test_val);
	EXPECT_EQ(*_their_vector == their_vec, *_my_vector == my_vec);
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector == their_vec, *_my_vector == my_vec);
}

TEST_F(RelationalOperator, NotEqual) {
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	std::vector<int>	their_vec(_test_size, _test_val);
	ft::vector<int>		my_vec(_test_size, _test_val);
	EXPECT_EQ(*_their_vector != their_vec, *_my_vector != my_vec);
	their_vec[0] = 50;
	my_vec[0] = 50;
	EXPECT_EQ(*_their_vector != their_vec, *_my_vector != my_vec);
	their_vec[0] = _test_val;
	my_vec[0] = _test_val;
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector != their_vec, *_my_vector != my_vec);
	their_vec.push_back(10);
	their_vec.push_back(_test_val);
	my_vec.push_back(10);
	my_vec.push_back(_test_val);
	EXPECT_EQ(*_their_vector != their_vec, *_my_vector != my_vec);
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector != their_vec, *_my_vector != my_vec);
}

TEST_F(RelationalOperator, SmallerThen) {
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	std::vector<int>	their_vec(_test_size, _test_val);
	ft::vector<int>		my_vec(_test_size, _test_val);
	EXPECT_EQ(*_their_vector < their_vec, *_my_vector < my_vec);
	their_vec[0] = 50;
	my_vec[0] = 50;
	EXPECT_EQ(*_their_vector < their_vec, *_my_vector < my_vec);
	their_vec[0] = _test_val;
	my_vec[0] = _test_val;
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector < their_vec, *_my_vector < my_vec);
	their_vec.push_back(10);
	their_vec.push_back(_test_val);
	my_vec.push_back(10);
	my_vec.push_back(_test_val);
	EXPECT_EQ(*_their_vector < their_vec, *_my_vector < my_vec);
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector < their_vec, *_my_vector < my_vec);
}

TEST_F(RelationalOperator, SmallerOrEqualTo) {
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	std::vector<int>	their_vec(_test_size, _test_val);
	ft::vector<int>		my_vec(_test_size, _test_val);
	EXPECT_EQ(*_their_vector <= their_vec, *_my_vector <= my_vec);
	their_vec[0] = 50;
	my_vec[0] = 50;
	EXPECT_EQ(*_their_vector <= their_vec, *_my_vector <= my_vec);
	their_vec[0] = _test_val;
	my_vec[0] = _test_val;
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector <= their_vec, *_my_vector <= my_vec);
	their_vec.push_back(10);
	their_vec.push_back(_test_val);
	my_vec.push_back(10);
	my_vec.push_back(_test_val);
	EXPECT_EQ(*_their_vector <= their_vec, *_my_vector <= my_vec);
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector <= their_vec, *_my_vector <= my_vec);
}

TEST_F(RelationalOperator, BiggerThen) {
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	std::vector<int>	their_vec(_test_size, _test_val);
	ft::vector<int>		my_vec(_test_size, _test_val);
	EXPECT_EQ(*_their_vector > their_vec, *_my_vector > my_vec);
	their_vec[0] = 50;
	my_vec[0] = 50;
	EXPECT_EQ(*_their_vector > their_vec, *_my_vector > my_vec);
	their_vec[0] = _test_val;
	my_vec[0] = _test_val;
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector > their_vec, *_my_vector > my_vec);
	their_vec.push_back(10);
	their_vec.push_back(_test_val);
	my_vec.push_back(10);
	my_vec.push_back(_test_val);
	EXPECT_EQ(*_their_vector > their_vec, *_my_vector > my_vec);
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector > their_vec, *_my_vector > my_vec);
}

TEST_F(RelationalOperator, BiggerOrEqualTo) {
	_their_vector	= new std::vector<int>(_test_size, _test_val);
	_my_vector		= new ft::vector<int>(_test_size, _test_val);
	std::vector<int>	their_vec(_test_size, _test_val);
	ft::vector<int>		my_vec(_test_size, _test_val);
	EXPECT_EQ(*_their_vector >= their_vec, *_my_vector >= my_vec);
	their_vec[0] = 50;
	my_vec[0] = 50;
	EXPECT_EQ(*_their_vector >= their_vec, *_my_vector >= my_vec);
	their_vec[0] = _test_val;
	my_vec[0] = _test_val;
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector >= their_vec, *_my_vector >= my_vec);
	their_vec.push_back(10);
	their_vec.push_back(_test_val);
	my_vec.push_back(10);
	my_vec.push_back(_test_val);
	EXPECT_EQ(*_their_vector >= their_vec, *_my_vector >= my_vec);
	their_vec.pop_back();
	my_vec.pop_back();
	EXPECT_EQ(*_their_vector >= their_vec, *_my_vector >= my_vec);
}
