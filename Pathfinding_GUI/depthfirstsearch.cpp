#include "depthfirstsearch.h"
#include <stack>
#include <iostream>

DepthFirstSearch::DepthFirstSearch() {}

void DepthFirstSearch::_Find(GridOfNodes* grid)
{
    GraphicalNode* current_node = grid->getStartPtr();
    _writeIntoCallstack(current_node);

    //0. Start at Start
    while(!callstack.empty())
    {
        //1. Visit nodes one by one horizontal or vertical
        //2. Push visited in a stack
        if(_isVisitable(current_node->right))
        {
            current_node = current_node->right;
            _writeIntoCallstack(current_node);
        }
        else if(_isVisitable(current_node->bottom))
        {
            current_node = current_node->bottom;
            _writeIntoCallstack(current_node);
        }
        else if(_isVisitable(current_node->left))
        {
            current_node = current_node->left;
            _writeIntoCallstack(current_node);
        }
        else if(_isVisitable(current_node->top))
        {
            current_node = current_node->top;
            _writeIntoCallstack(current_node);
        }
        else
        {
            callstack.pop();
            current_node = callstack.top();
        }
         //3. If Dead End encountered - backtrack to the last node, which has unvisited neighbours
        //4. If Finish encountered - visited stack is path.
        if(current_node != grid->getFinishPtr())
        {
            _constructPath(); break;
        }

        current_node->setVisited();
    }



}

void DepthFirstSearch::_writeIntoCallstack(GraphicalNode* node)
{
    callstack.push(node);
}

void DepthFirstSearch::_constructPath()
{
    GraphicalNode* pathNode = nullptr;

    while(!callstack.empty())
    {
        pathNode = callstack.top();
        pathNode->setPartOfPath();
        callstack.pop();
    }
}

bool DepthFirstSearch::_isVisitable(GraphicalNode* neighbour)
{
    return(neighbour!=nullptr && neighbour!=callstack.top() &&  neighbour->isNode());
}
