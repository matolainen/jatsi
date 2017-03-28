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



