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

void Points::setPoints(EPointsCategory category)
{
    switch(category)
    {
        case EOnes:
            if(pointsTable.ones == 0)
            {
                pointsTable.ones = getSumOfSames(1);
                pointsTable.total += pointsTable.ones;
            }
            break;
        case ETwos:
            if(pointsTable.twos == 0)
            {
                pointsTable.twos = getSumOfSames(2);
                pointsTable.total += pointsTable.twos;
            }
            break;
        case EThrees:
            if(pointsTable.threes == 0)
            { 
                pointsTable.threes = getSumOfSames(3);
                pointsTable.total += pointsTable.threes;
            }
            break;
        case EFours:
            if(pointsTable.fours == 0)
            {
                pointsTable.fours = getSumOfSames(4);
                pointsTable.total += pointsTable.fours;
            }
            break;
        case EFives:
            if(pointsTable.fives == 0)
            {
                pointsTable.fives = getSumOfSames(5);
                pointsTable.total += pointsTable.fives;
            }
            break;
        case ESixes:
            if(pointsTable.sixes == 0)
            {
                pointsTable.sixes = getSumOfSames(6);
                pointsTable.total += pointsTable.sixes;
            }
            break;
        case EPair:
            if(pointsTable.pair == 0)
            {
                pointsTable.pair = isPair();
                pointsTable.total += pointsTable.pair;
            }
            break;
        case ETwoPairs:
            if(pointsTable.twoPairs == 0)
            {
                pointsTable.twoPairs = isTwoPairs();
                pointsTable.total += pointsTable.twoPairs;
            }
            break;
        case EThreeSame:
            if(pointsTable.threeSame == 0)
            {
                pointsTable.threeSame = isThreeSame();
                pointsTable.total += pointsTable.threeSame;
            }
            break;
        case EFourSame:
            if(pointsTable.fourSame == 0)
            {
                pointsTable.fourSame = isFourSame();
                pointsTable.total += pointsTable.fourSame;
            }
            break;
        case ESmallStraight:
            if(pointsTable.smallStraight == 0)
            {
                pointsTable.smallStraight = isSmallStraight();
                pointsTable.total += pointsTable.smallStraight;
            }
            break;
        case EBigStraight:
            if(pointsTable.bigStraight == 0)
            {
                pointsTable.bigStraight = isBigStraight();
                pointsTable.total += pointsTable.bigStraight;
            }
            break;
        case EFullHouse:
            if(pointsTable.fullHouse == 0)
            {
                pointsTable.fullHouse = isFullHouse();
                pointsTable.total += pointsTable.fullHouse;
            }
            break;
        case ERandom:
            if(pointsTable.random == 0)
            {
                pointsTable.random = getSumOfNumbers();
                pointsTable.total += pointsTable.random;
            }
            break;
        case EYatzy:
            if(pointsTable.yatzy == 0)
            {
                pointsTable.yatzy = isYatzy();
                pointsTable.total += pointsTable.yatzy;
            }
            break;
    }
}

SPoints Points::getPoints()
{
    return pointsTable;
}
