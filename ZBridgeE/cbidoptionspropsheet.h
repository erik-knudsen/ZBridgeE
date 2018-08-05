/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBidOptionsPropSheet.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  6-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Property sheet for selecting bid options.

  Platforms: Qt.

*/

/**
 * \file
 * Property sheet for selecting bid options.
 */

#ifndef CBIDOPTIONSPROPSHEET_H
#define CBIDOPTIONSPROPSHEET_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

#include "cbidoptiondoc.h"

class CZBridgeApp;
class CZBridgeDoc;

/**
 * @brief Property sheet for selecting bid options.
 */
class CBidOptionsPropSheet : public QWidget
{
    Q_OBJECT
    
public:
    explicit CBidOptionsPropSheet(CBidOptionDoc &bidOption, CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent = 0);
    ~CBidOptionsPropSheet();

    CBidOptionDoc &getBidOption() { return bidOptionDoc; }

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    //--------------------Bidding and Play Conventions.--------------------------

    //General configuration.
    void on_americanStyle_clicked();
    void on_europeanStyle_clicked();
    void on_majorFour_clicked();
    void on_majorFive_clicked();
    void on_stayman_clicked(bool checked);
    void on_jacobyTransfers_clicked(bool checked);
    void on_limitRaises_clicked(bool checked);

    //2-Bids configuration.
    void on_weakTwo_clicked(bool checked);    

    //NT Range configuration. configuration.
    void on_oneNTRange12_14_clicked();
    void on_oneNTRange15_17_clicked();
    void on_open1NTWeakMajor_clicked(bool checked);

    //Misc. configuration.
    void on_structuredReverses_clicked(bool checked);
    void on_takeOutDoubles_clicked(bool checked);
    void on_negativeDoubles_clicked(bool checked);
    void on_michaelsCueBid_clicked(bool checked);
    void on_unusualNT_clicked(bool checked);
    void on_jumpOvercallWeak_clicked(bool checked);   

    void on_ok_clicked();
    void on_cancel_clicked();

    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    void setDependencies();

    CZBridgeApp *app;
    CZBridgeDoc *doc;
    CBidOptionDoc bidOptionDoc;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CBIDOPTIONSPROPSHEET_H
