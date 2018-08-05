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

    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    property alias newConvention: newConvention
    property alias refConvention: refConvention
    property alias ok: ok
    property alias cancel: cancel

    width: 132 * zf
    height: 48 * zf

    Grid {
        id: grid
        rows: 2
        columns: 2
        anchors.top: parent.top
        anchors.topMargin: 4 * zf
        width: parent.width
        spacing: 2 * zf

        Label {
            id: label
            font.pixelSize: fontPixelsize
            text: qsTr(" Reference name")
        }

        TLineEdit {
            id: refConvention
            width: 75 * zf
            height: 9 * zf
            text: qsTr("")
            input.font.pixelSize: fontPixelsize
            input.font.family: fontFamily
        }

        Label {
            id: label1
            font.pixelSize: fontPixelsize
            text: qsTr(" New name")
        }

        TLineEdit {
            id: newConvention
            width: 75 * zf
            height: 9 * zf
            text: qsTr("")
            input.font.pixelSize: fontPixelsize
            input.font.family: fontFamily
        }
    }

    Row
    {
        id: okBox
        anchors.top: grid.bottom
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
