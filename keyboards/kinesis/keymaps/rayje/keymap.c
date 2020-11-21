#include QMK_KEYBOARD_H

/* #define QWERTY 0 // Base qwerty */
/* #define _ADJUST 1 */

enum layer_names {
    _QWERTY,
    _ADJUST,
};


#define KC_ADJ  MO(_ADJUST)
#define KC_CTES LCTL_T(KC_ESC)
#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAES LT(_NAV, KC_ESC)
#define KC_SHPR LSFT(KC_PSCR)
#define KC_SHIN LSFT(KC_INS)
#define KC_CTPR LCTL(KC_PSCR)


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
           // Left Hand
           KC_ESC,  KC_F1  ,KC_F2  ,KC_F3  , KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL,  KC_1   ,KC_2   ,KC_3   , KC_4   ,KC_5   ,
           KC_TAB,  KC_Q   ,KC_W   ,KC_E   , KC_R   ,KC_T   ,
           KC_CTES, KC_A   ,KC_S   ,KC_D   , KC_F   ,KC_G   ,
           KC_LSFT, KC_Z   ,KC_X   ,KC_C   , KC_V   ,KC_B   ,
                    KC_GRV ,KC_INS ,KC_LEFT, KC_RGHT,
           // Left Thumb
                    KC_LGUI, KC_LALT,
                             KC_ADJ,
           KC_BSPC,  KC_DEL, KC_RCTL,
 
           // Right Hand
           KC_F9  ,KC_F10 ,KC_F11 , KC_F12 , KC_PSCR, KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
           KC_6   ,KC_7   ,KC_8   , KC_9   , KC_0   , KC_MINS,
           KC_Y   ,KC_U   ,KC_I   , KC_O   , KC_P   , KC_BSLS,
           KC_H   ,KC_J   ,KC_K   , KC_L   , KC_SCLN, KC_QUOT,
           KC_N   ,KC_M   ,KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                   KC_UP  ,KC_DOWN, KC_LBRC, KC_RBRC,
           // Right Thumb
           KC_RGUI, KC_RCTL,
           KC_ADJ, 
           KC_PGDN, KC_ENTER, KC_SPC
    ),

[_ADJUST] = LAYOUT(
           // Left Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
           _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,
           // Left Thumb
                    _______, _______,
                             _______,
           _______, _______, _______,

           // Right Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,
           // Right Thumb
           _______, _______,
           _______,
           _______, _______, _______
    )
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
