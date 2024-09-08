#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include "graphicalnode.h"

void GraphicalNode::set_nodeType(NodeTypes type)
{
    this->m_nodeType = type;
    if(type == BLOCKED)
    {
        setBrush(Qt::black);
    }
    else if(type == FINISH)
    {
         setBrush(Qt::blue);
    }
    else if(type == START)
    {
        set_nodeType(START);
    }
    else if(type == NODE)
    {
        setBrush(Qt::white);
    }
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
        }
        else if(event->button() == Qt::RightButton)
        {
            set_nodeType(NODE);
        }
    }
  else if(m_actionType == 0)
    {
        if(event->button() == Qt::LeftButton)
        {
            emit sendStart(this);
            setBrush(Qt::green);
        }
        else if(event->button() == Qt::RightButton)
        {
            emit sendFinish(this);
            set_nodeType(FINISH);
        }
    }

}

void GraphicalNode::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit sendID(m_nodeID);
}

int GraphicalNode::getNodeID()
{
  return m_nodeID;
}

void GraphicalNode::setVisited()
{
    if(m_nodeType == NODE)
    {
        m_visited = true;
        setBrush(Qt::gray);
    }
    else
    {
        std::cerr <<"You cannot visit object of this type"<<std::endl;
        std::cerr <<"Type: "<< m_nodeType<<std::endl;
    }
}

void GraphicalNode::setValue(ActionType value)
{
   set_actionType(value);
}
