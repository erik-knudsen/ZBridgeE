/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CDDTable.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Double dummy table.

  Platforms: Qt/QML.
*/

import QtQuick

CDDTableForm {
    signal on_OKButton_Clicked()

    okButton.onClicked:
    {
        on_OKButton_Clicked()
    }

    function tricksNTNSSetText(text)
    {
        tricksNTNS.text = text
    }
    function tricksNTEWSetText(text)
    {
        tricksNTEW.text = text
    }
    function tricksSNSSetText(text)
    {
        tricksSNS.text = text
    }
    function tricksSEWSetText(text)
    {
        tricksSEW.text = text
    }
    function tricksHNSSetText(text)
    {
        tricksHNS.text = text
    }
    function tricksHEWSetText(text)
    {
        tricksHEW.text = text
    }
    function tricksDNSSetText(text)
    {
        tricksDNS.text = text
    }
    function tricksDEWSetText(text)
    {
        tricksDEW.text = text
    }
    function tricksCNSSetText(text)
    {
        tricksCNS.text = text
    }
    function tricksCEWSetText(text)
    {
        tricksCEW.text = text
    }
    function parScoreSetText(text)
    {
        parScore.text = text
    }
    function parContractSetText(text)
    {
        parContract.text = text
    }
    function setZoom(zoom)
    {
//        zf = zoom
    }
}
