/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CBidOptions.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  23-dec-2018 eak: Use QML instead of widgets.

  Abstract: Select current bid option set (conventions etc.).

  Platforms: Qt.

*/

/**
 * \file
 * Select current bid option set (conventions etc.) (definition).
 */

#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>

#include "cbidoptions.h"
#include "czbridgeapp.h"
#include "czbridgedoc.h"
#include "cbidoptionspropsheet.h"
#include "cnewconvention.h"
#include "cbidoptiondoc.h"
#include "cmessagebox.h"

/**
 * @brief The constructor sets up the user interface.
 *
 *   - Finds available bid option sets.
 *   - Determines current bid option sets for North/South and East/Weat.
 */
CBidOptions::CBidOptions(CZBridgeApp *app, CZBridgeDoc *doc, QWidget *parent) :
    QWidget(parent)
{
    //Initialize with QML seat configuration dialog.
    pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    connect(pWidget, &QQuickWidget::statusChanged, this, &CBidOptions::quickWidgetStatusChanged);
    connect(pWidget, &QQuickWidget::sceneGraphError, this, &CBidOptions::sceneGraphError);
    setWindowTitle(tr("ZBridge - Bidding/Play"));
    pWidget->setSource(QUrl("qrc:///CBidOptions.qml"));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(pWidget);

    QObject *pBidOptionsObject = pWidget->rootObject();

    //Set screen zoom factor.
    QVariant returnedValue;
    int zf = CZBridgeApp::getZoom();
    QMetaObject::invokeMethod(pBidOptionsObject, "setZoom",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, zf));
    this->app = app;
    this->doc = doc;

    //Connect signals (QML -> C++).
    connect(pBidOptionsObject, SIGNAL(on_northSouth_clicked()), this, SLOT(on_northSouth_clicked()));
    connect(pBidOptionsObject, SIGNAL(on_eastWest_clicked()), this, SLOT(on_eastWest_clicked()));
    connect(pBidOptionsObject, SIGNAL(on_northSouthConvention_currentIndexChanged(int)), this, SLOT(on_northSouthConvention_currentIndexChanged(int)));
    connect(pBidOptionsObject, SIGNAL(on_eastWestConvention_currentIndexChanged(int)), this, SLOT(on_eastWestConvention_currentIndexChanged(int)));
    connect(pBidOptionsObject, SIGNAL(on_newConvention_clicked()), this, SLOT(on_newConvention_clicked()));
    connect(pBidOptionsObject, SIGNAL(on_editConvention_clicked()), this, SLOT(on_editConvention_clicked()));
    connect(pBidOptionsObject, SIGNAL(on_deleteConvention_clicked()), this, SLOT(on_DeleteConvention_clicked()));
    connect(pBidOptionsObject, SIGNAL(on_ok_clicked()), this, SLOT(on_ok_clicked()));
    connect(pBidOptionsObject, SIGNAL(on_cancel_clicked()), this, SLOT(on_cancel_clicked()));

    //Find available bid option sets.
    curBidOption = doc->getCurBidOption();
    bidOptions = doc->getBidOptions();
    nsIndex = ewIndex = -1;
    if (!bidOptions->empty())
    {
        int i;

        //Add bid option sets to drop down.
        for (i = 0; i < bidOptions->size(); i++)
        {
            QMetaObject::invokeMethod(pBidOptionsObject, "addNorthSouthConventionItem",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, (*bidOptions)[i].name));
            QMetaObject::invokeMethod(pBidOptionsObject, "addEastWestConventionItem",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, (*bidOptions)[i].name));
        }
        QMetaObject::invokeMethod(pBidOptionsObject, "findNorthSouthConventionText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, curBidOption[NSBIDOPTIONSINDEX]));
                nsIndex = returnedValue.toInt();
        QMetaObject::invokeMethod(pBidOptionsObject, "findEastWestConventionText",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, curBidOption[EWBIDOPTIONSINDEX]));
                ewIndex = returnedValue.toInt();

        if (nsIndex < 0) nsIndex = 0;
        if (ewIndex < 0) ewIndex = 0;

        //Set current bid option sets.
        QMetaObject::invokeMethod(pBidOptionsObject, "setNorthSouthConventionCurrentIndex",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, nsIndex));
        QMetaObject::invokeMethod(pBidOptionsObject, "setEastWestConventionCurrentIndex",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, ewIndex));
    }
    else
    {
        QMetaObject::invokeMethod(pBidOptionsObject, "setDeleteConventionEnable",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, false));
        QMetaObject::invokeMethod(pBidOptionsObject, "setEditConventionEnable",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, false));
    }
    QMetaObject::invokeMethod(pBidOptionsObject, "setNorthSouthChecked",
            Q_RETURN_ARG(QVariant, returnedValue));
    QMetaObject::invokeMethod(pBidOptionsObject, "setEastWestConventionEnable",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, false));
}

