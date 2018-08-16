/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: CMainFrame.cpp
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original
  4-mar-2018 eak: Use QML instead of Widgets.

  Abstract: Mainframe.

  Platforms: Qt.

*/

/**
 * \file
 * Mainframe.
 */

//#include <QApplication>
#include <QQuickItem>
#include <QResizeEvent>
#include <QSizePolicy>
#include <QSettings>
#include <QFile>
#include <QFileInfo>
#include <QHostInfo>
#include <QString>
#include <QThread>
#include <QDebug>

#include "ZBridgeException.h"
#include "cmainframe.h"
#include "cmainframemenu.h"
#include "czbridgeapp.h"
#include "czbridgedoc.h"
#include "cgamesdoc.h"
#include "cplayview.h"
#include "caboutdlg.h"
#include "cbidoptions.h"
#include "cdealoptionspropsheet.h"
#include "cdispoptionspropsheet.h"
#include "cgameoptionspropsheet.h"
#include "cseatconfiguration.h"
#include "ctblmngrserver.h"
#include "ctblmngrserverauto.h"
#include "ctblmngrclient.h"
#include "ctblmngrclientauto.h"
#include "cmainscoredialog.h"
#include "crubberscoredialog.h"
#include "cbiddb.h"
#include "cbiddesc.h"
#include "cbidandplayengines.h"
#include "cmessagebox.h"
#include "cfiledialog.h"
#include "ccontent.h"

//Static pointer to mainframe singleton.
CMainFrame *CMainFrame::m_pInstance = 0;

/**
 * @brief Mainframe constructor.
 *
 * Sets up the mainframe etc.:
 *
 *   - Set up mainframe (main menu etc.).
 *   - Allocate playview. This is the view where the play is visualized.
 *   - Determine (server or client) and allocate table manager. The table manager is\n
 *     the controller of what happens.
 *
 * @param app Pointer to application.
 * @param doc Pointer to data container.
 * @param games Pointer to game data.
 */
CMainFrame::CMainFrame(CZBridgeApp *app, CZBridgeDoc *doc, CGamesDoc *games)
{
    this->app = app;
    this->doc = doc;
    this->games = games;

    tableManager = 0;
    tableManagerAuto = 0;

    scoreSelect = false;

    //Bid and play engines.
    bidAndPlayEngines = new CBidAndPlayEngines();

    //Initialize with QML mainframe toolbar.
    pToolBarWidget = new QQuickWidget(this);
    pToolBarWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    pToolBarWidget->setSource(QUrl("qrc:///CMainFrameToolBar.qml"));

    setMenuWidget(pToolBarWidget);

    QObject *pToolBarObject = pToolBarWidget->rootObject();

    connect(pToolBarObject, SIGNAL(on_showMenu_triggered()), this, SLOT(on_showMenu_triggered()));
    connect(pToolBarObject, SIGNAL(on_actionNew_Session_triggered()), this, SLOT(on_actionNew_Session_triggered()));
    connect(pToolBarObject, SIGNAL(on_actionUndo_triggered()), this, SLOT(on_actionUndo_triggered()));
    connect(pToolBarObject, SIGNAL(on_actionHint_triggered()), this, SLOT(on_actionHint_triggered()));

    //Allocate and initialize play view.
    playView = new CPlayView(this);

    //Reset play
    resetPlay();

    //Initialization of main frame window.
    setCentralWidget(playView);
    setWindowIcon(QIcon(":/resources/ZBridgeICN.bmp"));

    resize(QSize(SCENE_HOR_SIZE + 100, SCENE_VER_SIZE + 160));
    setMinimumSize(QSize((SCENE_HOR_SIZE + 100) * .75, (SCENE_VER_SIZE + 160) * .75));
    setMaximumSize(QSize((SCENE_HOR_SIZE + 100) * 2.0, (SCENE_VER_SIZE + 160) * 2.0));

    move(0, 0);
}

CMainFrame::~CMainFrame()
{
    delete bidAndPlayEngines;
}

/**
 * @brief Get pointer to mainframe singleton instance.
 *
 * @return Pointer to mainframe singleton instance.
 */
