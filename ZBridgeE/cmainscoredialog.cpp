/* Erik Aagaard Knudsen.
  Copyright © 2014 - All Rights Reserved

  Project: ZBridge
  File: CMainScoreDialog.cpp
  Developers: eak

  Revision History:
  9-aug-2014 eak: Original
  8-feb-2018 eak: Use QML instead of Widgets.

  Abstract: Main score dialog.

  Platforms: Qt.
  */

/**
 * \file
 * The file implements the definition of the main score dialog class.
 */
#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "cpointscoredialog.h"
#include "crubberscoredialog.h"
#include "crankscoredialog.h"
#include "cplaydialog.h"
#include "cgamesdoc.h"
#include "cmainscoredialog.h"

CMainScoreDialog::CMainScoreDialog(CGamesDoc *games, QWidget *parent) :
    QWidget(parent)
{
    this->games = games;

    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CMainScoreDialog::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CMainScoreDialog::sceneGraphError);
    setWindowTitle(tr("ZBridge - Main Scores"));

    scoringMethod = FORSCORE;
    sUpdateTable();
}

CMainScoreDialog::~CMainScoreDialog()
{
}

int CMainScoreDialog::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CMainScoreDialog::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CMainScoreDialog::sUpdateTable()
{
    QString westName, northName, eastName, southName;
    QObject *pScoreTableObject;
    QVariant returnedValue;

    if (scoringMethod != games->getScoringMethod())
    {
        scoringMethod = games->getScoringMethod();
        QString text;

        //Headline for table.
        if (scoringMethod == RUBBER)
        {
            //Initialize with QML rubber score table.
            pWidget->setSource(QUrl("qrc:///CMainScoreDialog_Rubber.qml"));
            text = tr("Scoring method is Rubber.");
        }
        else if (scoringMethod == PRACTICE)
        {
            //Initialize with QML practice score table.
            pWidget->setSource(QUrl("qrc:///CMainScoreDialog_Practice.qml"));
            text = tr("Scoring method is Practice.");
        }
        else if (scoringMethod == IMP)
        {
            //Initialize with QML IMP/MP score table.
            pWidget->setSource(QUrl("qrc:///CMainScoreDialog_MP.qml"));
            text = tr("Scoring method is IMP");
        }
        else if (scoringMethod == MP)
        {
            //Initialize with QML IMP/MP score table.
            pWidget->setSource(QUrl("qrc:///CMainScoreDialog_MP.qml"));
            text = tr("Scoring method is MP");
        }

        if(layout() != 0)
            delete layout();

        QHBoxLayout *layout = new QHBoxLayout(this);
        layout->addWidget(pWidget);

        pScoreTableObject = pWidget->rootObject();

        //Respond to click of cell.
        connect(pScoreTableObject, SIGNAL(cellClicked(int, int)), this, SLOT(cellClicked(int, int)));

        //Respond to click on row.
        connect(pScoreTableObject, SIGNAL(rowClicked(int)), this, SLOT(rowClicked(int)));

        //Respond to exit.
        connect(pScoreTableObject, SIGNAL(on_OKButton_Clicked()), this, SLOT(on_OKButton_Clicked()));

        //Set scoring method text.
        QMetaObject::invokeMethod(pScoreTableObject, "scoringMethodSetText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, text));
    }
    else
    {
        pScoreTableObject = pWidget->rootObject();
        QMetaObject::invokeMethod(pScoreTableObject, "resetScoreModel",
                Q_RETURN_ARG(QVariant, returnedValue));
    }

    int noPlayed = games->getNumberPlayedGames();

    QString nsNames, ewNames;
    if (noPlayed > 0)
    {
        games->getPlayerNames(PLAYED_GAME, &westName, &northName, &eastName, &southName);
        nsNames = northName + " / " + southName;
        ewNames = eastName + " / " + westName;
    }
    QMetaObject::invokeMethod(pScoreTableObject, "ewNamesSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, ewNames));
    QMetaObject::invokeMethod(pScoreTableObject, "nsNamesSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, nsNames));

    int belowTheLineNSGamePoint = 0, belowTheLineEWGamePoint = 0;
    int belowTheLineNSGame = 0, belowTheLineEWGame = 0;

    //Fill table.
    for (int gameIndex = 0; gameIndex < noPlayed; gameIndex++)
    {
        //First board, vulnerability, contract and tricks (common for all scoring methods).
        int board;
        Seat dealer;
        Team vulnerable;
        Seat declarer;
        Bids contract, contractModifier;
        int result;

        QString boardTxt;
        QString vulnerabilityTxt;
        QString contractTxt;
        QString tricksTxt;

        games->getGame(gameIndex, &board, &dealer, &vulnerable);
        int playedAuctionAndPlayIndex = games->getPlayedAuctionAndPlayIndex(gameIndex);
        games->getAuctionAndPlay(gameIndex, playedAuctionAndPlayIndex,
                        &declarer, &contract, &contractModifier, &result);

        //Board.
        boardTxt = QString("%1").arg(board);

        //Vulnerability.
        vulnerabilityTxt = QString("%1").
                               arg(QCoreApplication::translate("defines", TEAM_NAMES[vulnerable]));

        //Contract.
        QString cntr;
        //Has the game been played?
        if (contract == BID_NONE)
            cntr = tr("NP");
        //Was it a pass game?
        else if (contract == BID_PASS)
            cntr = tr("P");
        //It is a played game.
        else
        {
            Suit suit = BID_SUIT(contract);
            int level = BID_LEVEL(contract);
            cntr = QString("%1 %2%3").arg(QCoreApplication::translate("defines", SEAT_NAMES[declarer])[0]).
                    arg(level).
                    arg(QCoreApplication::translate("defines", SUIT_NAMES[suit]));
            if (contractModifier == BID_DOUBLE)
                cntr += " X";
            else if (contractModifier == BID_REDOUBLE)
                cntr += " XX";
        }
        contractTxt = cntr;

        //Result (number of tricks taken).
        QString res;
        if (declarer == NO_SEAT)
            res = tr("-");
        else
            res = QString("%1").arg(result);
        tricksTxt = res;

        if (scoringMethod == RUBBER)
        {
            QString NSTxt;
            QString nsCol = "black";
            QString EWTxt;
            QString ewCol = "black";

            //Next fill in rubber bridge columns.
            int belowTheLinePoint = games->getBelowTheLine(gameIndex);

            if (belowTheLinePoint > 0)
            {
                belowTheLineNSGamePoint += belowTheLinePoint;
                NSTxt = QString("%1").arg(belowTheLinePoint);
                if (belowTheLineNSGamePoint >= 100)
                {
                    belowTheLineNSGame++;
                    if (belowTheLineNSGame == 2)
                    {
                        nsCol = "green";      //Green
                        belowTheLineNSGame = belowTheLineEWGame = 0;
                    }
                    else
                        nsCol = "red";      //Red
                    belowTheLineNSGamePoint = belowTheLineEWGamePoint = 0;
                }
            }
            else if (belowTheLinePoint < 0)
            {
                belowTheLineEWGamePoint -= belowTheLinePoint;
                EWTxt = QString("%1").arg(-belowTheLinePoint);
                if (belowTheLineEWGamePoint >= 100)
                {
                    belowTheLineEWGame++;
                    if (belowTheLineEWGame == 2)
                    {
                        ewCol = "green";      //Green
                      belowTheLineNSGame = belowTheLineEWGame = 0;
                    }
                    else
                        ewCol = "red";      //Red
                    belowTheLineNSGamePoint = belowTheLineEWGamePoint = 0;
                }
            }
            QMetaObject::invokeMethod(pScoreTableObject, "addToScoreModel",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, boardTxt), Q_ARG(QVariant, vulnerabilityTxt),
                    Q_ARG(QVariant, contractTxt), Q_ARG(QVariant, tricksTxt),
                    Q_ARG(QVariant, NSTxt), Q_ARG(QVariant, nsCol),
                    Q_ARG(QVariant, EWTxt), Q_ARG(QVariant, ewCol));
        }
        else
        {
            QString scoreTxt;
            int score;

            //Score.
            if (playedAuctionAndPlayIndex != -1)
            {
                score = games->getDuplicateScore(gameIndex, playedAuctionAndPlayIndex);
                scoreTxt = QString("%1").arg(score);
            }
            else
                scoreTxt= QString("-");

            if (scoringMethod == PRACTICE)
                QMetaObject::invokeMethod(pScoreTableObject, "addToScoreModel",
                        Q_RETURN_ARG(QVariant, returnedValue),
                        Q_ARG(QVariant, boardTxt), Q_ARG(QVariant, vulnerabilityTxt),
                        Q_ARG(QVariant, contractTxt), Q_ARG(QVariant, tricksTxt),
                        Q_ARG(QVariant, scoreTxt));
            else
            {
                QString resultTxt;
                QString allTxt;

                float result = games->getDuplicatePointBoard(gameIndex, playedAuctionAndPlayIndex,
                                             scoringMethod);
                if (scoringMethod == IMP)
                    resultTxt = QString("%1").arg(result, 0, 'f', 1);
                else
                    resultTxt = QString("%1").arg(result, 0, 'f', 0);

                QString nameWN, nameES;
                if ((declarer == WEST_SEAT) || (declarer == EAST_SEAT))
                {
                    nameWN = westName;
                    nameES = eastName;
                }
                else
                {
                    nameWN = northName;
                    nameES = southName;
                }
                result = games->getDuplicateResultAll(gameIndex, nameWN, nameES, scoringMethod);
                if (scoringMethod == IMP)
                    allTxt = QString("%1").arg(result, 0, 'f', 1);
                else
                    allTxt = QString("%1").arg(result, 0, 'f', 0);

                QMetaObject::invokeMethod(pScoreTableObject, "addToScoreModel",
                        Q_RETURN_ARG(QVariant, returnedValue),
                        Q_ARG(QVariant, boardTxt), Q_ARG(QVariant, vulnerabilityTxt),
                        Q_ARG(QVariant, contractTxt), Q_ARG(QVariant, tricksTxt),
                        Q_ARG(QVariant, scoreTxt), Q_ARG(QVariant, resultTxt),
                        Q_ARG(QVariant, allTxt));
            }
        }
    }
}

void CMainScoreDialog::on_OKButton_Clicked()
{
    eventLoop.exit(QDialog::Accepted);
}

//User clicked a cell in the score table.
void CMainScoreDialog::cellClicked(int row, int column)
{
    if (((column == 4) || (column == 5)) && (scoringMethod == RUBBER))
    {
        //Show rubber score dialog.
        hide();
        CRubberScoreDialog rubberScoreDialog(games, row, this->parentWidget());
        rubberScoreDialog.exec();
        show();
    }
    else if (column == 5)
    {
        //Show point score dialog (MP or IMP).
        hide();
        CPointScoreDialog pointScoreDialog(games, scoringMethod, row, this->parentWidget());
        pointScoreDialog.exec();
        show();
    }
    else if (column == 6)
    {
        //Show rank dialog.
        hide();
        CRankScoreDialog rankScoreDialog(games, scoringMethod, row, this->parentWidget());
        rankScoreDialog.exec();
        show();
    }
}

//User clicked a row in the table.
void CMainScoreDialog::rowClicked(int row)
{
    //Show play dialog.
    hide();
    int playedAuctionAndPlayIndex = games->getPlayedAuctionAndPlayIndex(row);
    CPlayDialog playDialog(games, row, playedAuctionAndPlayIndex, this->parentWidget());
    playDialog.exec();
    show();
}

void CMainScoreDialog::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CMainScoreDialog::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
