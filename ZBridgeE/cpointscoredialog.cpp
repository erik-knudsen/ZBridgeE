/* Erik Aagaard Knudsen.
  Copyright © 2014 - All Rights Reserved

  Project: ZBridge
  File: CPointDialog.cpp
  Developers: eak

  Revision History:
  9-aug-2014 eak: Original
  12-feb-2018 eak: Use QML instead of Widgets.

  Abstract: Point (MP or IMP) score dialog.

  Platforms: Qt.
  */

/**
 * \file
 * The file implements the definition of the point score dialog class.
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "Defines.h"
#include "cgamesdoc.h"
#include "cplaydialog.h"
#include "cpointscoredialog.h"

CPointScoreDialog::CPointScoreDialog(CGamesDoc *games, int scoringMethod, int index, QWidget *parent) :
    QWidget(parent)
{
    int board;
    Seat dealer;
    Team vulnerable;

    this->games = games;
    this->scoringMethod = scoringMethod;
    this->index = index;

    //Initialize with QML point score dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CPointScoreDialog::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CPointScoreDialog::sceneGraphError);
    setWindowTitle(tr("ZBridge - Board Scores"));
    pWidget->setSource(QUrl("qrc:///CPointScoreDialog.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pPointScoreDialogObject = pWidget->rootObject();
    QVariant returnedValue;

    connect(pPointScoreDialogObject, SIGNAL(on_OKButton_Clicked()), this, SLOT(on_OKButton_Clicked()));

    games->getGame(index, &board, &dealer, &vulnerable);

    //Set board text.
    QString text = QString(tr("Board") + " %1").arg(board);
    QMetaObject::invokeMethod(pPointScoreDialogObject, "boardSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, text));

    //Vulnerability.
    text = QString(tr("Vulnerability") + " %1").
            arg(QCoreApplication::translate("defines", TEAM_NAMES[vulnerable]));
    QMetaObject::invokeMethod(pPointScoreDialogObject, "vulnerabilitySetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, text));

    //Scoring method.
    if (scoringMethod == IMP)
        text = tr("Scoring method is IMP");
    else
        text = tr("Scoring method is MP");
    QMetaObject::invokeMethod(pPointScoreDialogObject, "scoringMethodSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, text));

    //Fill table.
    int noAuctionAndPlay = games->getNumberAuctionAndPlay(index);
    for (int auctionAndPlayIndex = 0; auctionAndPlayIndex < noAuctionAndPlay; auctionAndPlayIndex++)
    {
        QString westName, northName, eastName, southName;
        Seat declarer;
        Bids contract, contractModifier;
        int result;

        games->getActorNames(index, auctionAndPlayIndex,
                             &westName, &northName, &eastName, &southName);
        games->getAuctionAndPlay(index, auctionAndPlayIndex,
                        &declarer, &contract, &contractModifier, &result);
        QString namesTxt;
        QString contractTxt;
        QString tricksTxt;
        QString scoreTxt;
        QString pointTxt;

        //Players.
        namesTxt = QString("%1-%2 / %3-%4").arg(northName).arg(southName).arg(eastName).arg(westName);

        //Contract.
        if (contract == BID_PASS)
            contractTxt = tr("P");
        else
        {
            Suit suit = BID_SUIT(contract);
            int level = BID_LEVEL(contract);
            contractTxt = QString("%1 %2%3").arg(QCoreApplication::translate("defines", SEAT_NAMES[declarer])[0]).
                    arg(level).
                    arg(QCoreApplication::translate("defines", SUIT_NAMES[suit]));
            if (contractModifier == BID_DOUBLE)
                contractTxt += " X";
            else if (contractModifier == BID_REDOUBLE)
                contractTxt += " XX";
        }

        //Result.
        if (declarer == NO_SEAT)
            tricksTxt = QString("-");
        else
            tricksTxt = QString("%1").arg(result);

        //Score.
        int score = games->getDuplicateScore(index, auctionAndPlayIndex);
        scoreTxt = QString("%1").arg(score);

        //Points (MP or IMP).
        float point = games->getDuplicatePointBoard(index,auctionAndPlayIndex, scoringMethod);
        if (scoringMethod == IMP)
                pointTxt = QString("%1").arg(point, 0, 'f', 1);
        else
                pointTxt = QString("%1").arg(point, 0, 'f', 0);

        QMetaObject::invokeMethod(pPointScoreDialogObject, "addToScoreModel",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, namesTxt), Q_ARG(QVariant, contractTxt),
                Q_ARG(QVariant, tricksTxt), Q_ARG(QVariant, scoreTxt),
                Q_ARG(QVariant, pointTxt));
    }

    //Respond to click on row.
    connect(pPointScoreDialogObject, SIGNAL(namesClicked(int)), this, SLOT(rowClicked(int)));
}

CPointScoreDialog::~CPointScoreDialog()
{
}

int CPointScoreDialog::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CPointScoreDialog::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CPointScoreDialog::on_OKButton_Clicked()
{
    eventLoop.exit(QDialog::Accepted);
}

//User clicked a row in the table.
void CPointScoreDialog::rowClicked(int row)
{
    //Show play dialog.
    hide();
    CPlayDialog playDialog(games, index, row, this->parentWidget());
    playDialog.exec();
    show();
}

void CPointScoreDialog::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CPointScoreDialog::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
