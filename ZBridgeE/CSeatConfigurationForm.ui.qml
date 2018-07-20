/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CSeatConfigurationForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Seat configuration UI form.

  Platforms: Qt/QML.
*/
import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: configurationDialog

    width: 1020
    height: 750
    property alias dialogButtonBox: dialogButtonBox
    property alias portLabel: portLabel
    property alias hostLabel: hostLabel
    property alias port: port
    property alias host: host
    property alias role: role
    property alias southActor: southActor
    property alias southName: southName
    property alias south: south
    property alias eastActor: eastActor
    property alias eastName: eastName
    property alias east: east
    property alias northActor: northActor
    property alias northName: northName
    property alias north: north
    property alias westActor: westActor
    property alias westName: westName
    property alias west: west

    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

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
                text: qsTr("Seat")
            }
            TabButton {
                text: qsTr("Role")
            }
        }
    }

    SwipeView {
        id: swipeView
        height: 550
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: header.bottom
        anchors.topMargin: 0
        currentIndex: tabBar.currentIndex
        font.pixelSize: fontPixelsize

        Item {
            GroupBox {
                id: groupBox
                anchors.fill: parent
                title: qsTr("   ")

                Grid {
                    id: grid
                    spacing: 15
                    rows: 4
                    columns: 3
                    anchors.fill: parent
                    verticalItemAlignment: Grid.AlignVCenter

                    RadioButton {
                        id: west
                        width: 270
                        height: 90
                        text: qsTr("West")
                    }
                    Rectangle {
                        width: 370
                        height: 90
                        TLineEdit {
                            id: westName
                            anchors.fill: parent
                            text: qsTr("")
                            input.font.pixelSize: fontPixelsize
                            input.font.family: fontFamily
                        }
                    }
                    Rectangle {
                        width: 330
                        height: 90
                        ComboBox {
                            id: westActor
                            anchors.fill: parent
                        }
                    }
                    RadioButton {
                        id: north
                        width: 270
                        height: 90
                        text: qsTr("North")
                    }
                    Rectangle {
                        width: 370
                        height: 90
                        TLineEdit {
                            id: northName
                            anchors.fill: parent
                            text: qsTr("")
                            input.font.pixelSize: fontPixelsize
                            input.font.family: fontFamily
                        }
                    }
                    Rectangle {
                        width: 330
                        height: 90
                        ComboBox {
                            id: northActor
                            anchors.fill: parent
                        }
                    }
                    RadioButton {
                        id: east
                        width: 270
                        height: 90
                        text: qsTr("East")
                    }
                    Rectangle {
                        width: 370
                        height: 90
                        TLineEdit {
                            id: eastName
                            anchors.fill: parent
                            text: qsTr("")
                            input.font.pixelSize: fontPixelsize
                            input.font.family: fontFamily
                        }
                    }
                    Rectangle {
                        width: 330
                        height: 90
                        ComboBox {
                            id: eastActor
                            anchors.fill: parent
                        }
                    }
                    RadioButton {
                        id: south
                        width: 270
                        height: 90
                        text: qsTr("South")
                    }
                    Rectangle {
                        width: 370
                        height: 90
                        TLineEdit {
                            id: southName
                            anchors.fill: parent
                            text: qsTr("")
                            input.font.pixelSize: fontPixelsize
                            input.font.family: fontFamily
                        }
                    }
                    Rectangle {
                        width: 330
                        height: 90
                        ComboBox {
                            id: southActor
                            anchors.fill: parent
                        }
                    }
                }
            }
        }

        Item {
            GroupBox {
                id: groupBox1
                anchors.fill: parent
                title: qsTr("  ")

                Grid {
                    id: grid1
                    spacing: 15
                    anchors.fill: parent
                    rows: 2
                    columns: 3
                    verticalItemAlignment: Grid.AlignVCenter

                    Rectangle {
                        width: 420
                        height: 90
                        ComboBox {
                            id: role
                            anchors.fill: parent
                        }
                    }
                    Rectangle {
                        id: rectangle1
                        width: 170
                        height: 90
                        Label {
                            id: hostLabel
                            text: qsTr(" Host:")
                            anchors.fill: parent
                        }
                    }
                    Rectangle {
                        width: 380
                        height: 90
                        TLineEdit {
                            id: host
                            anchors.fill: parent
                            text: qsTr("")
                            input.font.pixelSize: fontPixelsize
                            input.font.family: "MS Shell Dlg 2"
                        }
                    }
                    Rectangle {
                        width: 420
                        height: 90
                        Label {
                            id: label1
                            anchors.fill: parent
                            text: qsTr("    ")
                        }
                    }
                    Rectangle {
                        id: rectangle
                        width: 170
                        height: 90
                        Label {
                            id: portLabel
                            text: qsTr(" Port:")
                            anchors.fill: parent
                        }
                    }
                    Rectangle {
                        width: 380
                        height: 90
                        TLineEdit {
                            id: port
                            anchors.fill: parent
                            text: qsTr("")
                            input.font.pixelSize: fontPixelsize
                            input.font.family: "MS Shell Dlg 2"
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: footer
        anchors.top: swipeView.bottom
        anchors.topMargin: 20
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
