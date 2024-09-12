#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

#include <stack>
#include "pathfindingalgo.h"

class DepthFirstSearch : public PathFindingAlgo
{

public:
    DepthFirstSearch();
    ~DepthFirstSearch(){};

    void _Find(GridOfNodes* grid) override;

    void _constructPath();
    void _writeIntoCallstack(GraphicalNode*);
    bool _isVisitable(GraphicalNode*);

private:
    std::stack<GraphicalNode*, std::vector<GraphicalNode*>> callstack;

};

#endif // DEPTHFIRSTSEARCH_H
