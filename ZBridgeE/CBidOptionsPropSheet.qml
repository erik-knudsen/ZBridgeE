/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CBidOptionsPropSheet.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Bid options property sheet.

  Platforms: Qt/QML.
*/

import QtQuick

CBidOptionsPropSheetForm {
    signal on_americanStyle_clicked()
    signal on_europeanStyle_clicked()
    signal on_majorFour_clicked()
    signal on_majorFive_clicked()
    signal on_stayman_clicked(bool checked)
    signal on_jacobyTransfers_clicked(bool checked)
    signal on_limitRaises_clicked(bool checked)
    signal on_weakTwo_clicked(bool checked)
    signal on_oneNTRange12_14_clicked()
    signal on_oneNTRange15_17_clicked()
    signal on_open1NTWeakMajor_clicked(bool checked)
    signal on_structuredReverses_clicked(bool checked)
    signal on_takeoutDoubles_clicked(bool checked)
    signal on_negativeDoubles_clicked(bool checked)
    signal on_michaelsCueBid_clicked(bool checked)
    signal on_unusualNT_clicked(bool checked)
    signal on_jumpOvercallWeak_clicked(bool checked)
    signal on_ok_clicked()
    signal on_cancel_clicked()

    americanStyle.onClicked:
    {
        on_americanStyle_clicked()
    }
    europeanStyle.onClicked:
    {
        on_europeanStyle_clicked()
    }
    majorFour.onClicked:
    {
        on_majorFour_clicked()
    }
    majorFive.onClicked:
    {
        on_majorFive_clicked()
    }
    stayman.onClicked:
    {
        on_stayman_clicked(stayman.checked)
    }
    jacobyTransfers.onClicked:
    {
        on_jacobyTransfers_clicked(jacobyTransfers.checked)
    }
    limitRaises.onClicked:
    {
        on_limitRaises_clicked(limitRaises.checked)
    }
    weakTwo.onClicked:
    {
        on_weakTwo_clicked(weakTwo.checked)
    }
    oneNTRange12_14.onClicked:
    {
        on_oneNTRange12_14_clicked()
    }
    oneNTRange15_17.onClicked:
    {
        on_oneNTRange15_17_clicked()
    }
    open1NTWeakMajor.onClicked:
    {
        on_open1NTWeakMajor_clicked(open1NTWeakMajor.checked)
    }
    structuredReverses.onClicked:
    {
        on_structuredReverses_clicked(structuredReverses.checked)
    }
    takeoutDoubles.onClicked:
    {
        on_takeoutDoubles_clicked(takeoutDoubles.checked)
    }
    negativeDoubles.onClicked:
    {
        on_negativeDoubles_clicked(negativeDoubles.checked)
    }
    michaelsCueBid.onClicked:
    {
        on_michaelsCueBid_clicked(michaelsCueBid.checked)
    }
    unusualNT.onClicked:
    {
        on_unusualNT_clicked(unusualNT.checked)
    }
    jumpOvercallWeak.onClicked:
    {
        on_jumpOvercallWeak_clicked(jumpOvercallWeak.checked)
    }
    ok.onClicked:
    {
        on_ok_clicked()
    }
    cancel.onClicked:
    {
        on_cancel_clicked()
    }

    function americanStyleSetChecked(checked)
    {
        americanStyle.checked = checked
    }
    function europeanStyleSetChecked(checked)
    {
        europeanStyle.checked = checked
    }
    function majorFourSetChecked(checked)
    {
        majorFour.checked = checked
    }
    function majorFiveSetChecked(checked)
    {
        majorFive.checked = checked
    }
    function staymanSetChecked(checked)
    {
        stayman.checked = checked
    }
    function jacobyTransfersSetChecked(checked)
    {
        jacobyTransfers.checked = checked
    }
    function limitRaisesSetChecked(checked)
    {
        limitRaises.checked = checked
    }
    function weakTwoSetChecked(checked)
    {
        weakTwo.checked = checked
    }
    function oneNTRange12_14SetChecked(checked)
    {
        oneNTRange12_14.checked = checked
    }
    function oneNTRange15_17SetChecked(checked)
    {
        oneNTRange15_17.checked = checked
    }
    function open1NTWeakMajorSetChecked(checked)
    {
        open1NTWeakMajor.checked = checked
    }
    function structuredReversesSetChecked(checked)
    {
        structuredReverses.checked = checked
    }
    function takeoutDoublesSetChecked(checked)
    {
        takeoutDoubles.checked = checked
    }
    function negativeDoublesSetChecked(checked)
    {
        negativeDoubles.checked = checked
    }
    function michaelsCueBidSetChecked(checked)
    {
        michaelsCueBid.checked = checked
    }
    function unusualNTSetChecked(checked)
    {
        unusualNT.checked = checked
    }
    function jumpOvercallWeakSetChecked(checked)
    {
        jumpOvercallWeak.checked = checked
    }
    function setZoom(zoom)
    {
        zf = zoom
    }
}
