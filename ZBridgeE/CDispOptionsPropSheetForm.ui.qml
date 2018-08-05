/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CDispOptionsPropSheetForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Display options property sheet UI form.

  Platforms: Qt/QML.
*/
import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: item1

    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 61 * zf
    height: 64 * zf
    property alias cardBack5: cardBack5
    property alias cardBack4: cardBack4
    property alias cardBack3: cardBack3
    property alias cardBack2: cardBack2
    property alias cardBack1: cardBack1
    property alias cardBack0: cardBack0
    property alias ok: ok
    property alias cancel: cancel

    ToolButton {
        id: cardBack0
        width: 20 * zf
        height: 24 * zf
        text: qsTr("")
        anchors.left: parent.left
        anchors.leftMargin: 0 * zf
        anchors.top: parent.top
        anchors.topMargin: 0 * zf
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback1.png"
        }
    }

    ToolButton {
        id: cardBack1
        width: 20 * zf
        height: 24 * zf
        text: qsTr("")
        anchors.left: cardBack0.right
        anchors.leftMargin: 0 * zf
        anchors.top: parent.top
        anchors.topMargin: 0 * zf
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback22.png"
        }
    }

    ToolButton {
        id: cardBack2
        width: 20 * zf
        height: 24 * zf
        text: qsTr("")
        anchors.left: cardBack1.right
        anchors.leftMargin: 0 * zf
        anchors.top: parent.top
        anchors.topMargin: 0 * zf
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback3.png"
        }
    }

    ToolButton {
        id: cardBack3
        width: 20 * zf
        height: 24 * zf
        text: qsTr("")
        anchors.left: parent.left
        anchors.leftMargin: 0 * zf
        anchors.top: cardBack0.bottom
        anchors.topMargin: 0 * zf
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback5.png"
        }
    }

    ToolButton {
        id: cardBack4
        width: 20 * zf
        height: 24 * zf
        text: qsTr("")
        anchors.left: cardBack3.right
        anchors.leftMargin: 0 * zf
        anchors.top: cardBack1.bottom
        anchors.topMargin: 0 * zf
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback11.png"
        }
    }

    ToolButton {
        id: cardBack5
        width: 20 * zf
        height: 24 * zf
        text: qsTr("")
        anchors.left: cardBack4.right
        anchors.leftMargin: 0 * zf
        anchors.top: cardBack2.bottom
        anchors.topMargin: 0 * zf
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback2.png"
        }
    }

    Row
    {
        id: okBox
        anchors.top: cardBack4.bottom
        anchors.topMargin: 4 *zf
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 1 * zf

        Button {
            id: ok
            width: 10 * fontPixelsize/2
            text: qsTr("OK")
            font.pixelSize: fontPixelsize
        }

        Button {
            id: cancel
            width: 10 * fontPixelsize/2
            text: qsTr("Cancel")
            font.pixelSize: fontPixelsize
        }
    }
}
