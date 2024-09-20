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
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: configurationDialog

    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 120 * zf
    height: 105 * zf

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
        font.family: fontFamily
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
        height: 55 * zf
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: tabBar.bottom
        anchors.topMargin: 4 * zf
        anchors.leftMargin: 1 * zf
        currentIndex: tabBar.currentIndex
        font.family: fontFamily
        font.pixelSize: fontPixelsize

        Item {
            GridLayout {
                id: grid
                rows: 4
                columns: 3

                RadioButton {
                    id: west
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 37 *zf
                    text: qsTr("West")
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 37 *zf
                    TLineEdit {
                        id: westName
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 41 *zf
                    ComboBox {
                        id: westActor
                        anchors.fill: parent
                        popup: Popup{
                                    id:popup1
                                    y: westActor.height - 1
                                    width: westActor.width
                                    height: westActor.height * 3
                                    padding: 0

                                    contentItem: ListView {
                                        id: listview1
                                        implicitHeight: popup1.height
                                        clip: true
                                        model:westActor.delegateModel
                                        currentIndex: westActor.highlightedIndex
                                        interactive: true
                                        highlightMoveDuration: 0
                                        boundsBehavior: ListView.StopAtBounds

                                        ScrollBar.vertical:ScrollBar {}
                                    }
                                }
                    }
                }
                RadioButton {
                    id: north
                    Layout.preferredHeight: 12 * zf
                    text: qsTr("North")
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 37 *zf
                    TLineEdit {
                        id: northName
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 41 *zf
                    ComboBox {
                        id: northActor
                        anchors.fill: parent
                        popup: Popup{
                                    id:popup2
                                    y: northActor.height - 1
                                    width: northActor.width
                                    height: northActor.height * 3
                                    padding: 0

                                    contentItem: ListView {
                                        id: listview2
                                        implicitHeight: popup2.height
                                        clip: true
                                        model:northActor.delegateModel
                                        currentIndex: northActor.highlightedIndex
                                        interactive: true
                                        highlightMoveDuration: 0
                                        boundsBehavior: ListView.StopAtBounds

                                        ScrollBar.vertical:ScrollBar {}
                                    }
                                }
                    }
                }
                RadioButton {
                    id: east
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 37 *zf
                    text: qsTr("East")
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 37 *zf
                    TLineEdit {
                        id: eastName
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 41 *zf
                    ComboBox {
                        id: eastActor
                        anchors.fill: parent
                        popup: Popup{
                                    id:popup3
                                    y: eastActor.height - 1
                                    width: eastActor.width
                                    height: eastActor.height * 3
                                    padding: 0

                                    contentItem: ListView {
                                        id: listview3
                                        implicitHeight: popup3.height
                                        clip: true
                                        model:eastActor.delegateModel
                                        currentIndex: eastActor.highlightedIndex
                                        interactive: true
                                        highlightMoveDuration: 0
                                        boundsBehavior: ListView.StopAtBounds

                                        ScrollBar.vertical:ScrollBar {}
                                    }
                                }
                    }
                }
                RadioButton {
                    id: south
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 37 *zf
                    text: qsTr("South")
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 37 *zf
                    TLineEdit {
                        id: southName
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 41 *zf
                    ComboBox {
                        id: southActor
                        anchors.fill: parent
                        popup: Popup{
                                    id:popup4
                                    y: northActor.height - 1
                                    width: southActor.width
                                    height: southActor.height * 3
                                    padding: 0

                                    contentItem: ListView {
                                        id: listview4
                                        implicitHeight: popup4.height
                                        clip: true
                                        model:southActor.delegateModel
                                        currentIndex: southActor.highlightedIndex
                                        interactive: true
                                        highlightMoveDuration: 0
                                        boundsBehavior: ListView.StopAtBounds

                                        ScrollBar.vertical:ScrollBar {}
                                    }
                                }
                    }
                }
            }
        }

        Item {
            GridLayout {
                id: grid1
                rows: 2
                columns: 3

                ComboBox {
                    id: role
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 54 *zf
                    popup: Popup{
                                id:popup5
                                y: role.height - 1
                                width: role.width
                                height: role.height * 4
                                padding: 0

                                contentItem: ListView {
                                    id: listview5
                                    implicitHeight: popup5.height
                                    clip: true
                                    model:role.delegateModel
                                    currentIndex: role.highlightedIndex
                                    interactive: true
                                    highlightMoveDuration: 0
                                    boundsBehavior: ListView.StopAtBounds

                                    ScrollBar.vertical:ScrollBar {}
                                }
                            }
                }
                Label {
                    id: hostLabel
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 17 *zf
                    text: qsTr(" Host:")
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 40 *zf
                    TLineEdit {
                        id: host
                        anchors.fill: parent
                        input.font.pixelSize: fontPixelsize
                        input.font.family: fontFamily
                    }
                }
                Label {
                    id: label1
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 47 *zf
                    text: qsTr("    ")
                }
                Label {
                    id: portLabel
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 17 *zf
                    text: qsTr(" Port:")
                }
                Rectangle {
                    Layout.preferredHeight: 12 * zf
                    Layout.preferredWidth: 40 *zf
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
