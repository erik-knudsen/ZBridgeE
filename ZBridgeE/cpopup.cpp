#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "czbridgeapp.h"
#include "cpopup.h"

CPopup::CPopup(QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML popup dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CPopup::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CPopup::sceneGraphError);
//    setWindowFlags ((Qt::WindowFlags)Qt::Dialog & (~Qt::WindowContextHelpButtonHint) | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_ShowWithoutActivating);
    setWindowFlags(
                (Qt::WindowFlags)Qt::Dialog & (~Qt::WindowContextHelpButtonHint) | // Add if popup doesn't show up
                Qt::FramelessWindowHint | // No window border
                Qt::WindowDoesNotAcceptFocus | // No focus
                Qt::WindowStaysOnTopHint // Always on top
                );
    pWidget->setSource(QUrl("qrc:///CPopup.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pPopupDlgObject = pWidget->rootObject();

    //Set screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pPopupDlgObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));
}

CPopup::~CPopup()
{
}

void CPopup::showPopup(QString description)
{
    QObject *pPopupDlgObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pPopupDlgObject, "descriptionSetText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, description));

    show();
}

void CPopup::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CPopup::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}

