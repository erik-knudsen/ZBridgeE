/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMainFrameMenu.h
  Developers: eak

  Revision History:
  1-apr-2018 eak: Original

  Abstract: Menu for main frame

  Platforms: Qt.

*/

/**
 * @file
 * Main frame menu (declaration).
 */

#ifndef CMAINFRAMEMENU_H
#define CMAINFRAMEMENU_H

#include <QDialog>
#include <QQuickWidget>
#include <QWidget>
#include <QEventLoop>

#include "cmainframemenuenables.h"
#include "defines.h"

class CMainFrameMenu : public QWidget
{
    Q_OBJECT

public:
    explicit CMainFrameMenu(CMainFrameMenuEnables &mainFrameMenuEnables, QWidget *parent = 0);
    ~CMainFrameMenu();

    void actionSaveSetEnabled(bool enable);
    void actionSave_AsSetEnabled(bool enable);
    void actionDeleteSetEnabled(bool enable);
    void action_Deal_New_HandSetEnabled(bool enable);
    void action_Bid_RebidSetEnabled(bool enable);
    void action_Restart_HandSetEnabled(bool enable);
    void action_Expose_All_CardsSetEnabled(bool enable);
    void actionDouble_Dummy_ResultsSetEnabled(bool enable);
    void action_ScoreSetEnabled(bool enable);
    void actionOpenSetEnabled(bool enable);
    void actionActivate_Deal_ProfileSetChecked(bool check);
    void action_Expose_All_CardsSetChecked(bool check);

    bool actionSaveGetEnabled();
    bool actionActivate_Deal_ProfileGetChecked();
    bool action_Expose_All_CardsGetChecked();

    MenuAction getMenuChoice() { return menuChoice; }

    int exec();

protected:
    void closeEvent(QCloseEvent *event);


private slots:
    void on_actionOpen_triggered_S();
    void on_actionSave_triggered_S();
    void on_actionSave_As_triggered_S();
    void on_actionDelete_triggered_S();

    void on_action_Expose_All_Cards_triggered_S();
    void on_action_Score_triggered_S();
    void on_actionDouble_Dummy_Results_triggered_S();

    void on_actionNew_Session_triggered_S();
    void on_action_Deal_New_Hand_triggered_S();
    void on_actionActivate_Deal_Profile_triggered_S();
    void on_actionUndo_triggered_S();
    void on_action_Bid_Rebid_triggered_S();
    void on_action_Restart_Hand_triggered_S();
    void on_actionHint_triggered_S();

    void on_actionSeat_Configuration_triggered_S();
    void on_action_Bidding_Options_triggered_S();
    void on_action_Deal_Options_triggered_S();
    void on_action_Di_splay_Options_triggered_S();
    void on_action_Game_Options_triggered_S();

    void on_action_Contents_triggered_S();
    void on_action_About_ZBridge_triggered_S();

public slots:
    void on_hideMenu_triggered_S();

private:
    QQuickWidget *pMenuWidget;
    MenuAction menuChoice;

    QEventLoop eventLoop;
};

#endif // CMAINFRAMEMENU_H
