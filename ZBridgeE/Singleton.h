#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QtQml/qqml.h>

class Singleton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int zh READ getZh WRITE setZh NOTIFY ZhChanged FINAL)
    Q_PROPERTY(int zw READ getZw WRITE setZw NOTIFY ZwChanged FINAL)
    QML_ELEMENT
    QML_SINGLETON

public:
    Singleton(QObject *parent = nullptr) : QObject(parent) {}

    int getZh() const { return zh; }
    int getZw() const { return zw; }
    void setZh(int v)
    {
        if (v != zh) {
            zh = v;
            emit ZhChanged();
        }
    }
    void setZw(int v)
    {
        if (v != zw) {
            zw = v;
            emit ZwChanged();
        }
    }

signals:
    void ZhChanged();
    void ZwChanged();

public:
    int zh = 3;
    int zw = 3;
};

#endif // SINGLETON_H
