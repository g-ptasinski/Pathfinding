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

int GraphicalNode::getNodeID()
{
  std::cout<<m_nodeType<<std::endl;
  return m_nodeType;;
}

void GraphicalNode::setVisited()
{
  m_visited = true;
}

void GraphicalNode::setValue(int value)
{
  std::cout<<value<<std::endl;
}

