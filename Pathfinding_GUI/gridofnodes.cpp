#include "gridofnodes.h"
#include <iostream>

GridOfNodes::GridOfNodes()
{

}

void GridOfNodes::WriteNodeIntoGrid(GraphicalNode * node)
{
    _RectItemMap.push_back(node);
}

void GridOfNodes::SetStart(GraphicalNode * node)
{
    if( _StartFinishPair.first!=nullptr)
    {
        _StartFinishPair.first->set_nodeType(NODE);
    }
    _StartFinishPair.first = node;
}

void GridOfNodes::SetFinish(GraphicalNode * node)
{
    if( _StartFinishPair.second!=nullptr)
    {
        _StartFinishPair.second->set_nodeType(NODE);
    }
    _StartFinishPair.second = node;
 }

void GridOfNodes::getFinish(GraphicalNode * node)
{
    SetFinish(node);
}
void GridOfNodes::getStart(GraphicalNode * node)
{
    SetStart(node);
}

void GridOfNodes::PrintStartFinish()
{
    std::cout<< _StartFinishPair.first->getNodeID()<<" "<< _StartFinishPair.second->getNodeID()<<std::endl;
}
