/*
 * Keyboard: Atreus
 * Keymap:   replicaJunction
 * Version:  0.4
 *
 * This keymap is designed to complement my Ergodox keyboard layout, found in keyboards/ergodox_ez.
 * The Atreus keyboard is a 40% board whose design was heavily influenced by the Ergodox. I now
 * have both keyboards, so I've designed these layouts in an effort to make switching between the
 * two as easy as possible.
 *
 * Clearly, the Atreus is the limiting factor in this equation, so I've taken heavy advantage of
 * function and dual-role keys.
 *
 * The default key layout in this keymap is Colemak-ModDH. Information on that layout can be found
 * here: https://colemakmods.github.io/mod-dh/
 */

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Note that whatever is set as layer 0 will be the default layer of the keyboard.
//
enum macro_keycodes {
  KC_ALT_TAB,
  KC_CMD_TAB,
  KC_CMS_TAB,
  KC_CTL_L,
  KC_CTL_I,
  KC_CTL_E,
  KC_CTA_PIPE,
  KC_CTA_MINS,
  KC_HELLO,
  KC_ALT_SPC,
};

#define _CO  0 // Colemak
#define _NU  1 // Numbers
#define _CTL 2 // Control
#define _MS  3 // Mouse
#define _TC  4 // Touch Cursor
#define _ADJ 5 // Adjust

// Some quick aliases, just to make it look pretty
#define _______ KC_TRNS

// Custom macros
#define LCTL_TAB    LCTL(KC_TAB)
#define SFCTL_TAB   LCTL(LSFT(KC_TAB))
#define ALTSH_TAB   LALT(LSFT(KC_TAB))
#define ALTSH_EQL   LALT(LSFT(KC_EQL))
#define UND_SCR     S(KC_MINS)
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
// Tmux keys
#define CTL_A       LCTL(KC_A)
// Vim keys
#define CTL_V       LCTL(KC_V)
#define CTL_D       LCTL(KC_D)
#define CTL_B       LCTL(KC_B)
#define CTL_U       LCTL(KC_U)
#define CTL_J       LCTL(KC_J)
#define CTL_K       LCTL(KC_K)
#define CTL_H       LCTL(KC_H)
#define CTL_L       LCTL(KC_L)
#define CTL_P       LCTL(KC_P)
#define CTL_R       LCTL(KC_R)
#define CTL_C       LCTL(KC_C)
#define CTL_X       LCTL(KC_X)
#define CTL_Z       LCTL(KC_Z)
#define CTL_N       LCTL(KC_N)
#define CTL_I       LCTL(KC_I)
#define CTL_O       LCTL(KC_O)

#define CTL_TAB     MT(MOD_LCTL, KC_TAB)               // Tap for Tab, hold for Ctrl
#define SFT_EQL     SFT_T(KC_EQL)               // Tap for Equal, hold for Shift
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper
#define GUI_SEM     GUI_T(KC_SCLN)              // Tap for Semicolon, hold for GUI
#define ALT_QUO     ALT_T(KC_QUOT)              // Tap for Quote, hold for Alt
// Requires KC_TRNS/_______ for the trigger key in the destination layer
#define LT_TC       LT(_TOUCHCURSOR, KC_SPC)    // L-ayer T-ap T-ouch C-ursor
#define LT_MC(kc)   LT(_MOUSECURSOR, kc)        // L-ayer T-ap M-ouse C-ursor
#define ALT_TAB     M(KC_ALT_TAB)               // Macro for Alt-Tab
#define CMD_TAB     M(KC_CMD_TAB)               // Macro for Cmd-Tab
#define CMS_TAB     M(KC_CMS_TAB)
#define ALT_SPC     M(KC_ALT_SPC)
#define CTA_PIPE    M(KC_CTA_PIPE)
#define CTA_MINS    M(KC_CTA_MINS)


#define _USER 0 // User macro

