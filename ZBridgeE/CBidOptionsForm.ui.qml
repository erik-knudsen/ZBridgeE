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

    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 100 * zf
    height: 87 * zf

    property alias northSouth: northSouth
    property alias northSouthConvention: northSouthConvention
    property alias nsModel: nsModel
    property alias eastWest: eastWest
    property alias eastWestConvention: eastWestConvention
    property alias ewModel: ewModel
    property alias newConvention: newConvention
    property alias editConvention: editConvention
    property alias deleteConvention: deleteConvention
    property alias ok: ok
    property alias cancel: cancel

    GroupBox {
        id: groupBox
        height: 45 * zf
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: parent.top
        anchors.topMargin: 2 * zf
        font.pixelSize: fontPixelsize
        title: qsTr("Convention")

        Grid
        {
            rows: 2
            columns: 2
            spacing: 5 * zf
            anchors.horizontalCenter: parent.horizontalCenter

            RadioButton {
                id: northSouth
                text: qsTr("N/S")
            }

            ComboBox {
                id: northSouthConvention
                width: 12 * fontPixelsize/2
                height: 9 * zf
                ListModel {
                    id: nsModel
                }
                model: nsModel
            }

            RadioButton {
                id: eastWest
                text: qsTr("E/W")
            }

            ComboBox {
                id: eastWestConvention
                width: 12 * fontPixelsize/2
                height: 9 * zf
                ListModel {
                    id: ewModel
                }
                model: ewModel
            }
        }
    }

    Row
    {
        id: rowLine
        anchors.top: groupBox.bottom
        anchors.topMargin: 6 *zf
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 1 * zf

        Button {
            id: newConvention
            width: 8 * fontPixelsize/2
            text: qsTr("New")
            font.pixelSize: fontPixelsize
        }

        Button {
            id: editConvention
            width: 8 * fontPixelsize/2
            text: qsTr("Edit")
            font.pixelSize: fontPixelsize
        }

        Button {
            id: deleteConvention
            width: 8 * fontPixelsize/2
            text: qsTr("Delete")
            font.pixelSize: fontPixelsize
        }
    }

    Row
    {
        id: okBox
        anchors.top: rowLine.bottom
        anchors.topMargin: 6 *zf
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
