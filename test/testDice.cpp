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
    u8 cast[5] = {1, 2, 3, 4, 1};
    dice.storeThrow(cast);
    EXPECT_TRUE(dice.isPair());
    EXPECT_FALSE(dice.isTwoPairs());
    EXPECT_FALSE(dice.isThreeSame());
    EXPECT_FALSE(dice.isFourSame());
    EXPECT_FALSE(dice.isYatzy());
}

TEST_F(TestDice, giveZeroPairs_returnFalse)
{
    u8 cast[5] = {1, 2, 3, 4, 5};
    dice.storeThrow(cast);
    EXPECT_FALSE(dice.isPair());
}

TEST_F(TestDice, giveTwoPairs_returnTrue)
{
    u8 cast[5] = {1, 2, 2, 5, 5};
    dice.storeThrow(cast);
    EXPECT_TRUE(dice.isPair());
}

TEST_F(TestDice, giveTwoPairs_returnTrueAgain)
{
    u8 cast[5] = {1, 2, 1, 6, 6};
    dice.storeThrow(cast);
    EXPECT_TRUE(dice.isTwoPairs());
}

TEST_F(TestDice, giveThreeSames_returnTrue)
{
    u8 cast[5] = {1, 2, 2, 2, 5};
    dice.storeThrow(cast);
    EXPECT_TRUE(dice.isThreeSame());
}

TEST_F(TestDice, giveFourSames_returnTrue)
{
    u8 cast[5] = {1, 6, 6, 6, 6};
    dice.storeThrow(cast);
    EXPECT_TRUE(dice.isFourSame());
}

TEST_F(TestDice, giveYatzy_returnTrue)
{
    u8 cast[5] = {1, 1, 1, 1, 1};
    dice.storeThrow(cast);
    EXPECT_TRUE(dice.isYatzy());
}

TEST_F(TestDice, giveFullHouse_returnTrue)
{
    u8 cast[5] = {6, 1, 1, 6, 1};
    dice.storeThrow(cast);
    EXPECT_TRUE(dice.isTwoPairs());
    EXPECT_TRUE(dice.isPair());
    EXPECT_TRUE(dice.isThreeSame());
    EXPECT_TRUE(dice.isFullHouse());
    EXPECT_FALSE(dice.isFourSame());
    EXPECT_FALSE(dice.isYatzy());
}

TEST_F(TestDice, giveSmallStraight_returnTrue)
{
    u8 cast[5] = {5, 3, 1, 2, 4};
    dice.storeThrow(cast);
    EXPECT_FALSE(dice.isTwoPairs());
    EXPECT_FALSE(dice.isPair());
    EXPECT_TRUE(dice.isSmallStraight());
}
