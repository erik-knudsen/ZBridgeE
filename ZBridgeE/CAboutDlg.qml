/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CAboutDlg.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: About ZBridge.

  Platforms: Qt/QML.
*/

import QtQuick

CAboutDlgForm {
    signal on_OKButton_Clicked()

    okButton.onClicked:
    {
        on_OKButton_Clicked()
    }

    function setZoom(zoom)
    {
        zf = zoom
    }
}
