/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMessage.cpp
  Developers: eak

  Revision History:
  8-dec-2017 eak: Original.

  Abstract: Message class (C++ interface to QML MessageBox).

  Platforms: Qt.

*/

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "czbridgeapp.h"
#include "cmessage.h"

CMessage::CMessage(QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML seat configuration dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CMessage::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CMessage::sceneGraphError);
    if (parent == 0)
        setWindowFlags ((Qt::WindowFlags)Qt::Dialog & (~Qt::WindowContextHelpButtonHint) | Qt::WindowStaysOnTopHint);
    setWindowTitle(tr("ZBridge - Message Dialog"));
    pWidget->setSource(QUrl("qrc:///CMessage.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pMessageObject = pWidget->rootObject();

    //Set screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pMessageObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));

    //Connect signals (QML -> C++).
    connect(pMessageObject, SIGNAL(onAccepted()), this, SLOT(onAccepted()));
    connect(pMessageObject, SIGNAL(onRejected()), this, SLOT(onRejected()));
}

CMessage::~CMessage()
{
}

int CMessage::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CMessage::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

int CMessage::message(const QString &title, const QString &text, char *fnc)
{
    QObject *pMessageObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pMessageObject, fnc,
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, title), Q_ARG(QVariant, text));

    return exec();
}

int CMessage::question(const QString &title, const QString &text)
{
    char fnc[] = "question";
    return message(title, text, fnc);
}

int CMessage::information(const QString &title, const QString &text)
{
    char fnc[] = "information";
    return message(title, text, fnc);
}

int CMessage::warning(const QString &title, const QString &text)
{
    char fnc[] = "warning";
    return message(title, text, fnc);
}

int CMessage::critical(const QString &title, const QString &text)
{
    char fnc[] = "critical";
    return message(title, text, fnc);
}

void CMessage::onAccepted()
{
    eventLoop.exit(QDialog::Accepted);
}

void CMessage::onRejected()
{
    eventLoop.exit(QDialog::Rejected);
}

void CMessage::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CMessage::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
