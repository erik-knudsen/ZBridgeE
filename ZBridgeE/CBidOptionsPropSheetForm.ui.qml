/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBidOptionsPropSheetForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Bid options property sheet UI form.

  Platforms: Qt/QML.
*/

import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    width: 1200
    height: 900
    property alias jumpOvercallWeak: jumpOvercallWeak
    property alias unusualNT: unusualNT
    property alias michaelsCueBid: michaelsCueBid
    property alias takeoutDoubles: takeoutDoubles
    property alias negativeDoubles: negativeDoubles
    property alias structuredReverses: structuredReverses
    property alias open1NTWeakMajor: open1NTWeakMajor
    property alias oneNTRange15_17: oneNTRange15_17
    property alias oneNTRange12_14: oneNTRange12_14
    property alias weakTwo: weakTwo
    property alias limitRaises: limitRaises
    property alias majorFive: majorFive
    property alias majorFour: majorFour
    property alias jacobyTransfers: jacobyTransfers
    property alias stayman: stayman
    property alias europeanStyle: europeanStyle
    property alias americanStyle: americanStyle
    property alias dialogButtonBox: dialogButtonBox

    Rectangle {
        id: header
        anchors.top: parent.top
        anchors.topMargin: 0
        width: parent.width
        height: 60

        TabBar {
            id: tabBar
            currentIndex: swipeView.currentIndex
            position: TabBar.Header
            font.pixelSize: fontPixelsize
            width: parent.width

            TabButton {
                text: "General"
            }
            TabButton {
                text: "Notrump"
            }
            TabButton {
                text: "Misc"
            }
        }
    }

    SwipeView {
        id: swipeView
        width: parent.width
        height: 700
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: header.bottom
        anchors.topMargin: 20
        currentIndex: tabBar.currentIndex
        font.pixelSize: fontPixelsize

        Item {
            id: general

            Grid {
                id: grid
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                rows: 2
                columns: 2
                verticalItemAlignment: Grid.AlignVCenter
                spacing: 10

                GroupBox {
                    id: groupBox
                    width: 525
                    height: 325
                    title: qsTr("Style")

                    RadioButton {
                        id: americanStyle
                        text: qsTr("American")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                    }

                    RadioButton {
                        id: europeanStyle
                        text: qsTr("European")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: americanStyle.bottom
                        anchors.topMargin: 0
                    }
                }

                GroupBox {
                    id: groupBox1
                    width: 525
                    height: 325
                    title: qsTr("After 1NT")

                    CheckBox {
                        id: stayman
                        text: qsTr("Stayman")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                    }

                    CheckBox {
                        id: jacobyTransfers
                        text: qsTr("Jacoby")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: stayman.bottom
                        anchors.topMargin: 0
                    }
                }

                GroupBox {
                    id: groupBox2
                    width: 525
                    height: 325
                    title: qsTr("Majors")

                    RadioButton {
                        id: majorFour
                        text: qsTr("Four-Card")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                    }

                    RadioButton {
                        id: majorFive
                        text: qsTr("Five-Card")
                        anchors.top: majorFour.bottom
                        anchors.topMargin: 0
                    }
                }

                GroupBox {
                    id: groupBox3
                    width: 525
                    height: 325
                    title: qsTr("Other")

                    CheckBox {
                        id: limitRaises
                        text: qsTr("Limit Raises")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                    }

                    CheckBox {
                        id: weakTwo
                        text: qsTr("Weak Two-Bids")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.top: limitRaises.bottom
                        anchors.topMargin: 0
                    }
                }
            }
        }
        Item {
            id: nt
            GroupBox {
                id: groupBox4
                width: 650
                height: 425
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                title: qsTr("1NT Open Range")

                RadioButton {
                    id: oneNTRange12_14
                    text: qsTr("12-14 points")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0
                }

                RadioButton {
                    id: oneNTRange15_17
                    text: qsTr("15-17 points")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: oneNTRange12_14.bottom
                    anchors.topMargin: 0
                }
                CheckBox {
                    id: open1NTWeakMajor
                    text: qsTr("Weak 5 card major")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: oneNTRange15_17.bottom
                    anchors.topMargin: 10
                }
            }

            }
        Item {
            id: misc
            GroupBox {
                id: groupBox5
                width: 720
                height: 675
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                title: qsTr("Advanced")

                CheckBox {
                    id: structuredReverses
                    text: qsTr("Reverse Restriction")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0
                }

                CheckBox {
                    id: negativeDoubles
                    text: qsTr("Negative Doubles")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: structuredReverses.bottom
                    anchors.topMargin: 0
                }
                CheckBox {
                    id: takeoutDoubles
                    text: qsTr("Takeout Doubles")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: negativeDoubles.bottom
                    anchors.topMargin: 0
                }
                CheckBox {
                    id: michaelsCueBid
                    text: qsTr("Michaels Cue Bids")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: takeoutDoubles.bottom
                    anchors.topMargin: 0
                }
                CheckBox {
                    id: unusualNT
                    text: qsTr("Unusual Notrump")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: michaelsCueBid.bottom
                    anchors.topMargin: 0
                }
                CheckBox {
                    id: jumpOvercallWeak
                    text: qsTr("Jump Overcalls Weak")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: unusualNT.bottom
                    anchors.topMargin: 0
                }
            }
        }
    }

    Rectangle {
        id: footer
        anchors.top: swipeView.bottom
        anchors.topMargin: 0
        width: parent.width
        height: 130
        DialogButtonBox {
            id: dialogButtonBox
            width: parent.width
            height: parent.height
            standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel
            font.pixelSize: fontPixelsize
        }
    }
}
