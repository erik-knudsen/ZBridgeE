/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CContent.h
  Developers: eak

  Revision History:
  11-jun-2018 eak: Original

  Abstract: Content dialog. Displays help for the application.

  Platforms: Qt.

*/

/**
 * @file Content (help) dialog (declaration).
 * Content (help) dialog (declaration).
 */

#ifndef CCONTENT_H
#define CCONTENT_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

/**
 * @brief About dialog
 *
 * Version, copyright etc. are shown in the dialog.
 */
class CContent : public QWidget
{
    Q_OBJECT

public:
    explicit CContent(QWidget *parent = 0);
    ~CContent();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_Exit();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CCONTENT_H
