/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CPlayShow.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Show play (forward and backward buttons).

  Platforms: Qt/QML.
*/
import QtQuick
import QtQuick.Controls

Item {
    id: cPlayShow
    width: 115
    height: 60

    signal on_reviewPrev_clicked()
    signal on_reviewNext_clicked();

    ToolButton {
        id: reviewPrev
        width: 50
        text: qsTr("")
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 10
        onClicked: on_reviewPrev_clicked()

        Image {
            id: image
            anchors.fill: parent
            source: "qrc:///resources/review_prev.ico"
        }
    }

    ToolButton {
        id: reviewNext
        width: 50
        text: qsTr("")
        anchors.left: reviewPrev.right
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 10
        onClicked: on_reviewNext_clicked()

        Image {
            id: image1
            anchors.fill: parent
            source: "qrc:///resources/review_next.ico"
        }
    }

    function reviewPrevIsEnabled()
    {
        return reviewPrev.enabled
    }
    function reviewNextIsEnabled()
    {
        return reviewNext.enabled
    }
    function reviewPrevSetEnabled(enabled)
    {
        reviewPrev.enabled = enabled
    }
    function reviewNextSetEnabled(enabled)
    {
        reviewNext.enabled = enabled
    }
}
