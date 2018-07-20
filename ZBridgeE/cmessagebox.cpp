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

#include "cmessage.h"
#include "cmessagebox.h"

int CMessageBox::question(QWidget *parent, const QString &title, const QString &text)
{
    CMessage message(parent);

    return message.question(title, text);
}

int CMessageBox::information(QWidget *parent, const QString &title, const QString &text)
{
    CMessage message(parent);

    return message.information(title, text);
}

int CMessageBox::warning(QWidget *parent, const QString &title, const QString &text)
{
    CMessage message(parent);

    return message.warning(title, text);
}

int CMessageBox::critical(QWidget *parent, const QString &title, const QString &text)
{
    CMessage message(parent);

    return message.critical(title, text);
}
