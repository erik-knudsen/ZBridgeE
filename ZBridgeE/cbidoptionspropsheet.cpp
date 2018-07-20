/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBidOptionsPropSheet.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  6-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Property sheet for selecting bid options.

  Platforms: Qt.

*/

/**
 * \file
 * Property sheet for selecting bid options.
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "cbidoptionspropsheet.h"
#include "czbridgeapp.h"
#include "czbridgedoc.h"
#include "cbidoptiondoc.h"

CBidOptionsPropSheet::CBidOptionsPropSheet(CBidOptionDoc &bidOptionDoc, CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML seat configuration dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CBidOptionsPropSheet::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CBidOptionsPropSheet::sceneGraphError);
    setWindowTitle(tr("ZBridge - Bidding/Play"));
    pWidget->setSource(QUrl("qrc:///CBidOptionsPropSheet.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pBidOptionsPropSheetObject = pWidget->rootObject();

    this->app = app;
    this->doc = doc;
    this->bidOptionDoc = bidOptionDoc;

    //Connect signals (QML -> C++).
    connect(pBidOptionsPropSheetObject, SIGNAL(on_americanStyle_clicked()), this, SLOT(on_americanStyle_clicked()));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_europeanStyle_clicked()), this, SLOT(on_europeanStyle_clicked()));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_majorFour_clicked()), this, SLOT(on_majorFour_clicked()));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_majorFive_clicked()), this, SLOT(on_majorFive_clicked()));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_stayman_clicked(bool)), this, SLOT(on_stayman_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_jacobyTransfers_clicked(bool)), this, SLOT(on_jacobyTransfers_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_limitRaises_clicked(bool)), this, SLOT(on_limitRaises_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_weakTwo_clicked(bool)), this, SLOT(on_weakTwo_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_oneNTRange12_14_clicked()), this, SLOT(on_oneNTRange12_14_clicked()));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_oneNTRange15_17_clicked()), this, SLOT(on_oneNTRange15_17_clicked()));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_open1NTWeakMajor_clicked(bool)), this, SLOT(on_open1NTWeakMajor_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_structuredReverses_clicked(bool)), this, SLOT(on_structuredReverses_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_takeoutDoubles_clicked(bool)), this, SLOT(on_takeOutDoubles_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_negativeDoubles_clicked(bool)), this, SLOT(on_negativeDoubles_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_michaelsCueBid_clicked(bool)), this, SLOT(on_michaelsCueBid_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_unusualNT_clicked(bool)), this, SLOT(on_unusualNT_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_jumpOvercallWeak_clicked(bool)), this, SLOT(on_jumpOvercallWeak_clicked(bool)));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_buttonBox_accepted()), this, SLOT(on_buttonBox_accepted()));
    connect(pBidOptionsPropSheetObject, SIGNAL(on_buttonBox_rejected()), this, SLOT(on_buttonBox_rejected()));

    QVariant returnedValue;

    //General.
    if (bidOptionDoc.bidStyle == EUROPEAN_STYLE)
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "europeanStyleSetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, true));
    else
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "americanStyleSetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, true));

    if (bidOptionDoc.majorsMode == MAJOR_FOUR)
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "majorFourSetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, true));
    else
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "majorFiveSetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, true));

    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "staymanSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, true));
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "jacobyTransfersSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.jacobyTransfers));

    setDependencies();

    //2-Bids.
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "weakTwoSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.twoBidsMode != S2_NATURAL));

    //NT-Range.
    if (bidOptionDoc.oneNTRange == ONE_NT_RANGE_12_14)
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "oneNTRange12_14SetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, true));
    else if (bidOptionDoc.oneNTRange == ONE_NT_RANGE_15_17)
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "oneNTRange15_17SetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, true));
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "open1NTWeakMajorSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.open1NTWeakMajor));

    //Misc.
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "structuredReversesSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.structuredReverse));
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "takeoutDoublesSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.takeoutDoubles));
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "negativeDoublesSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.negativeDoubles));
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "michaelsCueBidSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.directCueBid == MICHAELS_CUEBID));
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "unusualNTSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.unusual2NT));
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "unusualNTSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, false));
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "jumpOvercallWeakSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, bidOptionDoc.jumpOvercalls != JUMP_OVERCALL_STRONG));
}

CBidOptionsPropSheet::~CBidOptionsPropSheet()
{
}

int CBidOptionsPropSheet::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CBidOptionsPropSheet::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CBidOptionsPropSheet::on_americanStyle_clicked()
{
    bidOptionDoc.bidStyle = AMERICAN_STYLE;

    setDependencies();
}

void CBidOptionsPropSheet::on_europeanStyle_clicked()
{
    bidOptionDoc.bidStyle = EUROPEAN_STYLE;

    setDependencies();
}

void CBidOptionsPropSheet::on_majorFour_clicked()
{
    bidOptionDoc.majorsMode = MAJOR_FOUR;

    setDependencies();
}

void CBidOptionsPropSheet::on_majorFive_clicked()
{
    bidOptionDoc.majorsMode = MAJOR_FIVE;

    setDependencies();
}

void CBidOptionsPropSheet::on_stayman_clicked(bool checked)
{
    QObject *pBidOptionsPropSheetObject = pWidget->rootObject();
    QVariant returnedValue;
    QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "staymanSetChecked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, true));
}

void CBidOptionsPropSheet::on_jacobyTransfers_clicked(bool checked)
{
    bidOptionDoc.jacobyTransfers = checked;
}

void CBidOptionsPropSheet::on_limitRaises_clicked(bool checked)
{
    if (bidOptionDoc.bidStyle == EUROPEAN_STYLE)
    {
        QObject *pBidOptionsPropSheetObject = pWidget->rootObject();
        QVariant returnedValue;
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "limitRaisesSetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, true));
    }
    else
    {
        bidOptionDoc.limitRaises = checked;
        setDependencies();
    }
}

void CBidOptionsPropSheet::on_weakTwo_clicked(bool checked)
{
    if (checked)
        bidOptionDoc.twoBidsMode = W2_FEATURE;
    else
        bidOptionDoc.twoBidsMode = S2_NATURAL;
}

void CBidOptionsPropSheet::on_oneNTRange12_14_clicked()
{
    bidOptionDoc.oneNTRange = ONE_NT_RANGE_12_14;
}

void CBidOptionsPropSheet::on_oneNTRange15_17_clicked()
{
    bidOptionDoc.oneNTRange = ONE_NT_RANGE_15_17;
}

void CBidOptionsPropSheet::on_open1NTWeakMajor_clicked(bool checked)
{
    bidOptionDoc.open1NTWeakMajor = checked;
}

void CBidOptionsPropSheet::on_structuredReverses_clicked(bool checked)
{
    bidOptionDoc.structuredReverse = checked;
}

void CBidOptionsPropSheet::on_takeOutDoubles_clicked(bool checked)
{
    bidOptionDoc.takeoutDoubles = checked;
}

void CBidOptionsPropSheet::on_negativeDoubles_clicked(bool checked)
{
    bidOptionDoc.negativeDoubles = checked;
}

void CBidOptionsPropSheet::on_michaelsCueBid_clicked(bool checked)
{
    if (checked)
        bidOptionDoc.directCueBid = MICHAELS_CUEBID;
    else
        bidOptionDoc.directCueBid = STRONG_CUE_BID;
}

void CBidOptionsPropSheet::on_unusualNT_clicked(bool checked)
{
    bidOptionDoc.unusual2NT = checked;
}

void CBidOptionsPropSheet::on_jumpOvercallWeak_clicked(bool checked)
{
    if (checked)
        bidOptionDoc.jumpOvercalls = JUMP_OVERCALL_WEAK_NATURAL;
    else
        bidOptionDoc.jumpOvercalls = JUMP_OVERCALL_STRONG;
}

void CBidOptionsPropSheet::on_buttonBox_accepted()
{
    eventLoop.exit(QDialog::Accepted);
}

void CBidOptionsPropSheet::on_buttonBox_rejected()
{
    eventLoop.exit(QDialog::Rejected);
}

void CBidOptionsPropSheet::setDependencies()
{
    QObject *pBidOptionsPropSheetObject = pWidget->rootObject();
    QVariant returnedValue;

    if (bidOptionDoc.bidStyle == EUROPEAN_STYLE)
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "limitRaisesSetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, true));
    else
        QMetaObject::invokeMethod(pBidOptionsPropSheetObject, "limitRaisesSetChecked",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, bidOptionDoc.limitRaises));
}

void CBidOptionsPropSheet::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CBidOptionsPropSheet::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
