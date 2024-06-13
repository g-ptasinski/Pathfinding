#include <iostream>
#include "graphicalnode.h"

void GraphicalNode::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
  setBrush(Qt::black);
  this->update();
}

void GraphicalNode::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
  setBrush(Qt::white);
  this->update();
}

void GraphicalNode::getNodeID()
{
  std::cout<<m_nodeID<<std::endl;
  //return m_nodeID;
}

void GraphicalNode::setVisited()
{
  m_visited = true;
}
