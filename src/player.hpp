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
    }

    void setName(const std::string newName);
    const std::string getName();
    const SPoints* getPoints();
    const bool setPoints(const EPointsCategory category);
    void storeCast(const u8* dice);

private:
    std::string name;
    Points points;
};

