/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CAboutDlg.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  17-jan-2018 eak: Use QML instead of Widgets.

  Abstract: About dialog.

  Platforms: Qt.

*/

/**
 * @file
 * About dialog for ZBridge (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "caboutdlg.h"
#include "czbridgeapp.h"
#include "czbridgedoc.h"

/**
 * @brief CAboutDlg::CAboutDlg
 *
 * The constructor initializes the About Dialog and shows relevant
 * information in the dialog.
 *
 * @param app Application pointer.
 * @param doc Document pointer.
 * @param parent Parent.
 */
CAboutDlg::CAboutDlg(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML about dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    pWidget->setSource(QUrl("qrc:///CAboutDlg.qml"));

    connect(pWidget, &QQuickWidget::statusChanged, this, &CAboutDlg::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CAboutDlg::sceneGraphError);
    setWindowTitle(tr("ZBridge - About Dialog"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pAboutDlgObject = pWidget->rootObject();

    //Set screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pAboutDlgObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));
    this->app = app;
    this->doc = doc;

    connect(pAboutDlgObject, SIGNAL(on_OKButton_Clicked()), this, SLOT(on_OKButton_Clicked()));
}

CAboutDlg::~CAboutDlg()
{
}

int CAboutDlg::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CAboutDlg::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CAboutDlg::on_OKButton_Clicked()
{
    eventLoop.exit(QDialog::Accepted);
}

void CAboutDlg::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CAboutDlg::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
