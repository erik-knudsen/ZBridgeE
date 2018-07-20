/*Erik Aagaard Knudsen.
  Copyright © 2013 - All Rights Reserved

  Project: ZBridge
  File: Defines.h
  Developers: eak

  Revision History:
  26-feb-2013 eak: Original

  Abstract: Global constant definitions.

  Platforms: Qt.
*/

/**
 * \file
 * Definition of global constants.
 */

#ifndef DEFINES_H
#define DEFINES_H

#include <QString>

//Menu actions.
enum MenuAction { ACTION_OPEN, ACTION_SAVE, ACTION_SAVE_AS, ACTION_DELETE, ACTION_EXPOSE_ALL_CARDS,
                  ACTION_SCORE, ACTION_DOUBLE_DUMMY_RESULTS, ACTION_NEW_SESSION, ACTION_DEAL_NEW_HAND,
                  ACTION_ACTIVATE_DEAL_PROFILE, ACTION_UNDO, ACTION_BID_REBID, ACTION_RESTART_HAND,
                  ACTION_HINT, ACTION_SEAT_CONFIGURATION, ACTION_BIDDING_OPTIONS, ACTION_DEAL_OPTIONS,
                  ACTION_DISPLAY_OPTIONS, ACTION_GAME_OPTIONS, ACTION_CONTENTS, ACTION_ABOUT_ZBRIDGE };

//Port offset for automatic play.
const int AUTOPORTOFFSET = 10;

//Number of random deals in a random session.
const int NO_RANDOM_DEALS = 32;

//Update (enable/disable) UI (mostly menues) actions.
enum UpdateUIAction { UPDATE_UI_INITIAL, UPDATE_UI_SERVER, UPDATE_UI_CLIENT, UPDATE_UI_NEW_SESSION,
                    UPDATE_UI_NEW_DEAL, UPDATE_UI_UNDO, UPDATE_UI_REBID, UPDATE_UI_REPLAY, UPDATE_UI_SHOW_ALL,
                    UPDATE_UI_SCORE, UPDATE_UI_DELETE, UPDATE_UI_SAVE, UPDATE_UI_SAVEAS, UPDATE_UI_PAR,
                    UPDATE_UI_HINT};

//Message type in network protocol.
enum MsgType { CONNECT_MSG, SEATED_MSG, RTNAMES_MSG, TEAMNAMES_MSG, RSBOARD_MSG, STARTOFBOARD_MSG, RDEALINFO_MSG,
               DEALINFO_MSG, RCARDS_MSG, CARDS_MSG, BID_MSG, RBID_MSG, ILLEGALBID_MSG, PLAYERTOLEAD_MSG,
               DUMMYTOLEAD_MSG, PLAYERPLAYS_MSG, READYFORPLAYER_MSG, READYFORDUMMY_MSG, ILLEGALCARD_MSG,
               READYFORDUMMYCARDS_MSG, DUMMYCARDS_MSG, ENDOFSESSION_MSG, UNKNOWN_MSG, UNDOBID_MSG, UNDOTRICK_MSG,
               REBID_MSG, REPLAY_MSG, ATTEMPT_SYNCHRONIZE_MSG, CONFIRM_SYNCHRONIZE_MSG, ALL_SYNCHRONIZED_MSG,
               ORIGINAL_PBN_START_MSG, PLAYED_PBN_START_MSG, PBN_LINE_MSG, ESCAPE_MSG};

//Deal and game types.
enum DealType { ORIGINAL_DEAL, RANDOM_DEAL };               /**< The two types of game sets. */
enum GameType { ORIGINAL_GAME, PLAYED_GAME, AUTO_GAME };    /**< The three types of games in a game set. */

//Honor card values
const int NINE = 7;
const int TEN =   8;
const int JACK =  9;
const int QUEEN = 10;
const int KING =  11;
const int ACE =   12;

//Seat names (indexed by enum Seat).
const char * const SEAT_NAMES[4] =
{
    QT_TRANSLATE_NOOP("defines", "West"),
    QT_TRANSLATE_NOOP("defines", "North"),
    QT_TRANSLATE_NOOP("defines", "East"),
    QT_TRANSLATE_NOOP("defines", "South")
};

//Auto seat names prefix.
const QString AUTO_SEAT_NAME_PREFIX = "AUTO_";

