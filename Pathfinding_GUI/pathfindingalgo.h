#ifndef PATHFINDINGALGO_H
#define PATHFINDINGALGO_H

#include <iostream>
#include "gridofnodes.h"

class PathFindingAlgo
{
public:
    PathFindingAlgo();
    ~PathFindingAlgo(){};

    virtual void TestFunct(){std::cout<<"Base test funct"<<std::endl;};
    virtual void Find(GridOfNodes* grid){};
};

#endif // PATHFINDINGALGO_H
