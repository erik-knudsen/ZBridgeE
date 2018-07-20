/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CDisplayOptionsPropSheet.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  12-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Property sheet for determining display options.

  Platforms: Qt.

*/

/**
 * \file
 * Property sheet for determining display options (declaration).
 */

#ifndef CDISPOPTIONSPROPSHEET_H
#define CDISPOPTIONSPROPSHEET_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

#include "cdisplayoptiondoc.h"

class CZBridgeApp;
class CZBridgeDoc;

/**
 * @brief Display option property sheet.
 *
 * This class allows the user to set/change the display options.
 */
class CDispOptionsPropSheet : public QWidget
{
    Q_OBJECT
    
public:
    explicit CDispOptionsPropSheet(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent = 0);
    ~CDispOptionsPropSheet();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_cardBack0_clicked();
    void on_cardBack1_clicked();
    void on_cardBack2_clicked();
    void on_cardBack3_clicked();
    void on_cardBack4_clicked();
    void on_cardBack5_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:   
    CZBridgeApp *app;
    CZBridgeDoc *doc;
    CDisplayOptionDoc displayOptionDoc;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CDISPOPTIONSPROPSHEET_H
