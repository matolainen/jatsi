#include "points.hpp"
#include <stdio.h>

int main()
{
    char dice[5] = {1, 1, 2, 4, 5};
    Points points;
    char numOfSameOnes = points.countNumOfSameOnes(dice);
    printf("Number of same ones is %d\n", numOfSameOnes);
}

