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

TEST_F(TestPoints, giveThreeSame_getCorrectPoints)
{
    u8 cast[5] = {1, 1, 6, 6, 1};
    points.storeThrow(cast);
    EXPECT_EQ(3, points.getSumOfSameOnes(1));
    EXPECT_EQ(0, points.getSumOfSameOnes(2));
    EXPECT_EQ(12, points.getSumOfSameOnes(6));
}

TEST_F(TestPoints, giveCast_getCorrectPointsArray)
{
    u8 cast[5] = {5, 5, 1, 3, 6};
    points.storeThrow(cast);
    EXPECT_EQ(1, points.getPoints().ones);
}
