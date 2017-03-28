#include "dice.hpp"

u8 Dice::getNumOfSames(u8 target)
{
    return numOfNumbers[target - 1];
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

void Dice::storeThrow(const u8* dice)
{
    init();
    for(u8 i = 0; i < NUM_OF_DICE; i++)
    {
        switch(dice[i])
        {
            case 1:
                numOfNumbers[0]++;
                break;
            case 2:
                numOfNumbers[1]++;
                break;
            case 3:
                numOfNumbers[2]++;
                break;
            case 4:
                numOfNumbers[3]++;
                break;
            case 5:
                numOfNumbers[4]++;
                break;
            case 6:
                numOfNumbers[5]++;
                break;
        }
    }
}

bool Dice::isPairOrSame(u8 threshold)
{
    for(u8 i = 0; i < NUM_OF_NUMBERS; i++)
    {
        if(numOfNumbers[i] >= threshold)
        {
            return true;
        }
    }

    return false;
}

bool Dice::isPair()
{
   if(isPairOrSame(2))
   {
      return true; 
   }
   
   return false;
} 

bool Dice::isTwoPairs()
{
    u8 numOfPairs = 0;

    for(u8 i = 0; i < NUM_OF_NUMBERS; i++)
    {
       if(numOfNumbers[i] > 1)
       {
          numOfPairs++;
       } 
    }

    return (numOfPairs == 2);
}

bool Dice::isThreeSame()
{
   if(isPairOrSame(3))
   {
      return true; 
   }
   
   return false;

}

bool Dice::isFourSame()
{
   if(isPairOrSame(4))
   {
      return true; 
   }
   
   return false;

}

bool Dice::isYatzy()
{
   if(isPairOrSame(5))
   {
      return true; 
   }
   
   return false;

}

bool Dice::isFullHouse()
{
    if(isThreeSame() && isPair())
    {
        return true;
    }

    return false;
}

bool Dice::isSmallStraight()
{
    if(!isPair() && getBiggest() == 5)
    {
        return true;
    }

    return false;
}

u8 Dice::getBiggest()
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

bool Dice::isBigStraight()
{
    if(!isPair() && getBiggest() == 6)
    {
        return true;
    }

    return false;
}

