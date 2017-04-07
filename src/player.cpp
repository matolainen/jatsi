#include "player.hpp"
#include <string>
#include <random>

void Player::setName(const std::string newName)
{
    if(newName.size() <= MAX_LENGTH_OF_NAME)
    {
        name = newName;
    }
}
    
const std::string Player::getName()
{
    return name;
}

const SPoints* Player::getPoints()
{
    return points.getPoints();
}

const bool Player::setPoints(const EPointsCategory category)
{
    return (points.setPoints(category));
}

void Player::storeCast(const u8* dice)
{
    points.storeThrow(dice);
}

void Player::rollDice()
{
    for(u8 i = 0; i < NUM_OF_DICE; i++)
    {
        if(cast[i] == INVALID_VALUE)
        {
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 eng(rd()); // seed the generator
            std::uniform_int_distribution<> distr(1, 6); // define the range
            cast[i] = distr(eng);
        }
    }
}

void Player::saveDice(const u8* indicesOfDiceToStore)
{
    u8 temp[NUM_OF_DICE];
    memcpy((void*)temp, (void*)cast, sizeof(temp));
    memset((void*)cast, INVALID_VALUE, sizeof(cast));

    for(u8 i = 0; i < NUM_OF_DICE; i++)
    {   
        if(indicesOfDiceToStore[i] <= 6)
        {
            cast[i] = temp[indicesOfDiceToStore[i]]; 
        }
    } 
}







