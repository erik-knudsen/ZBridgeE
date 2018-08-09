/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CContent.cpp
  Developers: eak

  Revision History:
  11-jun-2018 eak: Original

  Abstract: Content dialog. Displays help for the application.

  Platforms: Qt.

*/

/**
 * @file
 * Content dialog for ZBridge (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>
#include <QQmlContext>
#include <QApplication>

#include "czbridgeapp.h"
#include "ccontent.h"

/**
 * @brief CContent::CContent
 *
 * The constructor initializes the Content Dialog and shows relevant
 * information in the dialog.
 *
 * @param parent Parent.
 */
CContent::CContent(QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML about dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    pWidget->rootContext()->setContextProperty("applicationDirPath", QApplication::applicationDirPath());
    pWidget->setSource(QUrl("qrc:///CContent.qml"));

    connect(pWidget, &QQuickWidget::statusChanged, this, &CContent::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CContent::sceneGraphError);
    setWindowTitle(tr("ZBridge - Content Dialog"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pContentObject = pWidget->rootObject();

    //Set screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    int zfs = CZBridgeApp::getZoomS();
    QMetaObject::invokeMethod(pContentObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf), Q_ARG(QVariant, zfs));

    connect(pContentObject, SIGNAL(on_Exit()), this, SLOT(on_Exit()));
}

CContent::~CContent()
{
}

int CContent::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CContent::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CContent::on_Exit()
{
    eventLoop.exit(QDialog::Accepted);
}

void CContent::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CContent::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
