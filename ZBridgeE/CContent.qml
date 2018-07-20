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

    property int shorterDesktop: 768
    property int longerDesktop: 1500

    width: longerDesktop
    height: shorterDesktop

    RowLayout {
        id: container
        anchors.fill: parent
        spacing: 0

        ContentList {
            id: contentList
            width: 400
            Layout.fillWidth: true
            Layout.fillHeight: true
            onContentSelected: webView.showContent(url)
            onContentExit: on_Exit()
        }

        ColumnLayout {

            RowLayout {
                spacing: 10

                Layout.leftMargin: 20

                ToolButton {
                    id: backButton
                    Layout.preferredHeight: 100
                    Layout.preferredWidth: 100
                    anchors.top: parent.top
                    anchors.left: parent.left
                    onClicked: webView.goBack()
                    enabled: webView.canGoBack
                    contentItem: Image {
                        source: "qrc:///resources/review_prev.ico"
                        opacity: enabled ? 1 : 0.3
                    }
                }

                ToolButton {
                    id: forwardButton
                    Layout.preferredHeight: 100
                    Layout.preferredWidth: 100
                    anchors.left: backButton.right
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
                width: longerDesktop - 400
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
}
