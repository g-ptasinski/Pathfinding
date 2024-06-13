#ifndef GRAPHICALNODE_H
#define GRAPHICALNODE_H

#include <QGraphicsRectItem>
#include <QtGui>
#include <QStyle>
/*
enum NodeTypes
{
    NODE = 0,
    START,
    FINISH
};*/

class GraphicalNode : public QGraphicsRectItem
{
public:
  ///> Inherits constructors of the QGraphicsRectItem
  GraphicalNode(qreal x, qreal y, qreal w, qreal h, int ID) : QGraphicsRectItem(x,y,w,h) , m_nodeID{ID}
  {
    setBrush(Qt::white);
    setAcceptHoverEvents(true);
  };

  void getNodeID();
  void setVisited();

private:
  void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

  const int m_nodeID;
  bool  m_visited;
  int     m_nodeType;


};

#endif // GRAPHICALNODE_H
