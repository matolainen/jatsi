#include "points.hpp"
#include <string.h>

#define MAX_LENGTH_OF_NAME 16


class Player
{
public:
    Player()
    {
        init();
    }

    void init()
    {
        memset((void*)name, '\0', sizeof(name));
        strncpy(name, "NoppaTollo", strlen("NoppaTollo"));
        points.init();
    }

    void setName(const char newName[]);
    const char* getName();
    const SPoints* getPoints();
    void setPoints(const EPointsCategory category);
    void storeCast(const u8* dice);

private:
    char name[MAX_LENGTH_OF_NAME];
    Points points;
};

