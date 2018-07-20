/* Erik Aagaard Knudsen.
  Copyright © 2015 - All Rights Reserved

  Project: ZBridge
  File: CRankScoreDialog.cpp
  Developers: eak

  Revision History:
  3-feb-2015 eak: Original
  12-feb-2018 eak: Use QML instead of Widgets.

  Abstract: Rank score dialog.

  Platforms: Qt.
  */

/**
 * \file
 * The file implements the definition of the rank score dialog class.
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "Defines.h"
#include "cgamesdoc.h"
#include "cplaydialog.h"
#include "crankscoredialog.h"

CRankScoreDialog::CRankScoreDialog(CGamesDoc *games, int scoringMethod, int index, QWidget *parent) :
    QWidget(parent)
{
    this->scoringMethod = scoringMethod;
    this->games = games;
    this->index = index;

    //Initialize with QML rank score dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CRankScoreDialog::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CRankScoreDialog::sceneGraphError);
    setWindowTitle(tr("ZBridge - Point Scores"));
    pWidget->setSource(QUrl("qrc:///CRankScoreDialog.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pRankScoreDialogObject = pWidget->rootObject();
    QVariant returnedValue;

    connect(pRankScoreDialogObject, SIGNAL(on_OKButton_Clicked()), this, SLOT(on_OKButton_Clicked()));

    QString text;

    //Scoring method.
    if (scoringMethod == IMP)
        text = tr("Scoring method is IMP");
    else
        text = tr("Scoring method is MP");
    QMetaObject::invokeMethod(pRankScoreDialogObject, "scoringMethodSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, text));

    QStringList pairWN;
    QStringList pairES;
    int noPairs = games->getPairs(index, pairWN, pairES);

    //Fill table.
    for (int pairIndex = 0; pairIndex < noPairs; pairIndex++)
    {
        //Pair.
        QString nameTxt = QString("%1-%2").arg(pairWN[pairIndex]).arg(pairES[pairIndex]);

        //Result.
        float result = games->getDuplicateResultAll(index, pairWN[pairIndex], pairES[pairIndex],
                                             scoringMethod);
        result = (result > 0.) ? (((int)(result * 10. + 0.5)) / 10.) : (((int)(result * 10. - 0.5)) / 10.);

        QString resultTxt;
        if (scoringMethod == IMP)
            resultTxt = QString("%1").arg(result, 0, 'f', 1);
        else
            resultTxt = QString("%1").arg(result, 0, 'f', 0);

        QMetaObject::invokeMethod(pRankScoreDialogObject, "addToScoreModel",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, nameTxt), Q_ARG(QVariant, resultTxt));
    }

    //Sort results.
    QMetaObject::invokeMethod(pRankScoreDialogObject, "sort",
            Q_RETURN_ARG(QVariant, returnedValue));
}

CRankScoreDialog::~CRankScoreDialog()
{
}

int CRankScoreDialog::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CRankScoreDialog::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CRankScoreDialog::on_OKButton_Clicked()
{
    eventLoop.exit(QDialog::Accepted);
}

void CRankScoreDialog::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CRankScoreDialog::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
