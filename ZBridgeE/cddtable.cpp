/*Erik Aagaard Knudsen.
  Copyright © 2016 - All Rights Reserved

  Project: ZBridge
  File: CDDTable.cpp
  Developers: eak

  Revision History:
  14-jan-2016 eak: Original
  15-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Calculate and show double dummy results and par.

  Platforms: Qt.

*/

/**
 * \file
 * Calculate and show double dummy results and par(definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include <QString>

#include "dll.h"
#include "cmessagebox.h"
#include "cddslock.h"
#include "czbridgeapp.h"
#include "cddtable.h"

CDDTable::CDDTable(int cards[][13], Seat dealer, Team vulnerable, QWidget *parent) :
    QWidget(parent)
{
    ddTableDeal tableDeal;
    ddTableResults table;
    parResultsDealer pRes;

    for (int h = 0; h < DDS_HANDS; h++)
      for (int s = 0; s < DDS_SUITS; s++)
        tableDeal.cards[h][s] = 0;

    //Format according to dds specs.
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
        {
            int hand = (i + 3) % 4;
            int card = cards[i][j];
            Suit suit = CARD_SUIT(card);
            int face = CARD_FACE(card);
            tableDeal.cards[hand][3 - suit] |= (1 << (face + 2));
        }

    CddsLock::mutex.lock();     //Static lock to protect dds static data.
    resDD = CalcDDtable(tableDeal, &table);
    if (resDD == RETURN_NO_FAULT)
    {
        int vul = (vulnerable == NEITHER) ? (0) : (vulnerable == NORTH_SOUTH) ? (2) :
                                                  (vulnerable == EAST_WEST) ? (3) : (1);
        int deal = (dealer == WEST_SEAT) ? (3) : (dealer == NORTH_SEAT) ? (0) :
                                                 (dealer == EAST_SEAT) ? (1) : (2);
        resDD = DealerPar(&table, &pRes, deal, vul);
    }
    if (resDD != RETURN_NO_FAULT)
    {
        char line[80];
        ErrorMessage(resDD, line);
        //        hide();
        CMessageBox::critical(this->parentWidget(), tr("ZBridge Error"), tr("DDS Error: ") + QString(line));
        //        show();
    }
    CddsLock::mutex.unlock();
    if (resDD != RETURN_NO_FAULT)
        return;

    //Initialize with QML DD table dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CDDTable::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CDDTable::sceneGraphError);
    setWindowTitle(tr("ZBridge - Double Dummy table"));
    pWidget->setSource(QUrl("qrc:///CDDTable.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pDDTableObject = pWidget->rootObject();
    QVariant returnedValue;

    //Screen zoom factor.
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pDDTableObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));

    QString txt;

    //N-S NT.
    if (table.resTable[4][0] == table.resTable[4][2])
        txt = QString::number(table.resTable[4][0]);
    else
        txt = QString("%1 - %2").arg(table.resTable[4][0]).arg(table.resTable[4][2]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksNTNSSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //E-W NT
    if (table.resTable[4][1] == table.resTable[4][3])
        txt = QString::number(table.resTable[4][1]);
    else
        txt = QString("%1 - %2").arg(table.resTable[4][1]).arg(table.resTable[4][3]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksNTEWSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //N-S S.
    if (table.resTable[0][0] == table.resTable[0][2])
        txt = QString::number(table.resTable[0][0]);
    else
        txt = QString("%1 - %2").arg(table.resTable[0][0]).arg(table.resTable[0][2]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksSNSSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //E-W S.
    if (table.resTable[0][1] == table.resTable[0][3])
        txt = QString::number(table.resTable[0][1]);
    else
        txt = QString("%1 - %2").arg(table.resTable[0][1]).arg(table.resTable[0][3]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksSEWSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //N-S H.
    if (table.resTable[1][0] == table.resTable[1][2])
        txt = QString::number(table.resTable[1][0]);
    else
        txt = QString("%1 - %2").arg(table.resTable[1][0]).arg(table.resTable[1][2]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksHNSSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //E-W H.
    if (table.resTable[1][1] == table.resTable[1][3])
        txt = QString::number(table.resTable[1][1]);
    else
        txt = QString("%1 - %2").arg(table.resTable[1][1]).arg(table.resTable[1][3]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksHEWSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //N-S D.
    if (table.resTable[2][0] == table.resTable[2][2])
        txt = QString::number(table.resTable[2][0]);
    else
        txt = QString("%1 - %2").arg(table.resTable[2][0]).arg(table.resTable[2][2]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksDNSSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //E-W D.
    if (table.resTable[2][1] == table.resTable[2][3])
        txt = QString::number(table.resTable[2][1]);
    else
        txt = QString("%1 - %2").arg(table.resTable[2][1]).arg(table.resTable[2][3]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksDEWSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //N-S C.
    if (table.resTable[3][0] == table.resTable[3][2])
        txt = QString::number(table.resTable[3][0]);
    else
        txt = QString("%1 - %2").arg(table.resTable[3][0]).arg(table.resTable[3][2]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksCNSSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //E-W C.
    if (table.resTable[3][1] == table.resTable[3][3])
        txt = QString::number(table.resTable[3][1]);
    else
        txt = QString("%1 - %2").arg(table.resTable[3][1]).arg(table.resTable[3][3]);
    QMetaObject::invokeMethod(pDDTableObject, "tricksCEWSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //Par score.
    txt = QString("Score: %1").arg(pRes.score);
    QMetaObject::invokeMethod(pDDTableObject, "parScoreSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    //Par contract.
    txt = QString("Par: %1").arg(pRes.contracts[0]);
    for (int i = 1; i < pRes.number; i++)
        txt += QString(" ; %1").arg(pRes.contracts[i]);
    QMetaObject::invokeMethod(pDDTableObject, "parContractSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, txt));

    connect(pDDTableObject, SIGNAL(on_OKButton_Clicked()), this, SLOT(on_OKButton_Clicked()));
}

CDDTable::~CDDTable()
{
}

int CDDTable::exec()
{
    if (resDD != RETURN_NO_FAULT)
        return QDialog::Rejected;

    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CDDTable::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CDDTable::mouseReleaseEvent(QMouseEvent *event)
{
    eventLoop.exit(QDialog::Accepted);
}

void CDDTable::on_OKButton_Clicked()
{
    eventLoop.exit(QDialog::Accepted);
}

void CDDTable::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CDDTable::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
