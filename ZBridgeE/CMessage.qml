/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMessage.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Show message.

  Platforms: Qt/QML.
*/
import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

CMessageForm {
    signal onAccepted()
    signal onRejected()

    dialogButtonBox.onRejected:
    {
        onRejected()
    }
    dialogButtonBox.onAccepted:
    {
        onAccepted()
    }

    function question(boxTitle, boxText)
    {
        title.text = boxTitle
        desc.text = boxText
        dialogButtonBox.standardButtons = DialogButtonBox.Yes | DialogButtonBox.No
        image.source = "qrc:///resources/qmessagebox-quest.png"
    }
    function information(boxTitle, boxText)
    {
        title.text = boxTitle
        desc.text = boxText
        dialogButtonBox.standardButtons = DialogButtonBox.Ok
        image.source = "qrc:///resources/qmessagebox-info.png"
    }
    function warning(boxTitle, boxText)
    {
        title.text = boxTitle
        desc.text = boxText
        dialogButtonBox.standardButtons = DialogButtonBox.Ok
        image.source = "qrc:///resources/qmessagebox-warn.png"
    }
    function critical(boxTitle, boxText)
    {
        title.text = boxTitle
        desc.text = boxText
        dialogButtonBox.standardButtons = DialogButtonBox.Ok
        image.source = "qrc:///resources/qmessagebox-crit.png"
    }
    function setZoom(zoom)
    {
        zf = zoom
    }
}
