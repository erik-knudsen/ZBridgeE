/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CAboutDlgForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: About ZBridge UI form.

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
    height: 85 * zf

    property alias okButton: okButton

    Label {
        id: label
        text: qsTr("ZBridge")
        font.pixelSize: 2 * fontPixelsize
        font.capitalization: Font.AllUppercase
        font.bold: true
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: parent.top
        anchors.topMargin: 1 *zf
    }

    Button {
        id: okButton
        font.pixelSize: fontPixelsize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.top: parent.top
        anchors.topMargin: 1 * zf
        width: 6 * fontPixelsize/2
    }

    Image {
        id: image
        width: 25 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: label.bottom
        anchors.topMargin: 25
        anchors.bottom : parent.bottom
        anchors.bottomMargin: 3 * zf
        source: "resources/BridgeScene.bmp"
    }

    Label {
        id: label1
        font.pixelSize: fontPixelsize / 2
        text: qsTr("Copyright")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label.bottom
        anchors.topMargin: 2 * zf
        anchors.left: image.right
        anchors.leftMargin: 2 * zf
        anchors.right: parent.right
        anchors.rightMargin: 2 * zf
    }

    Label {
        id: label2
        font.pixelSize: fontPixelsize / 2
        text: qsTr("email eak.erik@gmail.com")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label1.bottom
        anchors.topMargin: 0
        anchors.left: image.right
        anchors.leftMargin: 2 * zf
        anchors.right: parent.right
        anchors.rightMargin: 2 * zf
    }

    Label {
        id: label3
        font.pixelSize: fontPixelsize / 2
        text: qsTr("Version 0.1")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label2.bottom
        anchors.topMargin: 1 * zf
        anchors.left: image.right
        anchors.leftMargin: 2 * zf
        anchors.right: parent.right
        anchors.rightMargin: 2 * zf
    }

    Label {
        id: label4
        font.pixelSize: fontPixelsize / 2
        text: qsTr("Build Date: 15-jan-2018")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label3.bottom
        anchors.topMargin: 0
        anchors.left: image.right
        anchors.leftMargin: 2 * zf
        anchors.right: parent.right
        anchors.rightMargin: 2 * zf
    }

    Label {
        id: label5
        font.pixelSize: fontPixelsize / 2
        text: qsTr("Platform Qt/QML")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label4.bottom
        anchors.topMargin: 0
        anchors.left: image.right
        anchors.leftMargin: 2 * zf
        anchors.right: parent.right
        anchors.rightMargin: 2 * zf
    }

    Label {
        id: label6
        font.pixelSize: fontPixelsize / 2
        text: qsTr("This program is Open Source.  There are no warranties, expressed or implied, provided with the application.  Any commercial or fee-based redistribution is strictly prohibited without the author's express written consent.")
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignLeft
        anchors.top: label5.bottom
        anchors.topMargin: 1 * zf
        anchors.left: image.right
        anchors.leftMargin: 2 * zf
        anchors.right: parent.right
        anchors.rightMargin: 2 * zf
    }
    Label {
        id: label7
        font.pixelSize: fontPixelsize / 2
        text: qsTr("The terms of use and redistribution is covered by GNU General Public License version 3 (GPLv3).")
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignLeft
        anchors.top: label6.bottom
        anchors.topMargin: zf / 2
        anchors.left: image.right
        anchors.leftMargin: 2 * zf
        anchors.right: parent.right
        anchors.rightMargin: 2 * zf
    }
}
