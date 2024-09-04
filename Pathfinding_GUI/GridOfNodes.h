#ifndef GRIDOFNODES_H
#define GRIDOFNODES_H

#include <vector>

#include "graphicalnode.h"

class GridOfNodes
{
public:
  GridOfNodes();
  ~GridOfNodes();

  void WriteNodeIntoGrid(GraphicalNode * node);

private:
  std::vector<GraphicalNode *>  _RectItemMap;
  std::pair<int,int> _StartFinishPair;
};

#endif // GRIDOFNODES_H
