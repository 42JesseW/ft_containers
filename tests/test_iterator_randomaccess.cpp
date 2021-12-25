#include <vector.hpp>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>

class RandomAccessFixture : public testing::Test
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

    virtual ~RandomAccessFixture() {
        delete	_their_vector;
        delete	_my_vector;
    }
};

TEST_F(RandomAccessFixture, Forward) {
    _their_vector				= new std::vector<int>(_test_size, _test_val);
    _my_vector					= new ft::vector<int>(_test_size, _test_val);
    std::vector<int>::iterator	std_begin;
    std::vector<int>::iterator	std_end;
    ft::vector<int>::iterator	ft_begin;
    ft::vector<int>::iterator	ft_end;

    EXPECT_EQ(*(std_begin = _their_vector->begin()), *(ft_begin = _my_vector->begin()));
    EXPECT_EQ(*(std_end = _their_vector->end() - 1), *(ft_end = _my_vector->end() - 1));
    (void)std_begin;
    (void)std_end;

    auto ft_iter = _my_vector->begin();
    auto std_iter = _their_vector->begin();
    for (; ft_iter != _my_vector->end() && std_iter != _their_vector->end(); ++ft_iter, ++std_iter)
        EXPECT_EQ(*ft_iter, *std_iter);
}

TEST_F(RandomAccessFixture, ForwardConst) {
    auto _c_their_vector				= new const std::vector<int>(_test_size, _test_val);
    auto _c_my_vector					= new const ft::vector<int>(_test_size, _test_val);
    std::vector<int>::const_iterator 	std_begin;
    std::vector<int>::const_iterator	std_end;
    ft::vector<int>::const_iterator		ft_begin;
    ft::vector<int>::const_iterator		ft_end;

    EXPECT_EQ(*(std_begin = _c_their_vector->begin()), *(ft_begin = _c_my_vector->begin()));
    EXPECT_EQ(*(std_end = _c_their_vector->end() - 1), *(ft_end = _c_my_vector->end() - 1));
    (void)std_begin;
    (void)std_end;

    auto ft_iter = _c_my_vector->begin();
    auto std_iter = _c_their_vector->begin();
    for (; ft_iter != _c_my_vector->end() && std_iter != _c_their_vector->end(); ++ft_iter, ++std_iter)
        EXPECT_EQ(*ft_iter, *std_iter);
    delete _c_their_vector;
    delete _c_my_vector;
}

TEST_F(RandomAccessFixture, Reverse) {
    _their_vector       = new std::vector<int>(_test_size);
    _my_vector          = new ft::vector<int>(_test_size);

    std::iota(_their_vector->begin(), _their_vector->end(), 0);
    std::iota(_my_vector->begin(), _my_vector->end(), 0);
    typedef std::vector<int>::iterator  their_iter_type;
    typedef ft::vector<int>::iterator   my_iter_type;

    their_iter_type their_begin(_their_vector->begin());
    their_iter_type their_end(_their_vector->end());
    my_iter_type    my_begin(_my_vector->begin());
    my_iter_type    my_end(_my_vector->end());

    std::reverse_iterator<their_iter_type>  their_rev_begin(their_end);
    std::reverse_iterator<their_iter_type>  their_rev_end(their_begin);
    ft::reverse_iterator<my_iter_type>      my_rev_begin(my_end);
    ft::reverse_iterator<my_iter_type>      my_rev_end(my_begin);

    while (my_rev_begin != my_rev_end)
    {
        EXPECT_EQ(*my_rev_begin, *their_rev_begin);
        ++my_rev_begin;
        ++their_rev_begin;
    }
}

