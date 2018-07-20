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
import QtQuick 2.4

CNewConventionForm {
    signal onAccepted()
    signal onRejected()

    buttonBox.onRejected:
    {
        onRejected()
    }
    buttonBox.onAccepted:
    {
        onAccepted()
    }

    function setRefConventionName(refConventionName)
    {
        refConvention.text = refConventionName
    }
    function getNewConventionName()
    {
        return newConvention.text
    }
}
