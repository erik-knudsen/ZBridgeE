/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMainFrameMenuEnables.cpp
  Developers: eak

  Revision History:
  8-apr-2018 eak: Original

  Abstract: Enables for main frame menu entries.

  Platforms: Qt.

*/

/**
 * @file
 * Enables for main frame menu entries (definition).
 */

#include "cmainframemenuenables.h"

CMainFrameMenuEnables::CMainFrameMenuEnables()
{
    actionSaveEnabled = false;
    actionSave_AsEnabled = false;
    actionDeleteEnabled = false;
    action_Deal_New_HandEnabled = false;
    action_Bid_RebidEnabled = false;
    action_Restart_HandEnabled = false;
    action_Expose_All_CardsEnabled = false;
    actionDouble_Dummy_ResultsEnabled = false;
    action_ScoreEnabled = false;
    actionOpenEnabled = false;
    actionActivate_Deal_ProfileChecked = false;
    action_Expose_All_CardsChecked = false;
}
