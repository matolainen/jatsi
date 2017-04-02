#include "points.hpp"
#include "dice.hpp"

const u8 Points::getSumOfNumbers()
{
    u8 sumOfNumbers = 0;

    for(u8 i = 0; i < NUM_OF_NUMBERS; i++)
    {
        sumOfNumbers += (numOfNumbers[i] * (i + 1));
    }

    return sumOfNumbers;
}

const bool Points::setPoints(const EPointsCategory category)
{ 
    bool pointsSet = false;

    switch(category)
    {
        case EOnes:
            if(pointsTable.ones == 0)
            {
                pointsTable.ones = getSumOfSames(1);
                pointsTable.total += pointsTable.ones;
                bonusTrigger += pointsTable.ones;
                pointsSet = true;
            }
            break;
        case ETwos:
            if(pointsTable.twos == 0)
            {
                pointsTable.twos = getSumOfSames(2);
                pointsTable.total += pointsTable.twos;
                bonusTrigger += pointsTable.twos;
                pointsSet = true;
            }
            break;
        case EThrees:
            if(pointsTable.threes == 0)
            { 
                pointsTable.threes = getSumOfSames(3);
                pointsTable.total += pointsTable.threes;
                bonusTrigger += pointsTable.threes;
                pointsSet = true;
            }
            break;
        case EFours:
            if(pointsTable.fours == 0)
            {
                pointsTable.fours = getSumOfSames(4);
                pointsTable.total += pointsTable.fours;
                bonusTrigger += pointsTable.fours;
                pointsSet = true;
            }
            break;
        case EFives:
            if(pointsTable.fives == 0)
            {
                pointsTable.fives = getSumOfSames(5);
                pointsTable.total += pointsTable.fives;
                bonusTrigger += pointsTable.fives;
                pointsSet = true;
            }
            break;
        case ESixes:
            if(pointsTable.sixes == 0)
            {
                pointsTable.sixes = getSumOfSames(6);
                pointsTable.total += pointsTable.sixes;
                bonusTrigger += pointsTable.sixes;
                pointsSet = true;
            }
            break;
        case EPair:
            if(pointsTable.pair == 0)
            {
                pointsTable.pair = isPair();
                pointsTable.total += pointsTable.pair;
                pointsSet = true;
            }
            break;
        case ETwoPairs:
            if(pointsTable.twoPairs == 0)
            {
                pointsTable.twoPairs = isTwoPairs();
                pointsTable.total += pointsTable.twoPairs;
                pointsSet = true;
            }
            break;
        case EThreeSame:
            if(pointsTable.threeSame == 0)
            {
                pointsTable.threeSame = isThreeSame();
                pointsTable.total += pointsTable.threeSame;
                pointsSet = true;
            }
            break;
        case EFourSame:
            if(pointsTable.fourSame == 0)
            {
                pointsTable.fourSame = isFourSame();
                pointsTable.total += pointsTable.fourSame;
                pointsSet = true;
            }
            break;
        case ESmallStraight:
            if(pointsTable.smallStraight == 0)
            {
                pointsTable.smallStraight = isSmallStraight();
                pointsTable.total += pointsTable.smallStraight;
                pointsSet = true;
            }
            break;
        case EBigStraight:
            if(pointsTable.bigStraight == 0)
            {
                pointsTable.bigStraight = isBigStraight();
                pointsTable.total += pointsTable.bigStraight;
                pointsSet = true;
            }
            break;
        case EFullHouse:
            if(pointsTable.fullHouse == 0)
            {
                pointsTable.fullHouse = isFullHouse();
                pointsTable.total += pointsTable.fullHouse;
                pointsSet = true;
            }
            break;
        case ERandom:
            if(pointsTable.random == 0)
            {
                pointsTable.random = getSumOfNumbers();
                pointsTable.total += pointsTable.random;
                pointsSet = true;
            }
            break;
        case EYatzy:
            if(pointsTable.yatzy == 0)
            {
                pointsTable.yatzy = isYatzy();
                pointsTable.total += pointsTable.yatzy;
                pointsSet = true;
            }
            break;
    }

    if(bonusTrigger >= BONUS_THRESHOLD)
    {
        pointsTable.bonus = 50;
    }

    return pointsSet;
}

const SPoints* Points::getPoints()
{
    return &pointsTable;
}
