#ifndef GRAPHICALNODE_H
#define GRAPHICALNODE_H

#include <QGraphicsRectItem>
#include <QtGui>
#include <QStyle>

enum NodeTypes
{
    NODE = 0,
    START,
    FINISH,
    BLOCKED
};

class GraphicalNode : public QGraphicsRectItem
{
public:
  ///> Inherits constructors of the QGraphicsRectItem
  GraphicalNode(qreal x, qreal y, qreal w, qreal h, int ID) : QGraphicsRectItem(x,y,w,h) , m_nodeID{ID}
  {
    setBrush(Qt::white);
    setAcceptHoverEvents(true);
    m_nodeType = NODE;
  };

  int getNodeID();
  void setVisited();
  void set_nodeType(NodeTypes type);

private:

  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  //void keyPressEvent(QKeyEvent *event) override;

  const int m_nodeID;
  bool  m_visited;
  int     m_nodeType;


};

#endif // GRAPHICALNODE_H
