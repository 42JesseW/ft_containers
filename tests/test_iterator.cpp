#include <IteratorTraits.hpp>
#include <ReverseIterator.hpp>
#include <vector.hpp>
#include <gtest/gtest.h>


TEST(ReverseIterator, Construction) {
    ft::vector<int>                                 vec;
    ft::vector<int>::iterator                       it;
    it = vec.begin();
    ft::reverse_iterator<ft::vector<int>::iterator> rev_it1(it);
    ft::reverse_iterator<ft::vector<int>::iterator> rev_it2(it + 1);

    std::cout << (rev_it1 == rev_it2) << '\n';
}

TEST(ReverseIterator, Operators) {

}
