/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBidButton.h
  Developers: eak

  Revision History:
  3-apr-2018 eak: Original

  Abstract: Describes and paints one bid in the bid dialog.

  Platforms: Qt.

*/

/**
 * \file
 * Describes and paints one bid in the bid dialog (declaration).
 */

#ifndef CBIDBUTTON_H
#define CBIDBUTTON_H



#include <QGraphicsItem>
#include <QGraphicsColorizeEffect>

#include "defines.h"

/**
 * @brief This class describes one bid in the bid dialog.
 *
 * The description includes:
 *   - The value of the bid.
 *   - The position of the card in the bid dialog.
 *   - The receiver of emitted events.
 */
class CBidButton : public QGraphicsItem
{
public:
    CBidButton(Bids value, int xSize, int ySize);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void setHint(bool set);
    void enable(bool enable);
    void connectBid(QObject *bidSignal) { this->bidSignal = bidSignal; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Bids bid;
    int xSize, ySize;
    QObject *bidSignal;
};

#endif // CBIDBUTTON_H
