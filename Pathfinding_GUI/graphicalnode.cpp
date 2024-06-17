#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include "graphicalnode.h"

void GraphicalNode::set_nodeType(NodeTypes type)
{
    this->m_nodeType = type;

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

/*
void GraphicalNode::keyPressEvent(QKeyEvent *event)
{
    if(event->key() ==Qt::Key_1)
    {
        set_nodeType(START);
        setBrush(Qt::yellow);
    }
    else if(event->key() == Qt::Key_2)
    {
        set_nodeType(FINISH);
        setBrush(Qt::green);
    }
}
*/
int GraphicalNode::getNodeID()
{
  std::cout<<m_nodeType<<std::endl;
  return m_nodeType;;
}

void GraphicalNode::setVisited()
{
  m_visited = true;
}


