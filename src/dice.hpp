#ifndef _DICE_HPP
#define _DICE_HPP

#include <string.h>

#define NUM_OF_DICE 5
#define NUM_OF_NUMBERS 6

#define u8   unsigned char
#define u32  unsigned int
#define i8   signed char


class Dice
{
public:
    Dice()
    {
        init();
    }

    bool isValid(const u8* dice);
    bool isPair();
    bool isTwoPairs();
    bool isThreeSame();
    bool isFourSame();
    bool isSmallStraight();
    bool isBigStraight();
    bool isFullHouse();
    bool isYatzy();

    u8 getNumOfSames(const u8* dice, u8 target);
    bool isPairOrSame(u8 threshold);
    void storeThrow(const u8* dice);
    u8 getBiggest();

private: 
    u8 numOfNumbers[NUM_OF_NUMBERS];
    u8 biggest; 

    void init()
    {
        biggest = 0;
        memset((void*)numOfNumbers, 0, sizeof(numOfNumbers));
    }
};
#endif