; // This doesn't do anything. It's just for VSCode because its syntax highlighting is weird for the above #define statements.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Colemak
 *
 * ,-------------------------------------.                     ,----------------------------------.
 * |    Q    |   W  |   F  |   P  |   G  |                     |   J  |   L  |   U  |   Y  |   ;  |
 * +---------+------+------+------+------|                     +------+------+------+------+------|
 * |    A    |   R  |   S  |   T  |   D  |                     |   H  |   N  |   E  |   I  |   O  |
 * +---------+------+------+------+------|                     +------+------+------+------+------|
 * |Z Shft   |   X  |   C  |   V  |   B  | ,------.   ,------. |   K  |   M  |   ,  |   .  |/ Shft|
 * +---------+------+------+------+------| |      |   | Ctrl | | +------+------+------+------+------|
 * | Ctl/Esc |  Tab |  _TC | _CTL | Bksp | |  Gui |   | Enter| |  Spc |  _NU |  _MS |  Alt | _ADJ |
 * `-------------------------------------' `------'   `------' `----------------------------------'
 */
[_CO] = KEYMAP(
  KC_Q,          KC_W,   KC_F,    KC_P,     KC_G,                             KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN,
  KC_A,          KC_R,   KC_S,    KC_T,     KC_D,                             KC_H,   KC_N,    KC_E,    KC_I,    KC_O,
  SFT_T(KC_Z),   KC_X,   KC_C,    KC_V,     KC_B,                             KC_K,   KC_M,    KC_COMM, KC_DOT,  SFT_T(KC_SLSH),
  CTL_T(KC_ESC), KC_TAB, MO(_TC), MO(_CTL), KC_BSPC, CTL_T(KC_ENT), KC_LGUI,  KC_SPC, MO(_NU), MO(_MS), KC_LALT, MO(_ADJ)
),

/*
 * ,----------------------------------.                     ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |                     |   6  |   7  |   8  |   9  |  10  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |                     |   ^  |   &  |   *  |   (  |   )  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * | Tab  |   "  |   '  |   _  |   +  | ,------.   ,------. |   -  |   \  |   =  |   {  |   }  |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |      |   |      | |      |      |      |   [  |   ]  |
 * `----------------------------------' `------'   `------' `----------------------------------'
 */
[_NU] = KEYMAP( /* Extend */
  KC_1,    KC_2,       KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,       KC_0,
  KC_EXLM, KC_AT,      KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,    KC_RPRN,
  KC_TAB,  S(KC_QUOT), KC_QUOT, KC_UNDS, KC_PLUS,                   KC_MINS, KC_BSLS, KC_EQL,  S(KC_LBRC), S(KC_RBRC),
  _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC,    KC_RBRC
),

/*
 * Control Layer
 *
 * ,----------------------------------.                     ,------------------------------------.
 * |  ESC |      |      | CTL_P|      |                     | CTL_J| CTL_L| CTL_U|   |  |CTL_MINS|
 * +------+------+------+------+------|                     +------+------+------+------+--------|
 * | CTL_A| CTL_R|      |      | CTL_D|                     | CTL_H| CTL_N|      | CTL_I| CTL_O  |
 * +------+------+------+------+------|                     +------+------+------+------+--------|
 * | CTL_Z| CTL_X| CTL_C| CTL_V| CTL_B| ,------.   ,------. | CTL_K|      |      |      | Shift  |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+--------|
 * |      |      |      |      |      | |      |   |      | |      |      |      |      |        |
 * `----------------------------------' `------'   `------' `------------------------------------'
 */
