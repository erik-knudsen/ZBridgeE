/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBottomInfoPlayShow.h
  Developers: eak

  Revision History:
  30-mar-2018 eak: Original

  Abstract: Bottom info buttons for controlling the display of an already played play.

  Platforms: Qt.

*/

/**
 * \file
 * Bottom info buttons for controlling the display of an already played play (declaration).
 */

#ifndef CBOTTOMINFOPLAYSHOW_H
#define CBOTTOMINFOPLAYSHOW_H

#define CBOTTOMINFOAUCTIONBUTTON_H

#include <QGraphicsWidget>

/**
 * @brief Shows 3 buttons in the bottom info widget in the play view.
 *
 * Two of the buttons are used for traversing the play. The third button is used for showing
 * double dummy results.
 */
class CBottomInfoPlayShow : public QGraphicsWidget
{
public:
    explicit CBottomInfoPlayShow(int horSize, int verSize, QGraphicsWidget *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief Connect button events to an event receiver.
     * @param buttonSignal Receiver.
     */
    void connectButton(QObject *buttonSignal) { this->buttonSignal = buttonSignal; }
    /**
     * @brief Set the ids of the buttons.
     * @param buttonId The button id.
     */
    void setButtonIds(int fwdButtonId, int bckButtonId, int ddButtonId, int okButtonId);
    void setFwdEnabled(bool enabled);
    bool isFwdEnabled();
    void setBckEnabled(bool enabled);
    bool isBckEnabled();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int horSize, verSize;
    int fwdButtonId, bckButtonId, ddButtonId, okButtonId;
    bool fwdPressed, bckPressed, ddPressed, okPressed;
    bool fwdEnabled, bckEnabled, ddEnabled, okEnabled;
    QObject *buttonSignal;
    QRectF fwdButton;
    QRectF bckButton;
    QRectF ddButton;
    QRectF okButton;
};

#endif // CBOTTOMINFOPLAYSHOW_H
