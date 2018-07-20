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
    width: 610
    height: 640
    property alias cardBack5: cardBack5
    property alias cardBack4: cardBack4
    property alias cardBack3: cardBack3
    property alias cardBack2: cardBack2
    property alias cardBack1: cardBack1
    property alias cardBack0: cardBack0
    property alias dialogButtonBox: dialogButtonBox

    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    ToolButton {
        id: cardBack0
        width: 200
        height: 240
        text: qsTr("")
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        checkable: true
        Image {
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            source: "resources/cardback1.png"
        }
    }

    ToolButton {
        id: cardBack1
        width: 200
        height: 240
        text: qsTr("")
        anchors.left: cardBack0.right
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        checkable: true
        Image {
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            source: "resources/cardback22.png"
        }
    }

    ToolButton {
        id: cardBack2
        width: 200
        height: 240
        text: qsTr("")
        anchors.left: cardBack1.right
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        checkable: true
        Image {
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            source: "resources/cardback3.png"
        }
    }

    ToolButton {
        id: cardBack3
        width: 200
        height: 240
        text: qsTr("")
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: cardBack0.bottom
        anchors.topMargin: 0
        checkable: true
        Image {
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            source: "resources/cardback5.png"
        }
    }

    ToolButton {
        id: cardBack4
        width: 200
        height: 240
        text: qsTr("")
        anchors.left: cardBack3.right
        anchors.leftMargin: 0
        anchors.top: cardBack1.bottom
        anchors.topMargin: 0
        checkable: true
        Image {
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            source: "resources/cardback11.png"
        }
    }

    ToolButton {
        id: cardBack5
        width: 200
        height: 240
        text: qsTr("")
        anchors.left: cardBack4.right
        anchors.leftMargin: 0
        anchors.top: cardBack2.bottom
        anchors.topMargin: 0
        checkable: true
        Image {
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            source: "resources/cardback2.png"
        }
    }

    Rectangle {
        id: footer
        anchors.top: cardBack4.bottom
        anchors.topMargin: 10
        width: parent.width
        height: 130
        DialogButtonBox {
            id: dialogButtonBox
            width: parent.width
            height: parent.height
            standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel
            font.pixelSize: fontPixelsize
        }
    }
}
