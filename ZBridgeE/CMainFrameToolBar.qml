/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMainFrameToolBar.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Main frame toolbar.

  Platforms: Qt/QML.
*/
import QtQuick.Controls 2.3
import QtQuick 2.7

Item {
    id: item1
    signal on_actionNew_Session_triggered()
    signal on_actionUndo_triggered()
    signal on_actionHint_triggered()
    signal on_showMenu_triggered()

    height: toolBar.height
    width: 300

    Action {
        id: actionNew_Session
        text: qsTr("New Session")
//        icon.source: "qrc:///resources/ManualDefend.bmp"
        onTriggered: on_actionNew_Session_triggered()
    }
    Action {
        id: actionUndo
        text: qsTr("Undo")
//        icon.source: "qrc:///resources/EDITUNDO.BMP"
        onTriggered: on_actionUndo_triggered()
    }
    Action {
        id: actionHint
        text: qsTr("Hint")
//        icon.source: "qrc:///resources/HelpAppAbout.bmp"
        onTriggered: on_actionHint_triggered()
    }
    Action {
        id: actionMenu
        text: qsTr("Menu")
//        icon.source: "qrc:///resources/menu.png"
        onTriggered: on_showMenu_triggered()
    }

    ToolBar {
        id: toolBar
        height: 80
        spacing: 15
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        ToolButton {
            id: newSession
            height: 80
            width: 80
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            action: actionNew_Session
//            icon.color: "transparent"
            display: AbstractButton.IconOnly
            Image {
                anchors.rightMargin: 5
                anchors.leftMargin: 5
                anchors.bottomMargin: 5
                anchors.topMargin: 5
                anchors.fill: parent
                source: "resources/ManualDefend.bmp"
            }
        }
        ToolButton {
            id: undo
            height: 80
            width: 80
            anchors.left: newSession.right
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            action: actionUndo
//            icon.color: "transparent"
            display: AbstractButton.IconOnly
            Image {
                anchors.rightMargin: 5
                anchors.leftMargin: 5
                anchors.bottomMargin: 5
                anchors.topMargin: 5
                anchors.fill: parent
                source: "resources/EDITUNDO.BMP"
            }
        }
        ToolButton {
            id: hint
            height: 80
            width: 80
            anchors.left: undo.right
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            action: actionHint
//            icon.color: "transparent"
            display: AbstractButton.IconOnly
            Image {
                anchors.rightMargin: 5
                anchors.leftMargin: 5
                anchors.bottomMargin: 5
                anchors.topMargin: 5
                anchors.fill: parent
                source: "resources/HelpAppAbout.bmp"
            }
        }
        ToolButton {
            id: menu
            height: 80
            width: 80
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            action: actionMenu
//            icon.color: "transparent"
            display: AbstractButton.IconOnly
                Image {
                    anchors.rightMargin: 5
                    anchors.leftMargin: 5
                    anchors.bottomMargin: 5
                    anchors.topMargin: 5
                    anchors.fill: parent
                    source: "resources/menu.png"
                }
        }
    }

    function actionNew_SessionSetEnabled(enable)
    {
        actionNew_Session.enabled =enable
        if (enable)
            newSession.opacity = 1.0
        else
            newSession.opacity = 0.2
    }
    function actionUndoSetEnabled(enable)
    {
        actionUndo.enabled = enable
        if (enable)
            undo.opacity = 1.0
        else
            undo.opacity = 0.2
    }
    function actionHintSetEnabled(enable)
    {
        actionHint.enabled = enable
        if (enable)
            hint.opacity = 1.0
        else
            hint.opacity = 0.2
    }
}
