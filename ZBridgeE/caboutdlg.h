/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CAboutDlg.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  17-jan-2018 eak: Use QML instead of Widgets.

  Abstract: About dialog.

  Platforms: Qt.

*/

/**
 * @file About dialog (declaration).
 * About dialog (declaration).
 */

#ifndef CABOUTDLG_H
#define CABOUTDLG_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

class CZBridgeApp;
class CZBridgeDoc;

/**
 * @brief About dialog
 *
 * Version, copyright etc. are shown in the dialog.
 */
class CAboutDlg : public QWidget
{
    Q_OBJECT

public:
    explicit CAboutDlg(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent = 0);
    ~CAboutDlg();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_OKButton_Clicked();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    CZBridgeApp *app;
    CZBridgeDoc *doc;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CABOUTDLG_H
