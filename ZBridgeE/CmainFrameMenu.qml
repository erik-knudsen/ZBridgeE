/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMainFrameMenu.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Main frame menu.

  Platforms: Qt/QML.
*/
import QtQuick.Controls 2.3
import QtQuick 2.7

Item {
    id: item1
    signal on_hideMenu_triggered()
    signal on_actionOpen_triggered()
    signal on_actionSave_triggered()
    signal on_actionSave_As_triggered()
    signal on_actionDelete_triggered()
    signal on_action_Expose_All_Cards_triggered()
    signal on_action_Score_triggered()
    signal on_actionDouble_Dummy_Results_triggered()
    signal on_action_Deal_New_Hand_triggered()
    signal on_actionActivate_Deal_Profile_triggered()
    signal on_action_Bid_Rebid_triggered()
    signal on_action_Restart_Hand_triggered()
    signal on_actionSeat_Configuration_triggered()
    signal on_action_Bidding_Options_triggered()
    signal on_action_Deal_Options_triggered()
    signal on_action_Di_splay_Options_triggered()
    signal on_action_Game_Options_triggered()
    signal on_action_Contents_triggered()
    signal on_action_About_ZBridge_triggered()

    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    height: 600
    width: 1100

    Action {
        id: actionOpen
        text: qsTr("Open...")
        icon.source: "qrc:///resources/FILEOPEN.BMP"
        onTriggered: on_actionOpen_triggered()
    }
    Action {
        id: actionSave
        text: qsTr("Save...")
        icon.source: "qrc:///resources/FILESAVE.BMP"
        onTriggered: on_actionSave_triggered()
    }
    Action {
        id: actionSave_As
        text: qsTr("Save As...")
        onTriggered: on_actionSave_As_triggered()
    }
    Action {
        id: actionDelete
        text: qsTr("Delete")
        onTriggered: on_actionDelete_triggered()
    }
    Action {
        id: actionExit
        text: qsTr("Exit Menu")
        onTriggered: on_hideMenu_triggered()
    }
    Action {
        id: action_Expose_All_Cards
        text: qsTr("Expose All Cards")
        icon.source: "qrc:///resources/ExposeAllCards.bmp"
        checkable: true
        onTriggered: on_action_Expose_All_Cards_triggered()
    }
    Action {
        id: action_Score
        text: qsTr("Score")
        icon.source: "qrc:///resources/ViewScore.bmp"
        onTriggered: on_action_Score_triggered()
    }
    Action {
        id: actionDouble_Dummy_Results
        text: qsTr("Double Dummy Results")
        icon.source: "qrc:///resources/ViewPlayHistory.bmp"
        onTriggered: on_actionDouble_Dummy_Results_triggered()
    }
    Action {
        id: action_Deal_New_Hand
        text: qsTr("Deal New Hand")
        icon.source: "qrc:///resources/DealNewHand.bmp"
        onTriggered: on_action_Deal_New_Hand_triggered()
    }
    Action {
        id: actionActivate_Deal_Profile
        text: qsTr("Activate Deal Profile")
        checkable: true
        onTriggered: on_actionActivate_Deal_Profile_triggered()
    }
    Action {
        id: action_Bid_Rebid
        text: qsTr("Rebid")
        icon.source: "qrc:///resources/BidHand.bmp"
        onTriggered: on_action_Bid_Rebid_triggered()
    }
    Action {
        id: action_Restart_Hand
        text: qsTr("Replay")
        icon.source: "qrc:///resources/RestartPlay.bmp"
        onTriggered: on_action_Restart_Hand_triggered()
    }
    Action {
        id: actionSeat_Configuration
        text: qsTr("Seat Configuration...")
        onTriggered: on_actionSeat_Configuration_triggered()
    }
    Action {
        id: action_Bidding_Options
        text: qsTr("Bidding/Play...")
        onTriggered: on_action_Bidding_Options_triggered()
    }
    Action {
        id: action_Deal_Options
        text: qsTr("Deal...")
        onTriggered: on_action_Deal_Options_triggered()
    }
    Action {
        id: action_Di_splay_Options
        text: qsTr("Display Options...")
        onTriggered: on_action_Di_splay_Options_triggered()
    }
    Action {
        id: action_Game_Options
        text: qsTr("Game...")
        onTriggered: on_action_Game_Options_triggered()
    }
    Action {
        id: action_Contents
        text: qsTr("Contents")
        onTriggered: on_action_Contents_triggered()
    }
    Action {
        id: action_About_ZBridge
        text: qsTr("About ZBridge")
        onTriggered: on_action_About_ZBridge_triggered()
    }

    MenuBar {
        id: menuBar
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        font.pixelSize: fontPixelsize
        Menu {
            title: qsTr("File")
            width: 400
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionOpen
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionSave
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionSave_As
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionDelete
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionExit
            }
        }
        Menu {
            title: qsTr("View")
            width: 750
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Expose_All_Cards
            }
            MenuItem {
                font.pixelSize: fontPixelsize
               display: AbstractButton.TextBesideIcon
               icon.color: "transparent"
                action: action_Score
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionDouble_Dummy_Results
            }
        }
        Menu {
            title: qsTr("Game")
            width: 700
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Deal_New_Hand
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionActivate_Deal_Profile
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Bid_Rebid
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Restart_Hand
            }
        }
        Menu {
            title: qsTr("Options")
            width: 700
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionSeat_Configuration
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Bidding_Options
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Deal_Options
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Di_splay_Options
            }
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Game_Options
            }
        }
        Menu {
            title: qsTr("About")
            width: 500
            MenuItem {
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Contents
            }
            MenuItem {
                display: AbstractButton.TextBesideIcon
                font.pixelSize: fontPixelsize
                icon.color: "transparent"
                action: action_About_ZBridge
            }
        }
    }

    function actionOpenSetEnabled(enable)
    {
        actionOpen.enabled = enable
    }
    function actionSaveSetEnabled(enable)
    {
        actionSave.enabled = enable
    }
    function actionSave_AsSetEnabled(enable)
    {
        actionSave_As.enabled = enable
    }
    function actionDeleteSetEnabled(enable)
    {
        actionDelete.enabled = enable
    }
    function action_Deal_New_HandSetEnabled(enable)
    {
        action_Deal_New_Hand.enabled = enable
    }
    function action_Bid_RebidSetEnabled(enable)
    {
        action_Bid_Rebid.enabled = enable
    }
    function action_Restart_HandSetEnabled(enable)
    {
        action_Restart_Hand.enabled = enable
    }
    function action_Expose_All_CardsSetEnabled(enable)
    {
        action_Expose_All_Cards.enabled = enable
    }
    function actionDouble_Dummy_ResultsSetEnabled(enable)
    {
        actionDouble_Dummy_Results.enabled = enable
    }
    function action_ScoreSetEnabled(enable)
    {
        action_Score.enabled = enable
    }
    function action_Expose_All_CardsSetChecked(check)
    {
        action_Expose_All_Cards.checked = check
    }
    function actionActivate_Deal_ProfileSetChecked(check)
    {
        actionActivate_Deal_Profile.checked = check
    }
    function actionSaveGetEnabled()
    {
        return actionSave.enabled
    }
    function action_Expose_All_CardsGetChecked()
    {
        return action_Expose_All_Cards.checked
    }
    function actionActivate_Deal_ProfileGetChecked()
    {
        return actionActivate_Deal_Profile.checked
    }
}
