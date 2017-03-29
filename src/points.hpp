#ifndef _POINTS_HPP
#define _POINTS_HPP

#include <string.h>
#include "dice.hpp"

struct SPointsArray
{
    u8 ones, twos, threes, fours, fives, sixes;
    u8 pair, twoPairs;
    u8 threeSame, fourSame;
    u8 smallStraight, bigStraight;
    u8 fullHouse;
    u8 random;
    u8 yatzy;
};


class Points: public Dice
{
public:
    Points()
    {
    }

    u8 getSumOfNumbers();
    u8 getSumOfSameOnes(u8 target);
    SPointsArray getPoints();

private:
    
    SPointsArray pointsTable;

};

#endif