//Suit names (indexed by enum Suit).
const char * const SUIT_NAMES[5] =
{
    QT_TRANSLATE_NOOP("defines", "C"),
    QT_TRANSLATE_NOOP("defines", "D"),
    QT_TRANSLATE_NOOP("defines", "H"),
    QT_TRANSLATE_NOOP("defines", "S"),
    QT_TRANSLATE_NOOP("defines", "NT")
};

//Face names (indexed by face value).
const char * const FACE_NAMES[13] =
{
    QT_TRANSLATE_NOOP("defines", "2"),
    QT_TRANSLATE_NOOP("defines", "3"),
    QT_TRANSLATE_NOOP("defines", "4"),
    QT_TRANSLATE_NOOP("defines", "5"),
    QT_TRANSLATE_NOOP("defines", "6"),
    QT_TRANSLATE_NOOP("defines", "7"),
    QT_TRANSLATE_NOOP("defines", "8"),
    QT_TRANSLATE_NOOP("defines", "9"),
    QT_TRANSLATE_NOOP("defines", "T"),
    QT_TRANSLATE_NOOP("defines", "J"),
    QT_TRANSLATE_NOOP("defines", "Q"),
    QT_TRANSLATE_NOOP("defines", "K"),
    QT_TRANSLATE_NOOP("defines", "A")
};

//Team names (indexed by enum Team).
const char * const TEAM_NAMES[4] =
{
    QT_TRANSLATE_NOOP("defines", "Neither"),
    QT_TRANSLATE_NOOP("defines", "North-South"),
    QT_TRANSLATE_NOOP("defines", "East-West"),
    QT_TRANSLATE_NOOP("defines", "All")
};

//Suit, position and vulnerability. MUST NOT be changed (used as index).
enum Suit { ANY=-1, CLUBS=0, DIAMONDS=1, HEARTS=2, SPADES=3, NOTRUMP=4 };
enum Position { LEFT_POS=0, TOP_POS=1, RIGHT_POS=2, BOTTOM_POS=3};
enum Team { NONE=-1, NEITHER=0, NORTH_SOUTH=1, EAST_WEST=2, BOTH=3 };

//Bids (these values MUST NOT be changed they are used as index in some places).
enum Bids {
    BID_NONE=-1,
    BID_PASS=0,
    BID_1C= 1, BID_1D= 2, BID_1H= 3, BID_1S= 4, BID_1NT= 5,
    BID_2C= 6, BID_2D= 7, BID_2H= 8, BID_2S= 9, BID_2NT=10,
    BID_3C=11, BID_3D=12, BID_3H=13, BID_3S=14, BID_3NT=15,
    BID_4C=16, BID_4D=17, BID_4H=18, BID_4S=19, BID_4NT=20,
    BID_5C=21, BID_5D=22, BID_5H=23, BID_5S=24, BID_5NT=25,
    BID_6C=26, BID_6D=27, BID_6H=28, BID_6S=29, BID_6NT=30,
    BID_7C=31, BID_7D=32, BID_7H=33, BID_7S=34, BID_7NT=35,
    BID_DOUBLE=36, BID_REDOUBLE=37, BID_PLAYER=38, BID_BLANK=39
};

//Card values (CLUBS, DIAMONDS, HEARTS, SPADES).
const int SUIT_INTERVAL[4][2] = {
    { 13, 25},
    {  0, 12},
    { 26, 38},
    { 39, 51}
                               };

//Card faces indexed by card values.
const QString CARD_FACES[52] = {
    ":/resources/15.png",
    ":/resources/16.png",
    ":/resources/17.png",
    ":/resources/18.png",
    ":/resources/19.png",
    ":/resources/20.png",
    ":/resources/21.png",
    ":/resources/22.png",
    ":/resources/23.png",
    ":/resources/24.png",
    ":/resources/25.png",
    ":/resources/26.png",
    ":/resources/14.png",

    ":/resources/2.png",
    ":/resources/3.png",
    ":/resources/4.png",
    ":/resources/5.png",
    ":/resources/6.png",
    ":/resources/7.png",
    ":/resources/8.png",
    ":/resources/9.png",
    ":/resources/10.png",
    ":/resources/11.png",
    ":/resources/12.png",
    ":/resources/13.png",
    ":/resources/1.png",

    ":/resources/28.png",
    ":/resources/29.png",
    ":/resources/30.png",
    ":/resources/31.png",
    ":/resources/32.png",
    ":/resources/33.png",
    ":/resources/34.png",
    ":/resources/35.png",
    ":/resources/36.png",
    ":/resources/37.png",
    ":/resources/38.png",
    ":/resources/39.png",
    ":/resources/27.png",

    ":/resources/41.png",
    ":/resources/42.png",
    ":/resources/43.png",
    ":/resources/44.png",
    ":/resources/45.png",
    ":/resources/46.png",
    ":/resources/47.png",
    ":/resources/48.png",
    ":/resources/49.png",
    ":/resources/50.png",
    ":/resources/51.png",
    ":/resources/52.png",
    ":/resources/40.png"
};

