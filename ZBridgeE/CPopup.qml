/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CPopup.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Show popup.

  Platforms: Qt/QML.
*/
import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    property int fontPixelsize: 25
    property string fontFamily: "MS Shell Dlg 2"

    id: cPopup
//    implicitWidth: description.implicitWidth
//    implicitHeight: description.implicitHeight


    Text {
        id: description
        font.pixelSize: fontPixelsize
        text: qsTr("Label         \n nnnnnnnn")
        anchors.fill: parent
    }

    function descriptionSetText(text)
    {
        var j = 0;
        var k = 0;
        var m = 0;
        for (var i = 0; i < text.length; i++)
        {
            m++;
            if (text.charAt(i) === '\n')
            {
                j++;
                if (m > k)
                    k = m;
                m = 0;
            }
        }

        description.text = text
        width = k * fontPixelsize / 2
        height = (j + 1) * (fontPixelsize + 8)
    }
}
