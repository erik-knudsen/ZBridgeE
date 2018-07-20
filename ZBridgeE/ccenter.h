/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CCenter.h
  Developers: eak

  Revision History:
  3-apr-2018 eak: Original

  Abstract: Center part of play view.

  Platforms: Qt.

*/

/**
 * \file
 * Center part of play view (declaration).
 */

#ifndef CCENTER_H
#define CCENTER_H

#include <QGraphicsWidget>

/**
 * @brief Center view class.
 *
 *The Center view class is used by the play view to show, depending on context, one of:
 *   - Bid dialog.
 *   - The cards trick by trick as the play progresses. It also shows vulnerability and who is to
 *     play next.
 *   - Arrows for review of play.
 */

class CCenter : public QGraphicsWidget
{
public:
    explicit CCenter(QGraphicsWidget *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    bool pressed;
};

#endif // CCENTER_H
