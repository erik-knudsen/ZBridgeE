/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMainScoreDialog_Practice.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: DMain score dialog Practice.

  Platforms: Qt/QML.
*/
import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: item1
    width: 900
    height: 850

    signal rowClicked(int row)
    signal cellClicked(int row, int column)
    signal on_OKButton_Clicked()

    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"
    property int h: 90

    Button {
        id: okButton
        font.pixelSize: fontPixelsize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 0
        onClicked: on_OKButton_Clicked()
    }

    GroupBox {
        id: groupBox
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: okButton.bottom
        anchors.topMargin: 10
        height: 150
        font.pixelSize: fontPixelsize / 2
        title: qsTr("Participants")

        Grid {
            id: grid
            rows: 2
            columns: 2
            anchors.fill: parent

            Label {
                id: label
                text: qsTr("NS: ")
            }
            Label {
                id: nsNames
                text: qsTr(" ")
            }
            Label {
                id: label1
                text: qsTr("EW: ")
            }
            Label {
                id: ewNames
                text: qsTr(" ")
            }
        }
    }

    Label {
        id: scoringMethod
        text: qsTr(" ")
        font.pixelSize: fontPixelsize / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: groupBox.bottom
        anchors.topMargin: 20
    }

    ListModel {
        id: scoreModel
/*        ListElement {
            board: "1"
            vul: "NONE"
            contract: "4S"
            tricks: "10"
            score: "490"
        }
        ListElement {
            board: "2"
            vul: "ALL"
            contract: "3S"
            tricks: "9"
            score: "140"
        }
        */
    }
    Component {
        id: scoreDelegate
        Row {
            id: row
            spacing: 1
            property int inx: index
            ItemDelegate {
                width: listView.headerItem.headerAt(0).width
                height: h
                font.pixelSize: fontPixelsize
                text: board
                padding: 0
                leftPadding: 15
                onClicked: rowClicked(row.inx)
            }
            Text {
                width: listView.headerItem.headerAt(1).width
                height: h
                font.pixelSize: fontPixelsize
                text: vul
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                width: listView.headerItem.headerAt(2).width
                height: h
                font.pixelSize: fontPixelsize
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: contract
            }
            Text {
                width: listView.headerItem.headerAt(3).width
                height: h
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: fontPixelsize
                horizontalAlignment: Text.AlignHCenter
                text: tricks
            }
            Text {
                width: listView.headerItem.headerAt(4).width
                height: h
                font.pixelSize: fontPixelsize
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: score
            }
        }
    }

    ListView {
        id: listView
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: scoringMethod.bottom
        anchors.topMargin: 20

        contentWidth: headerItem.width
        flickableDirection: Flickable.HorizontalAndVerticalFlick

        header: Row {
            spacing: 1
            function headerAt(index) { return headerRepeater.itemAt(index) }
            Repeater {
                id: headerRepeater
                model: ["Board", "Vulnerability", "Contract", "Tricks", "Score"]
                Label {
                    text: modelData
                    font.bold: true
                    font.pixelSize: fontPixelsize
                    padding: 10
                    background: Rectangle { color: "silver" }
                }
            }
        }
        headerPositioning: ListView.PullBackHeader

        model: scoreModel
        delegate: scoreDelegate

        ScrollIndicator.horizontal: ScrollIndicator { }
        ScrollIndicator.vertical: ScrollIndicator { }
    }

    function resetScoreModel()
    {
        scoreModel.clear()
    }
    function addToScoreModel(board, vulnerability, contract, tricks, score)
    {
        scoreModel.append({"board": board, "vul": vulnerability, "contract": contract,
                          "tricks": tricks, "score": score})
    }
    function scoringMethodSetText(text)
    {
        scoringMethod.text = text
    }
    function ewNamesSetText(text)
    {
        ewNames.text = text
    }
    function nsNamesSetText(text)
    {
        nsNames.text = text
    }
}
