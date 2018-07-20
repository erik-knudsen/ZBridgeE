/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMainFrameMenuEnables.h
  Developers: eak

  Revision History:
  8-apr-2018 eak: Original

  Abstract: Enables for main frame menu entries.

  Platforms: Qt.

*/

/**
 * @file
 * Enables for main frame menu entries (declaration).
 */

#ifndef CMAINFRAMEMENUENABLES_H
#define CMAINFRAMEMENUENABLES_H


class CMainFrameMenuEnables
{
public:
    CMainFrameMenuEnables();

    void actionSaveSetEnabled(bool enable) { actionSaveEnabled = enable; }
    bool actionSaveGetEnabled() { return actionSaveEnabled; }
    void actionSave_AsSetEnabled(bool enable) { actionSave_AsEnabled = enable; }
    bool actionSave_AsGetEnabled() { return actionSave_AsEnabled; }
    void actionDeleteSetEnabled(bool enable) { actionDeleteEnabled = enable; }
    bool actionDeleteGetEnabled() { return actionDeleteEnabled; }
    void action_Deal_New_HandSetEnabled(bool enable) { action_Deal_New_HandEnabled = enable; }
    bool action_Deal_New_HandGetEnabled() { return action_Deal_New_HandEnabled; }
    void action_Bid_RebidSetEnabled(bool enable) { action_Bid_RebidEnabled = enable; }
    bool action_Bid_RebidGetEnabled() { return action_Bid_RebidEnabled; }
    void action_Restart_HandSetEnabled(bool enable) { action_Restart_HandEnabled = enable; }
    bool action_Restart_HandGetEnabled() { return action_Restart_HandEnabled; }
    void action_Expose_All_CardsSetEnabled(bool enable) { action_Expose_All_CardsEnabled = enable; }
    bool action_Expose_All_CardsGetEnabled() { return action_Expose_All_CardsEnabled; }
    void actionDouble_Dummy_ResultsSetEnabled(bool enable) { actionDouble_Dummy_ResultsEnabled = enable; }
    bool actionDouble_Dummy_ResultsGetEnabled() { return actionDouble_Dummy_ResultsEnabled; }
    void action_ScoreSetEnabled(bool enable) { action_ScoreEnabled = enable; }
    bool action_ScoreGetEnabled() { return action_ScoreEnabled; }
    void actionOpenSetEnabled(bool enable) { actionOpenEnabled = enable; }
    bool actionOpenGetEnabled() { return actionOpenEnabled; }
    void actionActivate_Deal_ProfileSetChecked(bool check) { actionActivate_Deal_ProfileChecked = check; }
    bool actionActivate_Deal_ProfileGetChecked() { return actionActivate_Deal_ProfileChecked; }
    void action_Expose_All_CardsSetChecked(bool check) { action_Expose_All_CardsChecked = check; }
    bool action_Expose_All_CardsGetChecked() { return action_Expose_All_CardsChecked; }

private:
    bool actionSaveEnabled;
    bool actionSave_AsEnabled;
    bool actionDeleteEnabled;
    bool action_Deal_New_HandEnabled;
    bool action_Bid_RebidEnabled;
    bool action_Restart_HandEnabled;
    bool action_Expose_All_CardsEnabled;
    bool actionDouble_Dummy_ResultsEnabled;
    bool action_ScoreEnabled;
    bool actionOpenEnabled;
    bool actionActivate_Deal_ProfileChecked;
    bool action_Expose_All_CardsChecked;
};

#endif // CMAINFRAMEMENUENABLES_H
