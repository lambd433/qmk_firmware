/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

#define DRS1 DYN_REC_START1
#define DRS2 DYN_REC_START2
#define DMP1 DYN_MACRO_PLAY1
#define DMP2 DYN_NACRO_PLAY2
#define DRS DYN_REC_STOP

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BKSPC |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CTL  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |CTL/" |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SFT( |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | SFT) |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |GUI/ES|  FN  |  ESC | ALT  |LOWER | SPC  | ENT  |RAISE | ALT  |  APP |  FN  | GUI  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,          KC_Q,     KC_W,    KC_E,              KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,             KC_O,    KC_P,    KC_BSPC},
  {KC_LCTL,         KC_A,     KC_S,    KC_D,              KC_F,    KC_G,    KC_H,    KC_J,    KC_K,             KC_L,    KC_SCLN, RCTL_T(KC_QUOT)},
  {SC_LSPO,         KC_Z,     KC_X,    KC_C,              KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,          KC_DOT,  KC_SLSH, SC_RSPC},
  {LGUI_T(KC_ESC), FUNCTION,  QK_GESC	,LALT_T(KC_LANG2),  LOWER,   KC_SPC,  KC_ENT,  RAISE,   RALT_T(KC_LANG1), KC_APP, FUNCTION,KC_RGUI}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  M1  | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {QK_GESC,  DMP1,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  M1  | Alt  | GUI  |Lower | Space|Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {QK_GESC,  DMP1,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |      |      | LEFT | DOWN |  UP  | RIGHT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | PRSC |  INS | DRS1 | DRS  | DMP1 |      | HOME | PGDN | PGUP | END  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTON] = {
  {_______, KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,      KC_F8,    KC_F9,    KC_F10,   _______},
  {_______, KC_F11,  KC_F12,  KC_F13,   KC_F14,   _______,  _______, KC_LEFT,    KC_DOWN,  KC_UP,    KC_RIGHT, _______}
  {_______, KC_PSCR, KC_INS,  DRS1,     DRS,      DMP1,     _______, KC_HOME,    KC_PGDN,  KC_PGUP,  KC_END,   _______}
  {_______, _______, _______, _______,  _______,  _______,  _______, _______,    _______,  _______,  _______,  _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  ~   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  | CTL/||
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_GRAVE,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,    KC_ASTR,  KC_LPRN, KC_RPRN, KC_TILD},
  {_______,   _______,  _______,  _______,  _______,  _______,  _______,  KC_MINS,    KC_EQL,   KC_LCBR, KC_RCBR, KC_PIPE},
  {_______,   _______,  _______,  _______,  _______,  _______,  _______,  KC_UNDS,    KC_PLUS,  KC_LBRC, KC_RBRC, RCTL_T(KC_PIPE)},
  {_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______},
  {_______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______},
  {_______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |RESET |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TERMON|TERMOF|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {QWERTY,  RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,   RGB_VAI,  RGB_VAD,  _______},
  {COLEMAK, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,   _______,  _______,  _______},
  {DVORAK,  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF,  _______,  _______,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,  _______,  _______}
}
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
    return false;
    }
    
    switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case FUNCTION:
      layer_on(_FUNCTION);
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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
