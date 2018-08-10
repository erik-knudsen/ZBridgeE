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

    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 109 * zf
    height: 80 * zf

    property alias ok: ok
    property alias cancel: cancel
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
            text: qsTr("Seat")
        }
        TabButton {
            text: qsTr("Role")
        }
    }

    SwipeView {
        id: swipeView
        height: 45 * zf
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: tabBar.bottom
        anchors.topMargin: 4 * zf
        anchors.leftMargin: 1 * zf
        currentIndex: tabBar.currentIndex
        font.pixelSize: fontPixelsize

        Item {
            Grid {
                id: grid
                rows: 4
                columns: 3
                spacing: 2 * zf

                RadioButton {
                    id: west
                    width: 30 * zf
                    height: 9 * zf
                    text: qsTr("West")
                }
                Rectangle {
                    width: 37 * zf
                    height: 9 * zf
                    TLineEdit {
                        id: westName
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    width: 36 * zf
                    height: 9 * zf
                    ComboBox {
                        id: westActor
                        anchors.fill: parent
                    }
                }
                RadioButton {
                    id: north
                    width: 30 * zf
                    height: 9 * zf
                    text: qsTr("North")
                }
                Rectangle {
                    width: 37 * zf
                    height: 9 * zf
                    TLineEdit {
                        id: northName
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    width: 36 * zf
                    height: 9 * zf
                    ComboBox {
                        id: northActor
                        anchors.fill: parent
                    }
                }
                RadioButton {
                    id: east
                    width: 30 * zf
                    height: 9 * zf
                    text: qsTr("East")
                }
                Rectangle {
                    width: 37 * zf
                    height: 9 * zf
                    TLineEdit {
                        id: eastName
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    width: 36 * zf
                    height: 9 * zf
                    ComboBox {
                        id: eastActor
                        anchors.fill: parent
                    }
                }
                RadioButton {
                    id: south
                    width: 30 * zf
                    height: 9 * zf
                    text: qsTr("South")
                }
                Rectangle {
                    width: 37 * zf
                    height: 9 * zf
                    TLineEdit {
                        id: southName
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    width: 36 * zf
                    height: 9 * zf
                    ComboBox {
                        id: southActor
                        anchors.fill: parent
                    }
                }
            }
        }

        Item {
            Grid {
                id: grid1
                rows: 2
                columns: 3
                spacing: 1.5 * zf

                ComboBox {
                    id: role
                    width: 47 * zf
                    height: 9 * zf
                }
                Label {
                    id: hostLabel
                    width: 17 * zf
                    height: 9 * zf
                    text: qsTr(" Host:")
                }
                Rectangle {
                    width: 38 * zf
                    height: 9* zf
                    TLineEdit {
                        id: host
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Label {
                    id: label1
                    width: 47 * zf
                    height: 9 * zf
                    text: qsTr("    ")
                }
                Label {
                    id: portLabel
                    width: 17 * zf
                    height: 9 * zf
                    text: qsTr(" Port:")
                }
                Rectangle {
                    width: 38 * zf
                    height: 9 * zf
                    TLineEdit {
                        id: port
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
            }
        }
    }

    Row
    {
        id: okBox
        anchors.top: swipeView.bottom
        anchors.topMargin: 4 *zf
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
