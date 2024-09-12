#ifndef PATHFINDINGALGO_H
#define PATHFINDINGALGO_H
#include "gridofnodes.h"

class PathFindingAlgo
{
public:
    PathFindingAlgo();
    ~PathFindingAlgo(){};

    virtual void _Find(GridOfNodes* grid){};
};

#endif // PATHFINDINGALGO_H
