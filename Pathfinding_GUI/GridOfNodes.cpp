#include "GridOfNodes.h"

GridOfNodes::GridOfNodes()
{

}

void GridOfNodes::WriteNodeIntoGrid(GraphicalNode * node)
{
    _RectItemMap.push_back(node);
}

