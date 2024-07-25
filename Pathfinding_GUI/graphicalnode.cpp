#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include "graphicalnode.h"

void GraphicalNode::set_nodeType(NodeTypes type)
{
    this->m_nodeType = type;
}

void GraphicalNode::set_actionType(ActionType type)
{
    this->m_actionType = type;
}

void GraphicalNode::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

  if(m_actionType == 1)
    {
        if(event->button() == Qt::LeftButton)
        {
            set_nodeType(BLOCKED);
            setBrush(Qt::black);
        }
        else if(event->button() == Qt::RightButton)
        {
            set_nodeType(NODE);
            setBrush(Qt::white);
        }
    }
  else if(m_actionType == 0)
    {
        if(event->button() == Qt::LeftButton)
        {
            set_nodeType(START);
            setBrush(Qt::green);
        }
        else if(event->button() == Qt::RightButton)
        {
            set_nodeType(FINISH);
            setBrush(Qt::blue);
        }
    }

}

void GraphicalNode::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit sendID(m_nodeID);
}

int GraphicalNode::getNodeID()
{
  return m_nodeType;;
}

void GraphicalNode::setVisited()
{
  m_visited = true;
}

void GraphicalNode::setValue(ActionType value)
{
   set_actionType(value);
}
