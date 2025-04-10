#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
//#include "config.h"

#define BASE 0 // default layer
#define DVRK 1 // dvorak
#define CLMK 2 // colemak
#define MDIA 3 // symbols
#define SYMB 4 // media
#define LAYR 5 // dvorak

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

enum {
  TD_LBRC_RBRC,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Escape, twice for Caps Lock
  [TD_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | GrvESC |   1  |   2  |   3  |   4  |   5  | Muhen|           | Henka|   6  |   7  |   8  |   9  |   0  |  BS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  | LANG |           | LANG |   Y  |   U  |   I  |   O  |   P  |\ / RAlt|
 * |--------+------+------+------+------+------|   2  |           |   1  |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |' /RCtrl|
 * |--------+------+------+------+------+------| Shift|           |  Tab |------+------+------+------+------+--------|
 * | LShift(|   Z  |   X  |   C  |   V  |   B  |  Tab |           |      |   N  |   M  |   ,  |   .  |   /  | RShift)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt | [/] | LAYR | LGUI |=/MDIA|                                       |-/SYM| LEFT | DOWN |  UP  | RGHT |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  APP | PSCR |       | INS  |  DEL |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 |LCtrl | SPC  |------|       |------|Back  |Enter |
 *                                 |      |      | End  |       | PgDn |Space |      |
 *                                 `--------------------'       `--------------------'
 */ 
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GESC,                KC_1,                 KC_2,           KC_3,    KC_4,   KC_5,   KC_INT5,
        KC_TAB,                 KC_Q,                 KC_W,           KC_E,    KC_R,   KC_T,   KC_LNG2,
        KC_LCTL,                KC_A,                 KC_S,           KC_D,    KC_F,   KC_G,
        KC_LSPO,                KC_Z,                 KC_X,           KC_C,    KC_V,   KC_B,   LSFT(KC_TAB),
        KC_LALT,                TD_LBRC_RBRC,         MO(LAYR),       KC_LGUI, LT(MDIA, KC_NONE),
                                KC_APP,               KC_PSCR,
                                                      KC_HOME,
        KC_LCTL,                KC_SPC,               KC_END,

        // right hand
          KC_INT4	,             KC_6,   KC_7,    KC_8,    KC_9,           KC_0,             KC_BSPC,
          KC_LNG1,              KC_Y,   KC_U,    KC_I,    KC_O,           KC_P,             RALT_T(KC_BSLS, KC_QUOT),
                                KC_H,   KC_J,    KC_K,    KC_L,           KC_SCLN,          RCTL_T(KC_QUOT),
          KC_TAB,               KC_N,   KC_M,    KC_COMM, KC_DOT,         KC_SLSH,          KC_RSPO,
                       LT(SYMB, KC_MINS),        KC_LEFT, KC_DOWN,        KC_UP,            KC_RGHT,
          KC_INS,               KC_DEL, 
          KC_PGUP,
          KC_PGDN,              KC_BSPC,KC_ENT
    ),
/* Keymap 1: DVORAK
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  '   |  ,   |  .   |  P   |  Y   |      |           |      |  F   |  G   |  C   |  R   |  L   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  A   |  O   |  E   |  U   |  I   |------|           |------|  D   |  H   |  T   |  N   |  S   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ;   |  Q   |  J   |  K   |  X   |      |           |      |  B   |  M   |  W   |  V   |  Z   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// DVRK
[DVRK] = LAYOUT_ergodox(
      // left hand
      KC_TRNS,           KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,           KC_QUOT,     KC_COMM,    KC_DOT,       KC_P,    KC_Y,    KC_TRNS,
      KC_TRNS,           KC_A,        KC_O,       KC_E,         KC_U,    KC_I,
      KC_TRNS,           KC_SCLN,     KC_Q,       KC_J,         KC_K,    KC_X,    KC_TRNS,
      KC_TRNS,           KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,
      
      // left thumb cluster
                KC_TRNS,      KC_TRNS,
                              KC_TRNS,
       KC_TRNS, KC_TRNS,      KC_TRNS,
      
      // right hand
      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_TRNS,
                   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_TRNS,
      KC_TRNS,     KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_TRNS,
      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    
      // right thumb cluster
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: COLEMAK
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  '   |  ,   |  .   |  P   |  Y   |      |           |      |  F   |  G   |  C   |  R   |  L   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  A   |  O   |  E   |  U   |  I   |------|           |------|  D   |  H   |  T   |  N   |  S   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ;   |  Q   |  J   |  K   |  X   |      |           |      |  B   |  M   |  W   |  V   |  Z   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// COLEMAK
[CLMK] = LAYOUT_ergodox(
      // left hand
      KC_TRNS,           KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,           KC_Q,        KC_W,       KC_F,         KC_P,    KC_G,    KC_TRNS,
      KC_TRNS,           KC_A,        KC_R,       KC_S,         KC_T,    KC_D,
      KC_TRNS,           KC_Z,        KC_X,       KC_C,         KC_V,    KC_B,    KC_TRNS,
      KC_TRNS,           KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,
      
      // left thumb cluster
                KC_TRNS,      KC_TRNS,
                              KC_TRNS,
       KC_TRNS, KC_TRNS,      KC_TRNS,
      
      // right hand
      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
                   KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS,
      KC_TRNS,     KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    
      // right thumb cluster
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 5: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | RSTP |           | RSTP |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      | MREC |           | MREC |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|   1  |           |  2   |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------| HOME |PgDown| PgUp | END  |      |  Play  |
 * |--------+------+------+------+------+------| MPLY |           | MPLY |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |  1   |           |  2   |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Lclk | Rclk |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_RSTP,
  KC_TRNS,  KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, DM_REC1,
  KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_PLY1,
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                KC_TRNS, KC_TRNS, 
                                                         KC_TRNS,
                                       KC_BTN1, KC_BTN2, KC_TRNS,
  // right hand
  DM_RSTP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_MPLY,
  DM_PLY2, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 6: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      | HOME |PgDown| PgUp | END  |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| LEFT | DOWN |  UP  | RIGHT|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      | HOME |PgDown| PgUp | END  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_F12,
           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 7:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  RESET | DVRAK| CLMK |      |      | MDIA |      |           |      |  SYM |      |      |      | BASE |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  EPRM  |      |      |      |      |      |!Auto |           | Auto |      |      |      |      |      |        |
 * |--------+------+------+------+------+------| Shift|           | Shift|------+------+------+------+------+--------|
 * | Version|      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |  RPT |           |    inn  |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// layer-choosing layser
[LAYR] = LAYOUT_ergodox(
      // left hand
      QK_BOOT,           TO(DVRK),    TO(CLMK),   KC_TRNS,      KC_TRNS, TO(MDIA),KC_TRNS,
      EPRM,              KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, AS_OFF,
      VRSN,              KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS,
      KC_TRNS,           KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, AS_RPT,
      KC_TRNS,           KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,
      
      // left thumb cluster
                KC_TRNS,      KC_TRNS,
                              KC_TRNS,
       KC_TRNS, KC_TRNS,      KC_TRNS,
      
      // right hand
      KC_TRNS,     TO(SYMB),   KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(BASE),   KC_TRNS,
      AS_ON,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
      KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
      KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    
      // right thumb cluster
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.

layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
//          rgblight_init();
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};