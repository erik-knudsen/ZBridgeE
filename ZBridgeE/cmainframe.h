/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CMainFrame.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  4-mar-2018 eak: Use QML instead of Widgets.

  Abstract: Mainframe

  Platforms: Qt.

*/

/**
 * \file
 * Mainframe.
 */

#ifndef CMAINFRAME_H
#define CMAINFRAME_H

#include <QMainWindow>
#include <QHostAddress>
#include <QSemaphore>
#include <QQuickWidget>

#include "cmainframemenuenables.h"
#include "cpopup.h"
#include "Defines.h"

class CZBridgeApp;
class CZBridgeDoc;
class CGamesDoc;
class CPlayView;
class CTblMngr;
class CTblMngrBase;
class CSeatConfiguration;
class CMainScoreDialog;
class CBidAndPlayEngines;
class CMainFrameMenu;

//Enums for initial enable/disable of menu items.
enum actionIndicator { INITIAL_ACTIONS, SERVER_ACTIONS, CLIENT_ACTIONS };


/**
 * @brief Main frame window. All other windows are controlled from this window.
 *
 */
class CMainFrame : public QMainWindow
{
    Q_OBJECT
    
public:
    static CMainFrame* Instance();
    explicit CMainFrame(CZBridgeApp *app, CZBridgeDoc *doc, CGamesDoc *games);
    ~CMainFrame();

    //Initial enable/disable for main menu.
    void enableUIActionsInitial();  //Server/client mode not determined yet.
    void enableUIActionsServer();   //Server mode.
    void enableUIActionsClient();   //Client mode.

signals:
    void sAutoQuit();
    void sNewSession();

public slots:
    void sStatusText(QString text);

private slots:
    void closeEvent(QCloseEvent *event);

protected:
    virtual void resizeEvent(QResizeEvent *resizeEvent);

private:
    QHostAddress getHostAddress(QString host);
    virtual void customEvent(QEvent *event);

    void enableUIActions(actionIndicator actions);
    void resetPlay();
    void open(QString &originalFileName);    

    CZBridgeApp *app;
    CZBridgeDoc *doc;
    CGamesDoc *games;
    CPlayView *playView;
    CTblMngr *tableManager;
    CTblMngrBase *tableManagerAuto;
    static CMainFrame* m_pInstance;

    CMainFrameMenuEnables mainFrameMenuEnables;
    CBidAndPlayEngines *bidAndPlayEngines;

    int eventIndex;             //PBN event index.
    QString fileName;           //PBN file name.
    QHostAddress hostAddress;
    QSemaphore sem1, sem2;

    bool scoreSelect;

    QQuickWidget *pToolBarWidget;
    CPopup *popup = 0;

private slots:
    //Menu actions.
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionDelete_triggered();

    void on_action_Expose_All_Cards_triggered();
    void on_action_Score_triggered();
    void on_actionDouble_Dummy_Results_triggered();

    void on_actionNew_Session_triggered();
    void on_action_Deal_New_Hand_triggered();
    void on_actionActivate_Deal_Profile_triggered();
    void on_actionUndo_triggered();
    void on_action_Bid_Rebid_triggered();
    void on_action_Restart_Hand_triggered();
    void on_actionHint_triggered();

    void on_actionSeat_Configuration_triggered();
    void on_action_Bidding_Options_triggered();
    void on_action_Deal_Options_triggered();
    void on_action_Di_splay_Options_triggered();
    void on_action_Game_Options_triggered();

    void on_action_Contents_triggered();
    void on_action_About_ZBridge_triggered();

    void on_showMenu_triggered();
};

#endif // CMAINFRAME_H
