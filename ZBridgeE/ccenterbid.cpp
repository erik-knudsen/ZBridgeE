/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CCenterBid.cpp
  Developers: eak

  Revision History:
  3-apr-2018 eak: Original

  Abstract: The bid dialog.

  Platforms: Qt.

*/

/**
 * \file
 * The bid dilog (definition).
 */

#include <QCoreApplication>
#include <cassert>

#include "cbidbutton.h"
#include "ccenterbid.h"

CCenterBid::CCenterBid(QGraphicsWidget *parent) :
    QGraphicsWidget(parent)
{
    bidHint = BID_NONE;

    int xHeadline = 5;
    int yHeadline = 5;
    QFont font("Times New Roman", 10, QFont::Bold);

    headLineLabel = new QGraphicsTextItem(this);
    headLineLabel->setPos(xHeadline, yHeadline);
    headLineLabel->setFont(font);
    headLineLabel->setDefaultTextColor(Qt::darkRed);


    int xPad = 5;
    int yPad = 40;
    int xSize = (CENTER_HOR_SIZE - 2 * xPad) / 5;
    int ySize = (CENTER_VER_SIZE - 40 - 5) / 8;
    int dx = xSize - 5;
    int dy = ySize - 5;

    int yPos = yPad;
    for (int i = 1; i <= 5; i++)
    {
        bidButtons[i] = new CBidButton((Bids)i, dx, dy);
        bidButtons[i]->setPos(xPad + (i - 1) * xSize, yPos);
    }

    yPos += ySize;
    for (int i = 6; i <= 10; i++)
    {
        bidButtons[i] = new CBidButton((Bids)i, dx, dy);
        bidButtons[i]->setPos(xPad + (i - 6) * xSize, yPos);
    }

    yPos += ySize;
    for (int i = 11; i <= 15; i++)
    {
        bidButtons[i] = new CBidButton((Bids)i, dx, dy);
        bidButtons[i]->setPos(xPad + (i - 11) * xSize, yPos);
    }

    yPos += ySize;
    for (int i = 16; i <= 20; i++)
    {
        bidButtons[i] = new CBidButton((Bids)i, dx, dy);
        bidButtons[i]->setPos(xPad + (i - 16) * xSize, yPos);
    }

    yPos += ySize;
    for (int i = 21; i <= 25; i++)
    {
        bidButtons[i] = new CBidButton((Bids)i, dx, dy);
        bidButtons[i]->setPos(xPad + (i - 21) * xSize, yPos);
    }

    yPos += ySize;
    for (int i = 26; i <= 30; i++)
    {
        bidButtons[i] = new CBidButton((Bids)i, dx, dy);
        bidButtons[i]->setPos(xPad + (i - 26) * xSize, yPos);
    }

    yPos += ySize;
    for (int i = 31; i <= 35; i++)
    {
        bidButtons[i] = new CBidButton((Bids)i, dx, dy);
        bidButtons[i]->setPos(xPad + (i - 31) * xSize, yPos);
    }

    yPos += ySize;
    bidButtons[BID_PASS] = new CBidButton(BID_PASS, dx * 2 , dy);
    bidButtons[BID_PASS]->setPos(xPad, yPos);
    bidButtons[BID_DOUBLE] = new CBidButton(BID_DOUBLE,dx, dy);
    bidButtons[BID_DOUBLE]->setPos(xPad + 2* xSize, yPos);
    bidButtons[BID_REDOUBLE] = new CBidButton(BID_REDOUBLE, dx, dy);
    bidButtons[BID_REDOUBLE]->setPos(xPad + 3 * xSize, yPos);
}

/**
 * @brief Set event receiver.
 * @param bidSignalStrategy The receiver.
 */
void CCenterBid::connectBids(QObject *bidSignalStrategy)
{
    for (int i = 0; i < 38; i++)
        bidButtons[i]->connectBid(bidSignalStrategy);
}

/**
 * @brief Enable the bid dialog.
 * @param seat The seat to enable for.
 * @param lastBid The last proper bid given.
 * @param doubleBid Double bid (if any).
 *
 * Sets bidder text. Enables relevant bid buttons. Enables the dialog.
 */
void CCenterBid::enableBidder(Seat seat, Bids lastBid, Bids doubleBid)
{
    int i;

    //Set bidder text (next bidder) and enable.
    headLineLabel->setPlainText(tr("Bidder: ") + QCoreApplication::translate("defines", SEAT_NAMES[seat]));
    headLineLabel->setEnabled(true);

    //Enable proper bid buttons.
    for (i = BID_1C; i <= BID_7NT; i++)
        bidButtons[i]->enable(i > lastBid);

    //Enable proper double/redouble buttons.
    if (lastBid == BID_NONE)
        doubleBid = BID_NONE;

    bidButtons[BID_DOUBLE]->enable(doubleBid == BID_DOUBLE);
    bidButtons[BID_REDOUBLE]->enable(doubleBid == BID_REDOUBLE);

    //Always enable pass.
    bidButtons[BID_PASS]->enable(true);
}

/**
 * @brief Disable the bid dialog.
 */
void CCenterBid::disableBidder()
{
    //Erase bidder text (next bidder) and disable.
    QString headLine = "";
    headLineLabel->setPlainText(headLine);
    headLineLabel->setEnabled(true);

    //Disable all bid buttons.
    for (int i = BID_PASS; i <= BID_REDOUBLE; i++)
        bidButtons[i]->enable(false);
}

/**
 * @brief Show bid hint
 * @param bid Identifies the hinted bid.
 */
void CCenterBid::setBidHint(Bids bid)
{
    assert((bid >= BID_NONE) && (bid <= BID_REDOUBLE));

    if (bidHint != BID_NONE)
        bidButtons[bidHint]->setHint(false);

    if (bid != BID_NONE)
        bidButtons[bid]->setHint(true);

    bidHint = bid;
}

/**
 * @brief Disable the dialog and then show it.
 */
void CCenterBid::show()
{
    disableBidder();
    setParent(this);
    update();

    QGraphicsWidget::show();
}

/**
 * @brief Hide the dialog.
 */
void CCenterBid::hide()
{
    setParent(0);
    update();

    QGraphicsWidget::hide();
}

/**
 * @brief Set the parent of all bid widgets.
 * @param widget If 0 then clear the bid.
 */
void CCenterBid::setParent(QGraphicsWidget *widget)
{
    for (int i = BID_PASS; i <= BID_REDOUBLE; i++)
    {
        if (widget == 0)
            bidButtons[i]->setVisible(false);
        else
            bidButtons[i]->setVisible(true);

        bidButtons[i]->setParentItem(widget);
    }
}
