#include "keymap.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _TOUCHCURSOR 4
#define _MOUSECURSOR 5
#define _ADJUST 6

// Keycodes
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  GOODBYE,
  TSCALE,
  CLOSE_ENC,
};

enum macro_keycodes {
  KC_ALT_TAB,
  KC_CMD_TAB,
  KC_CMS_TAB,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define CTL_TAB     MT(MOD_LCTL, KC_TAB)               // Tap for Tab, hold for Ctrl
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-------------------------------------------------------------------------------------------.
 * | Esc      |  Q   |   W  |   E   |   R  |   T  |   Y  |   U   |   I   |   O  |   P  |   -   |
 * |----------+------+------+-------+------+-------------+-------+-------+------+------+-------|
 * | Ctrl/Tab |  A   |   S  | MC/D  |   F  |   G  |   H  |   J   |   K   |   L  |   ;  |   "   |
 * |----------+------+------+-------+------+------|------+-------+-------+------+------+-------|
 * | Shift    |  Z   |   X  |   C   |   V  |   B  |   N  |   M   |   ,   |   .  |   /  | Equal |
 * |----------+------+------+-------+------+------+------+-------+-------+------+------+-------|
 * | Tab      | LAlt | MO4  | Lower | Bksp | GUI  | Ent  | Space | Raise | Vol- | Vol+ |       |
 * `-------------------------------------------------------------------------------------------'
 */
[_QWERTY] = { /* Qwerty */
  {KC_ESC,    KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_MINS},
  {CTL_TAB,   KC_A,    KC_S, LT_MC(KC_D), KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT},
  {KC_LSFT,   KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_EQL },
  {KC_TAB,    KC_LGUI, MO(4), LOWER, KC_BSPC, KC_LALT, KC_ENT,   LT_TC,    RAISE,   KC_VOLD,  KC_VOLU,     MO(6)}
},
/* Colemak
 * ,----------------------------------------------------------------------------------------.
 * | Esc   |   Q  |   W  |   F   |   P  |   G  |   J  |   L   |   U   |   Y  |   ;  |   -   |
 * |-------+------+------+-------+------+-------------+-------+-------+------+------+-------|
 * | Ctrl  |   A  |   R  | MC/S  |   T  |   D  |   H  |   N   |   E   |   I  |   O  |   "   |
 * |-------+------+------+-------+------+------|------+-------+-------+------+------+-------|
 * | Shift |   Z  |   X  |   C   |   V  |   B  |   K  |   M   |   ,   |   .  |   /  | Equal |
 * |-------+------+------+-------+------+------+------+-------+-------+------+------+-------|
 * | Tab   | LAlt |      | Lower | Bksp | GUI  | Ent  | Space | Raise | Vol- | Vol+ |       |
 * `----------------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {HPR_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS},
  {CTL_TAB, KC_A,    KC_R, LT_MC(KC_S),KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT},
  {KC_TAB,  KC_LGUI, MO(4),  LOWER, KC_BSPC, KC_LALT,  KC_ENT,   LT_TC,    RAISE,   KC_VOLD, KC_VOLU, KC_TRNS}
},
/* Lower
 * ,------------------------------------------------------------------------------------.
 * | TAB  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp  |
 * |------+------+------+------+------+-------------+------+------+------+------+-------|
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |   |   |
 * |------+------+------+------+------+------|------+------+------+------+------+-------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   -  |   =  |      |  Up  |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * |      |      |      |      |      |             |      |      | Left | Down | Right |
 * `------------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS},
  {KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MINS, KC_EQL,  _______, KC_UP,   KC_BSLS},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT}
},
/* Raise
 * ,------------------------------------------------------------------------------------.
 * |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp  |
 * |------+------+------+------+------+-------------+------+------+------+------+-------|
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |   |   |
 * |------+------+------+------+------+------|------+------+------+------+------+-------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   -  |   =  |      |  Up  |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * |      |      |      |      |      |             |      |      | Left | Down | Right |
 * `------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_TAB,    KC_1,   KC_2,  KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,       S(KC_MINS)},
  {KC_GRV,    KC_F1,  KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, S(KC_LBRC), S(KC_RBRC), KC_PIPE},
  {_______,   KC_F7,  KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MINS, KC_EQL,  _______,    KC_UP,      KC_BSLS},
  {_______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,    KC_RIGHT}
},
/* TouchCursor layer (http://martin-stone.github.io/touchcursor/) plus personal customizations
 * ,-----------------------------------------------------------------------------------.
 * |AltTab|CmdTab|CtlTab| GUI  |Shift |  ~   |Insert| Home |  Up  | End  | Bksp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Alt  |Space |Tab_C | Find |Again | PgUp | Left | Down |Right |Desk_L|Desk_R|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy |Paste |  `   | PgDn | Del  |Tab_N |Tab_R |iTerm2|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 * The KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_FIND, and KC_AGAIN keycodes don't
 * seem to work on Mac. Presumably they'll work under Windows.
 */

[_TOUCHCURSOR] = {
  {CMD_TAB, CMS_TAB, CTL_TAB, KC_LGUI, KC_LSFT, KC_TILD,  KC_INS, KC_HOME,   KC_UP,  KC_END, KC_BSPC, _______},
  {_______, KC_LALT, KC_SPC,  _______, _______,_______,  KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______},
  {_______, _______, _______,  _______, _______,KC_GRV,  KC_PGDN,  KC_DEL, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Mouse Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |ACCL0 |      |      |      |      |WHL_L |  Up  |WHL_R | BTN2 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |ACCL2 | BTN2 |      | BTN1 |ACCL1 |WHL_Up| Left | Down |Right | BTN4 | BTN5 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | BTN3 |      |WHL_Dn| BTN1 |      |      | BTN3 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_MOUSECURSOR] = {
  {_______, _______, KC_ACL0, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN2, _______},
  {_______, KC_ACL2, KC_BTN2, _______, KC_BTN1, KC_ACL1, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, KC_BTN5},
  {_______, _______, _______, _______, KC_BTN3, _______, KC_WH_D, KC_BTN1, _______, _______, KC_BTN3, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, GOODBYE, TSCALE,  CLOSE_ENC},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______,   RESET},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}
};

#ifdef AUDIO_ENABLE

float tone_startup[][2] = SONG(STARTUP_SOUND);
float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
float tone_colemak[][2] = SONG(COLEMAK_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float close_encounters[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case TSCALE:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(music_scale, false, 0);
        #endif
      }
      return false;
      break;
    case GOODBYE:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
        #endif
      }
      return false;
      break;
    case CLOSE_ENC:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(close_encounters, false, 0);
        #endif
      }
      return false;
      break;
  }
  return true;
}

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
      case KC_ALT_TAB:
        return (record->event.pressed ? MACRO( D(LALT),  D(TAB), END ) : MACRO( U(TAB), END ));
      case KC_CMD_TAB:
        return (record->event.pressed ? MACRO( D(LGUI),  D(TAB), END ) : MACRO( U(TAB), END ));
    }

    return MACRO_NONE;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
