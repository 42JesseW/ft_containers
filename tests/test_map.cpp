#include <map>
#include <map.hpp>
#include <gtest/gtest.h>

class MapConstruction : public testing::Test
{
public:
    int					_test_size;
    int					_test_val;

protected:
    std::map<int, int>  *_their_map;
    ft::map<int, int>   *_my_map;

    void	SetUp() override {
        _their_map	= nullptr;
        _my_map		= nullptr;
        _test_size	= 100;
        _test_val	= 20;
    }

    virtual ~MapConstruction() {
        delete	_their_map;
        delete	_my_map;
    }
};

TEST_F(MapConstruction, Default) {
    ft::map<int, int>   my_map;
    std::map<int, int>  their_map;


}
