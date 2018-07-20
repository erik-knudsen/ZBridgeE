/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CRankScoreDialog.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Show rank score.

  Platforms: Qt/QML.
*/
import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: item1
    width: 900
    height: 850

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
        id: scoringMethod
        text: qsTr("scoring method")
        font.pixelSize: fontPixelSize / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: okButton.bottom
        anchors.topMargin: 10
    }

    ListModel {
        id: scoreModel
/*        ListElement {
            name: "Pedersen"
            point: "4.5"
        }
        ListElement {
            name: "Nielsen"
            point: "6.7"
        }
*/
        property string sortColumnName: "point"

        function swap(a,b) {
            if (a<b) {
                move(a,b,1);
                move (b-1,a,1);
            }
            else if (a>b) {
                move(b,a,1);
                move (a-1,b,1);
            }
        }

        function partition(begin, end, pivot)
        {
            var piv=Number(get(pivot)[sortColumnName]);
            swap(pivot, end-1);
            var store=begin;
            var ix;
            for(ix=begin; ix<end-1; ++ix) {
                if(Number(get(ix)[sortColumnName]) < piv) {
                    swap(store,ix);
                    ++store;
                }
            }
            swap(end-1, store);

            return store;
        }

        function qsort(begin, end)
        {
            if(end-1>begin) {
                var pivot=begin+Math.floor(Math.random()*(end-begin));

                pivot=partition( begin, end, pivot);

                qsort(begin, pivot);
                qsort(pivot+1, end);
            }
        }

        function sort() {
            qsort(0,count)
        }
    }
    Component {
        id: scoreDelegate
        Row {
            id: row
            spacing: 1
            property int inx: index
            Text {
                width: listView.headerItem.headerAt(0).width
                height: h
                font.pixelSize: fontPixelSize
                text: name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                width: listView.headerItem.headerAt(1).width
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
                model: ["               Name               ", "Point"]
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
    function addToScoreModel(name, point)
    {
        scoreModel.append({"name": name, "point": point})
    }
    function scoringMethodSetText(text)
    {
        scoringMethod.text = text
    }
    function sort() {
        scoreModel.sort()
    }
}