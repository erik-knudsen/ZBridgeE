/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CDispOptionsPropSheet.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Display options property sheet.

  Platforms: Qt/QML.
*/

import QtQuick 2.4

CDispOptionsPropSheetForm {
    signal on_ok_clicked()
    signal on_cancel_clicked()
    signal on_cardBack0_clicked()
    signal on_cardBack1_clicked()
    signal on_cardBack2_clicked()
    signal on_cardBack3_clicked()
    signal on_cardBack4_clicked()
    signal on_cardBack5_clicked()

    property int cARD_BACK_0: 0
    property int cARD_BACK_1: 1
    property int cARD_BACK_2: 2
    property int cARD_BACK_3: 3
    property int cARD_BACK_4: 4
    property int cARD_BACK_5: 5

    cardBack5.onClicked:
    {
        on_cardBack5_clicked()
        setChecked(cARD_BACK_5)
    }
    cardBack4.onClicked:
    {
        on_cardBack4_clicked()
        setChecked(cARD_BACK_4)
    }
    cardBack3.onClicked:
    {
        on_cardBack3_clicked()
        setChecked(cARD_BACK_3)
    }
    cardBack2.onClicked:
    {
        on_cardBack2_clicked()
        setChecked(cARD_BACK_2)
    }
    cardBack1.onClicked:
    {
        on_cardBack1_clicked()
        setChecked(cARD_BACK_1)
    }
    cardBack0.onClicked:
    {
        on_cardBack0_clicked()
        setChecked(cARD_BACK_0)
    }
    cancel.onClicked:
    {
        on_cancel_clicked()
    }
    ok.onClicked:
    {
        on_ok_clicked()
    }

    function setChecked(cardBack)
    {
        cardBack0.checked = (cardBack === cARD_BACK_0)
        cardBack1.checked = (cardBack === cARD_BACK_1)
        cardBack2.checked = (cardBack === cARD_BACK_2)
        cardBack3.checked = (cardBack === cARD_BACK_3)
        cardBack4.checked = (cardBack === cARD_BACK_4)
        cardBack5.checked = (cardBack === cARD_BACK_5)
    }
    function setZoom(zoom)
    {
        zf = zoom
    }
}
