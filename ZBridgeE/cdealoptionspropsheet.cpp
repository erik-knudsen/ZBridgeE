/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CDealOptionsPropSheet.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  9-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Property sheet for determining deal options.

  Platforms: Qt.

*/

/**
 * \file
 * Property sheet for determining deal options (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "cdealoptionspropsheet.h"
#include "czbridgeapp.h"
#include "czbridgedoc.h"
#include "cmessagebox.h"

CDealOptionsPropSheet::CDealOptionsPropSheet(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML deal options property sheet.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CDealOptionsPropSheet::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CDealOptionsPropSheet::sceneGraphError);
    setWindowTitle(tr("ZBridge - Deal"));
    pWidget->setSource(QUrl("qrc:///CDealOptionsPropSheet.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pDealOptionsPropSheetObject = pWidget->rootObject();

    //Screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));

    this->app = app;
    this->doc = doc;

    dealOptionDoc = doc->getDealOptions();

    //Connect signals (QML -> C++).
    connect(pDealOptionsPropSheetObject, SIGNAL(on_hcp_editingFinished(int, int)), this, SLOT(on_hcp_editingFinished(int, int)));
    connect(pDealOptionsPropSheetObject, SIGNAL(on_suitSize_editingFinished(int, int)), this, SLOT(on_suitSize_editingFinished(int, int)));
    connect(pDealOptionsPropSheetObject, SIGNAL(on_dp_editingFinished(int)), this, SLOT(on_dp_editingFinished(int)));
    connect(pDealOptionsPropSheetObject, SIGNAL(on_ok_clicked()), this, SLOT(on_ok_clicked()));
    connect(pDealOptionsPropSheetObject, SIGNAL(on_cancel_clicked()), this, SLOT(on_cancel_clicked()));

    QString txt;

    //High Card Points, j is suit and i is seat.
    for (int j = 0; j < 5; j++)
        for (int i = 0; i < 4; i++)
        {
            int low, high;
            low = dealOptionDoc.hcp[0][j][i];
            high = dealOptionDoc.hcp[1][j][i];
            int max = (j == NOTRUMP) ? (MAX_TOT_HCP) : (MAX_SUIT_HCP);
            if (high >= max)
                txt = QString("%1+").arg(low);
            else
                txt = QString("%1-%2").arg(low).arg(high);

            QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "hcpSetText",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, j), Q_ARG(QVariant, i), Q_ARG(QVariant, txt));
        }

    //Suit size, j is suit and i is seat.
    for (int j = 0; j < 4; j++)
        for (int i = 0; i < 4; i++)
        {
            int low, high;
            low = dealOptionDoc.suitSize[0][j][i];
            high = dealOptionDoc.suitSize[1][j][i];
            if (high >= MAX_SUIT_SIZE)
                txt = QString("%1+").arg(low);
            else
                txt = QString("%1-%2").arg(low).arg(high);

            QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "suitSizeSetText",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, j), Q_ARG(QVariant, i), Q_ARG(QVariant, txt));
        }

    //Distribution points, i is seat.
    for (int i = 0; i < 4; i++)
    {
        int low, high;
        low = dealOptionDoc.dp[0][i];
        high = dealOptionDoc.dp[1][i];
        if (high >= MAX_TOT_DP)
            txt = QString("%1+").arg(low);
        else
            txt = QString("%1-%2").arg(low).arg(high);

        QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "dpSetText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, i), Q_ARG(QVariant, txt));
    }
}

CDealOptionsPropSheet::~CDealOptionsPropSheet()
{
}

int CDealOptionsPropSheet::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CDealOptionsPropSheet::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CDealOptionsPropSheet::on_ok_clicked()
{
    QObject *pDealOptionsPropSheetObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "isAllOk",
            Q_RETURN_ARG(QVariant, returnedValue));

    bool ok = returnedValue.toBool();
    if (!ok)
    {
        hide();
        CMessageBox::critical(this->parentWidget(), tr("ZBridge Error"), tr("Correct errors before exiting."));
        show();
        return;
    }
    int noDeals = 100000;
    int noOk = dealOptionDoc.checkDealOptions(noDeals);

    if (noOk <= 0)
    {
        hide();
        CMessageBox::critical(this->parentWidget(), tr("ZBridge Error"), tr("No deals found."));
        show();
        return;
    }

    doc->setDealOptions(dealOptionDoc);

    eventLoop.exit(QDialog::Accepted);
}

void CDealOptionsPropSheet::on_cancel_clicked()
{
    eventLoop.exit(QDialog::Rejected);
}

void CDealOptionsPropSheet::on_hcp_editingFinished(int suit, int seat)
{
    QObject *pDealOptionsPropSheetObject = pWidget->rootObject();
    QVariant returnedValue;
    int low, high;

    QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "hcpText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, suit), Q_ARG(QVariant, seat));

    QString text = returnedValue.toString();
    int max = (suit == NOTRUMP) ? MAX_TOT_HCP : MAX_SUIT_HCP;

    bool ok = getValues(text, max, &low, &high);

    if (ok)
    {
        dealOptionDoc.hcp[0][suit][seat] = low;
        dealOptionDoc.hcp[1][suit][seat] = high;
    }

    QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "hcpSetOk",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, suit), Q_ARG(QVariant, seat), Q_ARG(QVariant, ok));
}


void CDealOptionsPropSheet::on_suitSize_editingFinished(int suit, int seat)
{
    QObject *pDealOptionsPropSheetObject = pWidget->rootObject();
    QVariant returnedValue;
    int low, high;

    QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "suitSizeText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, suit), Q_ARG(QVariant, seat));

    QString text = returnedValue.toString();

    bool ok = getValues(text, MAX_SUIT_SIZE, &low, &high);

    if (ok)
    {
        dealOptionDoc.suitSize[0][suit][seat] = low;
        dealOptionDoc.suitSize[1][suit][seat] = high;
    }

    QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "suitSizeSetOk",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, suit), Q_ARG(QVariant, seat), Q_ARG(QVariant, ok));
}


void CDealOptionsPropSheet::on_dp_editingFinished(int seat)
{
    QObject *pDealOptionsPropSheetObject = pWidget->rootObject();
    QVariant returnedValue;
    int low, high;

    QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "dpText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, seat));

    QString text = returnedValue.toString();

    bool ok = getValues(text, MAX_TOT_DP, &low, &high);

    if (ok)
    {
        dealOptionDoc.dp[0][seat] = low;
        dealOptionDoc.dp[1][seat] = high;
    }

    QMetaObject::invokeMethod(pDealOptionsPropSheetObject, "dpSetOk",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, seat), Q_ARG(QVariant, ok));
}

bool CDealOptionsPropSheet::getValues(QString &text, int max, int *low, int *high)
{
    int inx;
    bool ok;

    text = text.trimmed();
    if (text.contains('+') && text.endsWith('+') && !text.startsWith('+'))
    {
        *low = text.left(text.size() - 1).toInt(&ok);
        *high = max;
    }
    else if (((inx = text.indexOf('-')) != -1) && !text.endsWith('-') && !text.startsWith('-'))
    {
        *low = text.left(inx).toInt(&ok);
        if (ok)
            *high = text.right(text.size() - inx - 1).toInt(&ok);
    }
    else if (!text.contains('+') && !text.contains('-'))
        *low = *high = text.toInt(&ok);
    else
        ok = false;

    if (ok)
        ok = (*low >= 0) && (*high >= 0) && (*low <= max) && (*high <= max) && (*low <= *high);

    return ok;
}

void CDealOptionsPropSheet::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CDealOptionsPropSheet::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
