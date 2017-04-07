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

    const bool isValid(const u8* dice);
    const u8 isPair();
    const u8 isTwoPairs();
    const u8 isThreeSame();
    const u8 isFourSame();
    const u8 isSmallStraight();
    const u8 isBigStraight();
    const u8 isFullHouse();
    const u8 isYatzy();

    const u8 getNumOfSames(const u8 target);
    const u8 getSumOfSames(const u8 target);
    const u8 isPairOrSame(const u8 threshold);
    void storeThrow(const u8* dice); 
    void rollDie(const u8 numOfDice, u8* dice);
    u8 numOfNumbers[NUM_OF_NUMBERS];

private: 
    const u8 getBiggest();
    
    void init()
    { 
        memset((void*)numOfNumbers, 0, sizeof(numOfNumbers));
    }
};
#endif
