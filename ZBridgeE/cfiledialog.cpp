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
 * @file File dialog (definition).
 * File dialog (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "cfiledialog.h"

CFileDialog::CFileDialog(QString headLine, QStringList nameFilters, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML about dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CFileDialog::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CFileDialog::sceneGraphError);
    setWindowTitle(headLine);
    pWidget->setSource(QUrl("qrc:///CFileDialog.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pFileDialogObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pFileDialogObject, "setNameFilters",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, nameFilters));

    connect(pFileDialogObject, SIGNAL(on_buttonBox_accepted()), this, SLOT(on_buttonBox_accepted()));
    connect(pFileDialogObject, SIGNAL(on_buttonBox_rejected()), this, SLOT(on_buttonBox_rejected()));
}

CFileDialog::~CFileDialog()
{
}

QString CFileDialog::getFileURL()
{
    QObject *pFileDialogObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pFileDialogObject, "getFileURL",
            Q_RETURN_ARG(QVariant, returnedValue));

    return returnedValue.toString();
}

QString CFileDialog::getFileName()
{
    QObject *pFileDialogObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pFileDialogObject, "getFileName",
            Q_RETURN_ARG(QVariant, returnedValue));

    return returnedValue.toString();
}

int CFileDialog::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CFileDialog::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

void CFileDialog::on_buttonBox_accepted()
{
    eventLoop.exit(QDialog::Accepted);
}

void CFileDialog::on_buttonBox_rejected()
{
    eventLoop.exit(QDialog::Rejected);
}

void CFileDialog::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CFileDialog::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
