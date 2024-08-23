﻿/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBid.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original

  Abstract: One bid.

  Platforms: Qt. 

*/

/**
 * @file One bid.
 * One bid (declaration).
 */

#ifndef CBID_H
#define CBID_H

#include <QString>
#include <QList>

#include "crule.h"
#include "Defines.h"

/**
 * @brief The CBid class represents one bid.
 */
class CBid
{
public:
    CBid(Seat bidder, Bids bid, QString alert, QList<CRule *> &rules, bool substitute);
    CBid(Seat bidder, Bids bid, QString alert);
    CBid() { bid = BID_NONE; /* delRules = false; */}
    ~CBid();

    void deleteRules();

    Seat bidder;        /**< Position east, south, north or west. */
    Bids bid;           /**< Bid value. */
    QString alert;      /**< Text string describing possible alert. */
    QList<CRule *> rules; /**< Rules delimiting the bid. */
    bool substitute;    /**< Previous bidding sequence substitute? */
//    bool delRules;      /**< If true then delete non bid DB rules on destroy. */
};

#endif // CBID_H
