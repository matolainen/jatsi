#include "player.hpp"
#include <string>

#define NUM_OF_ROUNDS 15 


class Game
{
public:
    Game()
    {
        init();
    }

    void init()
    {
        numOfPlayers = 0;
    }

    const bool setNumOfPlayers(const u8 newNumOfPlayers)
    {
        numOfPlayers = newNumOfPlayers;
    }


private:
    u8 numOfPlayers;
