/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CTLineEdit.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Line edit.

  Platforms: Qt/QML.
*/
import QtQuick 2.7

FocusScope {
    id: root
    signal editingFinished()

    property string okColor: "lightsteelblue"
    property string errColor: "red"
    property bool ok: true

    Rectangle {
        id: bck
        anchors.fill: parent
        color: (ok) ? (okColor) : (errColor)
        border.color: "gray"
    }

    property alias text: input.text
    property alias input: input

    TextInput {
    id: input
    anchors.fill: parent
    anchors.margins: 4
    focus: true
    clip: true
    autoScroll: true
    onEditingFinished: root.editingFinished()
    }
}
