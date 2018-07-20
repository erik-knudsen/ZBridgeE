/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMainFrameMenu.cpp
  Developers: eak

  Revision History:
  1-apr-2018 eak: Original

  Abstract: Menu for main frame

  Platforms: Qt.

*/

/**
 * @file
 * Main frame menu (definition).
 */

#include <QHBoxLayout>
#include <QQuickItem>

#include "cmainframemenu.h"

CMainFrameMenu::CMainFrameMenu(CMainFrameMenuEnables &mainFrameMenuEnables, QWidget *parent) :
    QWidget(parent)
{    
    //Initialize with QML mainframe menu.
    pMenuWidget = new QQuickWidget();
    pMenuWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    pMenuWidget->setSource(QUrl("qrc:///CMainFrameMenu.qml"));

    //Initialize main frame menu entries.
    actionSaveSetEnabled(mainFrameMenuEnables.actionSaveGetEnabled());
    actionSave_AsSetEnabled(mainFrameMenuEnables.actionSave_AsGetEnabled());
    actionDeleteSetEnabled(mainFrameMenuEnables.actionDeleteGetEnabled());
    action_Deal_New_HandSetEnabled(mainFrameMenuEnables.action_Deal_New_HandGetEnabled());
    action_Bid_RebidSetEnabled(mainFrameMenuEnables.action_Bid_RebidGetEnabled());
    action_Restart_HandSetEnabled(mainFrameMenuEnables.action_Restart_HandGetEnabled());
    action_Expose_All_CardsSetEnabled(mainFrameMenuEnables.action_Expose_All_CardsGetEnabled());
    actionDouble_Dummy_ResultsSetEnabled(mainFrameMenuEnables.actionDouble_Dummy_ResultsGetEnabled());
    action_ScoreSetEnabled(mainFrameMenuEnables.action_ScoreGetEnabled());
    actionOpenSetEnabled(mainFrameMenuEnables.actionOpenGetEnabled());
    actionActivate_Deal_ProfileSetChecked(mainFrameMenuEnables.actionActivate_Deal_ProfileGetChecked());
    action_Expose_All_CardsSetChecked(mainFrameMenuEnables.action_Expose_All_CardsGetChecked());

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pMenuWidget);

    QObject *pMenuObject = pMenuWidget->rootObject();

    connect(pMenuObject, SIGNAL(on_hideMenu_triggered()), this, SLOT(on_hideMenu_triggered_S()));
    connect(pMenuObject, SIGNAL(on_actionOpen_triggered()), this, SLOT(on_actionOpen_triggered_S()));
    connect(pMenuObject, SIGNAL(on_actionSave_triggered()), this, SLOT(on_actionSave_triggered_S()));
    connect(pMenuObject, SIGNAL(on_actionSave_As_triggered()), this, SLOT(on_actionSave_As_triggered_S()));
    connect(pMenuObject, SIGNAL(on_actionDelete_triggered()), this, SLOT(on_actionDelete_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Expose_All_Cards_triggered()), this, SLOT(on_action_Expose_All_Cards_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Score_triggered()), this, SLOT(on_action_Score_triggered_S()));
    connect(pMenuObject, SIGNAL(on_actionDouble_Dummy_Results_triggered()), this, SLOT(on_actionDouble_Dummy_Results_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Deal_New_Hand_triggered()), this, SLOT(on_action_Deal_New_Hand_triggered_S()));
    connect(pMenuObject, SIGNAL(on_actionActivate_Deal_Profile_triggered()), this, SLOT(on_actionActivate_Deal_Profile_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Bid_Rebid_triggered()), this, SLOT(on_action_Bid_Rebid_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Restart_Hand_triggered()), this, SLOT(on_action_Restart_Hand_triggered_S()));
    connect(pMenuObject, SIGNAL(on_actionSeat_Configuration_triggered()), this, SLOT(on_actionSeat_Configuration_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Bidding_Options_triggered()), this, SLOT(on_action_Bidding_Options_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Deal_Options_triggered()), this, SLOT(on_action_Deal_Options_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Di_splay_Options_triggered()), this, SLOT(on_action_Di_splay_Options_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Game_Options_triggered()), this, SLOT(on_action_Game_Options_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_Contents_triggered()), this, SLOT(on_action_Contents_triggered_S()));
    connect(pMenuObject, SIGNAL(on_action_About_ZBridge_triggered()), this, SLOT(on_action_About_ZBridge_triggered_S()));
}

