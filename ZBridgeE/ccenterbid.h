/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved
  Project: ZBridge
  File: CCenterBid.h
  Developers: eak

  Revision History:
  3-apr-2018 eak: Original

  Abstract: The bid dialog.

  Platforms: Qt.

*/

/**
 * \file
 * The bid dilog (declaration).
 */

#ifndef CCENTERBID_H
#define CCENTERBID_H

#include <QGraphicsWidget>
#include <QGraphicsSimpleTextItem>

#include "defines.h"

class CBidButton;

class CCenterBid : public QGraphicsWidget
{
public:
    explicit CCenterBid(QGraphicsWidget *parent = 0);

    void connectBids(QObject *bidSignalStrategy);

    void enableBidder(Seat seat, Bids lastBid, Bids doubleBid);
    void disableBidder();
    void setBidHint(Bids bid);
    void setParent(QGraphicsWidget *widget);
    void show();
    void hide();

private:
    CBidButton *bidButtons[38];
    QGraphicsTextItem *headLineLabel;
    Bids bidHint;
};

#endif // CCENTERBID_H
