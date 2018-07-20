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

import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: item1

    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    property int editW: 210
    property int editH: 90

    width: 1320
    height: 800
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
        height: 750
        width: 700
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        font.pixelSize: fontPixelsize
        title: qsTr("DD Results")

        Grid {
            id: grid
            anchors.fill: parent
            rows: 6
            columns: 3
            spacing: 10

            Label {
                id: label
                width: editW
                height: editH
                text: qsTr(" ")
            }
            Label {
                id: label1
                width: editW
                height: editH
                text: qsTr("N-S")
            }
            Label {
                id: label2
                width: editW
                height: editH
                text: qsTr("E-W")
            }
            Label {
                id: label3
                width: editW
                height: editH
                text: qsTr("NT")
            }
            Label {
                id: tricksNTNS
                width: editW
                height: editH
                text: qsTr("ntns")
            }
            Label {
                id: tricksNTEW
                width: editW
                height: editH
                text: qsTr("ntew")
            }
            Image {
                id: image
                width: 70
                height: 70
                source: "qrc:///resources/suit_spade.ico"
            }
            Label {
                id: tricksSNS
                width: editW
                height: editH
                text: qsTr("sns")
            }
            Label {
                id: tricksSEW
                width: editW
                height: editH
                text: qsTr("sew")
            }
            Image {
                id: image1
                width: 70
                height: 70
                source: "qrc:///resources/suit_heart.ico"
            }
            Label {
                id: tricksHNS
                width: editW
                height: editH
                text: qsTr("hns")
            }
            Label {
                id: tricksHEW
                width: editW
                height: editH
                text: qsTr("hew")
            }
            Image {
                id: image2
                width: 70
                height: 70
                source: "qrc:///resources/suit_diamond.ico"
            }
            Label {
                id: tricksDNS
                width: editW
                height: editH
                text: qsTr("dns")
            }
            Label {
                id: tricksDEW
                width: editW
                height: editH
                text: qsTr("dew")
            }
            Image {
                id: image3
                width: 70
                height: 70
                source: "qrc:///resources/suit_club.ico"
            }
            Label {
                id: tricksCNS
                width: editW
                height: editH
                text: qsTr("cnt")
            }
            Label {
                id: tricksCEW
                width: editW
                height: editH
                text: qsTr("cew")
            }
        }
    }

    GroupBox {
        id: groupBox1
        height: 300
        width: 550
        anchors.left: groupBox.right
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        font.pixelSize: fontPixelsize
        title: qsTr("Par")

        Column {
            id: column
            anchors.fill: parent

            Label {
                id: parContract
                width: parent.width
                height: editH
                text: qsTr("par contract")
            }
            Label {
                id: parScore
                text: qsTr("par score")
                width: parent.width
                height: editH
            }
        }
    }

    Button {
        id: okButton
        font.pixelSize: fontPixelsize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: groupBox.bottom
        anchors.bottomMargin: 10
    }
}
