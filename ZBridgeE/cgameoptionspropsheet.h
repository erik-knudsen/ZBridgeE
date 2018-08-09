/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CGameOptionsPropSheet.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  14-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Property sheet for determining game options.

  Platforms: Qt.

*/

/**
 * \file
 * Property sheet for determining game options (declaration).
 */

#ifndef CGAMEOPTIONSPROPSHEET_H
#define CGAMEOPTIONSPROPSHEET_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

#include "cgameoptiondoc.h"

class CZBridgeApp;
class CZBridgeDoc;

/**
 * @brief Game option property sheet.
 *
 * Shows the game option property sheet and allows the user to set/change the options.
 */
class CGameOptionsPropSheet : public QWidget
{
    Q_OBJECT
    
public:
    explicit CGameOptionsPropSheet(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent = 0);
    ~CGameOptionsPropSheet();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_ok_clicked();
    void on_cancel_clicked();
    void on_biddingPause_sliderMoved(int position);
    void on_playPause_sliderMoved(int position);
    void on_insertBiddingPause_clicked(bool checked);
    void on_insertPlayPause_clicked(bool checked);
    void on_teamsIMP_clicked();
    void on_duplicateMP_clicked();
    void on_RubberBridge_clicked();
    void on_practice_clicked();
    void on_level0_clicked();
    void on_level1_clicked();
    void on_level2_clicked();
    void on_level3_clicked();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:    
    CZBridgeApp *app;
    CZBridgeDoc *doc;
    CGameOptionDoc gameOptionDoc;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CGAMEOPTIONSPROPSHEET_H
