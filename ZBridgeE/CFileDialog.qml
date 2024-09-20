/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CFileDialog.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: File dialog.

  Platforms: Qt/QML.
*/
import QtQuick
import QtQuick.Controls
import Qt.labs.platform
import Qt.labs.folderlistmodel
import QtQuick.Layouts

Item {
    signal on_ok_clicked()
    signal on_cancel_clicked()

    id: item1

    property int zf: 10

    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 120 * zf
    height: 110 * zf

    Text {
        id: directory
        width: parent.width
        height: 6 * zf
        anchors.leftMargin: 1 * zf
        font.family: fontFamily
        font.pixelSize: fontPixelsize / 2
        color: "steelblue"
    }

    RowLayout {
        id: row0
        anchors.top : directory.bottom

        RowLayout {
            id: row1
            RadioButton {
                id: localStorage
                Layout.preferredHeight: 15 * zf
                Layout.preferredWidth: 25 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("L")
                onClicked: folderModel.folder = StandardPaths.writableLocation(StandardPaths.AppLocalDataLocation)
//              onClicked: console.log(StandardPaths.writableLocation(StandardPaths.DataLocation))
            }
            RadioButton {
                id: globalStorage
                Layout.preferredHeight: 15 * zf
                Layout.preferredWidth: 25 * zf
                font.pixelSize: fontPixelsize
                text: qsTr("G")
                onClicked: folderModel.folder = StandardPaths.writableLocation(StandardPaths.GenericDataLocation)
//                onClicked: console.log(StandardPaths.writableLocation(StandardPaths.GenericDataLocation))
            }
        }

        TLineEdit {
            id: refFilename
            Layout.preferredWidth: 59 * zf
            Layout.preferredHeight: 15 * zf
            input.font.pixelSize: fontPixelsize
            input.font.family: fontFamily
        }
    }

    FolderListModel {
        id: folderModel
        showDirs: true
        showDirsFirst: true
        showDotAndDotDot: true
        nameFilters: ["*"]
    }

    ListView {
        id: list
        width: item1.width-15
        height: 55 * zf
        anchors.left: parent.left
        anchors.leftMargin: 2 * zf
        anchors.top: row0.bottom
        anchors.topMargin: 2 * zf
        model: folderModel

        delegate: Component {
            Item {
                width: item1.width-15
                height: 12 * zf
                Text {
                    text: fileName
                    font.family: fontFamily
                    font.pixelSize: fontPixelsize
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        list.currentIndex = index
                        if (folderModel.isFolder(index))
                        {
                            folderModel.folder = folderModel.get(index, "fileURL")
                            list.currentIndex = 0
                        }
                    }
                }
            }
        }
        highlight: Rectangle {
            color: 'grey'
        }
        focus: true
        onCurrentItemChanged: {
            directory.text = getPath()
            refFilename.text = folderModel.get(list.currentIndex, "fileName")
        }
    }

    RowLayout
    {
        id: okBox
        anchors.top: list.bottom
        anchors.topMargin: 4 *zf
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 1 * zf

        Button {
            id: ok
            Layout.preferredWidth: 12 * fontPixelsize/2+10
            text: qsTr("OK")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
            onClicked: on_ok_clicked()
        }

        Button {
            id: cancel
            Layout.preferredWidth: 12 * fontPixelsize/2+10
            text: qsTr("Cancel")
            font.family: fontFamily
            font.pixelSize: fontPixelsize
            onClicked: on_cancel_clicked()
        }
    }

    function setNameFilters(nameFilters)
    {
        folderModel.nameFilters = nameFilters
    }
    function globalStorageSetChecked()
    {
            localStorage.checked = true
    }
    function getFileURL()
    {
        return folderModel.get(list.currentIndex, "fileURL")
    }
    function getFileName()
    {
        return (getPath() + refFilename.text)
    }
    function getPath()
    {
        var path = folderModel.get(list.currentIndex, "filePath")
        var inx = path.lastIndexOf("/")
        if (inx >= 0)
            return path.slice(0, inx + 1)
        else
            return ""
    }
    function setZoom(zoom)
    {
        zf = zoom
    }
}
