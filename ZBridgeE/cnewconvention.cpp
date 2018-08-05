/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CNewConvention.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  3-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Select name for new convention.

  Platforms: Qt.

*/

/**
 * \file
 * Select name for new convention (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>
#include <QString>

#include "czbridgeapp.h"
#include "cnewconvention.h"

CNewConvention::CNewConvention(QString &refConventionName, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML new convention dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CNewConvention::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CNewConvention::sceneGraphError);
    setWindowTitle(tr("ZBridge - Bidding/Play"));
    pWidget->setSource(QUrl("qrc:///CNewConvention.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pNewConventionObject = pWidget->rootObject();

    //Set screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pNewConventionObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));

    //Connect signals (QML -> C++).
    connect(pNewConventionObject, SIGNAL(on_ok_clicked()), this, SLOT(on_ok_clicked()));
    connect(pNewConventionObject, SIGNAL(on_cancel_clicked()), this, SLOT(on_cancel_clicked()));

    QMetaObject::invokeMethod(pNewConventionObject, "setRefConventionName",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, refConventionName));
}

CNewConvention::~CNewConvention()
{
}

int CNewConvention::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

/**
 * @brief Get the name of the new bid option set.
 */
QString CNewConvention::getNewConventionName()
{
    QObject *pNewConventionObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pNewConventionObject, "getNewConventionName",
            Q_RETURN_ARG(QVariant, returnedValue));

    return returnedValue.toString();
}

void CNewConvention::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CNewConvention::on_ok_clicked()
{
    eventLoop.exit(QDialog::Accepted);
}

void CNewConvention::on_cancel_clicked()
{
    eventLoop.exit(QDialog::Rejected);
}

void CNewConvention::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CNewConvention::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
