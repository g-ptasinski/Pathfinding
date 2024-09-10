#include "depthfirstsearch.h"
#include <iostream>

DepthFirstSearch::DepthFirstSearch() {}

void DepthFirstSearch::TestFunct()
{
    std::cout<<"DFS test funct"<<std::endl;
}

void DepthFirstSearch::Find(GridOfNodes* grid)
{
    //0. Start at Start
    //1. Visit nodes one by one horizontal or vertical
    //2. Push visited in a stack
    //3. If Dead End encountered - backtrack to the last node, which has unvisited neighbours
    //4. If Finish encountered - visited stack is path.
}
