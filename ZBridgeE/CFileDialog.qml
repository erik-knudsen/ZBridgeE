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
    signal on_buttonBox_accepted()
    signal on_buttonBox_rejected()

    id: item1
    property int fontPixelsize: 70
    property string fontFamily: "MS Shell Dlg 2"

    width: 1200
    height: 850

    ToolButton{
        id: localStorage
        anchors.top: directory.bottom
        anchors.left: parent.left
        font.pixelSize: fontPixelsize
        text: qsTr("L")
        onClicked: folderModel.folder = StandardPaths.writableLocation(StandardPaths.AppLocalDataLocation)
//        onClicked: console.log(StandardPaths.writableLocation(StandardPaths.DataLocation))
    }
    ToolButton{
        id: globalStorage
        anchors.top: directory.bottom
        anchors.left: localStorage.right
        anchors.leftMargin: 10
        font.pixelSize: fontPixelsize
        text: qsTr("G")
        onClicked: folderModel.folder = StandardPaths.writableLocation(StandardPaths.GenericDataLocation)
//        onClicked: console.log(StandardPaths.writableLocation(StandardPaths.GenericDataLocation))
    }

    Text {
        id: directory
        width: parent.width
        height: 60
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 10
        font.pixelSize: fontPixelsize / 2
        color: "steelblue"
    }

    Rectangle {
        id: fileName
        width: parent.width - 600
        height: 60
        anchors.left: globalStorage.right
        anchors.leftMargin: 200
        anchors.top: directory.bottom
        anchors.topMargin: 10
        TLineEdit {
            id: refFilename
            width: parent.width
            height: parent.height
            input.font.pixelSize: fontPixelsize / 2
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
        width: parent.width
        height: 550
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: fileName.bottom
        anchors.topMargin: 20
        model: folderModel

        delegate: Component {
            Item {
                width: parent.width
                height: 120
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

    Rectangle {
        id: footer
        width: parent.width
        height: 130
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: list.bottom
        anchors.topMargin: 10
        DialogButtonBox {
            id: dialogButtonBox
            width: parent.width
            height: parent.height
            standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel
            font.pixelSize: fontPixelsize
            onAccepted: on_buttonBox_accepted()
            onRejected: on_buttonBox_rejected()
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
}
