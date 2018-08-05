/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CSeatConfiguration.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  19-dec-2017 eak: Use QML instead of Widgets.

  Abstract: Configuration of seats.

  Platforms: Qt.

*/

/**
 * \file
 * Configuration of seats (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "cseatconfiguration.h"
#include "czbridgeapp.h"
#include "czbridgedoc.h"

CSeatConfiguration::CSeatConfiguration(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML seat configuration dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CSeatConfiguration::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CSeatConfiguration::sceneGraphError);
    setWindowTitle(tr("ZBridge - Seat Configuration"));
    pWidget->setSource(QUrl("qrc:///CSeatConfiguration.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pSeatConfigurationObject = pWidget->rootObject();

    //Screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pSeatConfigurationObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));

    this->app = app;
    this->doc = doc;

    //Connect signals (QML -> C++).
    connect(pSeatConfigurationObject, SIGNAL(on_west_clicked()), this, SLOT(on_west_clicked()));
    connect(pSeatConfigurationObject, SIGNAL(on_north_clicked()), this, SLOT(on_north_clicked()));
    connect(pSeatConfigurationObject, SIGNAL(on_east_clicked()), this, SLOT(on_east_clicked()));
    connect(pSeatConfigurationObject, SIGNAL(on_south_clicked()), this, SLOT(on_south_clicked()));
    connect(pSeatConfigurationObject, SIGNAL(on_westActor_currentIndexChanged(int)), this, SLOT(on_westActor_currentIndexChanged(int)));
    connect(pSeatConfigurationObject, SIGNAL(on_northActor_currentIndexChanged(int)), this, SLOT(on_northActor_currentIndexChanged(int)));
    connect(pSeatConfigurationObject, SIGNAL(on_eastActor_currentIndexChanged(int)), this, SLOT(on_eastActor_currentIndexChanged(int)));
    connect(pSeatConfigurationObject, SIGNAL(on_southActor_currentIndexChanged(int)), this, SLOT(on_southActor_currentIndexChanged(int)));
    connect(pSeatConfigurationObject, SIGNAL(on_role_currentIndexChanged(int)), this, SLOT(on_role_currentIndexChanged(int)));
    connect(pSeatConfigurationObject, SIGNAL(on_ok_clicked()), this, SLOT(on_ok_clicked()));
    connect(pSeatConfigurationObject, SIGNAL(on_cancel_clicked()), this, SLOT(on_cancel_clicked()));

    QVariantList items;
    items << tr("Manual") << tr("Auto");
    for (int i = 0; i < 4; i++)
        QMetaObject::invokeMethod(pSeatConfigurationObject, "actorAddItems",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, i), Q_ARG(QVariant, items));

    items.clear();
    items << tr("Server") << tr("Client") << tr("Standalone");
    QMetaObject::invokeMethod(pSeatConfigurationObject, "roleAddItems",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, items));

    //Next set up dialog based on saved values.
    seatOptionDoc = doc->getSeatOptions();

    QMetaObject::invokeMethod(pSeatConfigurationObject, "setSeatChecked",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, seatOptionDoc.seat));

    for (int i = 0; i < 4; i++)
    {
        QVariant name = (i == 0) ? (seatOptionDoc.westName) : (i == 1) ? (seatOptionDoc.northName) :
                        (i == 2) ? (seatOptionDoc.eastName) : (seatOptionDoc.southName);
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, i), Q_ARG(QVariant, name));
    }

    for (int i = 0; i < 4; i++)
    {
        QVariant index = (i == 0) ? (seatOptionDoc.westActor) : (i == 1) ? (seatOptionDoc.northActor) :
                        (i == 2) ? (seatOptionDoc.eastActor) : (seatOptionDoc.southActor);
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setActorCurrentIndex",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, i), Q_ARG(QVariant, index));
    }

    QMetaObject::invokeMethod(pSeatConfigurationObject, "setRoleCurrentIndex",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, seatOptionDoc.role));

    //Enable/disable based on saved values.
    updateHostAndPort();
    updateSeatAndActor();
}

CSeatConfiguration::~CSeatConfiguration()
{
}

int CSeatConfiguration::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CSeatConfiguration::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CSeatConfiguration::on_west_clicked()
{
    seatOptionDoc.seat = WEST_SEAT;
    updateSeatAndActor();
}

void CSeatConfiguration::on_north_clicked()
{
    seatOptionDoc.seat = NORTH_SEAT;
    updateSeatAndActor();
}

void CSeatConfiguration::on_east_clicked()
{
    seatOptionDoc.seat = EAST_SEAT;
    updateSeatAndActor();
}

void CSeatConfiguration::on_south_clicked()
{
    seatOptionDoc.seat = SOUTH_SEAT;
    updateSeatAndActor();
}

void CSeatConfiguration::on_westActor_currentIndexChanged(int index)
{
    seatOptionDoc.westActor = (Actor)index;
    updateSeatAndActor();
}

void CSeatConfiguration::on_northActor_currentIndexChanged(int index)
{
    seatOptionDoc.northActor = (Actor)index;
    updateSeatAndActor();
}

void CSeatConfiguration::on_eastActor_currentIndexChanged(int index)
{
    seatOptionDoc.eastActor = (Actor)index;
    updateSeatAndActor();
}

void CSeatConfiguration::on_southActor_currentIndexChanged(int index)
{
    seatOptionDoc.southActor = (Actor)index;
    updateSeatAndActor();
}

void CSeatConfiguration::on_role_currentIndexChanged(int index)
{
    seatOptionDoc.role = (Role)index;
    updateHostAndPort();
    updateSeatAndActor();
}

void CSeatConfiguration::on_ok_clicked()
{
    QVariant text;
    QObject *pSeatConfigurationObject = pWidget->rootObject();

    QMetaObject::invokeMethod(pSeatConfigurationObject, "nameText",
            Q_RETURN_ARG(QVariant, text), Q_ARG(QVariant, WEST_SEAT));
    seatOptionDoc.westName = text.toString();
    QMetaObject::invokeMethod(pSeatConfigurationObject, "nameText",
            Q_RETURN_ARG(QVariant, text), Q_ARG(QVariant, NORTH_SEAT));
    seatOptionDoc.northName = text.toString();
    QMetaObject::invokeMethod(pSeatConfigurationObject, "nameText",
            Q_RETURN_ARG(QVariant, text), Q_ARG(QVariant, EAST_SEAT));
    seatOptionDoc.eastName = text.toString();
    QMetaObject::invokeMethod(pSeatConfigurationObject, "nameText",
            Q_RETURN_ARG(QVariant, text), Q_ARG(QVariant, SOUTH_SEAT));
    seatOptionDoc.southName = text.toString();


    if (seatOptionDoc.role == SERVER_ROLE)
    {
        QMetaObject::invokeMethod(pSeatConfigurationObject, "hostText",
                Q_RETURN_ARG(QVariant, text));
        seatOptionDoc.hostServer = text.toString();
        QMetaObject::invokeMethod(pSeatConfigurationObject, "portText",
                Q_RETURN_ARG(QVariant, text));
        seatOptionDoc.portServer = text.toString();
    }
    else if (seatOptionDoc.role == CLIENT_ROLE)
    {
        QMetaObject::invokeMethod(pSeatConfigurationObject, "hostText",
                Q_RETURN_ARG(QVariant, text));
        seatOptionDoc.hostClient = text.toString();
        QMetaObject::invokeMethod(pSeatConfigurationObject, "portText",
                Q_RETURN_ARG(QVariant, text));
        seatOptionDoc.portClient = text.toString();
    }
    doc->setSeatOptions(seatOptionDoc);

    eventLoop.exit(QDialog::Accepted);
}

void CSeatConfiguration::on_cancel_clicked()
{
    eventLoop.exit(QDialog::Rejected);
}

void CSeatConfiguration::updateSeatAndActor()
{    
    QObject *pSeatConfigurationObject = pWidget->rootObject();
    QVariant returnedValue;

    for (int i = 0; i < 4; i++)
    {
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, i), Q_ARG(QVariant, true));
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setActorVisible",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, i), Q_ARG(QVariant, true));
    }

    if ((seatOptionDoc.role == SERVER_ROLE) || (seatOptionDoc.role == STANDALONE_ROLE))
    {
        if (seatOptionDoc.westActor == AUTO_ACTOR)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, WEST_SEAT), Q_ARG(QVariant, false));
        }
        if (seatOptionDoc.northActor == AUTO_ACTOR)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, NORTH_SEAT), Q_ARG(QVariant, false));
        }
        if (seatOptionDoc.eastActor == AUTO_ACTOR)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, EAST_SEAT), Q_ARG(QVariant, false));
        }
        if (seatOptionDoc.southActor == AUTO_ACTOR)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, SOUTH_SEAT), Q_ARG(QVariant, false));
        }
    }
    else if (seatOptionDoc.role == CLIENT_ROLE)
    {
        if (seatOptionDoc.seat != WEST_SEAT)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, WEST_SEAT), Q_ARG(QVariant, false));
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setActorVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, WEST_SEAT), Q_ARG(QVariant, false));
        }
        else if (seatOptionDoc.westActor == AUTO_ACTOR)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, WEST_SEAT), Q_ARG(QVariant, false));
        }
        if (seatOptionDoc.seat != NORTH_SEAT)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, NORTH_SEAT), Q_ARG(QVariant, false));
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setActorVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, NORTH_SEAT), Q_ARG(QVariant, false));
        }
        else if (seatOptionDoc.northActor == AUTO_ACTOR)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, NORTH_SEAT), Q_ARG(QVariant, false));
        }
        if (seatOptionDoc.seat != EAST_SEAT)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, EAST_SEAT), Q_ARG(QVariant, false));
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setActorVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, EAST_SEAT), Q_ARG(QVariant, false));
        }
        else if (seatOptionDoc.eastActor == AUTO_ACTOR)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, EAST_SEAT), Q_ARG(QVariant, false));
        }
        if (seatOptionDoc.seat != SOUTH_SEAT)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, SOUTH_SEAT), Q_ARG(QVariant, false));
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setActorVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, SOUTH_SEAT), Q_ARG(QVariant, false));
        }
        else if (seatOptionDoc.southActor == AUTO_ACTOR)
        {
            QMetaObject::invokeMethod(pSeatConfigurationObject, "setNameVisible",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, SOUTH_SEAT), Q_ARG(QVariant, false));
        }
    }
}

void CSeatConfiguration::updateHostAndPort()
{
    QObject *pSeatConfigurationObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pSeatConfigurationObject, "setHostVisible",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, true));
    QMetaObject::invokeMethod(pSeatConfigurationObject, "setPortVisible",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, true));

    if (seatOptionDoc.role == STANDALONE_ROLE)
    {
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setHostVisible",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, false));
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setPortVisible",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, false));
    }
    else if (seatOptionDoc.role == SERVER_ROLE)
    {
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setHostText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, seatOptionDoc.hostServer));
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setPortText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, seatOptionDoc.portServer));
    }
    else
    {
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setHostText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, seatOptionDoc.hostClient));
        QMetaObject::invokeMethod(pSeatConfigurationObject, "setPortText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, seatOptionDoc.portClient));
    }
}

void CSeatConfiguration::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CSeatConfiguration::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