CMainFrame* CMainFrame::Instance()
{
    return m_pInstance;
}

/**
 * @brief Handle resize of mainframe (and children) windows.
 *
 * @param resizeEvent Parameters for resize.
 */
void CMainFrame::resizeEvent(QResizeEvent *resizeEvent)
{
    QSize size = resizeEvent->size();
    QSize oldSize = resizeEvent->oldSize();
    if (oldSize.width() > 0)
    {
       float scaleXFactor = float(size.width() - 30)/(oldSize.width() - 30);
       float scaleYFactor = float(size.height() - 130)/(oldSize.height() - 130);
       playView->scale(scaleXFactor, scaleYFactor);
    }
}

/**
 * @brief Get host address.
 *
 * @param host The name of the host.
 * @return the host address.
 */
QHostAddress CMainFrame::getHostAddress(QString host)
{
    QHostAddress hostAddress;

    //Determine IP address.
    QHostInfo hostInfo = QHostInfo::fromName(host);
    if (!hostInfo.addresses().isEmpty())
    {
        QList<QHostAddress> hostAddresses = hostInfo.addresses();
        int hostInx;
        for (hostInx = 0; hostInx < hostAddresses.size(); hostInx++)
        {
            if (hostAddresses.at(hostInx).protocol() == QAbstractSocket::IPv4Protocol)
                break;
        }
        if (hostInx < hostAddresses.size())
            hostAddress = hostAddresses.at(hostInx);
    }
    return hostAddress;
}

/**
 * @brief Custom event handling.
 *
 * Handles events for disabling/enabling of main menu entries.
 *
 * @param event The event type. Only update ui events are handled.
 */
void CMainFrame::customEvent(QEvent *event)
{
    if (event->type() == WMS_UPDATE_UI_ACTION)
    {
        UPDATE_UI_ACTION_Event * ev = static_cast<UPDATE_UI_ACTION_Event *>(event);

        QObject *pToolBarObject = pToolBarWidget->rootObject();
        QVariant returnedValue;

        UpdateUIAction uiAction = ev->getUIAction();
        bool param = ev->getEnable();

        switch (uiAction)
        {
            //Enable/Disable for initial main menu entries.
        case UPDATE_UI_INITIAL:
            enableUIActionsInitial();
            break;

            //Enable/Disable for initial main menu entries for table manager server.
        case UPDATE_UI_SERVER:
            enableUIActionsServer();
            break;

            //Enable/Disable for initial main menu entries for table manager client.
        case UPDATE_UI_CLIENT:
            enableUIActionsClient();
            break;

            //Enable/Disable save menu entry.
        case UPDATE_UI_SAVE:
            mainFrameMenuEnables.actionSaveSetEnabled(param);
            break;

            //Enable/Disable save as menu entry.
        case UPDATE_UI_SAVEAS:
            mainFrameMenuEnables.actionSave_AsSetEnabled(param);
            break;

            //Enable/Disable delete menu entry.
        case UPDATE_UI_DELETE:
            mainFrameMenuEnables.actionDeleteSetEnabled(param);
            break;

            //Enable/Disable new session menu entry.
        case UPDATE_UI_NEW_SESSION:       
            QMetaObject::invokeMethod(pToolBarObject, "actionNew_SessionSetEnabled",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, param));
            break;

            //Enable/Disable new deal menu entry.
        case UPDATE_UI_NEW_DEAL:
            mainFrameMenuEnables.action_Deal_New_HandSetEnabled(param);
            break;

            //Enable/Disable undo bid or trick menu entry.
        case UPDATE_UI_UNDO:
            QMetaObject::invokeMethod(pToolBarObject, "actionUndoSetEnabled",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, param));
            break;

            //Enable/Disable rebid menu entry.
        case UPDATE_UI_REBID:
            mainFrameMenuEnables.action_Bid_RebidSetEnabled(param);
            break;

            //Enable/Disable replay menu entry.
        case UPDATE_UI_REPLAY:
            mainFrameMenuEnables.action_Restart_HandSetEnabled(param);
            break;

            //Enable/Disable show all menu entry.
        case UPDATE_UI_SHOW_ALL:
            mainFrameMenuEnables.action_Expose_All_CardsSetEnabled(param);
            break;

            //Enable/Disable Double Dummy Results.
        case UPDATE_UI_PAR:
            mainFrameMenuEnables.actionDouble_Dummy_ResultsSetEnabled(param);
            break;

            //Enable/Disable score dialogs.
        case UPDATE_UI_SCORE:
            mainFrameMenuEnables.action_ScoreSetEnabled(param);
            break;

            //Enable/Disable hint.
        case UPDATE_UI_HINT:
            QMetaObject::invokeMethod(pToolBarObject, "actionHintSetEnabled",
                    Q_RETURN_ARG(QVariant, returnedValue),
                    Q_ARG(QVariant, param));
            break;
        }
    }
}

