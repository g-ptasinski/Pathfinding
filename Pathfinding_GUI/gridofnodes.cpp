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
        std::cerr<<"Something's lacking, Start or Finish"<<std::endl;
    }

}

GraphicalNode* GridOfNodes::getStartPtr()
{
    if( _StartFinishPair.second!=nullptr)
    {
        return _StartFinishPair.second;
    }
    else
    {
        std::cerr<<"Start is not defined"<<std::endl;
    }

    return nullptr;
}

GraphicalNode* GridOfNodes::getFinishPtr()
{
    if( _StartFinishPair.first!=nullptr)
    {
        return _StartFinishPair.first;
    }
    else
    {
        std::cerr<<"Finish is not defined"<<std::endl;
    }

    return nullptr;
}

void GridOfNodes::SaveNeighbours()
{
    for(auto node : _RectItemMap)
    {

    }
}

void GridOfNodes::SetWidth(int w)
{
    _width = w;
}

void GridOfNodes::SetHeight(int h)
{
    _height = h;
}

bool GridOfNodes::isLeft(GraphicalNode* node)
{
    int ID = node->getNodeID();

    if( ID%_width==0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GridOfNodes::isRight(GraphicalNode* node)
{
    int ID = node->getNodeID();

    if( ID%_width==0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GridOfNodes::isTop(GraphicalNode* node)
{
    int ID = node->getNodeID();

    if(ID < _width )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GridOfNodes::isBottom(GraphicalNode* node)
{
    int ID = node->getNodeID();

    if(ID > (_RectItemMap.size()-_width))
    {
        return true;
    }
    else
    {
        return false;
    }
}