CBidOptions::~CBidOptions()
{
}

int CBidOptions::exec()
{
    show();
    int ret = eventLoop.exec();
    hide();

    return ret;
}

void CBidOptions::closeEvent(QCloseEvent *event)
{
    eventLoop.exit(QDialog::Rejected);
}

/**
 * @brief Select North/South.
 */
void CBidOptions::on_northSouth_clicked()
{
    QObject *pBidOptionsObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pBidOptionsObject, "setNorthSouthConventionEnable",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, true));
    QMetaObject::invokeMethod(pBidOptionsObject, "setEastWestConventionEnable",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, false));
}

/**
 * @brief Select East/West.
 */
void CBidOptions::on_eastWest_clicked()
{
    QObject *pBidOptionsObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pBidOptionsObject, "setNorthSouthConventionEnable",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, false));
    QMetaObject::invokeMethod(pBidOptionsObject, "setEastWestConventionEnable",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, true));
}

/**
 * @brief Select new bid option set for North/South
 */
void CBidOptions::on_northSouthConvention_currentIndexChanged(int index)
{
    nsIndex = index;
}

/**
 * @brief Select new bid option set for East/West.
 */
void CBidOptions::on_eastWestConvention_currentIndexChanged(int index)
{
    ewIndex = index;
}

/**
 * @brief Create a new bid option set.
 */
void CBidOptions::on_newConvention_clicked()
{
    int i;
    QString refConventionName;
    bool isNorthSouthChecked, isEastWestChecked;
    QObject *pBidOptionsObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pBidOptionsObject, "isNorthSouthChecked",
            Q_RETURN_ARG(QVariant, returnedValue));
    isNorthSouthChecked = returnedValue.toBool();
    QMetaObject::invokeMethod(pBidOptionsObject, "isEastWestChecked",
            Q_RETURN_ARG(QVariant, returnedValue));
    isEastWestChecked = returnedValue.toBool();

    //Determine reference bid option set.
    if ((nsIndex >= 0) && isNorthSouthChecked)
    {
        QMetaObject::invokeMethod(pBidOptionsObject, "northSouthConventionCurrentText",
                Q_RETURN_ARG(QVariant, returnedValue));
        refConventionName = returnedValue.toString();
    }
    else
        if ((ewIndex >= 0) && isEastWestChecked)
        {
            QMetaObject::invokeMethod(pBidOptionsObject, "eastWestConventionCurrentText",
                    Q_RETURN_ARG(QVariant, returnedValue));
            refConventionName = returnedValue.toString();
        }

    //Activate new convention dialog (to determine name of new bid option set).
    hide();
    CNewConvention newConventionDialog(refConventionName, this->parentWidget());
    if (newConventionDialog.exec() == QDialog::Accepted)
    {
        //Name is accepted.
        QString newConventionName = newConventionDialog.getNewConventionName();

        //Check name of new bid option set.
        if (newConventionName.isEmpty())
        {
            CMessageBox::warning(this->parentWidget(), tr("ZBridge Warning"), tr("Illegal name of new bid option set.\nThe name must not be empty."));
            show();
            return;
        }

        for (i = 0; i < bidOptions->size(); i++)
        if ((*bidOptions)[i].name == newConventionName)
        {
            CMessageBox::warning(this->parentWidget(), tr("ZBridge Warning"), tr("Illegal name of new bid option set.\nThe bid option set already exists."));
            show();
            return;
        }
        for (i = 0; i < bidOptions->size(); i++)
            if ((*bidOptions)[i].name == refConventionName)
                break;

        //Name is ok. Activate bid options property sheet to determine bid options for the new
        //bid option set.
        CBidOptionDoc bidOption;
        bidOption = doc->getDefaultBidOption();
        if (i < bidOptions->size())
            bidOption = (*bidOptions)[i];
        CBidOptionsPropSheet biddingOptsDialog(bidOption, app, doc, this->parentWidget());
        if (biddingOptsDialog.exec() == QDialog::Accepted)
        {
            //The new bid option set was accepted. Add it to available bid option sets.
            bidOption = biddingOptsDialog.getBidOption();
            bidOption.name = newConventionName;
            bidOptions->append(bidOption);
            QMetaObject::invokeMethod(pBidOptionsObject, "addNorthSouthConventionItem",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, bidOption.name));
            QMetaObject::invokeMethod(pBidOptionsObject, "addEastWestConventionItem",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, bidOption.name));
            QMetaObject::invokeMethod(pBidOptionsObject, "setDeleteConventionEnable",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, true));
            QMetaObject::invokeMethod(pBidOptionsObject, "setEditConventionEnable",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, true));

            doc->SaveBidOptions();
        }
    }
    show();
}

