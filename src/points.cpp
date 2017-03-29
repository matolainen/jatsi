#include "points.hpp"
#include "dice.hpp"

u8 Points::getSumOfNumbers()
{
    u8 sumOfNumbers = 0;

    for(u8 i = 0; i < NUM_OF_NUMBERS; i++)
    {
        sumOfNumbers += (numOfNumbers[i] * (i + 1));
    }

    return sumOfNumbers;
}

u8 Points::getSumOfSameOnes(u8 target)
{
    u8 sumOfSameOnes = 0;
    sumOfSameOnes = (target * getNumOfSames(target)); 

    return sumOfSameOnes;
}

SPointsArray Points::getPoints()
{
    pointsTable.ones          = getSumOfSames(1);
    pointsTable.twos          = getSumOfSames(2);
    pointsTable.threes        = getSumOfSames(3);
    pointsTable.fours         = getSumOfSames(4);
    pointsTable.fives         = getSumOfSames(5);
    pointsTable.sixes         = getSumOfSames(6);
    pointsTable.pair          = isPair();
    pointsTable.twoPairs      = isTwoPairs();
    pointsTable.threeSame     = isThreeSame();
    pointsTable.fourSame      = isFourSame();
    pointsTable.smallStraight = isSmallStraight();
    pointsTable.bigStraight   = isBigStraight();
    pointsTable.fullHouse     = isFullHouse();
    pointsTable.random        = getSumOfNumbers();
    pointsTable.yatzy         = isYatzy();

    return pointsTable;
}

