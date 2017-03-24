#ifndef _DICE_HPP
#define _DICE_HPP

#define NUM_OF_DICE 5
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
    bool isPair(const u8* dice);
    bool isTwoPairs(const u8* dice);
    u8 getNumOfSames(const u8* dice, u8 target);

private:
    u8 ones;
    u8 twos;
    u8 threes;
    u8 fours;
    u8 fives;
    u8 sixes;
    
    void init()
    {
        ones = 0;
        twos = 0;
        threes = 0;
        fours = 0;
        fives = 0;
        sixes = 0;
    }
};
#endif