//Bid icons.
const QString BIDS[41] = {
    ":/resources/ico_pass.ico",
    ":/resources/ico_1c.ico",
    ":/resources/ico_1d.ico",
    ":/resources/ico_1h.ico",
    ":/resources/ico_1s.ico",
    ":/resources/ico_1nt.ico",
    ":/resources/ico_2c.ico",
    ":/resources/ico_2d.ico",
    ":/resources/ico_2h.ico",
    ":/resources/ico_2s.ico",
    ":/resources/ico_2nt.ico",
    ":/resources/ico_3c.ico",
    ":/resources/ico_3d.ico",
    ":/resources/ico_3h.ico",
    ":/resources/ico_3s.ico",
    ":/resources/ico_3nt.ico",
    ":/resources/ico_4c.ico",
    ":/resources/ico_4d.ico",
    ":/resources/ico_4h.ico",
    ":/resources/ico_4s.ico",
    ":/resources/ico_4nt.ico",
    ":/resources/ico_5c.ico",
    ":/resources/ico_5d.ico",
    ":/resources/ico_5h.ico",
    ":/resources/ico_5s.ico",
    ":/resources/ico_5nt.ico",
    ":/resources/ico_6c.ico",
    ":/resources/ico_6d.ico",
    ":/resources/ico_6h.ico",
    ":/resources/ico_6s.ico",
    ":/resources/ico_6nt.ico",
    ":/resources/ico_7c.ico",
    ":/resources/ico_7d.ico",
    ":/resources/ico_7h.ico",
    ":/resources/ico_7s.ico",
    ":/resources/ico_7nt.ico",
    ":/resources/ico_double.ico",
    ":/resources/ico_redouble.ico",
    ":/resources/PlayerBidPrompt.ico",
    ":/resources/BlankBidPrompt.ico"
};

//Sync states (must be the same as in the Yakindu client synchronization statechart).
//These values are used to determine whether there should be a pause and if so, which kind
//of pause (show a button etc.).
const int SS = 1;       //Start of Board synchronization (before new deal starts).
const int SA = 2;       //Start of Auction synchronization (before auction starts).
const int SP = 3;       //Start of Play synchronization (before play starts).
const int SL = 4;       //Start of Leader synchronization (before next trick starts).

//Button ids.
const int BUTTON_NONE = 0;
const int BUTTON_AUCTION = SA;
const int BUTTON_PLAY = SP;
const int BUTTON_LEADER = SL;
const int BUTTON_DEAL = SS;
const int BUTTON_FWD = 10;
const int BUTTON_BCK = 11;
const int BUTTON_DD = 12;
const int BUTTON_OK = 13;

//UNDO values (must be the same as in the Yakindu synchronization statecharts.
//These values are used as undo values to determine the undo type (rebid, replay, complete trick or partial trick).
const int REBID = -1;
const int REPLAY = -2;
const int CT = 1;
const int PT = 2;

//------------------------- Seat options. ---------------------------
enum Seat { NO_SEAT=-1, WEST_SEAT=0, NORTH_SEAT=1, EAST_SEAT=2, SOUTH_SEAT=3};
enum Actor { MANUAL_ACTOR = 0, AUTO_ACTOR = 1, REMOTE_ACTOR = 2 };
enum Role { SERVER_ROLE = 0, CLIENT_ROLE = 1,STANDALONE_ROLE = 2 };
enum Protocol { PROTOCOL_V0 = 20 };

//-------------------------- Bid/Play Options --------------------
//Bid configuration file name.
const QString BIDOPTIONFILENAME = "BidOption.bid";

const int NSBIDOPTIONSINDEX = 0;
const int EWBIDOPTIONSINDEX = 1;
const int MAXOPENINGLEADS = 2;

//Bid modes.
const int AMERICAN_STYLE = 0;
const int EUROPEAN_STYLE = 1;

//Major modes.
const int MAJOR_FOUR = 0;
const int MAJOR_FIVE = 1;

