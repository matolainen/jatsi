#include "dice.hpp"
#include <random>


const u8 Dice::getNumOfSames(const u8 target)
{
    if(target > 0)
    {
        return numOfNumbers[target - 1];
    }
    return INVALID_VALUE;
}

const bool Dice::isValid(const u8* dice)
{
    for(u8 i = 0; i < NUM_OF_DICE; i++)
    {
        if(dice[i] < 1 || dice[i] > 6)
        {
            return false;
        }
    }

    return true;
}

void Dice::storeThrow(const u8* dice)
{
    init();

    for(u8 i = 0; i < NUM_OF_DICE; i++)
    {
        if(dice[i] >= 1 && dice[i] <= 6)
        {
            numOfNumbers[(dice[i] - 1)]++;
        }
    }
}

const u8 Dice::isPairOrSame(const u8 threshold)
{
    u8 sum = 0;

    for(u8 i = 0; i < NUM_OF_NUMBERS; i++)
    {
        if(numOfNumbers[i] >= threshold)
        {
            sum = ((i + 1) * threshold);
        }
    }

    return sum;
}

const u8 Dice::isPair()
{
    return isPairOrSame(2);
} 

const u8 Dice::isTwoPairs()
{
    u8 numOfPairs = 0;
    u8 sum = 0;

    for(u8 i = 0; i < NUM_OF_NUMBERS; i++)
    {
        if(numOfNumbers[i] > 1)
        {
            sum += ((i + 1) * 2);
            numOfPairs++;
        } 
    }

    return (numOfPairs == 2 ? sum : 0);
}

const u8 Dice::isThreeSame()
{
    return isPairOrSame(3);
}

const u8 Dice::isFourSame()
{
    return isPairOrSame(4);
}

const u8 Dice::isYatzy()
{
    return (isPairOrSame(5) ? 50 : 0);
}

const u8 Dice::isFullHouse()
{
    u8 threeSame = isThreeSame();
    u8 pair = isPair();

    if((threeSame > 0) && (pair > 0))
    {
        return (threeSame + pair); 
    }

    return 0;
}

const u8 Dice::isSmallStraight()
{
    if((isPair() == 0) && (getBiggest() == 5))
    {
        return 15;
    }

    return 0;
}

const u8 Dice::getBiggest()
{
    for(u8 i = 5; i > 0; i--)
    {
        if(numOfNumbers[i] > 0)
        {
            return (i + 1);
        }
    }

    return INVALID_VALUE;
}

const u8 Dice::isBigStraight()
{
    if((isPair() == 0) && (getBiggest() == 6))
    {
        return 20;
    }

    return 0;
}

const u8 Dice::getSumOfSames(u8 target)
{
    return (target * getNumOfSames(target)); 
}

void Dice::rollDie(const u8 numOfDice, u8* dice)
{
    for(u8 i = 0; i < numOfDice; i++)
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<u8> distribution(1,6);
        dice[i] = distribution(generator); 
    }
}

