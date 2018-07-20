/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CNewConvention.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  3-jan-2018 eak: Use QML instead of Widgets.

  Abstract: Select name for new convention.

  Platforms: Qt.

*/

/**
 * \file
 * Select name for new convention (declaration).
 */

#ifndef CNEWCONVENTION_H
#define CNEWCONVENTION_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

class QString;

/**
 * @brief Dialog for user to select the name of a new bid option set.
 */
class CNewConvention : public QWidget
{
    Q_OBJECT
    
public:
    explicit CNewConvention(QString &refConventionName,  QWidget *parent = 0);
    ~CNewConvention();

    int exec();

    QString getNewConventionName();

protected:
    void closeEvent(QCloseEvent *event);
    
private slots:
    void onAccepted();
    void onRejected();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CNEWCONVENTION_H
