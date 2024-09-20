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
import QtQuick
import QtQuick.Controls

Item {
    id: cPopup

    property int zf: 10

    property int fontPixelsize: 4 * zf
    property string fontFamily: "MS Shell Dlg 2"

//    implicitWidth: description.implicitWidth
//    implicitHeight: description.implicitHeight


    Text {
        id: description
        font.family: fontFamily
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
        if (m > k)
            k = m;

        description.text = text
        width = k * fontPixelsize / 2
        height = (j + 2) * (fontPixelsize + 3)
    }
    function setZoom(zoom)
    {
        zf = zoom
    }
}
