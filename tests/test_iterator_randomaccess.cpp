#include <vector.hpp>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>

class RandomAccessFixture : public testing::Test {
protected:

    ft::vector<int>		ft_vec;
    std::vector<int>	std_vec;

};

TEST_F(RandomAccessFixture, Forward)
{
    ft::vector<int>::iterator	ft_iter;
    std::vector<int>::iterator	std_iter;
    size_t						test_size = 1000;
    size_t						idx;

    ft_vec.reserve(test_size);
    for (int i = 0; i < test_size; i++)
        ft_vec.push_back(i);
    std_vec.reserve(test_size);
    for (int i = 0; i < test_size; i++)
        std_vec.push_back(i);
    EXPECT_EQ(*(ft_vec.begin()), *(std_vec.begin()));
    EXPECT_EQ(*(ft_vec.end()), *(std_vec.end()));
    EXPECT_EQ(*(ft_vec.begin()), *(std_vec.begin()));
    EXPECT_EQ(*(ft_vec.end()), *(std_vec.end()));
    idx = 0;
    ft_iter = ft_vec.begin();
    std_iter = std_vec.begin();
    for (; ft_iter != ft_vec.end() && std_iter != std_vec.end(); ++ft_iter, ++std_iter)
    {
        EXPECT_EQ(*ft_iter, *std_iter);
        idx++;
    }
    EXPECT_EQ(idx, test_size);
}

TEST_F(RandomAccessFixture, ForwardConst)
{
    ft::vector<int>::const_iterator 	ft_iter;
    std::vector<int>::const_iterator	std_iter;
    size_t								test_size = 1000;
    size_t								idx;

    ft_vec.reserve(test_size);
    for (int i = 0; i < test_size; i++)
        ft_vec.push_back(i);
    std_vec.reserve(test_size);
    for (int i = 0; i < test_size; i++)
        std_vec.push_back(i);
    EXPECT_EQ(*(ft_vec.begin()), *(std_vec.begin()));
    EXPECT_EQ(*(ft_vec.end()), *(std_vec.end()));
    EXPECT_EQ(*(ft_vec.begin()), *(std_vec.begin()));
    EXPECT_EQ(*(ft_vec.end()), *(std_vec.end()));
    idx = 0;
    ft_iter = ft_vec.begin();
    std_iter = std_vec.begin();
    for (; ft_iter != ft_vec.end() && std_iter != std_vec.end(); ++ft_iter, ++std_iter)
    {
        EXPECT_EQ(*ft_iter, *std_iter);
        idx++;
    }
    EXPECT_EQ(idx, test_size);
}

TEST_F(RandomAccessFixture, Reverse)
{
    ft::vector<int>::reverse_iterator 	ft_iter;
    std::vector<int>::reverse_iterator	std_iter;
    size_t								test_size = 1000;
    size_t								idx;

    ft_vec.reserve(test_size);
    for (int i = 0; i < test_size; i++)
        ft_vec.push_back(i);
    std_vec.reserve(test_size);
    for (int i = 0; i < test_size; i++)
        std_vec.push_back(i);
    EXPECT_EQ(*(ft_vec.rbegin()), *(std_vec.rbegin()));
    EXPECT_EQ(*(ft_vec.rend()), *(std_vec.rend()));
    EXPECT_EQ(*(ft_vec.rbegin()), *(std_vec.rbegin()));
    EXPECT_EQ(*(ft_vec.rend()), *(std_vec.rend()));
    idx = 0;
    ft_iter = ft_vec.rbegin();
    std_iter = std_vec.rbegin();
    for (; ft_iter != ft_vec.rend() && std_iter != std_vec.rend(); ++ft_iter, ++std_iter)
    {
        EXPECT_EQ(*ft_iter, *std_iter);
        idx++;
    }
    EXPECT_EQ(idx, test_size);
}

TEST_F(RandomAccessFixture, ReverseConst)
{
    ft::vector<int>::const_reverse_iterator		ft_iter;
    std::vector<int>::const_reverse_iterator	std_iter;
    size_t										test_size = 1000;
    size_t										idx;

    ft_vec.reserve(test_size);
    for (int i = 0; i < test_size; i++)
        ft_vec.push_back(i);
    std_vec.reserve(test_size);
    for (int i = 0; i < test_size; i++)
        std_vec.push_back(i);
    EXPECT_EQ(*(ft_vec.rbegin()), *(std_vec.rbegin()));
    EXPECT_EQ(*(ft_vec.rend()), *(std_vec.rend()));
    EXPECT_EQ(*(ft_vec.rbegin()), *(std_vec.rbegin()));
    EXPECT_EQ(*(ft_vec.rend()), *(std_vec.rend()));
    idx = 0;
    ft_iter = ft_vec.rbegin();
    std_iter = std_vec.rbegin();
    for (; ft_iter != ft_vec.rend() && std_iter != std_vec.rend(); ++ft_iter, ++std_iter)
    {
        EXPECT_EQ(*ft_iter, *std_iter);
        idx++;
    }
    EXPECT_EQ(idx, test_size);
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
