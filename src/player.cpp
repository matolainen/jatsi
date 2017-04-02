#include "player.hpp"
#include <string>

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

