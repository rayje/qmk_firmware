// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _COLEMAK 1
#define _NAV 2
#define _ADJUST 3
#define _RESET 4

#define KC_ADJ  MO(_ADJUST)
#define KC_CTES LCTL_T(KC_ESC)
#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAES LT(_NAV, KC_ESC)
#define KC_SHPR LSFT(KC_PSCR)
#define KC_SHIN LSFT(KC_INS)
#define KC_CTPR LCTL(KC_PSCR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* qwerty */
        { KC_NAES, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS },
        { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC },
        { KC_CTES, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TRNS,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT },
        { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC },
        { KC_EQL,  KC_NAGR, KC_LALT, KC_LEFT, KC_RGHT, KC_BSPC, KC_ENT,  KC_SPC, KC_UP, KC_DOWN, KC_BSLS, KC_ENT,  KC_ADJ  }
},

[_COLEMAK] = { /* colemak */
        { KC_NAES, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS },
        { KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_TRNS,  KC_J,  KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_LBRC },
        { KC_CTES, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_TRNS,  KC_H,  KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT },
        { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,  KC_K,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC },
        { KC_EQL,  KC_NAGR, KC_LALT, KC_LEFT, KC_RGHT, KC_BSPC, KC_ENT,  KC_SPC, KC_UP, KC_DOWN, KC_BSLS, KC_ENT,  KC_ADJ  }
},

[_NAV] = { 
        { TO(_DEFAULT), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
        { TO(_COLEMAK),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_RGHT, KC_BSLS, KC_TRNS, KC_TRNS, KC_BSLS },
        { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_HOME, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS },
        { TO(_RESET),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
        { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_ADJUST] = {
        { TO(_DEFAULT), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_SHPR },
        { TO(_COLEMAK),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CTPR },
        { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD ,KC_VOLU ,KC_MUTE, KC_TRNS, KC_SHIN },
        { TO(_RESET),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
        { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_RESET] = {
        { TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
        { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
        { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
        { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET   },
        { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO }
}


/*
[_TRNS] = {
        { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
        { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
        { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
        { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
        { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};



const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch (id) {
    case 0:
        if (record->event.pressed) {
            register_code(KC_RSFT);
        }
        else {
            unregister_code(KC_RSFT);
        }
        break;
    }
    return MACRO_NONE;
};
