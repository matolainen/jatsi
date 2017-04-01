#include <limits.h>
#include <gtest/gtest.h>
#include "../src/player.hpp"


class TestPlayer : public::testing::Test
{
    protected:
    virtual void SetUp() {}
	virtual void TearDown()
    {
        player.init();
    }
	Player player;
};

TEST_F(TestPlayer, giveManyCasts_totalPointsAreUpdated)
{
    u8 cast1[5] = {5, 5, 1, 3, 6};
    u8 cast2[5] = {2, 2, 4, 5, 4};
    u8 cast3[5] = {1, 2, 3, 4, 5};
    u8 cast4[5] = {2, 4, 4, 2, 4};
    
    player.storeCast(cast1);
    player.setPoints(EFives);
    EXPECT_EQ(10, player.getPoints()->total);
    EXPECT_EQ(10, player.getPoints()->fives);
    EXPECT_EQ(0,  player.getPoints()->twos);
    EXPECT_EQ(0, player.getPoints()->ones);
    
    player.storeCast(cast2);
    player.setPoints(ETwoPairs);
    EXPECT_EQ(22, player.getPoints()->total);
    EXPECT_EQ(10, player.getPoints()->fives);
    
    player.storeCast(cast3);
    player.setPoints(ESmallStraight);
    EXPECT_EQ(37, player.getPoints()->total);
    
    player.storeCast(cast4);
    player.setPoints(EFullHouse);
    EXPECT_EQ(57, player.getPoints()->total);
}

TEST_F(TestPlayer, giveName_nameIsUpdated)
{ 
    EXPECT_EQ(DEFAULT_NAME, player.getName());
    player.setName("SuperMies");
    EXPECT_EQ("SuperMies", player.getName());
}

TEST_F(TestPlayer, giveTooLongName_nameIsNotUpdated)
{ 
    EXPECT_EQ(DEFAULT_NAME, player.getName());
    player.setName("SuperMiesNainenTransIhminen");
    EXPECT_EQ(DEFAULT_NAME, player.getName());
}

