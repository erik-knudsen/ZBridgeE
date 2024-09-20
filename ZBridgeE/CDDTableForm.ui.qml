/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CDDTableForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Double dummy table UI form.

  Platforms: Qt/QML.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

//The use of a singleton is just for experimenting.
import Singleton 1.0

Item {
    id: item1
    property int zf: Singleton.zh
//    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    property int editW: 21 *zf
    property int editH: 9 *zf

    width: 132 *zf
    height: 90 *zf

    property alias parScore: parScore
    property alias parContract: parContract
    property alias tricksCEW: tricksCEW
    property alias tricksCNS: tricksCNS
    property alias tricksDEW: tricksDEW
    property alias tricksDNS: tricksDNS
    property alias tricksHEW: tricksHEW
    property alias tricksHNS: tricksHNS
    property alias tricksSEW: tricksSEW
    property alias tricksSNS: tricksSNS
    property alias tricksNTEW: tricksNTEW
    property alias tricksNTNS: tricksNTNS
    property alias okButton: okButton

    GroupBox {
        id: groupBox
        width: 70 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1  *zf
        anchors.top: parent.top
        anchors.topMargin: 1 * zf
        font.family: fontFamily
        font.pixelSize: fontPixelsize
        title: qsTr("DD Results")

        GridLayout {
            id: grid
            anchors.fill: parent
            rows: 6
            columns: 3

            Label {
                id: label
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr(" ")
            }
            Label {
                id: label1
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("N-S")
            }
            Label {
                id: label2
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("E-W")
            }
            Label {
                id: label3
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("NT")
            }
            Label {
                id: tricksNTNS
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("ntns")
            }
            Label {
                id: tricksNTEW
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("ntew")
            }
            Image {
                id: image
                Layout.preferredWidth: 7 * zf
                Layout.preferredHeight: 7 * zf
                source: "qrc:///resources/suit_spade.ico"
            }
            Label {
                id: tricksSNS
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("sns")
            }
            Label {
                id: tricksSEW
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("sew")
            }
            Image {
                id: image1
                Layout.preferredWidth: 7 * zf
                Layout.preferredHeight: 7 * zf
                source: "qrc:///resources/suit_heart.ico"
            }
            Label {
                id: tricksHNS
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("hns")
            }
            Label {
                id: tricksHEW
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("hew")
            }
            Image {
                id: image2
                Layout.preferredWidth: 7 * zf
                Layout.preferredHeight: 7 * zf
                source: "qrc:///resources/suit_diamond.ico"
            }
            Label {
                id: tricksDNS
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("dns")
            }
            Label {
                id: tricksDEW
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("dew")
            }
            Image {
                id: image3
                Layout.preferredWidth: 7 * zf
                Layout.preferredHeight: 7 * zf
                source: "qrc:///resources/suit_club.ico"
            }
            Label {
                id: tricksCNS
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("cnt")
            }
            Label {
                id: tricksCEW
                Layout.preferredWidth: editW
                Layout.preferredHeight: editH
                text: qsTr("cew")
            }
        }
    }

    GroupBox {
        id: groupBox1
        width: 55 * zf
        anchors.left: groupBox.right
        anchors.leftMargin: 2 * zf
        anchors.top: parent.top
        anchors.topMargin: 1 * zf
        font.family: fontFamily
        font.pixelSize: fontPixelsize
        title: qsTr("Par")

        ColumnLayout {
            id: column
            anchors.fill: parent

            Label {
                id: parContract
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: editH
                text: qsTr("par contract")
            }
            Label {
                id: parScore
                text: qsTr("par score")
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: editH
            }
        }
    }

    Button {
        id: okButton
        font.family: fontFamily
        font.pixelSize: fontPixelsize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 2 * zf
        anchors.bottom: groupBox.bottom
        anchors.bottomMargin: 1 * zf
    }
}
