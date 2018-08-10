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
    property int zf: 5
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 120 *zf
    height: 130 *zf

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
    property alias ok: ok
    property alias cancel: cancel

    TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        position: TabBar.Header
        font.pixelSize: fontPixelsize
        width: parent.width
        MouseArea
        {
            anchors.fill: parent
        }

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

    SwipeView {
        id: swipeView
        height: 90 * zf
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: tabBar.bottom
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
                spacing: 1 * zf

                GroupBox {
                    id: groupBox
                    title: qsTr("Style")

                    Column
                    {
                        RadioButton {
                            id: americanStyle
                            text: qsTr("American")
                        }

                        RadioButton {
                            id: europeanStyle
                            text: qsTr("European")
                        }
                    }
                }

                GroupBox {
                    id: groupBox1
                    title: qsTr("After 1NT")

                    Column
                    {
                        CheckBox {
                            id: stayman
                            text: qsTr("Stayman")
                        }

                        CheckBox {
                            id: jacobyTransfers
                            text: qsTr("Jacoby")
                            height: fontPixelsize * 2
                        }
                    }
                }

                GroupBox {
                    id: groupBox2
                    title: qsTr("Majors")

                    Column
                    {
                        RadioButton {
                            id: majorFour
                            text: qsTr("Four-Card")
                        }

                        RadioButton {
                            id: majorFive
                            text: qsTr("Five-Card")
                        }
                    }
                }

                GroupBox {
                    id: groupBox3
                    title: qsTr("Other")

                    Column
                    {
                        CheckBox {
                            id: limitRaises
                            text: qsTr("Limit Raises")
                        }

                        CheckBox {
                            id: weakTwo
                            text: qsTr("Weak Two")
                        }
                    }
                }
            }
        }
        Item {
            id: nt
            GroupBox {
                id: groupBox4
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                title: qsTr("1NT Open Range")

                Column
                {
                    RadioButton {
                        id: oneNTRange12_14
                        text: qsTr("12-14 points")
                    }

                    RadioButton {
                        id: oneNTRange15_17
                        text: qsTr("15-17 points")
                    }
                    CheckBox {
                        id: open1NTWeakMajor
                        text: qsTr("Weak 5 card major")
                    }
                }
            }

        }
        Item {
            id: misc
            GroupBox {
                id: groupBox5
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                title: qsTr("Advanced")

                Column
                {
                    CheckBox {
                        id: structuredReverses
                        text: qsTr("Reverse Restriction")
                    }

                    CheckBox {
                        id: negativeDoubles
                        text: qsTr("Negative Doubles")
                    }
                    CheckBox {
                        id: takeoutDoubles
                        text: qsTr("Takeout Doubles")
                    }
                    CheckBox {
                        id: michaelsCueBid
                        text: qsTr("Michaels Cue Bids")
                    }
                    CheckBox {
                        id: unusualNT
                        text: qsTr("Unusual Notrump")
                    }
                    CheckBox {
                        id: jumpOvercallWeak
                        text: qsTr("Jump Overcalls Weak")
                    }
                }
            }
        }
    }

    Row
    {
        id: okBox
        anchors.top: swipeView.bottom
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
