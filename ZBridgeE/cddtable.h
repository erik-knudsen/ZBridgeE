/*Erik Aagaard Knudsen.
  Copyright © 2016 - All Rights Reserved

  Project: ZBridge
  File: CDDTable.h
  Developers: eak

  Revision History:
  14-jan-2016 eak: Original
  15-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Calculate and show double dummy results and par.

  Platforms: Qt.

*/

/**
 * \file
 * Calculate and show double dummy results and par(declaration).
 */

#ifndef CDDTABLE_H
#define CDDTABLE_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

#include "Defines.h"

class CDDTable : public QWidget
{
    Q_OBJECT

public:
    explicit CDDTable(int cards[][13], Seat dealer, Team vulnerable, QWidget *parent = 0);
    ~CDDTable();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_OKButton_Clicked();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:    

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CDDTABLE_H
