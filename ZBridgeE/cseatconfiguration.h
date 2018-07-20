/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CSeatConfiguration.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  19-dec-2017 eak: Use QML instead of Widgets.

  Abstract: Configuration of seats.

  Platforms: Qt.

*/

/**
 * \file
 * Configuration of seats (declaration).
 */

#ifndef CSEATCONFIGURATION_H
#define CSEATCONFIGURATION_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

#include "cseatoptiondoc.h"

class CZBridgeApp;
class CZBridgeDoc;

/**
 * @brief Seat option dialog.
 *
 * Shows the seat option dialog and allows the user to set/change the options.
 */
class CSeatConfiguration : public QWidget
{
    Q_OBJECT
    
public:
    explicit CSeatConfiguration(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent = 0);
    ~CSeatConfiguration();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_west_clicked();
    void on_north_clicked();
    void on_east_clicked();
    void on_south_clicked();
    void on_westActor_currentIndexChanged(int index);
    void on_northActor_currentIndexChanged(int index);
    void on_eastActor_currentIndexChanged(int index);
    void on_southActor_currentIndexChanged(int index);
    void on_role_currentIndexChanged(int index);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    void updateSeatAndActor();
    void updateHostAndPort();

    CZBridgeApp *app;
    CZBridgeDoc *doc;
    CSeatOptionDoc seatOptionDoc;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CSEATCONFIGURATION_H
