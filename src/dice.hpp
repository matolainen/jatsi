#ifndef _DICE_HPP
#define _DICE_HPP

#include <string.h>

#define NUM_OF_DICE 5
#define NUM_OF_NUMBERS 6

#define u8   unsigned char
#define u32  unsigned int
#define i8   signed char
#define INVALID_VALUE 0xFF


class Dice
{
public:
    Dice()
    {
        init();
    }

    bool isValid(const u8* dice);
    u8 isPair();
    u8 isTwoPairs();
    u8 isThreeSame();
    u8 isFourSame();
    u8 isSmallStraight();
    u8 isBigStraight();
    u8 isFullHouse();
    u8 isYatzy();

    u8 getNumOfSames(u8 target);
    u8 getSumOfSames(u8 target);
    u8 isPairOrSame(u8 threshold);
    void storeThrow(const u8* dice); 
    u8 numOfNumbers[NUM_OF_NUMBERS];

private: 
    u8 getBiggest();

    void init()
    {
        memset((void*)numOfNumbers, 0, sizeof(numOfNumbers));
    }
};
#endif
