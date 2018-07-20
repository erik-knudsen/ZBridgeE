/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CMessageBox.h
  Developers: eak

  Revision History:
  8-dec-2017 eak: Original.

  Abstract: Message box class (C++ interface to QML MessageBox).

  Platforms: Qt.

*/

#ifndef CMESSAGEBOX_H
#define CMESSAGEBOX_H

#include <QString>
#include <QWidget>


class CMessageBox
{
public:
    static int question(QWidget *parent, const QString &title, const QString &text);
    static int information(QWidget *parent, const QString &title, const QString &text);
    static int warning(QWidget *parent, const QString &title, const QString &text);
    static int critical(QWidget *parent, const QString &title, const QString &text);
};

#endif // CMESSAGEBOX_H
