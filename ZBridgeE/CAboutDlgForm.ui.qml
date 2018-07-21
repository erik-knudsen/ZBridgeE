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
    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    id: item1
    width: 1000
    height: 850
    property alias okButton: okButton

    Label {
        id: label
        text: qsTr("ZBridge")
        font.pixelSize: 2 * fontPixelsize
        font.capitalization: Font.AllUppercase
        font.bold: true
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
    }

    Button {
        id: okButton
        font.pixelSize: fontPixelsize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
    }

    Image {
        id: image
        width: 250
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: label.bottom
        anchors.topMargin: 25
        anchors.bottom : parent.bottom
        anchors.bottomMargin: 25
        source: "resources/BridgeScene.bmp"
    }

    Label {
        id: label1
        font.pixelSize: fontPixelsize / 2
        text: qsTr("Copyright")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label.bottom
        anchors.topMargin: 20
        anchors.left: image.right
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

    Label {
        id: label2
        font.pixelSize: fontPixelsize / 2
        text: qsTr("email eak.erik@gmail.com")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label1.bottom
        anchors.topMargin: 0
        anchors.left: image.right
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

    Label {
        id: label3
        font.pixelSize: fontPixelsize / 2
        text: qsTr("Version 0.1")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label2.bottom
        anchors.topMargin: 10
        anchors.left: image.right
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

    Label {
        id: label4
        font.pixelSize: fontPixelsize / 2
        text: qsTr("Build Date: 15-jan-2018")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label3.bottom
        anchors.topMargin: 0
        anchors.left: image.right
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

    Label {
        id: label5
        font.pixelSize: fontPixelsize / 2
        text: qsTr("Platform Qt/QML")
        horizontalAlignment: Text.AlignHCenter
        anchors.top: label4.bottom
        anchors.topMargin: 0
        anchors.left: image.right
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

    Label {
        id: label6
        font.pixelSize: fontPixelsize / 2
        text: qsTr("This program is Open Source.  There are no warranties, expressed or implied, provided with the application.  Any commercial or fee-based redistribution is strictly prohibited without the author's express written consent.")
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignLeft
        anchors.top: label5.bottom
        anchors.topMargin: 10
        anchors.left: image.right
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }
    Label {
        id: label7
        font.pixelSize: fontPixelsize / 2
        text: qsTr("The terms of use and redistribution is covered by GNU General Public License version 3 (GPLv3).")
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignLeft
        anchors.top: label6.bottom
        anchors.topMargin: 5
        anchors.left: image.right
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }
}
