/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBidItem.cpp
  Developers: eak

  Revision History:
  5-sep-2013 eak: Original

  Abstract: Description of one bid (to be used in the play view)..

  Platforms: Qt.

*/

/**
 * \file
 * Description of one bid (definition).
 */

#include <QApplication>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "CBidItem.h"
#include "Defines.h"

const int MOUSE_RELEASE = 1;
const int MOUSE_PRESS = 2;

/**
 * @brief Constructor creates the bid.
 * @param seat The seat who gave the bid.
 * @param bid The bid.
 */
CBidItem::CBidItem(Seat seat, Bids bid)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    bidSignal = 0;

    processingMouse = false;

    setSeat(seat);
    setBid(bid);
}

CBidItem::~CBidItem()
{
}

QRectF CBidItem::boundingRect() const
{
    return QRectF(0, 0, BID_HOR_SIZE * 2.2, BID_VER_SIZE * 2.2);
}

/**
 * @brief Paint the bid.
 */
void CBidItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    QString bidRef = BIDS[bid];
    pixmap.load(bidRef);
    QRectF rect = boundingRect();
    painter->drawPixmap(rect.x(), rect.y(), rect.width(), rect.height(), pixmap);
}

void CBidItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        mouseQueue.enqueue(MOUSE_PRESS);        //Serialize mouse press event.

    QGraphicsItem::mousePressEvent(event);

    processMouse();
}


/**
 * @brief Mouse release event for the bid is sent to the event receiver.
 * @param event The event.
 *
 * In case of a left button release event the bidClickedEvent is sent to the event receiver.
 */
void CBidItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        mouseQueue.enqueue(MOUSE_RELEASE);      //Serialize mouse release event.

    QGraphicsItem::mouseReleaseEvent(event);

    processMouse();
}

//Process serialized mouse press and mouse release events.
void CBidItem::processMouse()
{
    if (processingMouse)
        return;

    processingMouse = true;
    while (!mouseQueue.isEmpty())
    {
        int mouseEvent = mouseQueue.dequeue();
        if (mouseEvent == MOUSE_PRESS)
        {
            popup = new CPopup();

            if (alert.size() > 0)
                popup->showPopup(alert + "\n" + features);
            else if (features.size() > 0)
                popup->showPopup(features);
        }
        else if (mouseEvent == MOUSE_RELEASE)
            delete popup;
    }
    processingMouse = false;
}
