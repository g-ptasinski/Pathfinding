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
    STARTFINISH=0,
    NODEBLOCK = 1
};

class GraphicalNode : public QObject, public QGraphicsRectItem
{
  Q_OBJECT

public:
  ///> Inherits constructors of the QGraphicsRectItem
  GraphicalNode(qreal x, qreal y, qreal w, qreal h, int ID) : QGraphicsRectItem(x,y,w,h) , m_nodeID{ID}
  {
    setBrush(Qt::white);
    setAcceptHoverEvents(true);
    m_nodeType = NODE;
    m_partOfPath = false;
    m_visited       = false;
    m_actionType = 1;

    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;

  };

  GraphicalNode * top;
  GraphicalNode * bottom;
  GraphicalNode * left;
  GraphicalNode * right;

  bool isVisited();
  bool isNode();
  int getNodeID();

  void setVisited();
  void setPartOfPath();
  void set_nodeType(NodeTypes type);
  void set_actionType(ActionType type);

private:

  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

  const int m_nodeID;
  bool  m_visited;
  bool  m_partOfPath;
  int     m_nodeType;
  int     m_actionType;

public slots:

  void setValue(ActionType value);

signals:
    void sendID( int  m_nodeID);
    void sendStart(GraphicalNode * node);
    void sendFinish(GraphicalNode * node);

};

#endif // GRAPHICALNODE_H
