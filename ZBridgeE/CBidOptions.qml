/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBidOptions.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Bid options.

  Platforms: Qt/QML.
*/

import QtQuick 2.4

CBidOptionsForm {
    signal on_northSouth_clicked()
    signal on_eastWest_clicked()
    signal on_northSouthConvention_currentIndexChanged(int index)
    signal on_eastWestConvention_currentIndexChanged(int index)
    signal on_newConvention_clicked()
    signal on_editConvention_clicked()
    signal on_deleteConvention_clicked()
    signal on_buttonBox_accepted()
    signal on_buttonBox_rejected()

    buttonBox.onRejected:
    {
        on_buttonBox_rejected()
    }
    buttonBox.onAccepted:
    {
        on_buttonBox_accepted()
    }
    deleteConvention.onClicked:
    {
        on_deleteConvention_clicked()
    }
    editConvention.onClicked:
    {
        on_editConvention_clicked()
    }
    newConvention.onClicked:
    {
        on_newConvention_clicked()
    }
    eastWest.onClicked:
    {
        on_eastWest_clicked()
    }
    northSouth.onClicked:
    {
        on_northSouth_clicked()
    }
    eastWestConvention.onCurrentIndexChanged:
    {
        on_eastWestConvention_currentIndexChanged(eastWestConvention.currentIndex)
    }
    northSouthConvention.onCurrentIndexChanged:
    {
        on_northSouthConvention_currentIndexChanged(northSouthConvention.currentIndex)
    }
    function addNorthSouthConventionItem(text)
    {
        nsModel.append({text: text})
    }
    function addEastWestConventionItem(text)
    {
        ewModel.append({text: text})
    }
    function removeNorthSouthConventionItem(index)
    {
        nsModel.remove(index)
    }
    function removeEastWestConventionItem(index)
    {
        ewModel.remove(index)
    }
    function findNorthSouthConventionText(text)
    {
        return northSouthConvention.find(text)
    }
    function findEastWestConventionText(text)
    {
        return eastWestConvention.find(text)
    }
    function northSouthConventionCurrentText()
    {
        return northSouthConvention.currentText
    }
    function eastWestConventionCurrentText()
    {
        return eastWestConvention.currentText
    }
    function setNorthSouthConventionCurrentIndex(index)
    {
        northSouthConvention.currentIndex = index
    }
    function setEastWestConventionCurrentIndex(index)
    {
        eastWestConvention.currentIndex = index
    }
    function setNorthSouthConventionEnable(enable)
    {
        northSouthConvention.enabled = enable
    }
    function setEastWestConventionEnable(enable)
    {
        eastWestConvention.enabled = enable
    }
    function setNorthSouthChecked()
    {
            northSouth.checked = true
    }
    function setEastWestChecked()
    {
            eastWest.checked = true
    }
    function isNorthSouthChecked()
    {
        return northSouth.checked
    }
    function isEastWestChecked()
    {
        return eastWest.checked
    }
    function setDeleteConventionEnable(enable)
    {
        deleteConvention.enabled = enable
    }
    function setEditConventionEnable(enable)
    {
        editConvention.enabled = enable
    }
}