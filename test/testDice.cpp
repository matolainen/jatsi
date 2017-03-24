#include <limits.h>
#include <gtest/gtest.h>
#include "../src/dice.hpp"

class TestDice : public::testing::Test
{
    protected:
    virtual void SetUp() {}
	virtual void TearDown() {}
	Dice dice;
};

TEST_F(TestDice, giveTwoOnes_getTwoOnes)
{
    u8 threw[5] = {1, 1, 3, 4, 5};
    EXPECT_EQ(2, dice.getNumOfSames(threw, 1));
}
    
TEST_F(TestDice, giveZeroOne_getZeroOne)
{
    u8 threw[5] = {5, 2, 3, 4, 5};
    EXPECT_EQ(0, dice.getNumOfSames(threw, 1));
}

TEST_F(TestDice, giveUnderValues_validationFailed)
{
    u8 threw[5] = {0, 0, 0, 0, 0};
    EXPECT_FALSE(dice.isValid(threw));
}

TEST_F(TestDice, giveTooBigValues_validationFail)
{
    u8 threw[5] = {7, 7, 7, 7, 7};
    EXPECT_FALSE(dice.isValid(threw));
}

TEST_F(TestDice, giveLegalThrew_validationSuccess)
{
    u8 threw[5] = {1, 2, 3, 4, 5};
    EXPECT_TRUE(dice.isValid(threw));
}

TEST_F(TestDice, giveOnePair_returnTrue)
{
    u8 threw[5] = {1, 2, 3, 4, 1};
    EXPECT_TRUE(dice.isPair(threw));
}

TEST_F(TestDice, giveZeroPairs_returnFalse)
{
    u8 threw[5] = {1, 2, 3, 4, 5};
    EXPECT_TRUE(dice.isPair(threw));
}

TEST_F(TestDice, giveTwoPairs_returnTrue)
{
    u8 threw[5] = {1, 2, 2, 5, 5};
    EXPECT_TRUE(dice.isPair(threw));
}

TEST_F(TestDice, giveTwoPairs_returnTrueAgain)
{
    u8 threw[5] = {1, 2, 2, 5, 5};
    EXPECT_TRUE(dice.isTwoPairs(threw));
}

TEST_F(TestDice, giveThreeSames_returnTrue)
{
    u8 threw[5] = {1, 2, 2, 2, 5};
    EXPECT_TRUE(dice.isTwoPairs(threw));
}

