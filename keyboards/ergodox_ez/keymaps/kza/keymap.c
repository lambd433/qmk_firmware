#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define DVRK 1 // dvorak
#define SYMB 2 // symbols
#define GAME 3 // game

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Grv   |   1  |   2  |   3  |   4  |   5  | ESC  |           | DEL  |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |  (   |           |   )  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * |MHen/SFT|Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |Hen/SFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Meh  |  L0  |AltTab| LAlt | LGui |                                       | RGui |   -  |  L3  |  L1  |\ / L2|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LEFT | RGHT |       | DOWN |  UP  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space |Back  |------|       |------|Back    |Enter |
 *                                 |      |Space | End  |       | PgDn |Space   |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,                 KC_1,                 KC_2,           KC_3,    KC_4,   KC_5,   KC_ESC,
        KC_TAB,                 KC_Q,                 KC_W,           KC_E,    KC_R,   KC_T,   S(KC_9),
        KC_LCTL,                KC_A,                 KC_S,           KC_D,    KC_F,   KC_G,
        LSFT_T(KC_MHEN),        LCTL_T(KC_Z),         KC_X,           KC_C,    KC_V,   KC_B,   KC_LBRC,
        KC_MEH,                 TO(BASE),             LALT(KC_TAB),   KC_LALT, KC_LGUI,
                                                      KC_LEFT, KC_RGHT,
                                                      KC_HOME,
                                                      KC_SPC, KC_LSFT, KC_END,
        // right hand
             KC_DELT,     KC_6,   KC_7,    KC_8,    KC_9,           KC_0,             KC_MINS,
             S(KC_0),     KC_Y,   KC_U,    KC_I,    KC_O,           KC_P,             KC_BSLS,
                          KC_H,   KC_J,    KC_K,    KC_L,           KC_SCLN,          GUI_T(KC_QUOT),
             KC_RBRC,     KC_N,   KC_M,    KC_COMM, KC_DOT,         KC_SLSH,          RSFT_T(KC_HENK),
                                  KC_RGUI, KC_MINS, TO(GAME),       TG(DVRK),         LT(SYMB, KC_BSLS),
             KC_DOWN, KC_UP, 
             KC_PGUP,
             KC_PGDN, KC_BSPC, KC_ENT
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
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  | MsUp |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |MsLeft|MsDown|MsRght|   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   .  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       | BTN1 | BTN2 | BTN3 |   =  | Reset|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |      |      |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_MS_U, KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_MS_L,KC_MS_D, KC_MS_R, KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_DOT, KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_BTN1,KC_BTN2, KC_BTN3, KC_EQL,  RESET,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Game layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |  =   |           | Del  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |  L0  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L3|' / Cmd |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  L2  |AltShf| LGui | LAlt |                                       | LEFT | DOWN |  UP  |RIGHT | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | RGHT |       | DOWN |  UP  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space |Backsp|------|       |------|Back    |Enter |
 *                                 |      |ace   | End  |       | PgDn |space   |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[GAME] = LAYOUT_ergodox(  // layer 3 : game
        // left hand
        KC_ESC,                 KC_1,         KC_2,           KC_3,    KC_4,   KC_5,   KC_EQL,
        KC_TAB,                 KC_Q,         KC_W,           KC_E,    KC_R,   KC_T,   TO(BASE),
        KC_LCTL,                KC_A,         KC_S,           KC_D,    KC_F,   KC_G,
        KC_LSFT,                KC_Z,         KC_X,           KC_C,    KC_V,   KC_B,   KC_LBRC,
        LT(SYMB,KC_GRV),        TG(DVRK),     LALT(KC_TAB),   KC_LGUI, KC_LALT,
                                              KC_APP, KC_LGUI,
                                                       KC_HOME,
                                KC_SPC, KC_BSPC, KC_END,
        // right hand
             KC_DELT,      KC_6,   KC_7,    KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),     KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,             KC_BSLS,
                           KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_RBRC,      KC_N,   KC_M,    KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                           KC_LEFT,KC_DOWN, KC_UP,  KC_RGHT, KC_FN1,
             KC_RALT, RCTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN, KC_BSPC, KC_ENT
                          )
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

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
uint32_t layer_state_set_user(uint32_t state) {
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
          rgblight_init();
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
