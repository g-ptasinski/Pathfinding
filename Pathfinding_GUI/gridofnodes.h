#ifndef GRIDOFNODES_H
#define GRIDOFNODES_H

#include <vector>
#include "graphicalnode.h"

class GridOfNodes : public QObject
{
      Q_OBJECT

public:
  GridOfNodes();
    ~GridOfNodes(){};

  void WriteNodeIntoGrid(GraphicalNode * node);
  void SetStart(GraphicalNode * node);
  void SetFinish(GraphicalNode * node);
  void PrintStartFinish();

  public slots:

  void getStart(GraphicalNode * node);
  void getFinish(GraphicalNode * node);

private:
  std::vector<GraphicalNode *>  _RectItemMap;
  std::pair<GraphicalNode * , GraphicalNode *> _StartFinishPair;
};

#endif // GRIDOFNODES_H