//Stayman types.
const int STAYMAN_OFF = 0;
const int STAYMAN_3R_F = 1;
const int STAYMAN_3R_NF = 2;
const int STAYMAN_4R = 3;

//2-Bid modes.
const int S2_NATURAL = 0;
const int W2_NATURAL = 1;
const int W2_OGUST = 2;
const int W2_FEATURE = 3;

//Weak two new suit.
const int W2_NEW_SUIT_NF = 0;
const int W2_NEW_SUIT_F = 1;

//2C Open values.
const int OPEN_VALUE_20 = 20;
const int OPEN_VALUE_21 = 21;
const int OPEN_VALUE_22 = 22;
const int OPEN_VALUE_23 = 23;

//After strong two club.
const int TWO_C_TWO_D_NEGATIVE = 0;
const int TWO_C_TWO_D_WAITING = 1;

//NT Range.
const int ONE_NT_RANGE_12_14 = 0;
const int ONE_NT_RANGE_15_17 = 1;
const int ONE_NT_RANGE_16_18 = 2;

const int TWO_NT_RANGE_20_21 = 0;
const int TWO_NT_RANGE_21_22 = 1;
const int TWO_NT_RANGE_22_24 = 2;

const int THREE_NT_RANGE_25_27 = 0;
const int GAMBLING_3_NT = 1;
const int GAMBLING_3_NT_ACOL = 2;

//2 NT after 1/1.
const int TWO_NT_11_18_20 = 0;
const int TWO_NT_11_17_18 = 1;

//2 NT after 2/1.
const int TWO_NT_21_15_18 = 0;
const int TWO_NT_21_12_14 = 1;

//After 1NT rebid.
const int REBID_1NT_NAT = 0;
const int REBID_1NT_F = 1;

//3 minor after 1NT.
const int ONE_NT_3m_SI = 0;
const int ONE_NT_3m_GI = 1;
const int ONE_NT_3m_PE = 2;

//3 major after 1NT.
const int ONE_NT_3M_SI = 0;
const int ONE_NT_3M_GF = 1;
const int ONE_NT_3M_GI = 2;
const int ONE_NT_3M_PE = 3;

//Jump overcall types.
const int JUMP_OVERCALL_STRONG = 0;
const int JUMP_OVERCALL_WEAK_NATURAL = 1;
const int JUMP_OVERCALL_WEAK_OGUST = 2;
const int JUMP_OVERCALL_WEAK_FEATURE = 3;

//Direct cuebid.
const int MICHAELS_CUEBID = 0;
const int STRONG_CUE_BID = 1;

//Three level vulnerability.
const int SOUND_THREE_LEVEL = 0;
const int LIGHT_THREE_LEVEL = 1;
const int LIGHT_THREE_LEVEL_NV = 2;

//Signals.
const int SIGNAL_NO_SIGNAL = 0;
const int SIGNAL_COUNT_HIGH = 1;
const int SIGNAL_COUNT_LOW = 2;
const int SIGNAL_ATTITUDE_HIGH = 3;
const int SIGNAL_ATTITUDE_LOW = 4;

//Leads.
const int FOURTH_BEST = 0;
const int THIRD_FIFTH_BEST = 1;
const int LOW_ENCOURAGING = 2;

const int OPEN_SUIT = 0;
const int OPEN_NT = 1;

const int AK_INX = 0;
const int XXX_INX = 1;

const int Xxx_VAL = 0;
const int xXx_VAL = 1;
const int xxX_VAL = 2;

const int Ak_VAL = 0;
const int aK_VAL = 1;

//---------------------------- Deal Options -------------------
const int MAX_SUIT_HCP = 10;
const int MAX_TOT_HCP = 37;
const int MAX_TOT_DP = 9;
const int MAX_SUIT_SIZE = 13;

//------------------------- Display options. ------------------------
//Card Backs.
const int CARD_BACK_0 = 0;
const int CARD_BACK_1 = 1;
const int CARD_BACK_2 = 2;
const int CARD_BACK_3 = 3;
const int CARD_BACK_4 = 4;
const int CARD_BACK_5 = 5;
const int CARD_BACK_6 = 6;
//Card back names indexed by above index.
const QString CARD_BACK_NAME[6] = { ":/resources/cardback1.png",
                                    ":/resources/cardback22.png",
                                    ":/resources/cardback3.png",
                                    ":/resources/cardback5.png",
                                    ":/resources/cardback11.png",
                                    ":/resources/cardback2.png"
                                   };