/**
 * @brief Edit the current bid option set.
 */
void CBidOptions::on_editConvention_clicked()
{
    QString curConventionName;
    int i;
    bool isNorthSouthChecked;
    QObject *pBidOptionsObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pBidOptionsObject, "isNorthSouthChecked",
            Q_RETURN_ARG(QVariant, returnedValue));
    isNorthSouthChecked = returnedValue.toBool();

    //Determine which bid option set to edit.
    if (isNorthSouthChecked)
    {
        QMetaObject::invokeMethod(pBidOptionsObject, "northSouthConventionCurrentText",
                Q_RETURN_ARG(QVariant, returnedValue));
        curConventionName = returnedValue.toString();
    }
    else
    {
        QMetaObject::invokeMethod(pBidOptionsObject, "eastWestConventionCurrentText",
                Q_RETURN_ARG(QVariant, returnedValue));
        curConventionName = returnedValue.toString();
    }

    for (i = 0; i < bidOptions->size(); i++)
        if ((*bidOptions)[i].name == curConventionName)
            break;

    //Activate bid option property sheet to edit the current bid option set.
    hide();
    CBidOptionsPropSheet biddingOptsDialog((*bidOptions)[i], app, doc, this->parentWidget());
    if (biddingOptsDialog.exec() == QDialog::Accepted)
    {
        //Editing was accepted. Save the changes.
        (*bidOptions)[i] = biddingOptsDialog.getBidOption();

        doc->SaveBidOptions();
    }
    show();
}

/**
 * @brief Delete the current bid option set.
 */
void CBidOptions::on_DeleteConvention_clicked()
{
    int delIndex;
    QString delConventionName;
    bool isNorthSouthChecked;
    QObject *pBidOptionsObject = pWidget->rootObject();
    QVariant returnedValue;

    QMetaObject::invokeMethod(pBidOptionsObject, "isNorthSouthChecked",
            Q_RETURN_ARG(QVariant, returnedValue));
    isNorthSouthChecked = returnedValue.toBool();

    //Determine which bid option set to delete.
    if (isNorthSouthChecked)
    {
        QMetaObject::invokeMethod(pBidOptionsObject, "northSouthConventionCurrentText",
                Q_RETURN_ARG(QVariant, returnedValue));
        delConventionName = returnedValue.toString();

        delIndex = nsIndex;
    }
    else
    {
        QMetaObject::invokeMethod(pBidOptionsObject, "eastWestConventionCurrentText",
                Q_RETURN_ARG(QVariant, returnedValue));
        delConventionName = returnedValue.toString();

        delIndex = ewIndex;
    }

    int i;
    for (i = 0; i < bidOptions->size(); i++)
        if ((*bidOptions)[i].name == delConventionName)
            break;

    //Delete the bid option set.
    bidOptions->removeAt(i);

    QMetaObject::invokeMethod(pBidOptionsObject, "removeNorthSouthConventionItem",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, delIndex));
    QMetaObject::invokeMethod(pBidOptionsObject, "removeEastWestConventionItem",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, delIndex));

    if (bidOptions->size() == 0)
    {
        QMetaObject::invokeMethod(pBidOptionsObject, "setDeleteConventionEnable",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, false));
        QMetaObject::invokeMethod(pBidOptionsObject, "setEditConventionEnable",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(QVariant, false));
    }

    //Save the changes.
    doc->SaveBidOptions();
}

/**
 * @brief Ok was clicked.
 */
void CBidOptions::on_ok_clicked()
{
    QObject *pBidOptionsObject = pWidget->rootObject();
    QVariant returnedValue;

    if ((nsIndex >= 0) && (ewIndex >= 0))
    {
        //Save current North/South and East/West bid option set choices.
        QMetaObject::invokeMethod(pBidOptionsObject, "northSouthConventionCurrentText",
                Q_RETURN_ARG(QVariant, returnedValue));
        curBidOption[NSBIDOPTIONSINDEX] = returnedValue.toString();
        QMetaObject::invokeMethod(pBidOptionsObject, "eastWestConventionCurrentText",
                Q_RETURN_ARG(QVariant, returnedValue));
        curBidOption[EWBIDOPTIONSINDEX] = returnedValue.toString();
    }
    eventLoop.exit(QDialog::Accepted);
}

void CBidOptions::on_cancel_clicked()
{
    eventLoop.exit(QDialog::Rejected);
}

void CBidOptions::quickWidgetStatusChanged(QQuickWidget::Status status)
{
    if (status == QQuickWidget::Error) {
        QStringList errors;
        const auto widgetErrors = pWidget->errors();
        for (const QQmlError &error : widgetErrors)
            errors.append(error.toString());
//        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void CBidOptions::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
//     statusBar()->showMessage(message);
}
