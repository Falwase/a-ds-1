#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player
{

protected:
    std::string name;

public:
    virtual char makeMove() = 0;
    std::string getName();
};

#endif