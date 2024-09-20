/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CCenter.cpp
  Developers: eak

  Revision History:
  3-apr-2018 eak: Original

  Abstract: Center part of play view.

  Platforms: Qt.

*/

/**
 * \file
 * Center part of play view (definition).
 */

#include <QGraphicsWidget>
#include <QRectF>
#include <QBrush>
#include <QPainter>

#include "ccenter.h"
#include "Defines.h"

CCenter::CCenter(QGraphicsWidget *parent) :
    QGraphicsWidget(parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable);

    pressed = true;
}

QRectF CCenter::boundingRect() const
{
    return QRectF(0, 0, CENTER_HOR_SIZE, CENTER_VER_SIZE);
}

void CCenter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
/*    QRectF rec = boundingRect();
    QBrush brush(Qt::gray);
    if (pressed)
    {
        brush.setColor(Qt::darkGray);
    }
    else
    {
        brush.setColor(Qt::gray);
    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);

    QGraphicsWidget::paint(painter, option, widget);
*/
}

void CCenter::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    update();
    QGraphicsWidget::mousePressEvent(event);
}


void CCenter::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = true;
    update();
    QGraphicsWidget::mouseReleaseEvent(event);
}
