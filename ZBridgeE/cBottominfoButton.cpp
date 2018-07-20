/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBottomInfoButton.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original

  Abstract: Button for bottom info auction widget.

  Platforms: Qt.

*/

/**
 * \file
 * Button for bottom info auction widget (definition).
 */

#include <QApplication>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "defines.h"
#include "cbottominfobutton.h"

CBottomInfoButton::CBottomInfoButton(int horSize, int verSize, QString text,
                                                   QGraphicsWidget *parent) :
    QGraphicsWidget(parent)
{
    this->horSize = horSize;
    this->verSize = verSize;
    this->text = text;

    setFlag(QGraphicsItem::ItemIsSelectable);

    buttonSignal = 0;
    pressed = false;
}

QRectF CBottomInfoButton::boundingRect() const
{
    return QRectF(0, 0, horSize, verSize);
}

void CBottomInfoButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::green);
    if (pressed)
    {
        brush.setColor(Qt::darkGray);
    }
    else
    {
        brush.setColor(Qt::lightGray);
    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);

    painter->setPen(Qt::blue);
    QFont font("MS Shell Dlg 2");
    font.setPixelSize(30);
    font.setBold(true);
    painter->setFont(font);
    painter->drawText(rec, Qt::AlignCenter, text);

    QGraphicsWidget::paint(painter, option, widget);
}

void CBottomInfoButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        pressed = true;
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
void CBottomInfoButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        pressed = false;
        update();
        BUTTON_CLICKED_Event *buttonClickedEvent = new BUTTON_CLICKED_Event(buttonId);
        QApplication::postEvent(buttonSignal, buttonClickedEvent);
    }

    QGraphicsItem::mouseReleaseEvent(event);
}
