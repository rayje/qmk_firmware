#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _MAC_QWERTY 1
#define _SYMB 2
#define _NAV 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MAC_QWERTY,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)
#define QWE_L   DF(_QWERTY)
#define MAC_L   DF(_MAC_QWERTY)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)
#define KC_CBSP LCTL_T(KC_BSPC)       // - Backspace / Left Ctrl
#define KC_NAES LT(_NAV, KC_ESC)        // - Escape / Left GUI
#define KC_NAAL LT(_NAV, KC_RALT)        // - Escape / Left ALT
#define KC_CTES LCTL_T(KC_ESC)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)
#define KC_NAT  LT(_NAV, KC_T)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define KC_GUTB LGUI(KC_TAB)
#define KC_SMQT LT(_SYMB, KC_QUOT)
#define KC_SMGR LT(_SYMB, KC_GRV)
#define KC_SMMI LT(_SYMB, KC_MINS)
#define KC_SHPR LSFT(KC_PSCR)
#define KC_ALEQ LALT_T(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                     ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NAGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                      KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_SMMI ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                   ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_PIPE ,                    KC_EQL  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CTES ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_COMM ,                    KC_BSLS ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_SMQT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐ ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,  KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RBRC ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤ ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_ALEQ ,KC_NAGR ,KC_LEFT ,KC_RIGHT,     KC_LGUI ,    KC_BSPC ,KC_LCTL ,  KC_ENT  ,KC_SPC  ,    KC_NAES ,     KC_UP   ,KC_DOWN ,KC_BSLS ,SYM_L 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘ └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_MAC_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                     ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NAGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                      KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_SMMI ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                   ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_PIPE ,                    KC_EQL  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CTES ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_COMM ,                    KC_BSLS ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_SMQT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐ ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,  KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RBRC ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤ ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_ALEQ ,KC_NAGR ,KC_LEFT ,KC_RIGHT,     KC_LCTL ,    KC_BSPC ,KC_LGUI ,  KC_ENT  ,KC_SPC  ,    KC_NAES ,     KC_UP   ,KC_DOWN ,KC_BSLS ,SYM_L 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘ └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                     ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                      KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                   ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,MAC_L   ,                    _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EQL  ,KC_PIPE ,KC_LBRC ,KC_RBRC ,KC_GRV  ,QWE_L   ,                    _______ ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐ ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_BSLS ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,  _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤ ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,  _______ ,_______ ,    KC_P0   ,     KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘ └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                     ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GUTB ,_______ ,_______ ,_______ ,KC_END  ,_______ ,                                      _______ ,_______ ,_______ ,_______ ,KC_HOME ,KC_SHPR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                   ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,_______ ,                    _______ ,KC_DOWN ,KC_RIGHT,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,_______ ,                    _______ ,KC_LEFT ,KC_VOLD ,KC_VOLU ,KC_MUTE ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐ ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,  _______ ,XXXXXXX ,KC_UP   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤ ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,_______ ,  _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘ └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                     ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                      KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                   ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                    RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN,RGB_M_K ,XXXXXXX ,                    XXXXXXX ,RGB_M_X ,RGB_M_G ,RGB_M_T ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐ ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,  XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤ ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,  XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘ └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  
};
