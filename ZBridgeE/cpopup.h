#ifndef CPOPUP_H
#define CPOPUP_H

#include <QQuickWidget>
#include <QDialog>
#include <QWidget>

class CPopup : public QWidget
{
    Q_OBJECT

public:
    explicit CPopup(QWidget *parent = 0);
    ~CPopup();

    void showPopup(QString description);

private slots:
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:

    QQuickWidget *pWidget;
};

#endif // CPOPUP_H
