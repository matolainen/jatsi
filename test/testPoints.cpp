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


TEST_F(TestPoints, giveCast_getCorrectPointsArray)
{
    u8 cast[5] = {5, 5, 1, 3, 6};
    points.storeThrow(cast);
    points.setPoints(EOnes);
    EXPECT_EQ(1, points.getPoints()->ones);
    EXPECT_EQ(0, points.getPoints()->twos);
}

TEST_F(TestPoints, giveManyCasts_totalPointsAreUpdated)
{
    u8 cast1[5] = {5, 5, 1, 3, 6};
    u8 cast2[5] = {2, 2, 4, 5, 4};
    u8 cast3[5] = {1, 2, 3, 4, 5};
    u8 cast4[5] = {2, 4, 4, 2, 4};
    
    points.storeThrow(cast1);
    points.setPoints(EFives);
    EXPECT_EQ(10, points.getPoints()->total);
    EXPECT_EQ(10, points.getPoints()->fives);
    EXPECT_EQ(0,  points.getPoints()->twos);
    EXPECT_EQ(0, points.getPoints()->ones);
    
    points.storeThrow(cast2);
    points.setPoints(ETwoPairs);
    EXPECT_EQ(22, points.getPoints()->total);
    EXPECT_EQ(10, points.getPoints()->fives);
    
    points.storeThrow(cast3);
    points.setPoints(ESmallStraight);
    EXPECT_EQ(37, points.getPoints()->total);
    
    points.storeThrow(cast4);
    points.setPoints(EFullHouse);
    EXPECT_EQ(57, points.getPoints()->total);
}

