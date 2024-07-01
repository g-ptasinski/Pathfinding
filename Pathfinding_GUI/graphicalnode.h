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

enum ActionType
{
    NODEBLOCK = 0,
    STARTFINISH=1
};

class GraphicalNode : public QGraphicsRectItem , public QObject
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
  void set_actionType(ActionType type);

private:

  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

  const int m_nodeID;
  bool  m_visited;
  int     m_nodeType;
  int     m_actionType;

public slots:

  void setValue(int value);

};

#endif // GRAPHICALNODE_H
