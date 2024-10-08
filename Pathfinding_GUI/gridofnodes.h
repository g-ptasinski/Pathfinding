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

    int getSize(){return std::sqrt(_RectItemMap.size());};

    void WriteNodeIntoGrid(GraphicalNode * node);
    void SetStart(GraphicalNode * node);
    void SetFinish(GraphicalNode * node);
    void SetHeight(int h);
    void SetWidth(int w);

    void PrintStartFinish();
    void SaveNeighbours();

    bool isLeft(GraphicalNode* node);
    bool isRight(GraphicalNode* node);
    bool isTop(GraphicalNode* node);
    bool isBottom(GraphicalNode* node);

    GraphicalNode* getStartPtr();
    GraphicalNode* getFinishPtr();

  public slots:
  void getStart(GraphicalNode * node);
  void getFinish(GraphicalNode * node);

  private:
    int _width;
    int _height;
    std::vector<GraphicalNode *>  _RectItemMap;
    std::pair<GraphicalNode * , GraphicalNode *> _StartFinishPair;

};

#endif // GRIDOFNODES_H
