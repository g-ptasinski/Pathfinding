#ifndef PATHFINDINGALGO_H
#define PATHFINDINGALGO_H

#include <iostream>

class PathFindingAlgo
{
public:
    PathFindingAlgo();
    ~PathFindingAlgo(){};

    virtual void TestFunct(){std::cout<<"Base test funct"<<std::endl;};
};

#endif // PATHFINDINGALGO_H
