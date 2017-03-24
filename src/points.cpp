#include "points.hpp"

u8 Points::countMaxNumOfSameOnes(const u8* dice)
{
    u8 numOfSameOnes = 0;
    for(u8 i; i < NUM_OF_DICE; i++)
    {
	for(u8 j; j < NUM_OF_DICE; j++)
	{
	    if((dice[i] < 7) & (dice[j] < 7))
	    {
		if(dice[i] == dice[j])
		{
	            numOfSameOnes++;
		}
	    }
	    else
	    {
		return 0xFF;
	    }
	}
    }
    return numOfSameOnes;
}

u8 Points::countPairs(const u8* dice)
{
    u8 numOfPairs = 1;

    return numOfPairs;
}
