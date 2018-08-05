/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CDisplayOptionsPropSheet.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  12-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Property sheet for determining display options.

  Platforms: Qt.

*/

/**
 * \file
 * Property sheet for determining display options (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "cdispoptionspropsheet.h"
#include "czbridgeapp.h"
#include "czbridgedoc.h"

CDispOptionsPropSheet::CDispOptionsPropSheet(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML seat configuration dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CDispOptionsPropSheet::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CDispOptionsPropSheet::sceneGraphError);
    setWindowTitle(tr("ZBridge - Display Options"));
    pWidget->setSource(QUrl("qrc:///CDispOptionsPropSheet.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pDispOptionsPropSheetObject = pWidget->rootObject();

    //Screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pDispOptionsPropSheetObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));

    this->app = app;
    this->doc = doc;

    //Connect signals (QML -> C++).
    connect(pDispOptionsPropSheetObject, SIGNAL(on_cardBack0_clicked()), this, SLOT(on_cardBack0_clicked()));
    connect(pDispOptionsPropSheetObject, SIGNAL(on_cardBack1_clicked()), this, SLOT(on_cardBack1_clicked()));
    connect(pDispOptionsPropSheetObject, SIGNAL(on_cardBack2_clicked()), this, SLOT(on_cardBack2_clicked()));
    connect(pDispOptionsPropSheetObject, SIGNAL(on_cardBack3_clicked()), this, SLOT(on_cardBack3_clicked()));
    connect(pDispOptionsPropSheetObject, SIGNAL(on_cardBack4_clicked()), this, SLOT(on_cardBack4_clicked()));
    connect(pDispOptionsPropSheetObject, SIGNAL(on_cardBack5_clicked()), this, SLOT(on_cardBack5_clicked()));
    connect(pDispOptionsPropSheetObject, SIGNAL(on_ok_clicked()), this, SLOT(on_ok_clicked()));
    connect(pDispOptionsPropSheetObject, SIGNAL(on_cancel_clicked()), this, SLOT(on_cancel_clicked()));

    displayOptionDoc = doc->getDisplayOptions();

    //Card Backs.
    QMetaObject::invokeMethod(pDispOptionsPropSheetObject, "setChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, displayOptionDoc.cardBack));
}

CDispOptionsPropSheet::~CDispOptionsPropSheet()
{
}

int CDispOptionsPropSheet::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CDispOptionsPropSheet::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CDispOptionsPropSheet::on_ok_clicked()
{
    doc->setDisplayOptions(displayOptionDoc);

    eventLoop.exit(QDialog::Accepted);
}

void CDispOptionsPropSheet::on_cancel_clicked()
{
    eventLoop.exit(QDialog::Rejected);
}

void CDispOptionsPropSheet::on_cardBack0_clicked()
{
    displayOptionDoc.cardBack = CARD_BACK_0;
}

void CDispOptionsPropSheet::on_cardBack1_clicked()
{
    displayOptionDoc.cardBack = CARD_BACK_1;
}

void CDispOptionsPropSheet::on_cardBack2_clicked()
{
    displayOptionDoc.cardBack = CARD_BACK_2;
}

void CDispOptionsPropSheet::on_cardBack3_clicked()
{
    displayOptionDoc.cardBack = CARD_BACK_3;
}

void CDispOptionsPropSheet::on_cardBack4_clicked()
{
    displayOptionDoc.cardBack = CARD_BACK_4;
}

void CDispOptionsPropSheet::on_cardBack5_clicked()
{
    displayOptionDoc.cardBack = CARD_BACK_5;
}

void CDispOptionsPropSheet::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CDispOptionsPropSheet::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
