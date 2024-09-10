#include "gridofnodes.h"
#include <iostream>

GridOfNodes::GridOfNodes()
{
    _StartFinishPair = {nullptr, nullptr};
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
    if(_StartFinishPair.first != nullptr && _StartFinishPair.second != nullptr)
    {
        std::cout<< _StartFinishPair.first->getNodeID()<<" "<< _StartFinishPair.second->getNodeID()<<std::endl;
    }
    else
    {
        std::cout<<"Something's lacking, Start or Finish"<<std::endl;
    }

}