//Scoring.
enum Forcing { NON_FORCING=0, FORCING=1, GAME_FORCING=2, MUST_PASS=3};
enum Vulnerability { VUL_II=0, VUL_NI=1, VUL_YI=2, VUL_NN=3, VUL_NY=4, VUL_YN=5, VUL_YY=6 };
enum ScoringMethod { IMP=0, MP=1, RUBBER=2, PRACTICE=3, NOSCORE=4, FORSCORE=5};

//------------------------- Play View definitions ----------------------
const int CARD_VER_SIZE = 96;
const int TB_CARD_VER_SIZE = CARD_VER_SIZE + 2;
const int LR_CARD_VER_SIZE = 4 * TB_CARD_VER_SIZE;
const int CENTER_VER_SIZE = LR_CARD_VER_SIZE;
const int INF_VER_SIZE = CENTER_VER_SIZE;
const int SCENE_VER_SIZE = CENTER_VER_SIZE + TB_CARD_VER_SIZE + TB_CARD_VER_SIZE;

const int CARD_HOR_SIZE = 71;
const int CENTER_HOR_SIZE = 290;
const int LR_CARD_HOR_SIZE = (CENTER_VER_SIZE + 4 * TB_CARD_VER_SIZE  - CENTER_HOR_SIZE) >> 1;
const int TB_CARD_HOR_SIZE = CENTER_HOR_SIZE + LR_CARD_HOR_SIZE + LR_CARD_HOR_SIZE - TB_CARD_VER_SIZE;
const int INF_HOR_SIZE = 180;
const int SCENE_HOR_SIZE = CENTER_HOR_SIZE + LR_CARD_HOR_SIZE + LR_CARD_HOR_SIZE + INF_HOR_SIZE;

const int BID_HOR_SIZE = 18;
const int BID_VER_SIZE = 12;




// Shortcuts (Macros)
#define pMAINFRAME		 CMainframe::Instance()
#define pDOC			 CZBridgeDoc::Instance()

#define	ABS(x)			 ((x>=0)?x:-x)

//Suit is CLUBS or DIAMONDS or Hearts ot SPADES. Face in suit ranges from 0 to 12 (inclusive), where
//0 corresponds to 2 in the suit and 12 corresponds to ace in the suit.
#define IS_CLUBS(card)          ((SUIT_INTERVAL[CLUBS][0] <= card) && (card <= SUIT_INTERVAL[CLUBS][1]))
#define IS_DIAMONDS(card)       ((SUIT_INTERVAL[DIAMONDS][0] <= card) && (card <= SUIT_INTERVAL[DIAMONDS][1]))
#define IS_HEARTS(card)         ((SUIT_INTERVAL[HEARTS][0] <= card) && (card <= SUIT_INTERVAL[HEARTS][1]))
#define IS_SPADES(card)         ((SUIT_INTERVAL[SPADES][0] <= card) && (card <= SUIT_INTERVAL[SPADES][1]))
#define	MAKE_CARD(suit, face)   (((suit >= CLUBS) && (suit <= SPADES) && (face >= 0) && (face <= 12)) ?\
                                 (SUIT_INTERVAL[suit][0] + face) : -1)
#define	CARD_SUIT(card)         (IS_CLUBS(card) ? CLUBS :\
                                 IS_DIAMONDS(card) ? DIAMONDS :\
                                  IS_HEARTS(card) ? HEARTS :\
                                   IS_SPADES(card) ? SPADES : ANY)
#define	CARD_FACE(card)         (IS_CLUBS(card) ? (card - SUIT_INTERVAL[CLUBS][0]) :\
                                 IS_DIAMONDS(card) ? (card - SUIT_INTERVAL[DIAMONDS][0]) :\
                                  IS_HEARTS(card) ? (card - SUIT_INTERVAL[HEARTS][0]) :\
                                   IS_SPADES(card) ? (card - SUIT_INTERVAL[SPADES][0]) : -1)

#define ISMAJOR(suit)	(((suit == HEARTS) || (suit == SPADES)) ? true : false)
#define ISMINOR(suit)	(((suit == CLUBS) || (suit == DIAMONDS)) ? true : false)
#define ISNOTRUMP(suit) ((suit == NOTRUMP) ? true : false)

#define MAKE_BID(suit, level) (((suit > ANY) && (suit <= NOTRUMP) && (level >= 1) && (level <= 7)) ?\
                               (Bids)(BID_PASS + (level-1)*5 + suit + 1) : BID_NONE)
