#ifndef _POINTS_HPP
#define _POINTS_HPP

#include <string.h>
#include "dice.hpp"

struct SPoints
{
    u8 ones, twos, threes, fours, fives, sixes;
    u8 bonus;
    u8 pair, twoPairs;
    u8 threeSame, fourSame;
    u8 smallStraight, bigStraight;
    u8 fullHouse;
    u8 random;
    u8 yatzy;
    u8 total;
};

enum EPointsCategory
{
    EOnes, ETwos, EThrees, EFours, EFives, ESixes,
    EPair, ETwoPairs, EThreeSame, EFourSame,
    ESmallStraight, EBigStraight, EFullHouse,
    ERandom, EYatzy
};

class Points: public Dice
{
public:
    Points()
    {
        init();
    }

    SPoints getPoints();
    void setPoints(EPointsCategory category);

private:
    u8 getSumOfNumbers();
    u8 getSumOfSameOnes(u8 target);
    SPoints pointsTable;
    void init()
    {
        memset(&pointsTable, 0, sizeof(SPoints));
    }
};

#endif