/**
 * @brief Enable main menu entries initially (before server or client mode is determined).
 */
void CMainFrame::enableUIActionsInitial()
{
    enableUIActions(INITIAL_ACTIONS);
}

/**
 * @brief Enable main menu entries initially for server mode.
 */
void CMainFrame::enableUIActionsServer()
{
    enableUIActions(SERVER_ACTIONS);
}

/**
 * @brief Enable main menu entries initially for client mode.
 */
void CMainFrame::enableUIActionsClient()
{
    enableUIActions(CLIENT_ACTIONS);
}

void CMainFrame::closeEvent(QCloseEvent *event)
{
    exit(0);

    QMainWindow::closeEvent(event);
}

/**
 * @brief Enable/disable main menu entries.
 *
 * @param actions identifies which actions to intially enable/disable for.
 *        - INITIAL_ACTIONS before server/client mode is determined.
 *        - SERVER_ACTIONS for server mode.
 *        - CLIENT_ACTIONS for client mode.
 */
void CMainFrame::enableUIActions(actionIndicator actions)
{
    QObject *pToolBarObject = pToolBarWidget->rootObject();
    QVariant returnedValue;

    bool param = (actions == INITIAL_ACTIONS) || (actions == SERVER_ACTIONS);
    mainFrameMenuEnables.actionOpenSetEnabled(param);

    QMetaObject::invokeMethod(pToolBarObject, "actionHintSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, false));

    mainFrameMenuEnables.actionSaveSetEnabled(false);

    mainFrameMenuEnables.actionSave_AsSetEnabled(false);

    mainFrameMenuEnables.actionDeleteSetEnabled(false);

    QMetaObject::invokeMethod(pToolBarObject, "actionNew_SessionSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, true));

    mainFrameMenuEnables.action_Deal_New_HandSetEnabled(false);

    mainFrameMenuEnables.action_Bid_RebidSetEnabled(false);

    mainFrameMenuEnables.action_Restart_HandSetEnabled(false);

    QMetaObject::invokeMethod(pToolBarObject, "actionUndoSetEnabled",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, false));

    mainFrameMenuEnables.action_Expose_All_CardsSetEnabled(false);

    mainFrameMenuEnables.actionDouble_Dummy_ResultsSetEnabled(false);

    param = (actions == SERVER_ACTIONS) || (actions == CLIENT_ACTIONS);
    mainFrameMenuEnables.action_ScoreSetEnabled(param);
}

/**
 * @brief Reset play configuration (manual play, auto play etc.)
 */
void CMainFrame::resetPlay()
{
    if (tableManager != 0)
        delete tableManager;
    tableManager = 0;
    if (tableManagerAuto != 0)
        emit sAutoQuit();
    tableManagerAuto = 0;

    hostAddress.clear();
    if ((doc->getSeatOptions().role == SERVER_ROLE) || (doc->getSeatOptions().role == CLIENT_ROLE))
    {
        QString host = (doc->getSeatOptions().role == SERVER_ROLE) ? (doc->getSeatOptions().hostServer) :
                                                                     (doc->getSeatOptions().hostClient);
        hostAddress = getHostAddress(host);
        if (hostAddress.isNull())
            CMessageBox::warning(this->centralWidget(), tr("ZBridge"), tr("Could not determine IP address."));
    }

    //Table manager server?
    if((doc->getSeatOptions().role == SERVER_ROLE) && !hostAddress.isNull())
    {
        try
        {
            tableManager = new CTblMngrServer(doc, games, bidAndPlayEngines, hostAddress, playView, this);
            tableManagerAuto = new CTblMngrServerAuto(doc, games, bidAndPlayEngines, hostAddress, 0);
        }
        catch (NetProtocolException &e)
        {
            CMessageBox::warning(this->centralWidget(), tr("ZBridge"), e.what());

            if (tableManager != 0)
                delete tableManager;
            hostAddress.clear();
        }
    }

    //Table manager client?
    else if((doc->getSeatOptions().role == CLIENT_ROLE) && !hostAddress.isNull())
    {
        tableManager = new CTblMngrClient(doc, games, bidAndPlayEngines, hostAddress, playView, this);
        tableManagerAuto = new CTblMngrClientAuto(doc, games, bidAndPlayEngines, hostAddress, 0);
        connect(tableManager, &CTblMngrBase::sigDisconnect, tableManagerAuto, &CTblMngrBase::sltDisconnect);
        connect(tableManagerAuto, &CTblMngrBase::sigDisconnect, tableManager, &CTblMngrBase::sltDisconnect);
    }

    //Table manager standalone?
    if (hostAddress.isNull())
    {
        tableManager = new CTblMngrServer(doc, games, bidAndPlayEngines, hostAddress, playView, this);
        tableManagerAuto = new CTblMngrServerAuto(doc, games, bidAndPlayEngines, hostAddress, 0);
    }

    QThread *thread = new QThread();
    tableManagerAuto->moveToThread(thread);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    connect(this, &CMainFrame::sAutoQuit, tableManagerAuto, &CTblMngrBase::sAutoQuit);
    connect(this, &CMainFrame::sNewSession, tableManagerAuto, &CTblMngrBase::sNewSession);
    thread->start();

    connect(tableManager, &CTblMngr::sShowScore, this, &CMainFrame::on_action_Score_triggered,
            Qt::QueuedConnection);

    //If non saved game then ask if it should be saved (save can only be enabled on server).
    if (mainFrameMenuEnables.actionSaveGetEnabled() &&
            (CMessageBox::question(this->centralWidget(), tr("ZBridge"),
                                   tr("Do you want to save played games?")) == QDialog::Accepted))
        on_actionSave_triggered();

    //Clear expose all cards.
    mainFrameMenuEnables.action_Expose_All_CardsSetEnabled(false);

    //No current file.
    fileName = "";
    eventIndex = 0;

    setWindowTitle("");
}

/**
 * @brief Open Portable Bridge Notation (pbn) file for play etc.
 * @param originalFileName Name of the pbn file to open.
 */
void CMainFrame::open(QString &originalFileName)
{
    try
    {
    QFile originalFile(originalFileName);
    if (!originalFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        CMessageBox::critical(this->centralWidget(), tr("ZBridge"),
                               tr("Could not open file:\n") + originalFileName);
        return;
    }
    QTextStream original(&originalFile);

    QTextStream played;
    QString event;

    //Determine events.
    QStringList strLines;
    games->determineEvents(original, strLines);

    if (strLines.size() > 1)
    {
        CMessageBox::information(this->centralWidget(), tr("ZBridge"),
                               tr("Accepts only one event in a pbn file."));
            return;
    }
    else if (strLines.size() == 1)
        event = strLines.at(0);

    //Determine event index.
    int inx;
    for (inx = 0; inx < strLines.size(); inx++)
        if (strLines.at(inx) == event)
            break;

    //Open file with already (in this program) played games.
    QString playedFilename = originalFileName.left(originalFileName.indexOf(".pbn", 0, Qt::CaseInsensitive)) +
            "_" + QString::number(inx) + ".zbr";
    QFile playedFile(playedFilename);

    //None might be played.
    if (playedFile.open(QIODevice::ReadOnly | QIODevice::Text))
        played.setDevice(&playedFile);

    emit sNewSession();     //Start new session for table manager auto.

    //Read games.
    original.seek(0);
    games->readGames(original, played, event, doc->getGameOptions().scoringMethod);

    originalFile.close();

    //Save info about pbn file.
    eventIndex = inx;
    fileName = originalFileName;

    //Initialize bid and play engines.
    bidAndPlayEngines->initialize(doc->getGameOptions().computerLevel, doc->getBidDB(), doc->getBidDesc(),
                                  doc->getNSBidOptions(), doc->getEWBidOptions(),
                                  games->getScoringMethod());

    //Set up synchronization (auto play or not).
    //Open is not available on client, i.e table manager is either server or standalone.
    disconnect(tableManager, &CTblMngrBase::sigPlayStart, 0, 0);
    disconnect(tableManagerAuto, &CTblMngrBase::sigPlayStart, 0, 0);
    if (!games->getComputerPlays())
        connect(tableManager, &CTblMngrBase::sigPlayStart, tableManager, &CTblMngrBase::sltPlayStart);
    else
    {
        connect(tableManager, &CTblMngrBase::sigPlayStart, tableManagerAuto, &CTblMngrBase::sltPlayStart);
        connect(tableManagerAuto, &CTblMngrBase::sigPlayStart, tableManager, &CTblMngrBase::sltPlayStart);
    }

    //Start new session for table manager.
    tableManager->newSession();

    if (played.device() != 0)
    {
        playedFile.close();
        QApplication::postEvent(this, new UPDATE_UI_ACTION_Event(UPDATE_UI_DELETE , true));
    }

    setWindowTitle(originalFileName);

    //Can now be saved with another name.
    QApplication::postEvent(this, new UPDATE_UI_ACTION_Event(UPDATE_UI_SAVEAS , true));
    }
    catch (PlayException &e)
    {
        //There was an error in processing of pbn file.
        CMessageBox::critical(this->centralWidget(), tr("ZBridge"), e.what());
    }
}

//Following methods are automatically generated main menu actions.
//----------------------------------------------------------------
/**
 * @brief Open pbn file. Use the games in the file(s) for playing.
 *
 * The original games are read from the pbn file. Played games are read from a companion to the original
 * pbn file with a filename derived from the original pbn filename and the event index. With the extension zbr.
 */
void CMainFrame::on_actionOpen_triggered()
{
    //If non saved game then ask if it should be saved (save can only be enabled on server).
    if (mainFrameMenuEnables.actionSaveGetEnabled() &&
       (CMessageBox::question(this->centralWidget(), tr("ZBridge Question"), tr("Do you want to save played games?")) == QDialog::Accepted))
        on_actionSave_triggered();

    //Determine pbn file to read games from.
    QString headLine = tr("Open Portable Bridge Notation file");
    QStringList nameFilters;
    nameFilters << "*.pbn";
    CFileDialog fileDialog(headLine, nameFilters, this->centralWidget());
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    QString originalFileName = fileDialog.getFileName();
    if (originalFileName.size() == 0)
        return;

    //Open file and prepare for play.
    open(originalFileName);
}

/**
 * @brief Save the current games in pbn file format.
 *
 * Played games are saved as companion to the original pbn file with a filename derived from the original
 * pbn filename and the event index. With the extension zbr.
 */
void CMainFrame::on_actionSave_triggered()
{
    //Save (in this program) played games.
    //Might be (by this program) random generated games.
    if (fileName.size() == 0)
        on_actionSave_As_triggered();
    else
    {
        //Save (by this program) played games.
        QString playedFilename = fileName.left(fileName.indexOf(".pbn", 0, Qt::CaseInsensitive)) +
                "_" + QString::number(eventIndex) + ".zbr";
        QFile playedFile(playedFilename);
        playedFile.open(QIODevice::ReadWrite | QIODevice::Text);
        playedFile.resize(0);
        QTextStream played(&playedFile);

        games->writePlayedGames(played);

        playedFile.close();

        QApplication::postEvent(this, new UPDATE_UI_ACTION_Event(UPDATE_UI_SAVE , false));
        QApplication::postEvent(this, new UPDATE_UI_ACTION_Event(UPDATE_UI_DELETE , true));
    }
}

/**
 * @brief Save the current games in pbn file format, but with a new name.
 *
 * The games from the original pbn file with the chosen event are saved in a new pbn file. In case of
 * random generated games (no original pbn file) then the file will be empty. But it will still be existing.
 * This to allow it to be chosen in the open action. Played games are saved as companion to the new pbn file
 * with a filename derived from the new pbn filename and the event index zero (0). With the extension zbr.
 */
void CMainFrame::on_actionSave_As_triggered()
{
    //Determine pbn file to write to.
    QString headLine = tr("Save Portable Bridge Notation file");
    QStringList nameFilters;
    nameFilters << "*.pbn";
    CFileDialog fileDialog(headLine, nameFilters, this->centralWidget());
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    QString originalFileName = fileDialog.getFileName();
    if (originalFileName.size() == 0)
        return;

    if (originalFileName.indexOf(".pbn", Qt::CaseInsensitive) == -1)
        originalFileName += ".pbn";

    QFile originalFile(originalFileName);
    originalFile.open(QIODevice::ReadWrite | QIODevice::Text);
    originalFile.resize(0);
    QTextStream original(&originalFile);

    //Save current file name and event index.
    fileName = originalFileName;
    eventIndex = 0;

    //Determine file with (by this program) played games.
    QString playedFilename = fileName.left(fileName.indexOf(".pbn", 0, Qt::CaseInsensitive)) +
            "_" + QString::number(eventIndex) + ".zbr";
    QFile playedFile(playedFilename);
    playedFile.open(QIODevice::ReadWrite | QIODevice::Text);
    playedFile.resize(0);
    QTextStream played(&playedFile);

    //Save original games (in case of random generated games there are no original games).
    games->writeOriginalGames(original);

    //Save (by this program) played games.
    games->writePlayedGames((played));

    originalFile.close();
    playedFile.close();

    //Update recent open files list.
    setWindowTitle(originalFileName);

    QApplication::postEvent(this, new UPDATE_UI_ACTION_Event(UPDATE_UI_SAVE , false));
    QApplication::postEvent(this, new UPDATE_UI_ACTION_Event(UPDATE_UI_DELETE , true));
}

/**
 * @brief Delete the current games (only played part - not original).
 */
void CMainFrame::on_actionDelete_triggered()
{
    if (CMessageBox::question(this->centralWidget(), tr("ZBridge"),
           tr("Do you want to delete played games?")) == QDialog::Accepted)
    {
        //Delete (by this program) played games.
        QString playedFilename = fileName.left(fileName.indexOf(".pbn", 0, Qt::CaseInsensitive)) +
                "_" + QString::number(eventIndex) + ".zbr";
        QFile playedFile(playedFilename);
        playedFile.remove();

        QApplication::postEvent(this, new UPDATE_UI_ACTION_Event(UPDATE_UI_DELETE , false));
    }
}

/**
 * @brief Show all four hands.
 */
void CMainFrame::on_action_Expose_All_Cards_triggered()
{
    mainFrameMenuEnables.action_Expose_All_CardsSetChecked(!mainFrameMenuEnables.action_Expose_All_CardsGetChecked());
    tableManager->showAllCards();
}

/**
* @brief Show score dialog.
*/
void CMainFrame::on_action_Score_triggered()
{
    bool enabled = menuWidget()->isEnabled();

    if (!scoreSelect && !enabled)
        return;

    if (enabled)
        menuWidget()->setEnabled(false);

    CMainScoreDialog mainScoreDialog(games, this->centralWidget());
    scoreSelect = false;
    mainScoreDialog.exec();

    if (enabled)
        menuWidget()->setEnabled(true);
}

/**
 * @brief Show double dummy results.
 */
void CMainFrame::on_actionDouble_Dummy_Results_triggered()
{
    tableManager->showDoubleDummyResults();
}

/**
 * @brief Main menu new (random) session triggered.
 */
void CMainFrame::on_actionNew_Session_triggered()
{
    emit sNewSession();     //Start new session for table manager auto.

    //If non saved game then ask if it should be saved (save can only be enabled on server).
    if (mainFrameMenuEnables.actionSaveGetEnabled() &&
        (CMessageBox::question(this->centralWidget(), tr("ZBridge"),
               tr("Do you want to save played games?")) == QDialog::Accepted))
        on_actionSave_triggered();

    games->clearGames(doc->getGameOptions().scoringMethod);

    if (mainFrameMenuEnables.actionActivate_Deal_ProfileGetChecked())
        games->setDealOptions(doc->getDealOptions());
    else
        games->clearDealOptions();

    fileName.clear();
    eventIndex = 0;

    setWindowTitle("");

    //Initialize bid and play engines.
    bidAndPlayEngines->initialize(doc->getGameOptions().computerLevel, doc->getBidDB(), doc->getBidDesc(),
                                  doc->getNSBidOptions(), doc->getEWBidOptions(),
                                  doc->getGameOptions().scoringMethod);

    //Set up synchronization (auto play or not).
    //Implicit standalone or server session.
    disconnect(tableManager, &CTblMngrBase::sigPlayStart, 0, 0);
    disconnect(tableManagerAuto, &CTblMngrBase::sigPlayStart, 0, 0);
    if (!games->getComputerPlays())
        connect(tableManager, &CTblMngrBase::sigPlayStart, tableManager, &CTblMngrBase::sltPlayStart);
    else
    {
        connect(tableManager, &CTblMngrBase::sigPlayStart, tableManagerAuto, &CTblMngrBase::sltPlayStart);
        connect(tableManagerAuto, &CTblMngrBase::sigPlayStart, tableManager, &CTblMngrBase::sltPlayStart);
    }

    //Start new session (client or server).
    tableManager->newSession();
}

/**
 * @brief Main menu new deal triggered.
 */
void CMainFrame::on_action_Deal_New_Hand_triggered()
{
    tableManager->newDeal();
}

/**
 * @brief Activate/deactivate deal profile.
 */
void CMainFrame::on_actionActivate_Deal_Profile_triggered()
{
    mainFrameMenuEnables.actionActivate_Deal_ProfileSetChecked(!mainFrameMenuEnables.actionActivate_Deal_ProfileGetChecked());

    if (mainFrameMenuEnables.actionActivate_Deal_ProfileGetChecked())
        games->setDealOptions(doc->getDealOptions());
    else
        games->clearDealOptions();
}

/**
 * @brief Undo bid or play.
 */
void CMainFrame::on_actionUndo_triggered()
{
    tableManager->undo();
}

/**
 * @brief Start bidding from beginning.
 */
void CMainFrame::on_action_Bid_Rebid_triggered()
{
    tableManager->reBid();
}

/**
 * @brief Start playing from beginning.
 */
void CMainFrame::on_action_Restart_Hand_triggered()
{
    tableManager->rePlay();
}

void CMainFrame::on_actionHint_triggered()
{
    tableManager->hint();
}

/**
 * @brief Main menu seat configuration triggered.
 *
 * Activate seat configuration dialog
 */
void CMainFrame::on_actionSeat_Configuration_triggered()
{
    CSeatConfiguration seatConfiguration(app, doc, this->centralWidget());
    if (seatConfiguration.exec() == QDialog::Accepted)
    {
        //Seat configuration has changed. The table manager is deleted
        //and a new table manager (server or client) is allocated and initialized.
        doc->WriteSeatOptions();

        //Reset play.
        resetPlay();
        games->clearGames(doc->getGameOptions().scoringMethod);
    }
}

/**
 * @brief main menu bidding options triggered.
 *
 * Activate bid options dialog.
 */
void CMainFrame::on_action_Bidding_Options_triggered()
{
    CBidOptions bidOptsDialog(app, doc, this->centralWidget());
    if (bidOptsDialog.exec() == QDialog::Accepted)
        doc->WriteSettings();
}

/**
 * @brief main menu deal options triggered.
 *
 * Activate deal options dialog.
 */
void CMainFrame::on_action_Deal_Options_triggered()
{
    CDealOptionsPropSheet dealOptsDialog(app, doc, this->centralWidget());
    if (dealOptsDialog.exec() == QDialog::Accepted)
        doc->WriteDealOptions();
}

/**
 * @brief main menu display options triggered.
 *
 * Activate display options dialog.
 */
void CMainFrame::on_action_Di_splay_Options_triggered()
{
    CDispOptionsPropSheet dispOptsDialog(app, doc, this->centralWidget());
    if (dispOptsDialog.exec() == QDialog::Accepted)
        doc->WriteDisplayOptions();
}

/**
 * @brief main menu game options triggered.
 *
 * Activate game options dialog.
 */
void CMainFrame::on_action_Game_Options_triggered()
{
    CGameOptionsPropSheet gameOptsDialog(app, doc, this->centralWidget());
    if (gameOptsDialog.exec() == QDialog::Accepted)
        doc->WriteGameOptions();
}

/**
 * @brief Select bidding system database.
 */
/*
void CMainFrame::on_actionSelect_Bid_Database_triggered()
{
    //Determine Bidding System file to read.
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Read Bidding System"), doc->getBidDBFileName(), tr("Bidding System Files (*.bsf)"));
    if (fileName.size() != 0)
    {
        doc->setBidDBFileName(fileName);
        doc->WriteBidDBFileName();
        doc->LoadBidDB();
    }
}
*/

void CMainFrame::on_action_Contents_triggered()
{
    CContent content(this->centralWidget());
    content.exec();
}

/**
 * @brief Show About dialog.
 */
void CMainFrame::on_action_About_ZBridge_triggered()
{
    CAboutDlg about(app, doc, this->centralWidget());
    about.exec();
}

void CMainFrame::on_showMenu_triggered()
{
    menuWidget()->setEnabled(false);

    CMainFrameMenu mainFrameMenu(mainFrameMenuEnables, this->centralWidget());
    if (mainFrameMenu.exec() == QDialog::Accepted)
    {
        switch (mainFrameMenu.getMenuChoice())
        {
        case ACTION_OPEN:
            on_actionOpen_triggered();
            break;
        case ACTION_SAVE:
            on_actionSave_triggered();
            break;
        case ACTION_SAVE_AS:
            on_actionSave_As_triggered();
            break;
        case ACTION_DELETE:
            on_actionDelete_triggered();
            break;
        case ACTION_EXPOSE_ALL_CARDS:
            on_action_Expose_All_Cards_triggered();
            break;
        case ACTION_SCORE:
            scoreSelect = true;
            on_action_Score_triggered();
            break;
        case ACTION_DOUBLE_DUMMY_RESULTS:
            on_actionDouble_Dummy_Results_triggered();
            break;
        case ACTION_NEW_SESSION:
            on_actionNew_Session_triggered();
            break;
        case ACTION_DEAL_NEW_HAND:
            on_action_Deal_New_Hand_triggered();
            break;
        case ACTION_ACTIVATE_DEAL_PROFILE:
            on_actionActivate_Deal_Profile_triggered();
            break;
        case ACTION_UNDO:
            on_actionUndo_triggered();
            break;
        case ACTION_BID_REBID:
            on_action_Bid_Rebid_triggered();
            break;
        case ACTION_RESTART_HAND:
            on_action_Restart_Hand_triggered();
            break;
        case ACTION_HINT:
            on_actionHint_triggered();
            break;
        case ACTION_SEAT_CONFIGURATION:
            on_actionSeat_Configuration_triggered();
            break;
        case ACTION_BIDDING_OPTIONS:
            on_action_Bidding_Options_triggered();
            break;
        case ACTION_DEAL_OPTIONS:
            on_action_Deal_Options_triggered();
            break;
        case ACTION_DISPLAY_OPTIONS:
            on_action_Di_splay_Options_triggered();
            break;
        case ACTION_GAME_OPTIONS:
            on_action_Game_Options_triggered();
            break;
        case ACTION_CONTENTS:
            on_action_Contents_triggered();
            break;
        case ACTION_ABOUT_ZBRIDGE:
            on_action_About_ZBridge_triggered();
            break;
        default:
            break;
        }
    }
    menuWidget()->setEnabled(true);
}
