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

