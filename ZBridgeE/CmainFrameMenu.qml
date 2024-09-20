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
import QtQuick.Controls
import QtQuick

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

    property int zf: 10

    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    height: fontPixelsize * 13
    width: 48 * fontPixelsize/2

    Action {
        id: actionOpen
        onTriggered: on_actionOpen_triggered()
    }
    Action {
        id: actionSave
        onTriggered: on_actionSave_triggered()
    }
    Action {
        id: actionSave_As
        onTriggered: on_actionSave_As_triggered()
    }
    Action {
        id: actionDelete
        onTriggered: on_actionDelete_triggered()
    }
    Action {
        id: actionExit
        onTriggered: on_hideMenu_triggered()
    }
    Action {
        id: action_Expose_All_Cards
        checkable: true
        text: qsTr("Expose All Cards")
        icon.source: "qrc:///resources/ExposeAllCards.bmp"
        onTriggered: on_action_Expose_All_Cards_triggered()
    }
    Action {
        id: action_Score
        onTriggered: on_action_Score_triggered()
    }
    Action {
        id: actionDouble_Dummy_Results
        onTriggered: on_actionDouble_Dummy_Results_triggered()
    }
    Action {
        id: action_Deal_New_Hand
        onTriggered: on_action_Deal_New_Hand_triggered()
    }
    Action {
        id: actionActivate_Deal_Profile
        checkable: true
        text: qsTr("Activate Deal Profile")
        onTriggered: on_actionActivate_Deal_Profile_triggered()
    }
    Action {
        id: action_Bid_Rebid
        onTriggered: on_action_Bid_Rebid_triggered()
    }
    Action {
        id: action_Restart_Hand
        onTriggered: on_action_Restart_Hand_triggered()
    }
    Action {
        id: actionSeat_Configuration
        onTriggered: on_actionSeat_Configuration_triggered()
    }
    Action {
        id: action_Bidding_Options
        onTriggered: on_action_Bidding_Options_triggered()
    }
    Action {
        id: action_Deal_Options
        onTriggered: on_action_Deal_Options_triggered()
    }
    Action {
        id: action_Di_splay_Options
        onTriggered: on_action_Di_splay_Options_triggered()
    }
    Action {
        id: action_Game_Options
        onTriggered: on_action_Game_Options_triggered()
    }
    Action {
        id: action_Contents
        onTriggered: on_action_Contents_triggered()
    }
    Action {
        id: action_About_ZBridge
        onTriggered: on_action_About_ZBridge_triggered()
    }

    MenuBar {
        id: menuBar
        anchors.right: parent.right
        anchors.rightMargin: 0 * zf
        anchors.left: parent.left
        anchors.leftMargin: 0 * zf
        anchors.top: parent.top
        anchors.topMargin: 0 * zf
        font.family: fontFamily
        font.pixelSize: fontPixelsize
        Menu {
            title: qsTr("File")
            width: 14 * fontPixelsize/2+10
            height: 10 * fontPixelsize
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Open...")
                icon.source: "qrc:///resources/FILEOPEN.BMP"
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionOpen
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Save...")
                icon.source: "qrc:///resources/FILESAVE.BMP"
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionSave
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Save As...")
                icon.color: "transparent"
                action: actionSave_As
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Delete")
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionDelete
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Exit Menu")
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionExit
            }
        }
        Menu {
            title: qsTr("View")
            width: 25 * fontPixelsize/2
            height: 7 * fontPixelsize
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Expose_All_Cards
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Score...")
                icon.source: "qrc:///resources/ViewScore.bmp"
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Score
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Double Dummy...")
                icon.source: "qrc:///resources/ViewPlayHistory.bmp"
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionDouble_Dummy_Results
            }
        }
        Menu {
            title: qsTr("Game")
            width: 25 * fontPixelsize/2
            height: 9 * fontPixelsize
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Deal New Hand")
                icon.source: "qrc:///resources/DealNewHand.bmp"
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Deal_New_Hand
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionActivate_Deal_Profile
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Rebid")
                icon.source: "qrc:///resources/BidHand.bmp"
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Bid_Rebid
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Replay")
                icon.source: "qrc:///resources/RestartPlay.bmp"
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Restart_Hand
            }
        }
        Menu {
            title: qsTr("Options")
            width: 23 * fontPixelsize/2
            height: 10 * fontPixelsize
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Seat Configuration...")
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: actionSeat_Configuration
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Bidding/Play...")
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Bidding_Options
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Deal...")
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Deal_Options
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Display Options...")
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Di_splay_Options
            }
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Game...")
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Game_Options
            }
        }
        Menu {
            title: qsTr("About")
            width: 19 * fontPixelsize/2
            height: 5 * fontPixelsize
            MenuItem {
                height: 13 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("Contents")
                display: AbstractButton.TextBesideIcon
                icon.color: "transparent"
                action: action_Contents
            }
            MenuItem {
                height: 13 * zf
                display: AbstractButton.TextBesideIcon
                text: qsTr("About ZBridge")
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
    function setZoom(zoom)
    {
        zf = zoom
    }
}
