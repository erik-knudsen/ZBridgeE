/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CContent.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Help content.

  Platforms: Qt/QML.
*/

import QtQuick 2.2
import QtQuick.Controls 2.0
import QtWebView 1.1
import QtQuick.Layouts 1.1

Item {
    id: itemWindow

    signal on_Exit()

    property int zf: 10
    property int zfs: 10

    property int fontPixelsize: 6 * zf
    property string fontFamily: "MS Shell Dlg 2"

    width: 190 * zfs
    height: 100 *zfs

    RowLayout {
        id: container
        anchors.fill: parent
        spacing: 0

        ContentList {
            id: contentList
            Layout.preferredWidth: 11 * fontPixelsize
            Layout.fillWidth: true
            Layout.fillHeight: true
            onContentSelected: webView.showContent(url)
            onContentExit: on_Exit()
        }

        ColumnLayout {

            RowLayout {
                spacing: 1 * zf

                Layout.leftMargin: 2 * zf

                ToolButton {
                    id: backButton
                    Layout.preferredHeight: 15 * zf
                    Layout.preferredWidth: 15 * zf
                    onClicked: webView.goBack()
                    enabled: webView.canGoBack
                    contentItem: Image {
                        source: "qrc:///resources/review_prev.ico"
                        opacity: enabled ? 1 : 0.3
                    }
                }

                ToolButton {
                    id: forwardButton
                    Layout.preferredHeight: 15 * zf
                    Layout.preferredWidth: 15 * zf
                    onClicked: webView.goForward()
                    enabled: webView.canGoForward
                    contentItem: Image {
                        source: "qrc:///resources/review_next.ico"
                        opacity: enabled ? 1 : 0.3
                    }
                }
            }

            WebView {
                id: webView
                Layout.preferredWidth: itemWindow.width - 11 * fontPixelsize
                Layout.fillWidth: true
                Layout.fillHeight: true

                property bool firstLoadComplete: false
                onLoadingChanged: {
                    if (loadRequest.status === WebView.LoadSucceededStatus
                            && !firstLoadComplete) {
                        // Debounce the showing of the web content, so images are more likely
                        // to have loaded completely.
                        showTimer.start()
                    }
                }

                Timer {
                    id: showTimer
                    interval: 500
                    repeat: false
                    onTriggered: {
                        webView.show(true)
                        webView.firstLoadComplete = true
                    }
                }

                Rectangle {
                    id: webViewPlaceholder
                    anchors.fill: parent
                    z: 1
                    color: "white"

                    BusyIndicator {
                        id: busy
                        anchors.centerIn: parent
                    }
                }

                function showContent(url) {
                    //                console.log(url)
                    webView.url = url
                }

                function show(show) {
                    if (show === true) {
                        busy.running = false
                        webViewPlaceholder.visible = false
                    } else {
                        webViewPlaceholder.visible = true
                        busy.running = true
                    }
                }
            }
        }
    }
    function setZoom(zoom, zooms)
    {
        zf = zoom
        zfs = zooms
        contentList.zf = zf
    }
}
