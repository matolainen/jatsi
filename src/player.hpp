#include "points.hpp"
#include <string>

#define MAX_LENGTH_OF_NAME 16
#define DEFAULT_NAME "JatsiMies"


class Player
{
public:
    Player()
    {
        init();
    }

    void init()
    {
        name.resize(MAX_LENGTH_OF_NAME);
        name = DEFAULT_NAME;
        points.init();
        resetCast();
    }

    void setName(const std::string newName);
    const std::string getName();
    const SPoints* getPoints();
    const bool setPoints(const EPointsCategory category);
    void rollDice();
    void storeCast(const u8* dice);
    void saveDice(const u8* indicesOfDiceToStore);
    u8 cast[NUM_OF_DICE];
private:
    std::string name; 
    void resetCast()
    {
        memset((void*)cast, INVALID_VALUE, sizeof(cast));
    }
    Points points;
};