CMainFrameMenu::~CMainFrameMenu()
{
}

void CMainFrameMenu::actionSaveSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "actionSaveSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::actionSave_AsSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "actionSave_AsSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::actionDeleteSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "actionDeleteSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::action_Deal_New_HandSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "action_Deal_New_HandSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::action_Bid_RebidSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "action_Bid_RebidSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::action_Restart_HandSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "action_Restart_HandSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::action_Expose_All_CardsSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "action_Expose_All_CardsSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::actionDouble_Dummy_ResultsSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "actionDouble_Dummy_ResultsSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::action_ScoreSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "action_ScoreSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::actionOpenSetEnabled(bool enable)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "actionOpenSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, enable));
}

void CMainFrameMenu::actionActivate_Deal_ProfileSetChecked(bool check)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "actionActivate_Deal_ProfileSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, check));
}

void CMainFrameMenu::action_Expose_All_CardsSetChecked(bool check)
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "action_Expose_All_CardsSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, check));
}

bool CMainFrameMenu::actionSaveGetEnabled()
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "actionSaveGetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue));

    return returnedValue.toBool();
}

bool CMainFrameMenu::actionActivate_Deal_ProfileGetChecked()
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "actionActivate_Deal_ProfileGetChecked",
            Q_RETURN_ARG(QVariant, returnedValue));

    return returnedValue.toBool();
}

bool CMainFrameMenu::action_Expose_All_CardsGetChecked()
{
    QObject *pMenuObject = pMenuWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMenuObject, "action_Expose_All_CardsGetChecked",
            Q_RETURN_ARG(QVariant, returnedValue));

    return returnedValue.toBool();
}

int CMainFrameMenu::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CMainFrameMenu::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CMainFrameMenu::on_actionOpen_triggered_S()
{
    menuChoice = ACTION_OPEN;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionSave_triggered_S()
{
    menuChoice = ACTION_SAVE;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionSave_As_triggered_S()
{
    menuChoice = ACTION_SAVE_AS;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionDelete_triggered_S()
{
    menuChoice = ACTION_DELETE;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Expose_All_Cards_triggered_S()
{
    menuChoice = ACTION_EXPOSE_ALL_CARDS;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Score_triggered_S()
{
    menuChoice = ACTION_SCORE;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionDouble_Dummy_Results_triggered_S()
{
    menuChoice = ACTION_DOUBLE_DUMMY_RESULTS;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionNew_Session_triggered_S()
{
    menuChoice = ACTION_NEW_SESSION;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Deal_New_Hand_triggered_S()
{
    menuChoice = ACTION_DEAL_NEW_HAND;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionActivate_Deal_Profile_triggered_S()
{
    menuChoice = ACTION_ACTIVATE_DEAL_PROFILE;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionUndo_triggered_S()
{
    menuChoice = ACTION_UNDO;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Bid_Rebid_triggered_S()
{
    menuChoice = ACTION_BID_REBID;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Restart_Hand_triggered_S()
{
    menuChoice = ACTION_RESTART_HAND;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionHint_triggered_S()
{
    menuChoice = ACTION_HINT;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_actionSeat_Configuration_triggered_S()
{
    menuChoice = ACTION_SEAT_CONFIGURATION;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Bidding_Options_triggered_S()
{
    menuChoice = ACTION_BIDDING_OPTIONS;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Deal_Options_triggered_S()
{
    menuChoice = ACTION_DEAL_OPTIONS;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Di_splay_Options_triggered_S()
{
    menuChoice = ACTION_DISPLAY_OPTIONS;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Game_Options_triggered_S()
{
    menuChoice = ACTION_GAME_OPTIONS;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_Contents_triggered_S()
{
    menuChoice = ACTION_CONTENTS;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_action_About_ZBridge_triggered_S()
{
    menuChoice = ACTION_ABOUT_ZBRIDGE;
    eventLoop.exit(QDialog::Accepted);
}

void CMainFrameMenu::on_hideMenu_triggered_S()
{
    eventLoop.exit(QDialog::Rejected);
}
