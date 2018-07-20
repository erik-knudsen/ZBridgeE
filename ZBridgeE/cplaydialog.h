/* Erik Aagaard Knudsen.
  Copyright © 2015 - All Rights Reserved

  Project: ZBridge
  File: CPlayDialog.h
  Developers: eak

  Revision History:
  4-feb-2015 eak: Original

  Abstract: Show play for a given board.

  Platforms: Qt.
  */

/**
 * \file
 * The file implements the declaration of a class for showing the play
 * (auction and play) for one board.
 */

#ifndef CPLAYDIALOG_H
#define CPLAYDIALOG_H

#include <QWidget>
#include <QEventLoop>
#include <QResizeEvent>

#include "cbidhistory.h"
#include "cplayhistory.h"

class CGamesDoc;
class CPlayView;

enum ReviewVal { REVIEW_PREV, REVIEW_NEXT};

/**
 * @brief One hand of cards.
 *
 * The class controls the display of one board (auction and play). The CPlayView class is used for the
 * actual display and the CPlayShow class is used for traversing the play.
 */
class CPlayDialog : public QWidget
{
    Q_OBJECT

public:
    explicit CPlayDialog(CGamesDoc *games, int gameIndex, int auctionIndex, QWidget *parent = 0);
    ~CPlayDialog();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

protected:
    virtual void resizeEvent(QResizeEvent *resizeEvent);

private slots:
    void buttonClicked(int button);

private:
    void playValue(ReviewVal reviewVal);

    CGamesDoc *games;
    int gameIndex, auctionIndex;
    int board;
    int cards[4][13];
    Seat dealer, declarer;
    Team vulnerable;
    Bids contract, dbl;
    int result;
    CBidHistory bidHistory;
    CPlayHistory playHistory;

    CPlayView *playView;

    Seat player;
    int playNo;
    int trickNo;
    int trick[4];

    QEventLoop eventLoop;
};

#endif // CPLAYDIALOG_H
