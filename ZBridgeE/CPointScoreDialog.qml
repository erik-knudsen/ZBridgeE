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
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

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
        font.family: fontFamily
        font.pixelSize: fontPixelsize
        text: qsTr("OK")
        anchors.right: parent.right
        anchors.rightMargin: 1 * zf
        anchors.top: parent.top
        anchors.topMargin: 0 * zf
        onClicked: on_OKButton_Clicked()
    }

    ColumnLayout {
        id: col
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: okButton.left
        Label {
            id: board
            text: qsTr("board")
            font.family: fontFamily
            font.pixelSize: fontPixelsize / 2
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            id: vulnerability
            text: qsTr("vulnerability")
            font.family: fontFamily
            font.pixelSize: fontPixelsize / 2
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            id: scoringMethod
            text: qsTr("scoring method")
            font.family: fontFamily
            font.pixelSize: fontPixelsize / 2
            Layout.alignment: Qt.AlignHCenter
        }
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
        RowLayout {
            id: row
            spacing: 1
            property int inx: index
            ItemDelegate {
                Layout.preferredWidth: listView.headerItem.headerAt(0).width
                Layout.preferredHeight: h
                font.family: fontFamily
                font.pixelSize: fontPixelsize
                text: name
                padding: 0 * zf
                leftPadding: 1.5 * zf
                onClicked: namesClicked(row.inx)
            }
            Text {
                Layout.preferredWidth: listView.headerItem.headerAt(1).width
                Layout.preferredHeight: h
                font.family: fontFamily
                font.pixelSize: fontPixelsize
                text: contract
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                Layout.preferredWidth: listView.headerItem.headerAt(2).width
                Layout.preferredHeight: h
                font.family: fontFamily
                font.pixelSize: fontPixelsize
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: tricks
            }
            Text {
                Layout.preferredWidth: listView.headerItem.headerAt(3).width
                Layout.preferredHeight: h
                verticalAlignment: Text.AlignVCenter
                font.family: fontFamily
                font.pixelSize: fontPixelsize
                horizontalAlignment: Text.AlignHCenter
                text: score
            }
            Text {
                Layout.preferredWidth: listView.headerItem.headerAt(4).width
                Layout.preferredHeight: h
                font.family: fontFamily
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
        anchors.top: col.bottom
        anchors.topMargin: 2 * zf

        contentWidth: headerItem.width
        flickableDirection: Flickable.HorizontalAndVerticalFlick

        header: RowLayout {
            spacing: 1
            function headerAt(index) { return headerRepeater.itemAt(index) }
            Repeater {
                id: headerRepeater
                model: ["      Name NS / EW      ", "Contract", "Tricks", "Score", "Point"]
                Label {
                    text: modelData
                    font.bold: true
                    font.family: fontFamily
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
