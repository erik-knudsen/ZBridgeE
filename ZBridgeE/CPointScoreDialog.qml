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

    signal namesClicked(int row)
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

    Label {
        id: board
        text: qsTr("board")
        font.pixelSize: fontPixelsize / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: okButton.bottom
        anchors.topMargin: 2 * zf
    }

    Label {
        id: vulnerability
        text: qsTr("vulnerability")
        font.pixelSize: fontPixelsize / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: board.bottom
        anchors.topMargin: 1 * zf
    }

    Label {
        id: scoringMethod
        text: qsTr("scoring method")
        font.pixelSize: fontPixelsize / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        anchors.top: vulnerability.bottom
        anchors.topMargin: 1 * zf
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
                font.pixelSize: fontPixelsize
                text: name
                padding: 0 * zf
                leftPadding: 1.5 * zf
                onClicked: namesClicked(row.inx)
            }
            Text {
                width: listView.headerItem.headerAt(1).width
                height: h
                font.pixelSize: fontPixelsize
                text: contract
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                width: listView.headerItem.headerAt(2).width
                height: h
                font.pixelSize: fontPixelsize
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: tricks
            }
            Text {
                width: listView.headerItem.headerAt(3).width
                height: h
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: fontPixelsize
                horizontalAlignment: Text.AlignHCenter
                text: score
            }
            Text {
                width: listView.headerItem.headerAt(4).width
                height: h
                font.pixelSize: fontPixelsize
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: point
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
                model: ["      Name NS / EW      ", "Contract", "Tricks", "Score", "Point"]
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
    function setZoom(zoom)
    {
        zf = zoom
    }
}
