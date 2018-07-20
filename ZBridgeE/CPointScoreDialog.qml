/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CPointScoreDialog.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Point score dialog.

  Platforms: Qt/QML.
*/
import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: item1
    width: 900
    height: 850

    signal namesClicked(int row)
    signal on_OKButton_Clicked()

    property int fontPixelSize: 70
    property string fontFamily: "MS Shell Dlg 2"
    property int h: 90

    Button {
        id: okButton
        font.pixelSize: fontPixelSize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 0
        onClicked: on_OKButton_Clicked()
    }

    Label {
        id: board
        text: qsTr("board")
        font.pixelSize: fontPixelSize / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: okButton.bottom
        anchors.topMargin: 20
    }

    Label {
        id: vulnerability
        text: qsTr("vulnerability")
        font.pixelSize: fontPixelSize / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: board.bottom
        anchors.topMargin: 10
    }

    Label {
        id: scoringMethod
        text: qsTr("scoring method")
        font.pixelSize: fontPixelSize / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: vulnerability.bottom
        anchors.topMargin: 10
    }

    ListModel {
        id: scoreModel
/*        ListElement {
            name: "Pedersen / Hansen"
            contract: "4S"
            tricks: "10"
            score: "490"
            point: "450"
        }
        ListElement {
            name: "Nielsen / Christensen"
            contract: "4S"
            tricks: "10"
            score: "490"
            point: "450"
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
                font.pixelSize: fontPixelSize
                text: name
                padding: 0
                leftPadding: 15
                onClicked: namesClicked(row.inx)
            }
            Text {
                width: listView.headerItem.headerAt(1).width
                height: h
                font.pixelSize: fontPixelSize
                text: contract
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                width: listView.headerItem.headerAt(2).width
                height: h
                font.pixelSize: fontPixelSize
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: tricks
            }
            Text {
                width: listView.headerItem.headerAt(3).width
                height: h
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: fontPixelSize
                horizontalAlignment: Text.AlignHCenter
                text: score
            }
            Text {
                width: listView.headerItem.headerAt(4).width
                height: h
                font.pixelSize: fontPixelSize
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: point
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
                model: ["      Name NS / EW      ", "Contract", "Tricks", "Score", "Point"]
                Label {
                    text: modelData
                    font.bold: true
                    font.pixelSize: fontPixelSize
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
    function addToScoreModel(name, contract, tricks, score, point)
    {
        scoreModel.append({"name": name, "contract": contract,
                          "tricks": tricks, "score": score, "point": point})
    }
    function scoringMethodSetText(text)
    {
        scoringMethod.text = text
    }
    function vulnerabilitySetText(text)
    {
        vulnerability.text = text
    }
    function boardSetText(text)
    {
        board.text = text
    }
}