TEST_F(RandomAccessFixture, ConstReverse) {
    _their_vector       = new std::vector<int>(_test_size);
    _my_vector          = new ft::vector<int>(_test_size);

    std::iota(_their_vector->begin(), _their_vector->end(), 0);
    std::iota(_my_vector->begin(), _my_vector->end(), 0);

    auto _c_their_vector    = new const std::vector<int>(_their_vector->begin(), _their_vector->end());
    auto _c_my_vector       = new const ft::vector<int>(_my_vector->begin(), _my_vector->end());

    typedef std::vector<int>::const_iterator            their_iter_type;
    typedef ft::vector<int>::const_iterator             my_iter_type;
    typedef ft::vector<int>::const_reverse_iterator     my_rev_it_t;

    their_iter_type their_end(_c_their_vector->end());
    my_iter_type    my_begin(_c_my_vector->begin());
    my_iter_type    my_end(_c_my_vector->end());

    std::reverse_iterator<their_iter_type>  their_rev_begin(their_end);
    my_rev_it_t     my_rev_begin(my_end);
    my_rev_it_t     my_rev_end(my_begin);

    while (my_rev_begin != my_rev_end)
    {
        EXPECT_EQ(*my_rev_begin, *their_rev_begin);
        ++my_rev_begin;
        ++their_rev_begin;
    }
    delete _c_their_vector;
    delete _c_my_vector;
}

TEST_F(RandomAccessFixture, Operators) {
    ft::vector<std::string>             my_vec(10);
    std::vector<std::string>            their_vec(10);
    ft::vector<std::string>::iterator   my_it;
    std::vector<std::string>::iterator  their_it;


    for (int i = 0; i < 10; ++i) {
        my_vec[i] = std::to_string(i);
        their_vec[i] = std::to_string(i);
    }
    /* operator = */
    my_it = my_vec.begin();
    their_it = their_vec.begin();
    /* operator == */
    EXPECT_TRUE(my_it == my_vec.begin());
    /* operator != */
    EXPECT_TRUE(my_it != my_vec.end());
    EXPECT_TRUE(!(my_it != my_vec.begin()));
    /* operator * */
    EXPECT_EQ(*my_it, *their_it);
    /* operator -> */
    EXPECT_EQ(my_it->size(), their_it->size());
    /* operator ++ postfix */
    EXPECT_EQ(*(my_it++), *(their_it++));
    /* operator ++ prefix */
    EXPECT_EQ(*(++my_it), *(++their_it));
    /* operator -- postfix */
    EXPECT_EQ(*((my_it + 1)--), *((their_it + 1)--));
    /* operator -- prefix */
    EXPECT_EQ(*(--(my_it + 1)), *(--(their_it + 1)));
    /* operator + */
    EXPECT_EQ(*(my_it + 5), *(their_it + 5));
    EXPECT_EQ(*(5 + my_it), *(5 + their_it));
    /* operator - */
    EXPECT_EQ(*((my_it + 10) - 5), *((their_it + 10) - 5));
    EXPECT_EQ((my_vec.end() - my_vec.begin()), (their_vec.end() - their_vec.begin()));
    /* operator < */
    EXPECT_EQ(my_it->begin() < my_it->end(), their_it->begin() < their_it->end());
    EXPECT_EQ(my_it->end() < my_it->begin(), their_it->end() < their_it->begin());
    /* operator > */
    EXPECT_EQ(my_it->begin() > my_it->end(), their_it->begin() > their_it->end());
    EXPECT_EQ(my_it->end() > my_it->begin(), their_it->end() > their_it->begin());
    /* operator <= */
    EXPECT_EQ(my_it->begin() <= my_it->end(), their_it->begin() <= their_it->end());
    EXPECT_EQ(my_it->end() <= my_it->begin(), their_it->end() <= their_it->begin());
    /* operator >= */
    EXPECT_EQ(my_it->begin() >= my_it->end(), their_it->begin() >= their_it->end());
    EXPECT_EQ(my_it->end() >= my_it->begin(), their_it->end() >= their_it->begin());
    /* operator += */
    my_it += 2;
    their_it += 2;
    EXPECT_EQ(*my_it, *their_it);
    /* operator -= */
    my_it -= 2;
    their_it -= 2;
    EXPECT_EQ(*my_it, *their_it);
}
