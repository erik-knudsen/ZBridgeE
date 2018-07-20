/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBidOptionsForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Bid options UI form.

  Platforms: Qt/QML.
*/

import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: item1
    width: 750
    height: 800
    property alias newConvention: newConvention
    property alias ewModel: ewModel
    property alias nsModel: nsModel
    property alias buttonBox: buttonBox
    property alias deleteConvention: deleteConvention
    property alias editConvention: editConvention
    property alias eastWest: eastWest
    property alias northSouth: northSouth
    property alias eastWestConvention: eastWestConvention
    property alias northSouthConvention: northSouthConvention

    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    GroupBox {
        id: groupBox
        height: 350
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 20
        font.pixelSize: fontPixelsize
        title: qsTr("Convention")

        ComboBox {
            id: northSouthConvention
            height: 95
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.left: eastWest.right
            anchors.leftMargin: 20
            anchors.top: northSouth.top
            ListModel {
                id: nsModel
            }
            model: nsModel
        }

        ComboBox {
            id: eastWestConvention
            height: 95
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.left: eastWest.right
            anchors.leftMargin: 20
            anchors.top: eastWest.top
            ListModel {
                id: ewModel
            }
            model: ewModel
        }

        RadioButton {
            id: northSouth
            text: qsTr("N/S")
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 15
        }

        RadioButton {
            id: eastWest
            text: qsTr("E/W")
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: northSouth.bottom
            anchors.topMargin: 10
        }
    }

    Button {
        id: newConvention
        text: qsTr("New")
        anchors.left: parent.left
        anchors.leftMargin: 95
        anchors.top: groupBox.bottom
        anchors.topMargin: 60
        font.pixelSize: fontPixelsize
    }

    Button {
        id: editConvention
        text: qsTr("Edit")
        anchors.left: newConvention.right
        anchors.leftMargin: 20
        anchors.top: newConvention.top
        font.pixelSize: fontPixelsize
    }

    Button {
        id: deleteConvention
        text: qsTr("Delete")
        anchors.left: editConvention.right
        anchors.leftMargin: 20
        anchors.top: newConvention.top
        font.pixelSize: fontPixelsize
    }

    Rectangle {
        id: footer
        anchors.top: newConvention.bottom
        anchors.topMargin: 60
        width: parent.width
        height: 130
        DialogButtonBox {
            id: buttonBox
            width: parent.width
            height: parent.height
            standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel
            font.pixelSize: fontPixelsize
        }
    }
}
