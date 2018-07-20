/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBidButton.cpp
  Developers: eak

  Revision History:
  3-apr-2018 eak: Original

  Abstract: Describes and paints one bid in the bid dialog.

  Platforms: Qt.

*/

/**
 * \file
 * Describes and paints one bid in the bid dialog (definition).
 */

#include <QApplication>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "cbidbutton.h"
#include "Defines.h"

CBidButton::CBidButton(Bids bid, int xSize, int ySize)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    this->xSize = xSize;
    this->ySize = ySize;
    bidSignal = 0;
    this->bid = bid;
}

QRectF CBidButton::boundingRect() const
{
    return QRectF(0, 0, xSize, ySize);
}

void CBidButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    QString bidPath = BIDS[bid];
    pixmap.load(bidPath);
    painter->drawPixmap(0, 0, pixmap.scaled(xSize, ySize));
}

void CBidButton::setHint(bool set)
{
    if (set)
    {
        QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect();
        effect->setColor(QColor(0, 0, 255));
        setGraphicsEffect(effect);
    }
    else
        setGraphicsEffect(0);
}

void CBidButton::enable(bool enable)
{
    setEnabled(enable);

    if (!enable)
    {
        QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect();
        effect->setColor(QColor(127, 127, 127));
        setGraphicsEffect(effect);
    }
    else
        setGraphicsEffect(0);
}

void CBidButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect();
        effect->setColor(QColor(127, 127, 127));
        setGraphicsEffect(effect);
    }

    QGraphicsItem::mousePressEvent(event);
}


/**
 * @brief Generates user events.
 * @param event An event received.
 *
 * The method generates the event:
 *   - BID_CHOSEN_Event for when the user selects the card with the left mouse button.
 */
void CBidButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        BID_CHOSEN_Event *bidChosenEvent = new BID_CHOSEN_Event(bid);
        QApplication::postEvent(bidSignal, bidChosenEvent);
    }
    else
      QGraphicsItem::mouseReleaseEvent(event);
}
