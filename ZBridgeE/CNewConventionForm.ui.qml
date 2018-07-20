/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CNewConventionForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Define new (bridge) convention UI form.

  Platforms: Qt/QML.
*/
import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: item1
    width: 1320
    height: 450
    property alias newConvention: newConvention
    property alias refConvention: refConvention
    property alias buttonBox: buttonBox

    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    Text {
        id: title
        anchors.top: parent.top
        anchors.topMargin: 0
        width: parent.width
        font.pixelSize: fontPixelsize
    }

    Grid {
        id: grid
        rows: 2
        columns: 2
        anchors.top: title.bottom
        anchors.topMargin: 20
        width: parent.width
        spacing: 20

        Label {
            id: label
            font.pixelSize: fontPixelsize
            text: qsTr(" Reference name")
        }

        Rectangle {
            width: 750
            height: 90
            TLineEdit {
                id: refConvention
                anchors.fill: parent
                text: qsTr("")
                input.font.pixelSize: fontPixelsize
                input.font.family: fontFamily
            }
        }

        Label {
            id: label1
            font.pixelSize: fontPixelsize
            text: qsTr(" New name")
        }

        Rectangle {
            width: 750
            height: 90
            TLineEdit {
                id: newConvention
                anchors.fill: parent
                text: qsTr("")
                input.font.pixelSize: fontPixelsize
                input.font.family: fontFamily
            }
        }
    }

    Rectangle {
        id: footer
        anchors.top: grid.bottom
        anchors.topMargin: 5
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
