/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CFileDialog.h
  Developers: eak

  Revision History:
  22-jan-2018 eak: original.

  Abstract: About dialog.

  Platforms: Qt/QML.

*/

/**
 * @file File dialog (declaration).
 * File dialog (declaration).
 */

#ifndef CFILEDIALOG_H
#define CFILEDIALOG_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>
#include <QEventLoop>

class CFileDialog : public QWidget
{
    Q_OBJECT

public:
    explicit CFileDialog(QString headLine, QStringList nameFilters, QWidget *parent = 0);
    ~CFileDialog();

    QString getFileURL();
    QString getFileName();

    int exec();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:

    QQuickWidget *pWidget;

    QEventLoop eventLoop;
};

#endif // CFILEDIALOG_H