[_CTL] = KEYMAP( 
  KC_ESC,  _______, _______, CTL_P,   _______,                   CTL_J,   CTL_L,   CTL_U,   KC_PIPE, CTA_MINS,
  CTL_A,   CTL_R,   _______, _______, CTL_D,                     CTL_H,   CTL_N,   _______, CTL_I,   CTL_O,
  CTL_Z,   CTL_X,   CTL_C,   CTL_V,   CTL_B,                     CTL_K,   _______, _______, _______, KC_LSFT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * Mouse
 *
 * ,----------------------------------.                     ,----------------------------------.
 * | Caps | Btn 1|  MUp | Btn 2|      |                     |      |      |      |      |   -  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * | Tab  | MLeft| MDown|MRight|      |                     |      |      |      |      |   "  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * | Shift|Whl Up|      |Whl Dn|      | ,------.   ,------. |      |      |      |      |   '  |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |      |   |      | |      |      |      |      |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */
[_MS] = KEYMAP( 
  KC_CAPS, KC_BTN1, KC_MS_U, KC_BTN2, _______,                   _______, _______, _______, _______, KC_MINS,
  KC_TAB,  KC_MS_L, KC_MS_D, KC_MS_R, _______,                   _______, _______, _______, _______, S(KC_QUOT),
  KC_LSFT, KC_WH_U, _______, KC_WH_D, _______,                   _______, _______, _______, _______, KC_QUOT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * TouchCursor
 *
 * ,-----------------------------------.                     ,----------------------------------.
 * |CmdTab |CMSTab|      |      |      |                     | Down | Right| PgDn |      |   -  |
 * +-------+------+------+------+------|                     +------+------+------+------+------|
 * |SCtlTab|CtlTab|      |      | PgDn |                     | Left |      |      |Insert|   "  | 
 * +-------+------+------+------+------|                     +------+------+------+------+------|
 * |Shift  |      |      |      |      | ,------.   ,------. |  Up  | HOME | End  |      |   '  |
 * +-------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |       |      |      |      |      | |      |   |      | |      |      |      |      |      |
 * `-----------------------------------' `------'   `------' `----------------------------------'
 *
 */
[_TC] = KEYMAP(
  CMD_TAB,   ALTSH_TAB, _______, _______, _______,                   KC_DOWN, KC_RGHT, KC_PGUP, _______, KC_MINS,
  SFCTL_TAB, LCTL_TAB,  _______, _______, KC_PGDN,                   KC_LEFT, _______, _______, KC_INS,  S(KC_QUOT),
  KC_LSFT,   _______,   _______, _______, _______,                   KC_UP,   KC_HOME, KC_END,  _______, KC_QUOT,
  _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * Adjust
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |                     | Mute |  F7  |  F8  |  F9  | F10  |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * | CAPS |  F11 |  F12 |      |      |                     | Vol ^|      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * | SHIFT|      |      |      |      | ,------.   ,------. | Vol v|      |      |      | RESET|
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |      |   |      | |      |      |      |      |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */
[_ADJ] = KEYMAP(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_MUTE,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_CAPS, KC_F11,  KC_F12,  _______, KC_F6,                     KC_VOLU, _______, _______, _______, _______,
  KC_LSFT, _______, _______, _______, _______,                   KC_VOLD, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};

/*
 * Template
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      | ,------.   ,------. |      |      |      |      |      |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |      |   |      | |      |      |      |      |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */

const uint16_t PROGMEM fn_actions[] = {

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case KC_ALT_TAB:
            return (record->event.pressed ? MACRO( D(LALT),  D(TAB), END ) : MACRO( U(TAB), END ));
        case KC_CMD_TAB:
            return (record->event.pressed ? MACRO( D(LGUI),  D(TAB), END ) : MACRO( U(TAB), END ));
        case KC_ALT_SPC:
            return (record->event.pressed ? MACRO( D(LALT),  D(SPC), END ) : MACRO( U(SPC), U(LALT), END ));
        case KC_CTA_MINS:
            return (record->event.pressed ? MACRO( D(LCTL),  D(A), U(LCTL), U(A), D(MINS), END ) : MACRO( U(MINS), END ));
      }
    return MACRO_NONE;
};
