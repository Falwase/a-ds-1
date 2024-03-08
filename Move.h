#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <unordered_set>

class Move{

private:
    std::string moveName;

    //vector contains every move this class beats
    //add new class by extending if/else sequence in move constructor
    std::unordered_set<std::string> matchups;
    
public:
    Move(std::string name);
    std::string getName();
    bool ifWin(Move* opp);
};

#endif