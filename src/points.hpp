#ifndef _POINTS_HPP
#define _POINTS_HPP

#include <string.h>
#include "dice.hpp"

#define BONUS_THRESHOLD 63

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
    u32 total;
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

    void init()
    {
        bonusTrigger = 0;
        memset(&pointsTable, 0, sizeof(SPoints));
    }
    const SPoints* getPoints();
    const bool setPoints(const EPointsCategory category);

private:
    const u8 getSumOfNumbers();
    SPoints pointsTable;
    u8 bonusTrigger;  
};

#endif

