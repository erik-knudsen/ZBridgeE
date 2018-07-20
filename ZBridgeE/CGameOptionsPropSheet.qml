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
import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
Item {
    width: 930
    height: 820

    signal on_buttonBox_accepted()
    signal on_buttonBox_rejected()
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

    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    property int iMP: 0
    property int mP: 1
    property int rUBBER: 2
    property int pRACTICE: 3

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
                text: qsTr("Interface")
            }
            TabButton {
                text: qsTr("Scoring")
            }
            TabButton {
                text: qsTr("Level")
            }
        }
    }

    SwipeView {
        id: swipeView
        height: 600
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: header.bottom
        anchors.topMargin: 30
        currentIndex: tabBar.currentIndex
        font.pixelSize: fontPixelsize

        Item {
            id: item1
            GroupBox {
                id: groupBox1
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top: parent.top
                anchors.topMargin: 20

                  label: CheckBox {
                      id: insertBiddingPause
                      checked: true
                      text: qsTr("Insert pause between bids")
                      onClicked: on_insertBiddingPause_clicked(checked)
                  }
                  ColumnLayout {
                      id: col
                      anchors.fill: parent
                      enabled: insertBiddingPause.checked

                      Label {
                          id: biddingPauseLength
                          text: "Text"
                          verticalAlignment: Text.AlignVCenter
                          horizontalAlignment: Text.AlignHCenter
                          Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                      }
                      Slider {
                          id: biddingPause
                          anchors.left: parent.left
                          anchors.leftMargin: 30
                          anchors.right: parent.right
                          anchors.rightMargin: 30
                          from: 0
                          to: 10
                          stepSize: 1
                          snapMode: Slider.SnapAlways
                          onMoved: on_biddingPause_sliderMoved(value)
                      }
                  }
            }
            GroupBox {
                id: groupBox2
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top: groupBox1.bottom
                anchors.topMargin: 30

                label: CheckBox {
                    id: insertPlayPause
                      checked: true
                      text: qsTr("Insert pause between plays")
                      onClicked: on_insertPlayPause_clicked(checked)
                  }
                  ColumnLayout {
                      anchors.fill: parent
                      enabled: insertPlayPause.checked

                      Label {
                          id: playPauseLength
                          text: "Text"
                          verticalAlignment: Text.AlignVCenter
                          horizontalAlignment: Text.AlignHCenter
                          Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                      }
                      Slider {
                          id: playPause
                          anchors.left: parent.left
                          anchors.leftMargin: 30
                          anchors.right: parent.right
                          anchors.rightMargin: 30
                          from: 0
                          to: 10
                          stepSize: 1
                          snapMode: Slider.SnapAlways
                          onMoved: on_playPause_sliderMoved(value)
                      }
                 }
            }
        }

        Item {
            id: item2
            GroupBox {
                id: groupBox3
                width: 550
                height: 500
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                title: "Scoring Method"

                RadioButton {
                    id: teamsImp
                    text: qsTr("Teams IMP")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    onClicked: on_teamsIMP_clicked()
                }
                RadioButton {
                    id: duplicateMP
                    text: qsTr("Duplicate MP")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: teamsImp.bottom
                    anchors.topMargin: 0
                    onClicked: on_duplicateMP_clicked()
                }
                RadioButton {
                    id: rubberBridge
                    text: qsTr("Rubber Bridge")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: duplicateMP.bottom
                    anchors.topMargin: 0
                    onClicked: on_rubberBridge_clicked()
                }
                RadioButton {
                    id: practice
                    text: qsTr("Practice")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: rubberBridge.bottom
                    anchors.topMargin: 0
                    onClicked: on_practice_clicked()
                }
            }
        }

        Item {
            id: item3
            GroupBox {
                id: groupBox4
                width: 550
                height: 500
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                title: "Computer Level"

                RadioButton {
                    id: computerLevel0
                    text: qsTr("Level 0")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    onClicked: on_level0_clicked()
                }
                RadioButton {
                    id: computerLevel1
                    text: qsTr("Level 1")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: computerLevel0.bottom
                    anchors.topMargin: 0
                    onClicked: on_level1_clicked()
                }
                RadioButton {
                    id: computerLevel2
                    text: qsTr("Level 2")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: computerLevel1.bottom
                    anchors.topMargin: 0
                    onClicked: on_level2_clicked()
                }
                RadioButton {
                    id: computerLevel3
                    text: qsTr("Level 3")
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: computerLevel2.bottom
                    anchors.topMargin: 0
                    onClicked: on_level3_clicked()
                }
            }
        }
    }

    Rectangle {
        id: footer
        anchors.top: swipeView.bottom
        anchors.topMargin: 10
        width: parent.width
        height: 130
        DialogButtonBox {
            id: dialogButtonBox
            width: parent.width
            height: parent.height
            standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel
            font.pixelSize: fontPixelsize
            onAccepted: on_buttonBox_accepted()
            onRejected: on_buttonBox_rejected()
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
}
