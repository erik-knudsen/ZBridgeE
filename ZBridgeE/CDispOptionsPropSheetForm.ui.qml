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
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: item1

    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 90 * zf
    height: 85 * zf

    property alias cardBack5: cardBack5
    property alias cardBack4: cardBack4
    property alias cardBack3: cardBack3
    property alias cardBack2: cardBack2
    property alias cardBack1: cardBack1
    property alias cardBack0: cardBack0
    property alias ok: ok
    property alias cancel: cancel


    GridLayout {
        id: grid
        rows: 2
        columns: 3

    ToolButton {
        id: cardBack0
        Layout.preferredWidth: 25 * zf
        Layout.preferredHeight: 30 * zf
        text: qsTr("")
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback1.png"
        }
        background: Rectangle {
            color: "#33333333"
            visible: cardBack0.checked
        }
    }

    ToolButton {
        id: cardBack1
        Layout.preferredWidth: 25 * zf
        Layout.preferredHeight: 30 * zf
        text: qsTr("")
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback22.png"
        }
        background: Rectangle {
            color: "#33333333"
            visible: cardBack1.checked
        }
    }

    ToolButton {
        id: cardBack2
        Layout.preferredWidth: 25 * zf
        Layout.preferredHeight: 30 * zf
        text: qsTr("")
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback3.png"
        }
        background: Rectangle {
            color: "#33333333"
            visible: cardBack2.checked
        }
    }

    ToolButton {
        id: cardBack3
        Layout.preferredWidth: 25 * zf
        Layout.preferredHeight: 30 * zf
        text: qsTr("")
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback5.png"
        }
        background: Rectangle {
            color: "#33333333"
            visible: cardBack3.checked
        }
    }

    ToolButton {
        id: cardBack4
        Layout.preferredWidth: 25 * zf
        Layout.preferredHeight: 30 * zf
        text: qsTr("")
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback11.png"
        }
        background: Rectangle {
            color: "#33333333"
            visible: cardBack4.checked
        }
    }

    ToolButton {
        id: cardBack5
        Layout.preferredWidth: 25 * zf
        Layout.preferredHeight: 30 * zf
        text: qsTr("")
        checkable: true
        Image {
            anchors.rightMargin: 2 * zf
            anchors.leftMargin: 2 * zf
            anchors.bottomMargin: 2 * zf
            anchors.topMargin: 2 * zf
            anchors.fill: parent
            source: "resources/cardback2.png"
        }
        background: Rectangle {
            color: "#33333333"
            visible: cardBack5.checked
        }
    }
    }

    RowLayout
    {
        id: okBox
        anchors.top: grid.bottom
        anchors.topMargin: 4 *zf
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 1 * zf

        Button {
            id: ok
            Layout.preferredWidth: 12 * fontPixelsize/2
            text: qsTr("OK")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
        }

        Button {
            id: cancel
            Layout.preferredWidth: 12 * fontPixelsize/2
            text: qsTr("Cancel")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
        }
    }
}
