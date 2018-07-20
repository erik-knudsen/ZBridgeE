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
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.1

FocusScope {
    id: root
    signal contentSelected(url url)
    signal contentExit()

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
                padding: 10
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
                text: model.name
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
                    append({"name": "Toolbar and Menu", url: "file:///" + applicationDirPath + "/pages/menus.html"});
                    append({"name": "Dialogs", url: "file:///" + applicationDirPath + "/pages/dialogs.html"});
                    append({"name": "Bidding Conventions", url: "file:///" + applicationDirPath + "/pages/bidconv.html"});
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

