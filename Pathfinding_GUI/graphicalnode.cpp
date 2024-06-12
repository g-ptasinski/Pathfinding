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

