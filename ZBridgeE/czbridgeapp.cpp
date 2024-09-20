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
#include <QQmlEngine>

#include "czbridgeapp.h"
#include "mt19937ar.h"
#include "cmainframe.h"
#include "czbridgedoc.h"
#include "cgamesdoc.h"
#include "Defines.h"
#include "dll.h"
#include "Singleton.h"

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

    app.setWindowIcon(QIcon(":/resources/IDR_MAIN.ICO"));

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
    QRect rect = QGuiApplication::primaryScreen()->geometry();

    /* Get number of dots/inch (each dot approx standard size 1/96 inch, 0,26 mm).
    Qt internally scales the physical screen to this standard size of dots */
    qreal dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch(); //Dots are approx 1/96 inch.

    //Must use landscape mode.
    qreal height = qMin(rect.width(), rect.height());
    qreal width = qMax(rect.width(), rect.height());

    //Check for minimum display (size in inch).
    qreal xSize = width/dpi;
    qreal ySize = height/dpi;
    if ((xSize <= 4) || (ySize <= 2.25))
        exit(-1);

    //Zoom factors to use for displays.
    //This is done to make it easy to simultaneously scale all menus etc.
    zf = 3;  //For menus.
    zfs = 3; //For help screen.
    //Below singleton is just for experimenting with a singleton.
    qmlRegisterSingletonType<Singleton>("Singleton", 1, 0, "Singleton", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        Singleton *singleton = new Singleton();
        singleton->zh = zf;  //Zomm factor for height.
        singleton->zw = zf;  //Zoom factor for width.
        return singleton;
    });

    QtWebView::initialize();

    doc = new CZBridgeDoc(this);
    games = new CGamesDoc(this);

    mainFrame = new CMainFrame(this, doc, games);
    mainFrame->show();
}
