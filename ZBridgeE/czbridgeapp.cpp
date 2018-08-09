/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBridgeApp.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original

  Abstract: ZBridge application.

  Platforms: Qt.

*/

/**
 * @file
 * ZBridge application.
 */

#include <QAbstractSocket>
#include <QTime>
#include <QtWebView/QtWebView>
#include <QScreen>

#include "czbridgeapp.h"
#include "mt19937ar.h"
#include "cmainframe.h"
#include "czbridgedoc.h"
#include "cgamesdoc.h"
#include "Defines.h"
#include "dll.h"

Q_DECLARE_METATYPE(Seat)

int CZBridgeApp::zf;
int CZBridgeApp::zfs = 10;

/**
 * Main for starting the ZBridge application.
 * The application is allocated. Relevant meta types are registered and the
 * application is started.
 */
int main(int argc, char *argv[])
{
    SetMaxThreads(0);

    CZBridgeApp app(argc, argv);

    qRegisterMetaType<QAbstractSocket::SocketError>();
    qRegisterMetaType<Seat>();

    init_genrand(QTime::currentTime().msecsSinceStartOfDay());

    return app.exec();
}


/**
 * The constructor initializes the Zbridge application.
 *   - Allocate data for the application (model).
 *   - Allocate the main frame window etc. (view).
 *   - Show the main frame window.
 */
CZBridgeApp::CZBridgeApp(int &argc, char **argv) :
    QApplication(argc, argv)
{    
    //Calculate zoom factor for QML pixels.
    //Pixel sizes are used in all QML displays.
    QRect rect = QGuiApplication::primaryScreen()->geometry();
    qreal dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch();
    qreal dpiC = 40;            //DPI used for QML pixels.
    qreal zfr = dpi/dpiC;

    //Must use landscape mode.
    qreal height = qMin(rect.width(), rect.height());
    qreal width = qMax(rect.width(), rect.height());

    //Check for minimum display.
    qreal xSize = width/dpi;
    qreal ySize = height/dpi;
    if ((xSize <= 4) || (ySize <= 2.25))
        exit(-1);

    //Correct so that dialogs can be shown on screen
    //Max dialog w x h: 150 x 170 QML pixels i.e.
    //w = 150/40x2.54 = 9.525 cm, h = 170/40x2.54 = 10.975 cm
    if (height < 170 * zfr)
        zfr = height / 170;
    if (width < 150 *zfr)
        zfr = width / 150;

    //Zoom factor to use for QML pixels.
    zf = (int)(zfr + 0.5);

    //Zoom factor for help screen (80% x 80% of available screen).
    if ((zfs * 190) > (width - zfs * 20))
        zfs = (width - zfs * 20) / 190;
    if ((zfs * 100) > (height - zfs * 20))
        zfs = (height - zfs * 20) / 100;

    QtWebView::initialize();

    doc = new CZBridgeDoc(this);
    games = new CGamesDoc(this);

    mainFrame = new CMainFrame(this, doc, games);
    mainFrame->show();
}
