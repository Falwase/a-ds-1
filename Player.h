#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Move.h"

class Player
{

protected:
    std::string name;

public:
    virtual Move* makeMove() = 0;
    std::string getName();
};

#endif