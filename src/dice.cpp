#include "dice.hpp"

u8 Dice::getNumOfSames(const u8* dice, u8 target)
{
    u8 numOfTarget = 0;
    
    for(u8 i = 0; i < NUM_OF_DICE; i++)
    {
       if(target == dice[i])
       {
          numOfTarget++;
       }
    }

    return numOfTarget;
}

bool Dice::isValid(const u8* dice)
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

bool Dice::isPair(const u8* dice)
{
    for(u8 i = 0; i < NUM_OF_DICE; i++)
    {
        for(u8 j = 0; j < NUM_OF_DICE; j++)
        {
            if((dice[i] == dice[j]) && (i != j))
            {
                return true;
            }
        }
    }

    return false;
}

bool Dice::isTwoPairs(const u8* dice)
{
    u8 numOfPairs = 0;
    
    for(u8 i = 0; i < NUM_OF_DICE; i++)
    {
        for(u8 j = i + 1; j < NUM_OF_DICE; j++)
        {
            if((dice[i] == dice[j]) && (i != j))
            {
                numOfPairs++;
            }
        }
    }

    return (numOfPairs == 2);
}

