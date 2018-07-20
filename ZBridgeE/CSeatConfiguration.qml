/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CSeatConfiguration.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Seat configuration.

  Platforms: Qt/QML.
*/
import QtQuick 2.4

CSeatConfigurationForm {
    signal on_west_clicked()
    signal on_north_clicked()
    signal on_east_clicked()
    signal on_south_clicked()
    signal on_westActor_currentIndexChanged(int index)
    signal on_northActor_currentIndexChanged(int index)
    signal on_eastActor_currentIndexChanged(int index)
    signal on_southActor_currentIndexChanged(int index)
    signal on_role_currentIndexChanged(int index)
    signal on_buttonBox_accepted()
    signal on_buttonBox_rejected()

    dialogButtonBox.onRejected:
    {
        on_buttonBox_rejected()
    }

    dialogButtonBox.onAccepted:
    {
        on_buttonBox_accepted()
    }
    southActor.onCurrentIndexChanged:
    {
        on_southActor_currentIndexChanged(southActor.currentIndex)
    }
    south.onClicked:
    {
        on_south_clicked()
    }
    eastActor.onCurrentIndexChanged:
    {
        on_eastActor_currentIndexChanged(eastActor.currentIndex)
    }
    east.onClicked:
    {
        on_east_clicked()
    }
    northActor.onCurrentIndexChanged:
    {
        on_northActor_currentIndexChanged(northActor.currentIndex)
    }
    north.onClicked:
    {
        on_north_clicked()
    }
    westActor.onCurrentIndexChanged:
    {
        on_westActor_currentIndexChanged(westActor.currentIndex)
    }
    west.onClicked:
    {
        on_west_clicked()
    }
    role.onCurrentIndexChanged:
    {
        on_role_currentIndexChanged(role.currentIndex)
    }

    function setHostVisible(visible)
    {
        host.visible = visible
        hostLabel.visible = visible
    }
    function setHostEnable(enable)
    {
        host.enabled = enable
    }
    function setHostText(text)
    {
        host.text = text
    }
    function hostText()
    {
        return host.text
    }
    function setPortVisible(visible)
    {
        port.visible = visible
        portLabel.visible = visible
    }
    function setPortEnable(enable)
    {
        port.enabled = enable
    }
    function setPortText(text)
    {
        port.text = text
    }
    function portText()
    {
        return port.text
    }
    function roleAddItems(items)
    {
        role.model = items
    }
    function setRoleCurrentIndex(index)
    {
        role.currentIndex = index
    }
    function setNameVisible(seat, visible)
    {
        if (seat === 0)
            westName.visible = visible
        else if (seat === 1)
            northName.visible = visible
        else if (seat === 2)
            eastName.visible = visible
        else
            southName.visible = visible
    }
    function setNameText(seat, text)
    {
        if (seat === 0)
            westName.text = text
        else if (seat === 1)
            northName.text = text
        else if (seat === 2)
            eastName.text = text
        else
            southName.text = text
    }
    function nameText(seat)
    {
        if (seat === 0)
            return westName.text
        else if (seat === 1)
            return northName.text
        else if (seat === 2)
            return eastName.text
        else
            return southName.text
    }

    function setActorVisible(seat, visible)
    {
        if (seat === 0)
            westActor.visible = visible
        else if (seat === 1)
            northActor.visible = visible
        else if (seat === 2)
            eastActor.visible = visible
        else
            southActor.visible = visible
    }
    function setActorCurrentIndex(seat, index)
    {
        if (seat === 0)
            westActor.currentIndex = index
        else if (seat === 1)
            northActor.currentIndex = index
        else if (seat === 2)
            eastActor.currentIndex = index
        else
            southActor.currentIndex = index
    }
    function actorAddItems(seat, items)
    {
        if (seat === 0)
            westActor.model = items
        else if (seat === 1)
            northActor.model = items
        else if (seat === 2)
            eastActor.model = items
        else
            southActor.model = items
    }
    function setSeatChecked(seat)
    {
        if (seat === 0)
            west.checked = true
        else if (seat === 1)
            north.checked = true
        else if (seat === 2)
            east.checked = true
        else
            south.checked = true
    }
}
