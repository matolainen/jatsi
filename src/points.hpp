#ifndef _POINTS_HPP
#define _POINTS_HPP

#include <string.h>
#include "dice.hpp"

class Points: public Dice
{
public:
    Points()
    {
    }

    u8 getSumOfNumbers();

private:

};

#endif
