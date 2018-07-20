/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMessageForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: DShow message UI form.

  Platforms: Qt/QML.
*/
import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: item1
    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    width: 1300
    height: 450
    property alias image: image
    property alias title: title
    property alias dialogButtonBox: dialogButtonBox
    property alias desc: desc

    Text {
        id: title
        anchors.top: parent.top
        anchors.topMargin: 0
        width: parent.width
        font.pixelSize: fontPixelsize
    }

    Image {
        id: image
        width: 100
        height: 100
        anchors.top: title.bottom
        anchors.topMargin: 50
    }

    Text {
        id: desc
        anchors.verticalCenter: image.verticalCenter
        anchors.left: image.right
        anchors.leftMargin: 10
        font.pixelSize: fontPixelsize
    }

    Rectangle {
        id: footer
        anchors.top: desc.bottom
        anchors.topMargin: 20
        width: parent.width
        height: 130
        DialogButtonBox {
            id: dialogButtonBox
            width: parent.width
            height: parent.height
            font.pixelSize: fontPixelsize
        }
    }
}
