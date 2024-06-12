#ifndef GRAPHICALNODE_H
#define GRAPHICALNODE_H

#include <QGraphicsRectItem>
#include <QtGui>
#include <QStyle>

class GraphicalNode : public QGraphicsRectItem
{
public:
  ///> Inherits constructors of the QGraphicsRectItem
  using QGraphicsRectItem::QGraphicsRectItem;

private:
  void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
};

#endif // GRAPHICALNODE_H
