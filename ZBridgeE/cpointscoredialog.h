/* Erik Aagaard Knudsen.
  Copyright © 2014 - All Rights Reserved

  Project: ZBridge
  File: CPointScoreDialog.h
  Developers: eak

  Revision History:
  9-aug-2014 eak: Original
  12-feb-2018 eak: Use QML instead of Widgets.

  Abstract: Point (MP or IMP) score dialog class.

  Platforms: Qt.
  */

/**
 * \file
 * The file implements the declaration of the point score dialog class.
 */

#ifndef CPOINTSCOREDIALOG_H
#define CPOINTSCOREDIALOG_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

class CGamesDoc;

/**
 * @brief The CPointScoreDialog class shows a table with results for a given game.
 *
 * The table has one line for each play of a given game. The columns shows name N-S / E-W, contract,
 * tricks, score and point (IMP or MP). If the user clicks a row then the play clicked (auction and play)
 * is shown in a separate dialog.
 */
class CPointScoreDialog : public QWidget
{
    Q_OBJECT

public:
    explicit CPointScoreDialog(CGamesDoc *games, int scoringMethod, int index, QWidget *parent = 0);
    ~CPointScoreDialog();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_OKButton_Clicked();
    void rowClicked(int row);
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:    
    CGamesDoc *games;
    int scoringMethod;
    int index;

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CPOINTSCOREDIALOG_H
