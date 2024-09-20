/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBidOptionsForm.ui.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Bid options UI form.

  Platforms: Qt/QML.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: item1

    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 120 * zf
    height: 110 * zf

    property alias northSouth: northSouth
    property alias northSouthConvention: northSouthConvention
    property alias nsModel: nsModel
    property alias eastWest: eastWest
    property alias eastWestConvention: eastWestConvention
    property alias ewModel: ewModel
    property alias newConvention: newConvention
    property alias editConvention: editConvention
    property alias deleteConvention: deleteConvention
    property alias ok: ok
    property alias cancel: cancel

    GroupBox {
        id: groupBox
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: parent.top
        anchors.topMargin: 2 * zf
        font.family: fontFamily
        font.pixelSize: fontPixelsize
        title: qsTr("Convention")

        GridLayout
        {
            rows: 2
            columns: 2
            anchors.horizontalCenter: parent.horizontalCenter

            RadioButton {
                id: northSouth
                Layout.preferredHeight: 12 * zf
                text: qsTr("N/S")
            }

            ComboBox {
                id: northSouthConvention
                Layout.preferredWidth: 14 * fontPixelsize/2
                Layout.preferredHeight: 12 * zf
                ListModel {
                    id: nsModel
                }
                model: nsModel
                popup: Popup{
                            id:popup
                            y: northSouthConvention.height - 1
                            width: northSouthConvention.width
                            height: northSouthConvention.height * 4
                            padding: 0

                            contentItem: ListView {
                                id: listview
                                implicitHeight: popup.height
                                clip: true
                                model:northSouthConvention.delegateModel
                                currentIndex: northSouthConvention.highlightedIndex
                                interactive: true
                                highlightMoveDuration: 0
                                boundsBehavior: ListView.StopAtBounds

                                ScrollBar.vertical:ScrollBar {}
                            }
                        }
            }

            RadioButton {
                id: eastWest
                Layout.preferredHeight: 12 * zf
                text: qsTr("E/W")
            }

            ComboBox {
                id: eastWestConvention
                Layout.preferredWidth: 14 * fontPixelsize/2
                Layout.preferredHeight: 12 * zf

                ListModel {
                    id: ewModel
                }
                model: ewModel
                popup: Popup{
                            id:popup1
                            y: eastWestConvention.height - 1
                            width: eastWestConvention.width
                            height: eastWestConvention.height * 4
                            padding: 0

                            contentItem: ListView {
                                id: listview1
                                implicitHeight: popup1.height
                                clip: true
                                model:eastWestConvention.delegateModel
                                currentIndex: eastWestConvention.highlightedIndex
                                interactive: true
                                highlightMoveDuration: 0
                                boundsBehavior: ListView.StopAtBounds

                                ScrollBar.vertical:ScrollBar {}
                            }
                        }
            }
        }
    }

    RowLayout
    {
        id: rowLine
        anchors.top: groupBox.bottom
        anchors.topMargin: 6 *zf
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 1 * zf

        Button {
            id: newConvention
            Layout.preferredWidth: 11 * fontPixelsize/2
            text: qsTr("New")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
        }

        Button {
            id: editConvention
            Layout.preferredWidth: 11 * fontPixelsize/2
            text: qsTr("Edit")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
        }

        Button {
            id: deleteConvention
            Layout.preferredWidth: 11 * fontPixelsize/2
            text: qsTr("Delete")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
        }
    }

    RowLayout
    {
        id: okBox
        anchors.top: rowLine.bottom
        anchors.topMargin: 6 *zf
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
