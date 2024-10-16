/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CContentList.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: List with help content.

  Platforms: Qt/QML.
*/
import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

FocusScope {
    id: root
    signal contentSelected(url url)
    signal contentExit()

    property int zf: 10
    property int fontPixelsize: 6 * zf
    property string fontFamily: "MS Shell Dlg 2"

    ColumnLayout {
        spacing: 0
        anchors.fill: parent

        ToolBar {
            id: headerBackground
            Layout.fillWidth: true

            Label {
                id: headerText
                width: parent.width
                text: qsTr("Content")
                font.pixelSize: fontPixelsize
                font.family: fontFamily
                font.bold: true
                anchors.centerIn: parent
            }
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            keyNavigationWraps: true
            clip: true
            focus: true
            ScrollBar.vertical: ScrollBar { }

            model: contentModel

            delegate: ItemDelegate {
                width: parent.width
                height: fontPixelsize+15
                text: model.name
                font.pixelSize: fontPixelsize
                font.family: fontFamily
                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    color: parent.enabled ? parent.Material.primaryTextColor
                                          : parent.Material.hintTextColor
                    elide: Text.ElideRight
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.Wrap
                }

                property url url: model.url
                highlighted: ListView.isCurrentItem

                onClicked: {
                    listView.forceActiveFocus()
                    listView.currentIndex = model.index
                }
            }

            onCurrentItemChanged: {
                if (String(currentItem.url).length == 0)
                    root.contentExit()
                else
                    root.contentSelected(currentItem.url)
            }

            ListModel {
                id: contentModel

                Component.onCompleted: {
/*                    append({"name": "Introduction", url: "file:///" + applicationDirPath + "/pages/intro_1.html"});
                    append({"name": "Quick Start", url: "file:///" + applicationDirPath + "/pages/quickstart.html"});
                    append({"name": "About Bridge", url: "file:///" + applicationDirPath + "/pages/rules.html"});
                    append({"name": "About ZBridge", url: "file:///" + applicationDirPath + "/pages/aboutzbridge.html"});
                    append({"name": "Main Window", url:  "file:///" + applicationDirPath + "/pages/mainwindow.html"});
                    append({"name": "Toolbar and Menu", url: "file:///" + applicationDirPath + "/pages/menus.html"});
                    append({"name": "Dialogs", url: "file:///" + applicationDirPath + "/pages/dialogs.html"});
                    append({"name": "Bidding Conventions", url: "file:///" + applicationDirPath + "/pages/bidconv.html"});
                    append({"name": "Bidding Systems", url: "file:///" + applicationDirPath + "/pages/bidsys.html"});
                    append({"name": "Exit", url: ""});
*/
                    append({"name": "Introduction", url: "file:///android_asset/pages/intro_1.html"});
                    append({"name": "Quick Start", url: "file:///android_asset/pages/quickstart.html"});
                    append({"name": "About Bridge", url: "file:///android_asset/pages/rules.html"});
                    append({"name": "About ZBridge", url: "file:///android_asset/pages/aboutzbridge.html"});
                    append({"name": "Main Window", url:  "file:///android_asset/pages/mainwindow.html"});
                    append({"name": "Toolbar and Menu", url:  "file:///android_asset/pages/menus.html"});
                    append({"name": "Dialogs", url: "file:///android_asset/pages/dialogs.html"});
                    append({"name": "Bidding Conventions", url: "file:///android_asset/pages/bidconv.html"});
                    append({"name": "Bidding Systems", url: "file:///android_asset/pages/bidsys.html"});
                    append({"name": "Exit", url: ""});

                }
            }
        }
    }
}

