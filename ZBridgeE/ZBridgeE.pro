#-------------------------------------------------
#
# Project created by QtCreator 2012-12-18T10:40:03
#
#-------------------------------------------------

QT       += core gui network webview
QT       += help

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets qml quick quickwidgets

TARGET = ZBridgeE
TEMPLATE = app
android: {
#   Bo Haglunds Double Dummy Solver (included in app).
    LIBS += c:\Projects\qt\ZbridgeE\ZBridgeE\libdds_arm64-v8a.a
#   Help files.
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
}
win32: {
#   Bo Haglunds Double Dummy Solver (as a DLL).
#   MinGW 32 bit(does not work, there is no webview).
#    LIBS += c:\Projects\qt\ZbridgeE\ZBridgeE\dds.dll
#   MSVC 2015 32 bit
    LIBS += c:\Projects\qt\ZbridgeE\ZBridgeE\dds.lib
}

SOURCES +=\
        cmainframe.cpp \
    czbridgedoc.cpp \
    czbridgeapp.cpp \
    caboutdlg.cpp \
    cbidoptionspropsheet.cpp \
    cdealoptionspropsheet.cpp \
    cdispoptionspropsheet.cpp \
    cgameoptionspropsheet.cpp \
    cstatusbar.cpp \
    cseatconfiguration.cpp \
    cbidoptions.cpp \
    cnewconvention.cpp \
    cbidoptiondoc.cpp \
    cseatoptiondoc.cpp \
    cdealoptiondoc.cpp \
    cdisplayoptiondoc.cpp \
    cgameoptiondoc.cpp \
    cplayview.cpp \
    ctopinfoplay.cpp \
    ctopinfoauction.cpp \
    ctopinfo.cpp \
    cmidinfoplay.cpp \
    cmidinfoauction.cpp \
    cmidinfo.cpp \
    ccentercards.cpp \
    ccard.cpp \
    cbottominfoplay.cpp \
    cbottominfoauction.cpp \
    cbottominfo.cpp \
    cbidengine.cpp \
    cactor.cpp \
    cactorremote.cpp \
    cplayengine.cpp \
    cbidhistory.cpp \
    cbid.cpp \
    ctblmngrserver.cpp \
    ctblmngrclient.cpp \
    ../src-gen/ZBridgeServer.c \
    ../src-gen/ZBridgeClient.c \
    CTblMngr.cpp \
    cremoteactorserver.cpp \
    cremoteactorclient.cpp \
    cremoteprotocol.cpp \
    cplayhistory.cpp \
    cactorlocal.cpp \
    cbiditem.cpp \
    cBottominfoButton.cpp \
    csquare.cpp \
    cbidandplay.cpp \
    ccards.cpp \
    clrcards.cpp \
    ctbcards.cpp \
    ../src-gen/ZBridgeClientSync.c \
    ../src-gen/ZBridgeServerSync.c \
    cmainscoredialog.cpp \
    crubberscoredialog.cpp \
    cgamesdoc.cpp \
    cpointscoredialog.cpp \
    crankscoredialog.cpp \
    cplaydialog.cpp \
    ctblmngrbase.cpp \
    cactorbase.cpp \
    cactorlocalauto.cpp \
    cactorremoteauto.cpp \
    ctblmngrserverauto.cpp \
    ctblmngrclientauto.cpp \
    mt19937ar.cpp \
    cddtable.cpp \
    cauction.cpp \
    cauctions.cpp \
    cbiddb.cpp \
    cbiddesc.cpp \
    cbids.cpp \
    cfeatures.cpp \
    crule.cpp \
    cbiddbdefine.cpp \
    cbidandplayengines.cpp \
    cpopup.cpp \
    cmessage.cpp \
    cfiledialog.cpp \
    cmessagebox.cpp \
    cmainframemenu.cpp \
    ccenter.cpp \
    ccenterbid.cpp \
    cbidbutton.cpp \
    cmainframemenuenables.cpp \
    cbottominfoplayshow.cpp \
    cddslock.cpp \
    ccontent.cpp

HEADERS  += cmainframe.h \
    czbridgedoc.h \
    czbridgeapp.h \
    caboutdlg.h \
    Defines.h \
    cbidoptionspropsheet.h \
    cdealoptionspropsheet.h \
    cdispoptionspropsheet.h \
    cgameoptionspropsheet.h \
    cstatusbar.h \
    cseatconfiguration.h \
    cbidoptions.h \
    cnewconvention.h \
    cbidoptiondoc.h \
    cseatoptiondoc.h \
    cdealoptiondoc.h \
    cdisplayoptiondoc.h \
    cgameoptiondoc.h \
    cplayview.h \
    ctopinfoplay.h \
    ctopinfoauction.h \
    ctopinfo.h \
    cmidinfoplay.h \
    cmidinfoauction.h \
    cmidinfo.h \
    ccentercards.h \
    ccard.h \
    cbottominfoplay.h \
    cbottominfoauction.h \
    cbottominfo.h \
    cbidengine.h \
    cactor.h \
    cactorremote.h \
    cplayengine.h \
    cbidhistory.h \
    cbid.h \
    ctblmngrserver.h \
    ctblmngrclient.h \
    ../src-gen/ZBridgeServer.h \
    ../src-gen/ZBridgeClient.h \
    ../src-gen/sc_types.h \
    CTblMngr.h \
    cremoteactorserver.h \
    cremoteactorclient.h \
    cremoteprotocol.h \
    ZBridgeException.h \
    cplayhistory.h \
    cactorlocal.h \
    cbiditem.h \
    cBottominfoButton.h \
    csquare.h \
    cbidandplay.h \
    ccards.h \
    clrcards.h \
    ctbcards.h \
    ZBridge_documentation.h \
    ../src-gen/ZBridgeClientSync.h \
    ../src-gen/ZBridgeServerSync.h \
    cmainscoredialog.h \
    crubberscoredialog.h \
    cgamesdoc.h \
    cpointscoredialog.h \
    crankscoredialog.h \
    cplaydialog.h \
    ctblmngrbase.h \
    cactorbase.h \
    cactorlocalauto.h \
    cactorremoteauto.h \
    ctblmngrserverauto.h \
    ctblmngrclientauto.h \
    mt19937ar.h \
    cddtable.h \
    cauction.h \
    cauctions.h \
    cbiddb.h \
    cbiddesc.h \
    cbids.h \
    cfeatures.h \
    crule.h \
    cbiddbdefine.h \
    cbidandplayengines.h \
    cpopup.h \
    cmessage.h \
    cfiledialog.h \
    cmessagebox.h \
    cmainframemenu.h \
    ccenter.h \
    ccenterbid.h \
    cbidbutton.h \
    cmainframemenuenables.h \
    sleepsimulator.h \
    cbottominfoplayshow.h \
    cddslock.h \
    ccontent.h

FORMS    +=

RESOURCES = \
    resources.qrc

win32: {
RC_ICONS = resources/IDR_MAIN.ICO
}

