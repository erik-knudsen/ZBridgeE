/* Erik Aagaard Knudsen.
  Copyright © 2015 - All Rights Reserved

  Project: ZBridge
  File: CRankScoreDialog.h
  Developers: eak

  Revision History:
  3-feb-2015 eak: Original
  12-feb-2018 eak: Use QML instead of Widgets.

  Abstract: Show ranking.

  Platforms: Qt.
  */

/**
 * \file
 * The file implements the declaration of the rank score dialog class.
 */

#ifndef CRANKSCOREDIALOG_H
#define CRANKSCOREDIALOG_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

class CGamesDoc;

/**
 * @brief The CRankScoreDialog class shows a table with the rank of pairs until now.
 *
 * The table has one line for each pair. The columns shows name and total point (IMP or % MP).
 */
class CRankScoreDialog : public QWidget
{
    Q_OBJECT

public:
    explicit CRankScoreDialog(CGamesDoc *games, int scoringMethod, int index, QWidget *parent = 0);
    ~CRankScoreDialog();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_OKButton_Clicked();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    CGamesDoc *games;
    int scoringMethod;
    int index;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CRANKSCOREDIALOG_H
