/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMessage.h
  Developers: eak

  Revision History:
  8-dec-2017 eak: Original.

  Abstract: Message class (C++ interface to QML MessageBox).

  Platforms: Qt.

*/

#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

class CMessage : public QWidget
{
    Q_OBJECT

public:
    CMessage(QWidget *parent = 0);
    ~CMessage();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

public:
    int question(const QString &title, const QString &text);
    int information(const QString &title, const QString &text);
    int warning(const QString &title, const QString &text);
    int critical(const QString &title, const QString &text);

private slots:
    void onAccepted();
    void onRejected();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    int message(const QString &title, const QString &text, char *fnc);

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CMESSAGE_H
