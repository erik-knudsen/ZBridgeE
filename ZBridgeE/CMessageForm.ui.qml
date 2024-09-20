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
import QtQuick
import QtQuick.Controls

Item {
    id: item1

    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 130 * zf
    height: 50 * zf

    property alias image: image
    property alias title: title
    property alias dialogButtonBox: dialogButtonBox
    property alias desc: desc

    Text {
        id: title
        anchors.top: parent.top
        anchors.topMargin: 0 * zf
        width: parent.width
        font.family: fontFamily
        font.pixelSize: fontPixelsize
    }

    Image {
        id: image
        width: 10 * zf
        height: 10 * zf
        anchors.top: title.bottom
        anchors.topMargin: 5 * zf
    }

    Text {
        id: desc
        anchors.verticalCenter: image.verticalCenter
        anchors.left: image.right
        anchors.leftMargin: 1 *zf
        font.family: fontFamily
        font.pixelSize: fontPixelsize
    }

    DialogButtonBox {
        id: dialogButtonBox
        anchors.top: desc.bottom
        anchors.topMargin: 2 * zf
        width: parent.width
        height: 13 * zf
        font.family: fontFamily
        font.pixelSize: fontPixelsize
    }
}
