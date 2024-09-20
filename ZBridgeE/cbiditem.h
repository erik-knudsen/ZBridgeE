#ifndef CBIDITEM_H
#define CBIDITEM_H

/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBidItem.h
  Developers: eak

  Revision History:
  5-sep-2013 eak: Original

  Abstract: Description of one bid (to be used in the play view).

  Platforms: Qt.

*/

#include <QGraphicsItem>
#include <QQueue>

#include "cpopup.h"
#include "Defines.h"

/**
 * \file
 * Description of one bid (declaration).
 */

/**
 * @brief Description of one bid.
 *
 * This class is used by the play view to handle one of the given bids.
 */
class CBidItem : public QGraphicsItem
{
public:
    explicit CBidItem(Seat seat, Bids bid);
    ~CBidItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void setSeat(Seat seat) { this->seat = seat; }
    Seat getSeat() { return seat; }
    void setBid(Bids bid) { this->bid = bid; }
    Bids getBid() { return bid; }
    void setFeatures(QString features) { this->features = features; }
    QString getFeatures() { return features; }
    void setAlert(QString alert) { this->alert = alert; }
    QString getAlert() { return alert; }
    void connectBid(QObject *bidSignal) { this->bidSignal = bidSignal; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    void processMouse();
    Seat seat;          /**< The seat who gave the bid. */
    Bids bid;           /**< The bid. */
    QString features;
    QString alert;
    QObject *bidSignal; /**< Event receiver. */
    CPopup *popup;
    QQueue<int> mouseQueue;
    bool processingMouse;
};

#endif // CBIDITEM_H
