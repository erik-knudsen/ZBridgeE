/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBidOptions.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  23-dec-2018 eak: Use QML instead of widgets.

  Abstract: Select current bid option set (conventions etc.).

  Platforms: Qt.

*/

/**
 * \file
 * Select current bid option set (conventions etc.) (declaration).
 */

#ifndef CBIDOPTIONS_H
#define CBIDOPTIONS_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

class CZBridgeApp;
class CZBridgeDoc;
class CBidOptionDoc;

/**
 * @brief The class handles bid option sets.
 *
 *The class shows the Bid Options user interface.
 *   - Create a bid option set.
 *   - Delete a bid option set.
 *   - Select bid options for North/South and East/West.
 */
//class CBidOptions : public QDialog
class CBidOptions : public QWidget
{
    Q_OBJECT
    
public:
    explicit CBidOptions(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent);
    ~CBidOptions();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_northSouth_clicked();
    void on_eastWest_clicked();
    void on_northSouthConvention_currentIndexChanged(int index);
    void on_eastWestConvention_currentIndexChanged(int index);
    void on_newConvention_clicked();
    void on_editConvention_clicked();
    void on_DeleteConvention_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    CZBridgeApp *app;
    CZBridgeDoc *doc;
    int nsIndex, ewIndex;
    QString *curBidOption;
    QList<CBidOptionDoc> *bidOptions;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CBIDOPTIONS_H
