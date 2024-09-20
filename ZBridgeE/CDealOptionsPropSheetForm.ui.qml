/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CDealOptionsPropSheetForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Deal options property sheet UI form.

  Platforms: Qt/QML.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    property int editW: 15 * zf
    property int editH: 10 * zf

    width: 100 * zf
    height: 115 * zf

    property alias ok: ok
    property alias cancel: cancel
    property alias hcpTotalWest: hcpTotalWest
    property alias hcpTotalNorth: hcpTotalNorth
    property alias hcpTotalEast: hcpTotalEast
    property alias hcpTotalSouth: hcpTotalSouth
    property alias hcpSpadeWest: hcpSpadeWest
    property alias hcpSpadeNorth: hcpSpadeNorth
    property alias hcpSpadeEast: hcpSpadeEast
    property alias hcpSpadeSouth: hcpSpadeSouth
    property alias hcpHeartWest: hcpHeartWest
    property alias hcpHeartNorth: hcpHeartNorth
    property alias hcpHeartEast: hcpHeartEast
    property alias hcpHeartSouth: hcpHeartSouth
    property alias hcpDiamondWest: hcpDiamondWest
    property alias hcpDiamondNorth: hcpDiamondNorth
    property alias hcpDiamondEast: hcpDiamondEast
    property alias hcpDiamondSouth: hcpDiamondSouth
    property alias hcpClubWest: hcpClubWest
    property alias hcpClubNorth: hcpClubNorth
    property alias hcpClubEast: hcpClubEast
    property alias hcpClubSouth: hcpClubSouth
    property alias suitSizeSpadeWest: suitSizeSpadeWest
    property alias suitSizeSpadeNorth: suitSizeSpadeNorth
    property alias suitSizeSpadeEast: suitSizeSpadeEast
    property alias suitSizeSpadeSouth: suitSizeSpadeSouth
    property alias suitSizeHeartWest: suitSizeHeartWest
    property alias suitSizeHeartNorth: suitSizeHeartNorth
    property alias suitSizeHeartEast: suitSizeHeartEast
    property alias suitSizeHeartSouth: suitSizeHeartSouth
    property alias suitSizeDiamondWest: suitSizeDiamondWest
    property alias suitSizeDiamondNorth: suitSizeDiamondNorth
    property alias suitSizeDiamondEast: suitSizeDiamondEast
    property alias suitSizeDiamondSouth: suitSizeDiamondSouth
    property alias suitSizeClubWest: suitSizeClubWest
    property alias suitSizeClubNorth: suitSizeClubNorth
    property alias suitSizeClubEast: suitSizeClubEast
    property alias suitSizeClubSouth: suitSizeClubSouth
    property alias dpWest: dpWest
    property alias dpNorth: dpNorth
    property alias dpEast: dpEast
    property alias dpSouth: dpSouth

    TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        position: TabBar.Header
        font.family: fontFamily
        font.pixelSize: fontPixelsize
        width: parent.width
        MouseArea
        {
            anchors.fill: parent
        }

        TabButton {
            text: "HCP"
        }
        TabButton {
            text: "Length"
        }
        TabButton {
            text: "DP"
        }
    }

    SwipeView {
        id: swipeView
        height: 70 * zf
        anchors.right: parent.right
        anchors.rightMargin: 0 * zf
        anchors.left: parent.left
        anchors.leftMargin: 0 * zf
        anchors.top: tabBar.bottom
        anchors.topMargin: 0 * zf
        currentIndex: tabBar.currentIndex
        font.family: fontFamily
        font.pixelSize: fontPixelsize

        Item {
            id: hcp
            
            GridLayout {
                id: grid
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                rows: 6
                columns: 5

                Label {
                    id: label
                    text: qsTr(" ")
                }
                Label {
                    id: label1
                    text: qsTr("West")
                }
                Label {
                    id: label2
                    text: qsTr("North")
               }
                Label {
                    id: label3
                    text: qsTr("East")
                }
                Label {
                    id: label4
                    text: qsTr("South")
                }
                Label {
                    id: label5
                    text: qsTr("Total")
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpTotalWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpTotalNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpTotalEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpTotalSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Image {
                    Layout.preferredWidth: 5 * zf
                    Layout.preferredHeight: 5 * zf
                    source: "qrc:///resources/suit_spade.ico"
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpSpadeWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpSpadeNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpSpadeEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpSpadeSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Image {
                    Layout.preferredWidth: 5 * zf
                    Layout.preferredHeight: 5 * zf
                    source: "qrc:///resources/suit_heart.ico"
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpHeartWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpHeartNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpHeartEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpHeartSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Image {
                    Layout.preferredWidth: 5 * zf
                    Layout.preferredHeight: 5 * zf
                    source: "qrc:///resources/suit_diamond.ico"
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpDiamondWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpDiamondNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpDiamondEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpDiamondSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Image {
                    Layout.preferredWidth: 5 * zf
                    Layout.preferredHeight: 5 * zf
                    source: "qrc:///resources/suit_club.ico"
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpClubWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpClubNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpClubEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: hcpClubSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
            }
        }
        Item {
            id: length

            GridLayout {
                id: grid1
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                rows: 5
                columns: 5

                Label {
                    id: label6
                    text: qsTr(" ")
                }
                Label {
                    id: label7
                    text: qsTr("West")
                }
                Label {
                    id: label8
                    text: qsTr("North")
               }
                Label {
                    id: label9
                    text: qsTr("East")
                }
                Label {
                    id: label10
                    text: qsTr("South")
                }
                Image {
                    Layout.preferredWidth: 5 * zf
                    Layout.preferredHeight: 5 * zf
                    source: "qrc:///resources/suit_spade.ico"
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeSpadeWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeSpadeNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeSpadeEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeSpadeSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Image {
                    Layout.preferredWidth: 5 * zf
                    Layout.preferredHeight: 5 * zf
                    source: "qrc:///resources/suit_heart.ico"
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeHeartWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeHeartNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeHeartEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeHeartSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Image {
                    Layout.preferredWidth: 5 * zf
                    Layout.preferredHeight: 5 * zf
                    source: "qrc:///resources/suit_diamond.ico"
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeDiamondWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeDiamondNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeDiamondEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeDiamondSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Image {
                    Layout.preferredWidth: 5 * zf
                    Layout.preferredHeight: 5 * zf
                    source: "qrc:///resources/suit_club.ico"
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeClubWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeClubNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeClubEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: suitSizeClubSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }

            }
        }
        Item {
            id: dp

            GridLayout {
                id: grid2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                rows: 2
                columns: 4

                Label {
                    id: label11
                    text: qsTr("West")
                }
                Label {
                    id: label12
                    text: qsTr("North")
               }
                Label {
                    id: label13
                    text: qsTr("East")
                }
                Label {
                    id: label14
                    text: qsTr("South")
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: dpWest
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: dpNorth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: dpEast
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredWidth: editW
                    Layout.preferredHeight: editH
                    TLineEdit {
                        id: dpSouth
                        anchors.fill: parent
                        text: qsTr("")
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
            }
        }
    }

    RowLayout
    {
        id: okBox
        anchors.top: swipeView.bottom
        anchors.topMargin: 4 *zf
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 1 * zf

        Button {
            id: ok
            Layout.preferredWidth: 12 * fontPixelsize/2
            text: qsTr("OK")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
        }

        Button {
            id: cancel
            Layout.preferredWidth: 12 * fontPixelsize/2
            text: qsTr("Cancel")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
        }
    }
}
