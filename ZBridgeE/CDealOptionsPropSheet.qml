/*Erik Aagaard Knudsen.
  Copyright © 2018 - All Rights Reserved

  Project: ZBridge
  File: CADealOptionsPropSheet.qml
  Developers: eak

  Revision History:
  12-jun-2018 eak: Original

  Abstract: Deal options properety sheet.

  Platforms: Qt/QML.
*/

import QtQuick 2.4

CDealOptionsPropSheetForm {
    signal on_ok_clicked()
    signal on_cancel_clicked()
    signal on_hcp_editingFinished(int suit, int seat)
    signal on_suitSize_editingFinished(int suit, int seat)
    signal on_dp_editingFinished(int seat)

    property int cLUBS: 0
    property int dIAMONDS: 1
    property int hEARTS: 2
    property int sPADES: 3
    property int nOTRUMP: 4

    property int wEST_SEAT: 0
    property int nORTH_SEAT: 1
    property int eAST_SEAT: 2
    property int sOUTH_SEAT: 3

    cancel.onClicked:
    {
        on_cancel_clicked()
    }
    ok.onClicked:
    {
        on_ok_clicked()
    }
    hcpTotalWest.onEditingFinished:
    {
        on_hcp_editingFinished(nOTRUMP, wEST_SEAT)
    }
    hcpTotalNorth.onEditingFinished:
    {
        on_hcp_editingFinished(nOTRUMP, nORTH_SEAT)
    }
    hcpTotalEast.onEditingFinished:
    {
        on_hcp_editingFinished(nOTRUMP, eAST_SEAT)
    }
    hcpTotalSouth.onEditingFinished:
    {
        on_hcp_editingFinished(nOTRUMP, sOUTH_SEAT)
    }
    hcpSpadeWest.onEditingFinished:
    {
        on_hcp_editingFinished(sPADES, wEST_SEAT)
    }
    hcpSpadeNorth.onEditingFinished:
    {
        on_hcp_editingFinished(sPADES, nORTH_SEAT)
    }
    hcpSpadeEast.onEditingFinished:
    {
        on_hcp_editingFinished(sPADES, eAST_SEAT)
    }
    hcpSpadeSouth.onEditingFinished:
    {
        on_hcp_editingFinished(sPADES, sOUTH_SEAT)
    }
    hcpHeartWest.onEditingFinished:
    {
        on_hcp_editingFinished(hEARTS, wEST_SEAT)
    }
    hcpHeartNorth.onEditingFinished:
    {
        on_hcp_editingFinished(hEARTS, nORTH_SEAT)
    }
    hcpHeartEast.onEditingFinished:
    {
        on_hcp_editingFinished(hEARTS, eAST_SEAT)
    }
    hcpHeartSouth.onEditingFinished:
    {
        on_hcp_editingFinished(hEARTS, sOUTH_SEAT)
    }
    hcpDiamondWest.onEditingFinished:
    {
        on_hcp_editingFinished(dIAMONDS, wEST_SEAT)
    }
    hcpDiamondNorth.onEditingFinished:
    {
        on_hcp_editingFinished(dIAMONDS, nORTH_SEAT)
    }
    hcpDiamondEast.onEditingFinished:
    {
        on_hcp_editingFinished(dIAMONDS, eAST_SEAT)
    }
    hcpDiamondSouth.onEditingFinished:
    {
        on_hcp_editingFinished(dIAMONDS, sOUTH_SEAT)
    }
    hcpClubWest.onEditingFinished:
    {
        on_hcp_editingFinished(cLUBS, wEST_SEAT)
    }
    hcpClubNorth.onEditingFinished:
    {
        on_hcp_editingFinished(cLUBS, nORTH_SEAT)
    }
    hcpClubEast.onEditingFinished:
    {
        on_hcp_editingFinished(cLUBS, eAST_SEAT)
    }
    hcpClubSouth.onEditingFinished:
    {
        on_hcp_editingFinished(cLUBS, sOUTH_SEAT)
    }
    suitSizeSpadeWest.onEditingFinished:
    {
        on_suitSize_editingFinished(sPADES, wEST_SEAT)
    }
    suitSizeSpadeNorth.onEditingFinished:
    {
        on_suitSize_editingFinished(sPADES, nORTH_SEAT)
    }
    suitSizeSpadeEast.onEditingFinished:
    {
        on_suitSize_editingFinished(sPADES, eAST_SEAT)
    }
    suitSizeSpadeSouth.onEditingFinished:
    {
        on_suitSize_editingFinished(sPADES, sOUTH_SEAT)
    }
    suitSizeHeartWest.onEditingFinished:
    {
        on_suitSize_editingFinished(hEARTS, wEST_SEAT)
    }
    suitSizeHeartNorth.onEditingFinished:
    {
        on_suitSize_editingFinished(hEARTS, nORTH_SEAT)
    }
    suitSizeHeartEast.onEditingFinished:
    {
        on_suitSize_editingFinished(hEARTS, eAST_SEAT)
    }
    suitSizeHeartSouth.onEditingFinished:
    {
        on_suitSize_editingFinished(hEARTS, sOUTH_SEAT)
    }
    suitSizeDiamondWest.onEditingFinished:
    {
        on_suitSize_editingFinished(dIAMONDS, wEST_SEAT)
    }
    suitSizeDiamondNorth.onEditingFinished:
    {
        on_suitSize_editingFinished(dIAMONDS, nORTH_SEAT)
    }
    suitSizeDiamondEast.onEditingFinished:
    {
        on_suitSize_editingFinished(dIAMONDS, eAST_SEAT)
    }
    suitSizeDiamondSouth.onEditingFinished:
    {
        on_suitSize_editingFinished(dIAMONDS, sOUTH_SEAT)
    }
    suitSizeClubWest.onEditingFinished:
    {
        on_suitSize_editingFinished(cLUBS, wEST_SEAT)
    }
    suitSizeClubNorth.onEditingFinished:
    {
        on_suitSize_editingFinished(cLUBS, nORTH_SEAT)
    }
    suitSizeClubEast.onEditingFinished:
    {
        on_suitSize_editingFinished(cLUBS, eAST_SEAT)
    }
    suitSizeClubSouth.onEditingFinished:
    {
        on_suitSize_editingFinished(cLUBS, sOUTH_SEAT)
    }
    dpWest.onEditingFinished:
    {
        on_dp_editingFinished(wEST_SEAT)
    }
    dpNorth.onEditingFinished:
    {
        on_dp_editingFinished(nORTH_SEAT)
    }
    dpEast.onEditingFinished:
    {
        on_dp_editingFinished(eAST_SEAT)
    }
    dpSouth.onEditingFinished:
    {
        on_dp_editingFinished(sOUTH_SEAT)
    }

    function hcpSetText(suit, seat, text)
    {
        if (suit === 0)
        {
            if (seat === 0)
                hcpClubWest.text = text
            else if (seat === 1)
                hcpClubNorth.text = text
            else if (seat === 2)
                hcpClubEast.text = text
            else if (seat === 3)
                hcpClubSouth.text = text
        }
        else if (suit === 1)
        {
            if (seat === 0)
                hcpDiamondWest.text = text
            else if (seat === 1)
                hcpDiamondNorth.text = text
            else if (seat === 2)
                hcpDiamondEast.text = text
            else if (seat === 3)
                hcpDiamondSouth.text = text
        }
        else if (suit === 2)
        {
            if (seat === 0)
                hcpHeartWest.text = text
            else if (seat === 1)
                hcpHeartNorth.text = text
            else if (seat === 2)
                hcpHeartEast.text = text
            else if (seat === 3)
                hcpHeartSouth.text = text
        }
        else if (suit === 3)
        {
            if (seat === 0)
                hcpSpadeWest.text = text
            else if (seat === 1)
                hcpSpadeNorth.text = text
            else if (seat === 2)
                hcpSpadeEast.text = text
            else if (seat === 3)
                hcpSpadeSouth.text = text
        }
        else if (suit === 4)
        {
            if (seat === 0)
                hcpTotalWest.text = text
            else if (seat === 1)
                hcpTotalNorth.text = text
            else if (seat === 2)
                hcpTotalEast.text = text
            else if (seat === 3)
                hcpTotalSouth.text = text
        }
    }
    function hcpText(suit, seat)
    {
        if (suit === 0)
        {
            if (seat === 0)
                return hcpClubWest.text
            else if (seat === 1)
                return hcpClubNorth.text
            else if (seat === 2)
                return hcpClubEast.text
            else if (seat === 3)
                return hcpClubSouth.text
        }
        else if (suit === 1)
        {
            if (seat === 0)
                return hcpDiamondWest.text
            else if (seat === 1)
                return hcpDiamondNorth.text
            else if (seat === 2)
                return hcpDiamondEast.text
            else if (seat === 3)
                return hcpDiamondSouth.text
        }
        else if (suit === 2)
        {
            if (seat === 0)
                return hcpHeartWest.text
            else if (seat === 1)
                return hcpHeartNorth.text
            else if (seat === 2)
                return hcpHeartEast.text
            else if (seat === 3)
                return hcpHeartSouth.text
        }
        else if (suit === 3)
        {
            if (seat === 0)
                return hcpSpadeWest.text
            else if (seat === 1)
                return hcpSpadeNorth.text
            else if (seat === 2)
                return hcpSpadeEast.text
            else if (seat === 3)
                return hcpSpadeSouth.text
        }
        else if (suit === 4)
        {
            if (seat === 0)
                return hcpTotalWest.text
            else if (seat === 1)
                return hcpTotalNorth.text
            else if (seat === 2)
                return hcpTotalEast.text
            else if (seat === 3)
                return hcpTotalSouth.text
        }
    }
    function hcpSetOk(suit, seat, ok)
    {
        if (suit === 0)
        {
            if (seat === 0)
                hcpClubWest.ok = ok
            else if (seat === 1)
                hcpClubNorth.ok = ok
            else if (seat === 2)
                hcpClubEast.ok = ok
            else if (seat === 3)
                hcpClubSouth.ok = ok
        }
        else if (suit === 1)
        {
            if (seat === 0)
                hcpDiamondWest.ok = ok
            else if (seat === 1)
                hcpDiamondNorth.ok = ok
            else if (seat === 2)
                hcpDiamondEast.ok = ok
            else if (seat === 3)
                hcpDiamondSouth.ok = ok
        }
        else if (suit === 2)
        {
            if (seat === 0)
                hcpHeartWest.ok = ok
            else if (seat === 1)
                hcpHeartNorth.ok = ok
            else if (seat === 2)
                hcpHeartEast.ok = ok
            else if (seat === 3)
                hcpHeartSouth.ok = ok
        }
        else if (suit === 3)
        {
            if (seat === 0)
                hcpSpadeWest.ok = ok
            else if (seat === 1)
                hcpSpadeNorth.ok = ok
            else if (seat === 2)
                hcpSpadeEast.ok = ok
            else if (seat === 3)
                hcpSpadeSouth.ok = ok
        }
        else if (suit === 4)
        {
            if (seat === 0)
                hcpTotalWest.ok = ok
            else if (seat === 1)
                hcpTotalNorth.ok = ok
            else if (seat === 2)
                hcpTotalEast.ok = ok
            else if (seat === 3)
                hcpTotalSouth.ok = ok
        }
    }

    function suitSizeSetText(suit, seat, text)
    {
        if (suit === 0)
        {
            if (seat === 0)
                suitSizeClubWest.text = text
            else if (seat === 1)
                suitSizeClubNorth.text = text
            else if (seat === 2)
                suitSizeClubEast.text = text
            else if (seat === 3)
                suitSizeClubSouth.text = text
        }
        else if (suit === 1)
        {
            if (seat === 0)
                suitSizeDiamondWest.text = text
            else if (seat === 1)
                suitSizeDiamondNorth.text = text
            else if (seat === 2)
                suitSizeDiamondEast.text = text
            else if (seat === 3)
                suitSizeDiamondSouth.text = text
        }
        else if (suit === 2)
        {
            if (seat === 0)
                suitSizeHeartWest.text = text
            else if (seat === 1)
                suitSizeHeartNorth.text = text
            else if (seat === 2)
                suitSizeHeartEast.text = text
            else if (seat === 3)
                suitSizeHeartSouth.text = text
        }
        else if (suit === 3)
        {
            if (seat === 0)
                suitSizeSpadeWest.text = text
            else if (seat === 1)
                suitSizeSpadeNorth.text = text
            else if (seat === 2)
                suitSizeSpadeEast.text = text
            else if (seat === 3)
                suitSizeSpadeSouth.text = text
        }
    }
    function suitSizeText(suit, seat)
    {
        if (suit === 0)
        {
            if (seat === 0)
                return suitSizeClubWest.text
            else if (seat === 1)
                return suitSizeClubNorth.text
            else if (seat === 2)
                return suitSizeClubEast.text
            else if (seat === 3)
                return suitSizeClubSouth.text
        }
        else if (suit === 1)
        {
            if (seat === 0)
                return suitSizeDiamondWest.text
            else if (seat === 1)
                return suitSizeDiamondNorth.text
            else if (seat === 2)
                return suitSizeDiamondEast.text
            else if (seat === 3)
                return suitSizeDiamondSouth.text
        }
        else if (suit === 2)
        {
            if (seat === 0)
                return suitSizeHeartWest.text
            else if (seat === 1)
                return suitSizeHeartNorth.text
            else if (seat === 2)
                return suitSizeHeartEast.text
            else if (seat === 3)
                return suitSizeHeartSouth.text
        }
        else if (suit === 3)
        {
            if (seat === 0)
                return suitSizeSpadeWest.text
            else if (seat === 1)
                return suitSizeSpadeNorth.text
            else if (seat === 2)
                return suitSizeSpadeEast.text
            else if (seat === 3)
                return suitSizeSpadeSouth.text
        }
    }
    function suitSizeSetOk(suit, seat, ok)
    {
        if (suit === 0)
        {
            if (seat === 0)
                suitSizeClubWest.ok = ok
            else if (seat === 1)
                suitSizeClubNorth.ok = ok
            else if (seat === 2)
                suitSizeClubEast.ok = ok
            else if (seat === 3)
                suitSizeClubSouth.ok = ok
        }
        else if (suit === 1)
        {
            if (seat === 0)
                suitSizeDiamondWest.ok = ok
            else if (seat === 1)
                suitSizeDiamondNorth.ok = ok
            else if (seat === 2)
                suitSizeDiamondEast.ok = ok
            else if (seat === 3)
                suitSizeDiamondSouth.ok = ok
        }
        else if (suit === 2)
        {
            if (seat === 0)
                suitSizeHeartWest.ok = ok
            else if (seat === 1)
                suitSizeHeartNorth.ok = ok
            else if (seat === 2)
                suitSizeHeartEast.ok = ok
            else if (seat === 3)
                suitSizeHeartSouth.ok = ok
        }
        else if (suit === 3)
        {
            if (seat === 0)
                suitSizeSpadeWest.ok = ok
            else if (seat === 1)
                suitSizeSpadeNorth.ok = ok
            else if (seat === 2)
                suitSizeSpadeEast.ok = ok
            else if (seat === 3)
                suitSizeSpadeSouth.ok = ok
        }
    }

    function dpSetText(seat, text)
    {
        if (seat === 0)
            dpWest.text = text
        else if (seat === 1)
            dpNorth.text = text
        else if (seat === 2)
            dpEast.text = text
        else if (seat === 3)
            dpSouth.text = text
    }
    function dpText(seat)
    {
        if (seat === 0)
            return dpWest.text
        else if (seat === 1)
            return dpNorth.text
        else if (seat === 2)
            return dpEast.text
        else if (seat === 3)
            return dpSouth.text
    }
    function dpSetOk(seat, ok)
    {
        if (seat === 0)
            dpWest.ok = ok
        else if (seat === 1)
            dpNorth.ok = ok
        else if (seat === 2)
            dpEast.ok = ok
        else if (seat === 3)
            dpSouth.ok = ok
    }

    function isAllOk()
    {
        if (!hcpClubWest.ok)
            return false
        if (!hcpClubNorth.ok)
            return false
        if (!hcpClubEast.ok)
            return false
        if (!hcpClubSouth.ok)
            return false
        if (!hcpDiamondWest.ok)
            return false
        if (!hcpDiamondNorth.ok)
            return false
        if (!hcpDiamondEast.ok)
            return false
        if (!hcpDiamondSouth.ok)
            return false
        if (!hcpHeartWest.ok)
            return false
        if (!hcpHeartNorth.ok)
            return false
        if (!hcpHeartEast.ok)
            return false
        if (!hcpHeartSouth.ok)
            return false
        if (!hcpSpadeWest.ok)
            return false
        if (!hcpSpadeNorth.ok)
            return false
        if (!hcpSpadeEast.ok)
            return false
        if (!hcpSpadeSouth.ok)
            return false
        if (!hcpTotalWest.ok)
            return false
        if (!hcpTotalNorth.ok)
            return false
        if (!hcpTotalEast.ok)
            return false
        if (!hcpTotalSouth.ok)
            return false
        if (!suitSizeClubWest.ok)
            return false
        if (!suitSizeClubEast.ok)
            return false
        if (!suitSizeClubSouth.ok)
            return false
        if (!suitSizeDiamondWest.ok)
            return false
        if (!suitSizeDiamondNorth.ok)
            return false
        if (!suitSizeDiamondEast.ok)
            return false
        if (!suitSizeDiamondSouth.ok)
            return falser
        if (!suitSizeHeartWest.ok)
            return false
        if (!suitSizeHeartNorth.ok)
            return false
        if (!suitSizeHeartEast.ok)
            return false
        if (!suitSizeHeartSouth.ok)
            return false
        if (!suitSizeSpadeWest.ok)
            return false
        if (!suitSizeSpadeNorth.ok)
            return false
        if (!suitSizeSpadeEast.ok)
            return false
        if (!suitSizeSpadeSouth.ok)
            return false
        if (!dpWest.ok)
            return false
        if (!dpNorth.ok)
            return false
        if (!dpEast.ok)
            return false
        if (!dpSouth.ok)
            return false

        return true
    }
    function setZoom(zoom)
    {
        zf = zoom
    }
}

