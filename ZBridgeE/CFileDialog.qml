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
import QtQuick 2.4
import QtQuick.Controls 2.2
import Qt.labs.platform 1.0
import Qt.labs.folderlistmodel 2.1

Item {
    signal on_ok_clicked()
    signal on_cancel_clicked()

    id: item1

    property int zf: 10

    property int fontPixelsize: 7 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 120 * zf
    height: 95 * zf

    ToolButton{
        id: localStorage
        height: 15 * zf
        width: 15 * zf
        anchors.top: directory.bottom
        anchors.left: parent.left
        font.pixelSize: fontPixelsize
        text: qsTr("L")
        onClicked: folderModel.folder = StandardPaths.writableLocation(StandardPaths.AppLocalDataLocation)
//        onClicked: console.log(StandardPaths.writableLocation(StandardPaths.DataLocation))
    }
    ToolButton{
        id: globalStorage
        height: 15 * zf
        width: 15 * zf
        anchors.top: directory.bottom
        anchors.left: localStorage.right
        anchors.leftMargin: 1 * zf
        font.pixelSize: fontPixelsize
        text: qsTr("G")
        onClicked: folderModel.folder = StandardPaths.writableLocation(StandardPaths.GenericDataLocation)
//        onClicked: console.log(StandardPaths.writableLocation(StandardPaths.GenericDataLocation))
    }

    Text {
        id: directory
        width: parent.width
        height: 6 * zf
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 1 * zf
        font.pixelSize: fontPixelsize / 2
        color: "steelblue"
    }

        TLineEdit {
            id: refFilename
            width: parent.width - 50 * zf
            height: 9 * zf
            anchors.left: globalStorage.right
            anchors.leftMargin: 20 * zf
            anchors.top: directory.bottom
            anchors.topMargin: 1 * zf
            input.font.pixelSize: fontPixelsize
            input.font.family: fontFamily
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
        width: parent.width
        height: 55 * zf
        anchors.left: parent.left
        anchors.leftMargin: 0 * zf
        anchors.top: localStorage.bottom
        anchors.topMargin: 2 * zf
        model: folderModel

        delegate: Component {
            Item {
                width: parent.width
                height: 12 * zf
                Text {
                    text: fileName
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

    Row
    {
        id: okBox
        anchors.top: list.bottom
        anchors.topMargin: 4 *zf
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 1 * zf

        Button {
            id: ok
            width: 10 * fontPixelsize/2
            text: qsTr("OK")
            font.pixelSize: fontPixelsize
            onClicked: on_ok_clicked()
        }

        Button {
            id: cancel
            width: 10 * fontPixelsize/2
            text: qsTr("Cancel")
            font.pixelSize: fontPixelsize
            onClicked: on_cancel_clicked()
        }
    }

    function setNameFilters(nameFilters)
    {
        folderModel.nameFilters = nameFilters
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
