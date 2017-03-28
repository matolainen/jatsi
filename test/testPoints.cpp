#include <limits.h>
#include <gtest/gtest.h>
#include "../src/points.hpp"

class TestPoints : public::testing::Test
{
    protected:
    virtual void SetUp() {}
	virtual void TearDown() {}
	Points points;
};

TEST_F(TestPoints, giveRandomCast_getCorrectPoints)
{
    u8 cast[5] = {1, 1, 3, 4, 5};
    points.storeThrow(cast);
    EXPECT_EQ(14, points.getSumOfNumbers());
}
