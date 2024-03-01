#include <string>
#include <iostream>

class Player
{

protected:
    string name;

public:
    virtual char makeMove() = 0;
    string getName();
};

