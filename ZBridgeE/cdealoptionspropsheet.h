/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CDealOptionsPropSheet.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  9-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Property sheet for determining deal options.

  Platforms: Qt.

*/

/**
 * \file
 * Property sheet for determining deal options (declaration).
 */

#ifndef CDEALOPTIONSPROPSHEET_H
#define CDEALOPTIONSPROPSHEET_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

#include "cdealoptiondoc.h"

class CZBridgeApp;
class CZBridgeDoc;

/**
 * @brief Deal option property sheet.
 *
 * This class shows the deal option property sheet and allows the user to set/change the deal options.
 */
class CDealOptionsPropSheet : public QWidget
{
    Q_OBJECT
    
public:
    explicit CDealOptionsPropSheet(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent = 0);
    ~CDealOptionsPropSheet();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:    
    void on_ok_clicked();
    void on_cancel_clicked();
    void on_hcp_editingFinished(int suit, int seat);
    void on_suitSize_editingFinished(int suit, int seat);
    void on_dp_editingFinished(int seat);
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    bool getValues(QString &text, int max, int *low, int *high);

    CZBridgeApp *app;
    CZBridgeDoc *doc;
    CDealOptionDoc dealOptionDoc;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CDEALOPTIONSPROPSHEET_H