#define BID_SUIT(bid)  ((Suit)(((bid <= BID_PASS) || (bid >= BID_DOUBLE)) ? -1 : (((bid-1) % 5))))
#define BID_LEVEL(bid) ( ((bid <= BID_PASS) || (bid >= BID_DOUBLE)) ? -1 : (((bid-1) / 5) + 1) )

#define IS_BID(bid) ((bid >= BID_1C) && (bid <= BID_7NT))
#define IS_DOUBLE_BID(bid) (bid == BID_DOUBLE)
#define IS_REDOUBLE_BID(bid) (bid == BID_REDOUBLE)
#define IS_SUIT(suit) ((suit >= CLUBS) && (suit <= SPADES))
#define IS_CARD(card) ((card >= 0) && (card <= 51))
#define IS_FACE(face) ((face >= 0) && (face <= ACE))
#define IS_POSITION(position) ((position >= LEFT_POS) && (position <= BOTTOM_POS))
#define IS_PLAYER(seat) ((seat >= WEST_SEAT) && (seat <= SOUTH_SEAT))
#define IS_TEAM(team) ((team == NORTH_SOUTH) || (team == EAST_WEST))

#define OTHER_MAJOR(suit) 	((suit == HEARTS) ? SPADES : HEARTS)
#define OTHER_MINOR(suit) 	((suit == CLUBS) ? DIAMONDS : CLUBS)

#define MIN(a,b) ( ((a) <= (b))? (a): (b) )
#define MAX(a,b) ( ((a) >= (b))? (a): (b) )


#include <QEvent>

#define WMS_UPDATE_TEXT			QEvent::Type(106 + QEvent::User)
class WMS_UPDATE_TEXT_Event : public QEvent
{
public:
    explicit WMS_UPDATE_TEXT_Event(bool get) : QEvent(WMS_UPDATE_TEXT)
    {   this->get = get; }

    bool getget()
    { return get; }

private:
     bool get;
};

#define WMS_CARD_CLICKED			QEvent::Type(107 + QEvent::User)
class CARD_CLICKED_Event : public QEvent
{
public:
    explicit CARD_CLICKED_Event(Position pos, int cardValue) : QEvent(WMS_CARD_CLICKED)
    {
        this->pos = pos;
        this->cardValue = cardValue;
    }

    Position getPos() { return pos; }
    int getCardValue() { return cardValue; }

private:
    Position pos;
    int cardValue;
};

#define WMS_HAND_CLICKED			QEvent::Type(108 + QEvent::User)
class HAND_CLICKED_Event : public QEvent
{
public:
    explicit HAND_CLICKED_Event(Position pos) : QEvent(WMS_CARD_CLICKED)
    {
       this->pos = pos;
    }

    Position getPos() { return pos; }

private:
    Position pos;
};

#define WMS_BUTTON_CLICKED          QEvent::Type(109 + QEvent::User)
class BUTTON_CLICKED_Event : public QEvent
{
public:
    explicit BUTTON_CLICKED_Event(int button) : QEvent(WMS_BUTTON_CLICKED)
    { this->button = button;}

    int getButton() { return button; }

private:
    int button;
};

#define WMS_BID_CLICKED			QEvent::Type(110 + QEvent::User)
class BID_CLICKED_Event : public QEvent
{
public:
    explicit BID_CLICKED_Event(Seat seat, Bids bid) : QEvent(WMS_BID_CLICKED)
    { this->bid = bid; }

    Seat getSeat() { return seat; }
    Bids getBid() { return bid; }

private:
    Seat seat;
    Bids bid;
};

#define WMS_BID_CHOSEN			QEvent::Type(111 + QEvent::User)
class BID_CHOSEN_Event : public QEvent
{
public:
    explicit BID_CHOSEN_Event(Bids bid) : QEvent(WMS_BID_CHOSEN)
    { this->bid = bid; }

    Bids getBid() { return bid; }

private:
    Bids bid;
};

#define WMS_UPDATE_UI_ACTION			QEvent::Type(112 + QEvent::User)
class UPDATE_UI_ACTION_Event : public QEvent
{
public:
    explicit UPDATE_UI_ACTION_Event(UpdateUIAction uiAction, bool enable = true) : QEvent(WMS_UPDATE_UI_ACTION)
    { this->uiAction = uiAction; this->enable = enable; }

    UpdateUIAction getUIAction() { return uiAction; }
    bool getEnable() { return enable; }

private:
    UpdateUIAction uiAction;
    bool enable;
};

#endif // DEFINES_H
