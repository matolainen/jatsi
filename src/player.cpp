#include "player.hpp"

void Player::setName(const char newName[])
{
    if(strlen(newName) <= MAX_LENGTH_OF_NAME)
    {
        memset((void*)name, '\0', sizeof(name));
        strncpy(name, newName, strlen(newName));
    }
}
    
const char* Player::getName()
{
    return name;
}

const SPoints* Player::getPoints()
{
    return points.getPoints();
}

void Player::setPoints(const EPointsCategory category)
{
    points.setPoints(category);
}

void Player::storeCast(const u8* dice)
{
    points.storeThrow(dice);
}

