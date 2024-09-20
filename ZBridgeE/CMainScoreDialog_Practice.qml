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
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: item1

    signal rowClicked(int row)
    signal cellClicked(int row, int column)
    signal on_OKButton_Clicked()

    property int zf: 10

    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"
    property int h: 9 * zf

    width: 115 * zf
    height: 100 * zf

    Button {
        id: okButton
        font.pixelSize: fontPixelsize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.top: parent.top
        anchors.topMargin: 8 * zf
        onClicked: on_OKButton_Clicked()
    }

    GroupBox {
        id: groupBox
        anchors.right: okButton.left
        anchors.rightMargin: 1 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: parent.top
        anchors.topMargin: 1 * zf
        font.pixelSize: fontPixelsize / 2
        title: qsTr("Participants")

        GridLayout {
            id: grid
            rows: 2
            columns: 2
            anchors.fill: parent

            Label {
                id: label
                Layout.preferredWidth: 8 * zf
                text: qsTr("NS: ")
            }
            Label {
                id: nsNames
                Layout.preferredWidth: 50 * zf
                text: qsTr(" ")
            }
            Label {
                id: label1
                Layout.preferredWidth: 8 * zf
                text: qsTr("EW: ")
            }
            Label {
                id: ewNames
                Layout.preferredWidth: 50 * zf
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
        anchors.rightMargin: 1 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: groupBox.bottom
        anchors.topMargin: 2 * zf
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
        RowLayout {
            id: row
            spacing: 1
            property int inx: index
            ItemDelegate {
                Layout.preferredWidth: listView.headerItem.headerAt(0).width
                Layout.preferredHeight: h
                font.pixelSize: fontPixelsize
                text: board
                padding: 0 * zf
                leftPadding: 1.5 * zf
                onClicked: rowClicked(row.inx)
            }
            Text {
                Layout.preferredWidth: listView.headerItem.headerAt(1).width
                Layout.preferredHeight: h
                font.pixelSize: fontPixelsize
                text: vul
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                Layout.preferredWidth: listView.headerItem.headerAt(2).width
                Layout.preferredHeight: h
                font.pixelSize: fontPixelsize
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: contract
            }
            Text {
                Layout.preferredWidth: listView.headerItem.headerAt(3).width
                Layout.preferredHeight: h
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: fontPixelsize
                horizontalAlignment: Text.AlignHCenter
                text: tricks
            }
            Text {
                Layout.preferredWidth: listView.headerItem.headerAt(4).width
                Layout.preferredHeight: h
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
        anchors.rightMargin: 0 * zf
        anchors.left: parent.left
        anchors.leftMargin: 0 * zf
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0 * zf
        anchors.top: scoringMethod.bottom
        anchors.topMargin: 2 * zf

        contentWidth: headerItem.width
        flickableDirection: Flickable.HorizontalAndVerticalFlick

        header: RowLayout {
            spacing: 1
            function headerAt(index) { return headerRepeater.itemAt(index) }
            Repeater {
                id: headerRepeater
                model: ["Board", "Vulnerability", "Contract", "Tricks", "Score"]
                Label {
                    text: modelData
                    font.bold: true
                    font.pixelSize: fontPixelsize
                    padding: 1 * zf
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
    function setZoom(zoom)
    {
        zf = zoom
    }
}
