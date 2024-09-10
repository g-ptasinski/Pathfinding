#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

#include "pathfindingalgo.h"

class DepthFirstSearch : public PathFindingAlgo
{

public:
    DepthFirstSearch();
    ~DepthFirstSearch(){};

    void TestFunct() override;
};

#endif // DEPTHFIRSTSEARCH_H
