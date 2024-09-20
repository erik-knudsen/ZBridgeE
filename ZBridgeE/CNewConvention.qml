/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CNewConvention.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Define new (bridge) convention.

  Platforms: Qt/QML.
*/
import QtQuick

CNewConventionForm {
    signal on_ok_clicked()
    signal on_cancel_clicked()

    cancel.onClicked:
    {
        on_cancel_clicked()
    }
    ok.onClicked:
    {
        on_ok_clicked()
    }

    function setRefConventionName(refConventionName)
    {
        refConvention.text = refConventionName
    }
    function getNewConventionName()
    {
        return newConvention.text
    }
    function setZoom(zoom)
    {
        zf = zoom
    }
}
