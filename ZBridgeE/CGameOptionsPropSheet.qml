/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CGameOptionsPropSheet.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Game options property sheet.

  Platforms: Qt/QML.
*/
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {    
    property int zf: 10
    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 115 * zf
    height: 125 * zf

    signal on_ok_clicked()
    signal on_cancel_clicked()
    signal on_biddingPause_sliderMoved(int position)
    signal on_playPause_sliderMoved(int position)
    signal on_insertBiddingPause_clicked(bool checked)
    signal on_insertPlayPause_clicked(bool checked)
    signal on_duplicateMP_clicked()
    signal on_rubberBridge_clicked()
    signal on_teamsIMP_clicked()
    signal on_practice_clicked()
    signal on_level0_clicked()
    signal on_level1_clicked()
    signal on_level2_clicked()
    signal on_level3_clicked()

    property int iMP: 0
    property int mP: 1
    property int rUBBER: 2
    property int pRACTICE: 3

    TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        position: TabBar.Header
        font.pixelSize: fontPixelsize
        font.family: fontFamily
        width: parent.width
        MouseArea
        {
            anchors.fill: parent
        }

        TabButton {
            text: qsTr("Interface")
        }
        TabButton {
            text: qsTr("Scoring")
        }
        TabButton {
            text: qsTr("Level")
        }
    }

    SwipeView {
        id: swipeView
        height: 80 * zf
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: tabBar.bottom
        currentIndex: tabBar.currentIndex
        font.pixelSize: fontPixelsize
        font.family: fontFamily

        Item {
            id: item1
            ColumnLayout {
                spacing: 5 *zf

            GroupBox {
                id: groupBox1
                Layout.topMargin: 5 * zf
                Layout.leftMargin: 3 * zf

                ColumnLayout {
                    CheckBox {
                        id: insertBiddingPause
                        Layout.preferredHeight: 12 *zf
                        checked: true
                        text: qsTr("Insert pause between bids ")
                        onClicked: on_insertBiddingPause_clicked(checked)
                    }

                    RowLayout {
                        enabled: insertBiddingPause.checked

                        Label {
                            id: biddingPauseLength
                            Layout.preferredHeight: 10 *zf
                            text: "Text"
                        }
                        Slider {
                            id: biddingPause
                            Layout.preferredHeight: 10 *zf
                            from: 0
                            to: 10
                            stepSize: 1
                            snapMode: Slider.SnapAlways
                            onMoved: on_biddingPause_sliderMoved(value)
                        }
                    }
                }
            }

            GroupBox {
                id: groupBox2
                Layout.leftMargin: 3 * zf

                ColumnLayout {
                    CheckBox {
                        id: insertPlayPause
                        Layout.preferredHeight: 12 *zf
                        checked: true
                        text: qsTr("Insert pause between plays")
                        onClicked: on_insertPlayPause_clicked(checked)
                    }
                    RowLayout {
                        enabled: insertPlayPause.checked

                        Label {
                            id: playPauseLength
                            Layout.preferredHeight: 10 *zf
                            text: "Text"
                        }
                        Slider {
                            id: playPause
                            Layout.preferredHeight: 10 *zf
                            from: 0
                            to: 10
                            stepSize: 1
                            snapMode: Slider.SnapAlways
                            onMoved: on_playPause_sliderMoved(value)
                        }
                    }
                }
            }
            }
        }

        Item {
            id: item2
            GroupBox {
                id: groupBox3
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                title: "Scoring Method"

                ColumnLayout {
                    RadioButton {
                        id: teamsImp
                        Layout.preferredHeight: 10 * zf
                        text: qsTr("Teams IMP")
                        onClicked: on_teamsIMP_clicked()
                    }
                    RadioButton {
                        id: duplicateMP
                        Layout.preferredHeight: 10 * zf
                        text: qsTr("Duplicate MP")
                        onClicked: on_duplicateMP_clicked()
                    }
                    RadioButton {
                        id: rubberBridge
                        Layout.preferredHeight: 10 * zf
                        text: qsTr("Rubber Bridge")
                        onClicked: on_rubberBridge_clicked()
                    }
                    RadioButton {
                        id: practice
                        Layout.preferredHeight: 10 * zf
                        text: qsTr("Practice")
                        onClicked: on_practice_clicked()
                    }
                }
            }
        }

        Item {
            id: item3
            GroupBox {
                id: groupBox4
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                title: "Computer Level"

                ColumnLayout {
                    RadioButton {
                        id: computerLevel0
                        Layout.preferredHeight: 10 * zf
                        text: qsTr("Level 0")
                        onClicked: on_level0_clicked()
                    }
                    RadioButton {
                        id: computerLevel1
                        Layout.preferredHeight: 10 * zf
                        text: qsTr("Level 1")
                        onClicked: on_level1_clicked()
                    }
                    RadioButton {
                        id: computerLevel2
                        Layout.preferredHeight: 10 * zf
                        text: qsTr("Level 2")
                        onClicked: on_level2_clicked()
                    }
                    RadioButton {
                        id: computerLevel3
                        Layout.preferredHeight: 10 * zf
                        text: qsTr("Level 3")
                        onClicked: on_level3_clicked()
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
            font.pixelSize: fontPixelsize
            onClicked: on_ok_clicked()
        }

        Button {
            id: cancel
            Layout.preferredWidth: 12 * fontPixelsize/2
            text: qsTr("Cancel")
            font.pixelSize: fontPixelsize
            onClicked: on_cancel_clicked()
        }
    }

    function insertBiddingPauseSetChecked(checked)
    {
        insertBiddingPause.checked = checked
    }
    function biddingPauseLengthSetText(text)
    {
        biddingPauseLength.text = text
    }
    function biddingPauseSetValue(value)
    {
        biddingPause.value = value
    }
    function insertPlayPauseSetChecked(checked)
    {
        insertPlayPause.checked = checked
    }
    function playPauseLengthSetText(text)
    {
        playPauseLength.text = text
    }
    function playPauseSetValue(value)
    {
        playPause.value = value
    }
    function methodSetChecked(method)
    {
        if (method === iMP)
            teamsImp.checked = true
        else if (method === mP)
            duplicateMP.checked = true
        else if (method === rUBBER)
            rubberBridge.checked = true
        else
            practice.checked = true

    }
    function computerLevelSetChecked(computerLevel)
    {
        if (computerLevel === 0)
            computerLevel0.checked = true
        else if (computerLevel === 1)
            computerLevel1.checked = true
        else if (computerLevel === 2)
            computerLevel2.checked = true
        else
            computerLevel3.checked = true

    }
    function setZoom(zoom)
    {
        zf = zoom
    }
}
