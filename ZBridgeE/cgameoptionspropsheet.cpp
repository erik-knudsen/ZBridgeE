/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CGameOptionsPropSheet.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  14-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Property sheet for determining game options.

  Platforms: Qt.

*/

/**
 * \file
 * Property sheet for determining game options (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include <QString>
#include <QTextStream>

#include "cgameoptionspropsheet.h"
#include "czbridgeapp.h"
#include "czbridgedoc.h"

CGameOptionsPropSheet::CGameOptionsPropSheet(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML game options dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CGameOptionsPropSheet::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CGameOptionsPropSheet::sceneGraphError);
    setWindowTitle(tr("ZBridge - Game Options"));
    pWidget->setSource(QUrl("qrc:///CGameOptionsPropSheet.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pGameOptionsPropSheetObject = pWidget->rootObject();

    //Set screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));

    this->app = app;
    this->doc = doc;

    //Connect signals (QML -> C++).
    connect(pGameOptionsPropSheetObject, SIGNAL(on_biddingPause_sliderMoved(int)), this, SLOT(on_biddingPause_sliderMoved(int)));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_playPause_sliderMoved(int)), this, SLOT(on_playPause_sliderMoved(int)));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_insertBiddingPause_clicked(bool)), this, SLOT(on_insertBiddingPause_clicked(bool)));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_insertPlayPause_clicked(bool)), this, SLOT(on_insertPlayPause_clicked(bool)));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_teamsIMP_clicked()), this, SLOT(on_teamsIMP_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_duplicateMP_clicked()), this, SLOT(on_duplicateMP_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_rubberBridge_clicked()), this, SLOT(on_RubberBridge_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_practice_clicked()), this, SLOT(on_practice_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_level0_clicked()), this, SLOT(on_level0_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_level1_clicked()), this, SLOT(on_level1_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_level2_clicked()), this, SLOT(on_level2_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_level3_clicked()), this, SLOT(on_level3_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_ok_clicked()), this, SLOT(on_ok_clicked()));
    connect(pGameOptionsPropSheetObject, SIGNAL(on_cancel_clicked()), this, SLOT(on_cancel_clicked()));

    gameOptionDoc = doc->getGameOptions();

    //Interface.
    QString text = QString::number(gameOptionDoc.biddingPause/10.0, 'f', 1) + " sec";
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "biddingPauseLengthSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, text));
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "biddingPauseSetValue",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, gameOptionDoc.biddingPause));
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "insertBiddingPauseSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, gameOptionDoc.insertBiddingPause));

    text = QString::number(gameOptionDoc.playPause/10.0, 'f', 1) + " sec";
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "playPauseLengthSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, text));
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "playPauseSetValue",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, gameOptionDoc.playPause));
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "insertPlayPauseSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, gameOptionDoc.insertPlayPause));

    //Scoring.
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "methodSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, gameOptionDoc.scoringMethod));

    //Computing level.
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "computerLevelSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, gameOptionDoc.computerLevel));
}

CGameOptionsPropSheet::~CGameOptionsPropSheet()
{
}

int CGameOptionsPropSheet::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CGameOptionsPropSheet::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CGameOptionsPropSheet::on_ok_clicked()
{
    doc->setGameOptions(gameOptionDoc);

    eventLoop.exit(QDialog::Accepted);
}

void CGameOptionsPropSheet::on_cancel_clicked()
{
    eventLoop.exit(QDialog::Rejected);
}

void CGameOptionsPropSheet::on_biddingPause_sliderMoved(int position)
{
    QObject *pGameOptionsPropSheetObject = pWidget->rootObject();
    QVariant returnedValue;

    QString text = QString::number(position/10.0, 'f', 1) + " sec";
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "biddingPauseLengthSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, text));

    gameOptionDoc.biddingPause = position;
}

void CGameOptionsPropSheet::on_playPause_sliderMoved(int position)
{
    QObject *pGameOptionsPropSheetObject = pWidget->rootObject();
    QVariant returnedValue;

    QString text = QString::number(position/10.0, 'f', 1) + " sec";
    QMetaObject::invokeMethod(pGameOptionsPropSheetObject, "playPauseLengthSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, text));

    gameOptionDoc.playPause = position;
}

void CGameOptionsPropSheet::on_insertBiddingPause_clicked(bool checked)
{
   gameOptionDoc.insertBiddingPause = checked;
}

void CGameOptionsPropSheet::on_insertPlayPause_clicked(bool checked)
{
    gameOptionDoc.insertPlayPause = checked;
}

void CGameOptionsPropSheet::on_teamsIMP_clicked()
{
    gameOptionDoc.scoringMethod = IMP;
}

void CGameOptionsPropSheet::on_duplicateMP_clicked()
{
    gameOptionDoc.scoringMethod = MP;
}

void CGameOptionsPropSheet::on_RubberBridge_clicked()
{
    gameOptionDoc.scoringMethod = RUBBER;
}

void CGameOptionsPropSheet::on_practice_clicked()
{
    gameOptionDoc.scoringMethod = PRACTICE;
}

void CGameOptionsPropSheet::on_level0_clicked()
{
    gameOptionDoc.computerLevel = 0;
}

void CGameOptionsPropSheet::on_level1_clicked()
{
    gameOptionDoc.computerLevel = 1;
}

void CGameOptionsPropSheet::on_level2_clicked()
{
    gameOptionDoc.computerLevel = 2;
}

void CGameOptionsPropSheet::on_level3_clicked()
{
    gameOptionDoc.computerLevel = 3;
}

void CGameOptionsPropSheet::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CGameOptionsPropSheet::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
