/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMainScoreDialog_MP.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Main score dialog IMP/MP.

  Platforms: Qt/QML.
*/
import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: item1

    signal rowClicked(int row)
    signal cellClicked(int row, int column)
    signal on_OKButton_Clicked()

    property int zf: 10

    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"
    property int h: 9 * zf

    width: 105 * zf
    height: 85 * zf

    Button {
        id: okButton
        font.pixelSize: fontPixelsize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.top: parent.top
        anchors.topMargin: 0 * zf
        onClicked: on_OKButton_Clicked()
    }

    GroupBox {
        id: groupBox
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: okButton.bottom
        anchors.topMargin: 0 * zf
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
            boardRes: "450"
            allRes: "300"
        }
        ListElement {
            board: "2"
            vul: "ALL"
            contract: "3S"
            tricks: "9"
            score: "140"
            boardRes: "60"
            allRes: "100"
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
                padding: 0 * zf
                leftPadding: 1.5 * zf
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
            ItemDelegate {
                width: listView.headerItem.headerAt(5).width
                height: h
                font.pixelSize: fontPixelsize
                text: boardRes
                padding: 0 * zf
                leftPadding: 1.5 * zf
                onClicked: cellClicked(row.inx, 5)
            }
            ItemDelegate {
                width: listView.headerItem.headerAt(6).width
                height: h
                font.pixelSize: fontPixelsize
                text: allRes
                padding: 0 * zf
                leftPadding: 1 * zf
                onClicked: cellClicked(row.inx, 6)
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

        header: Row {
            spacing: 1
            function headerAt(index) { return headerRepeater.itemAt(index) }
            Repeater {
                id: headerRepeater
                model: ["Board", "Vulnerability", "Contract", "Tricks", "Score", "Result", " All "]
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
    function addToScoreModel(board, vulnerability, contract, tricks, score, result, all)
    {
        scoreModel.append({"board": board, "vul": vulnerability, "contract": contract,
                          "tricks": tricks, "score": score, "boardRes": result,
                          "allRes": all})
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
