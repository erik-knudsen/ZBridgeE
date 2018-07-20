/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBottomInfoPlayShow.cpp
  Developers: eak

  Revision History:
  30-mar-2018 eak: Original

  Abstract: Bottom info buttons for controlling the display of an already played play.

  Platforms: Qt.

*/

/**
 * \file
 * Bottom info buttons for controlling the display of an already played play (definition).
 */

#include <QApplication>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "defines.h"

#include "cbottominfoplayshow.h"

CBottomInfoPlayShow::CBottomInfoPlayShow(int horSize, int verSize, QGraphicsWidget *parent) :
    QGraphicsWidget(parent)
{
    this->horSize = horSize;
    this->verSize = verSize;

    setFlag(QGraphicsItem::ItemIsSelectable);

    buttonSignal = 0;
    fwdPressed = bckPressed = ddPressed = okPressed = false;
    fwdEnabled = bckEnabled = ddEnabled = okEnabled = true;

    fwdButton.setCoords(horSize / 2, 0, horSize, verSize / 2);
    bckButton.setCoords(0, 0, horSize / 2, verSize / 2);
    ddButton.setCoords(0, verSize / 2, horSize / 2, verSize);
    okButton.setCoords(horSize / 2, verSize / 2, horSize, verSize);
}

QRectF CBottomInfoPlayShow::boundingRect() const
{
    return QRectF(0, 0, horSize, verSize);
}

void CBottomInfoPlayShow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush(Qt::green);
    Qt::GlobalColor color;

    //Forward background.
    color = (fwdPressed) ? (Qt::darkGray) : (fwdEnabled) ? (Qt::lightGray) : (Qt::black);
    brush.setColor(color);
    painter->fillRect(fwdButton, brush);
    painter->drawRect(fwdButton);

    //Backward background.
    color = (bckPressed) ? (Qt::darkGray) : (bckEnabled) ? (Qt::lightGray) : (Qt::black);
    brush.setColor(color);
    painter->fillRect(bckButton, brush);
    painter->drawRect(bckButton);

    //DD background.
    color = (ddPressed) ? (Qt::darkGray) : (ddEnabled) ? (Qt::lightGray) : (Qt::black);
    brush.setColor(color);
    painter->fillRect(ddButton, brush);
    painter->drawRect(ddButton);

    //OK background.
    color = (okPressed) ? (Qt::darkGray) : (okEnabled) ? (Qt::lightGray) : (Qt::black);
    brush.setColor(color);
    painter->fillRect(okButton, brush);
    painter->drawRect(okButton);

    QPixmap pixMap;
    QString path;

    //Forward pixmap
    path = QString(":/resources/review_next.ico");
    pixMap.load(path);
    int x = fwdButton.x() + (fwdButton.width() - fwdButton.height()) / 2;
    int y = fwdButton.y();
    painter->drawPixmap(x, y, fwdButton.height(), fwdButton.height(), pixMap);

    //Backward pixmap.
    path = QString(":/resources/review_prev.ico");
    pixMap.load(path);
    x = bckButton.x() + (bckButton.width() - bckButton.height()) / 2;
    y = bckButton.y();
    painter->drawPixmap(x, y, bckButton.height(), bckButton.height(), pixMap);

    //DD text.
    painter->setPen(Qt::blue);
    painter ->setFont(QFont("Times New Roman", 10, QFont::Bold));
    painter->drawText(ddButton, Qt::AlignCenter, tr("DD"));

    //OK text.
    painter->setPen(Qt::blue);
    painter ->setFont(QFont("Times New Roman", 10, QFont::Bold));
    painter->drawText(okButton, Qt::AlignCenter, tr("OK"));

    QGraphicsWidget::paint(painter, option, widget);
}

void CBottomInfoPlayShow::setButtonIds(int fwdButtonId, int bckButtonId, int ddButtonId, int okButtonId)
{
    this->fwdButtonId = fwdButtonId;
    this->bckButtonId = bckButtonId;
    this->ddButtonId = ddButtonId;
    this->okButtonId = okButtonId;
}

void CBottomInfoPlayShow::setFwdEnabled(bool enabled)
{
    fwdEnabled = enabled;
    update();
}

bool CBottomInfoPlayShow::isFwdEnabled()
{
    return fwdEnabled;
}

void CBottomInfoPlayShow::setBckEnabled(bool enabled)
{
    bckEnabled = enabled;
    update();
}

bool CBottomInfoPlayShow::isBckEnabled()
{
    return bckEnabled;
}

void CBottomInfoPlayShow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (fwdButton.contains(event->pos()) && fwdEnabled)
            fwdPressed = true;
        else if (bckButton.contains(event->pos()) && bckEnabled)
            bckPressed = true;
        else if (ddButton.contains(event->pos()) && ddEnabled)
            ddPressed = true;
        else if (okButton.contains(event->pos()) && okEnabled)
            okPressed = true;

        update();
    }

    QGraphicsWidget::mousePressEvent(event);
}

/**
 * @brief Generates a BUTTON_CLICKED_Event for the left mouse button.
 * @param event The event
 *
 * The event is sent to the receiver.
 */
void CBottomInfoPlayShow::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        int buttonId = (fwdPressed && fwdEnabled) ? (fwdButtonId) :
                       (bckPressed && bckEnabled) ? (bckButtonId) :
                       (ddPressed && ddEnabled) ? (ddButtonId) :
                       (okPressed && okEnabled) ? (okButtonId) : -1;
        if (buttonId != -1)
        {
            fwdPressed = bckPressed = ddPressed = okPressed = false;
            update();
            BUTTON_CLICKED_Event *buttonClickedEvent = new BUTTON_CLICKED_Event(buttonId);
            QApplication::postEvent(buttonSignal, buttonClickedEvent);
        }
    }

    QGraphicsItem::mouseReleaseEvent(event);
}
