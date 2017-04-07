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

void printCast(const u8* dice)
{
    printf("%u", dice[0]);

    for(u8 i = 1; i < NUM_OF_DICE; i++)
    {
        printf(", %u", dice[i]);
    }

    printf("\n");
}

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
    EXPECT_FALSE(player.setPoints(ETwoPairs));
    EXPECT_TRUE(player.setPoints(ESmallStraight));
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

TEST_F(TestPlayer, rollDice_castIsValid)
{
    Dice testDice;
    player.rollDice();
    EXPECT_TRUE(testDice.isValid(player.cast));
}

TEST_F(TestPlayer, rollDiceThreeTimes_pointsAreUpdated)
{
    Dice testDice;
    u8 chosen[5] = {0, 2, 4, INVALID_VALUE, INVALID_VALUE};
    u8 temp[5] = {0, 3, INVALID_VALUE, INVALID_VALUE, INVALID_VALUE};
    
    player.rollDice();
    player.saveDice(chosen);
    EXPECT_EQ(INVALID_VALUE, player.cast[3]);
    EXPECT_EQ(INVALID_VALUE, player.cast[4]);

    player.rollDice();
    player.saveDice(temp);
    EXPECT_EQ(INVALID_VALUE, player.cast[2]);
    EXPECT_EQ(INVALID_VALUE, player.cast[3]);
    EXPECT_EQ(INVALID_VALUE, player.cast[4]);
    
    player.rollDice();
    EXPECT_TRUE(testDice.isValid(player.cast));
}



