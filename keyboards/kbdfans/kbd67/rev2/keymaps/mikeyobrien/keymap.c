/* Copyright 2018 'mechmerlin'
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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) QWERTY Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  Bk  |PgUp|
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[0] = LAYOUT_65_ansi_blocker_splitbs(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV, KC_HOME,  \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC, KC_PGUP,   \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   MO(3), \
  MO(3), KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RALT, KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RGHT),

/* Programmer Dvorak Layer */
[1] = LAYOUT_65_ansi_blocker_splitbs(
  KC_ESC, S(KC_7), KC_LBRC, S(KC_LBRC), S(KC_9), KC_EQL, S(KC_8), S(KC_0), S(KC_RBRC), KC_RBRC, S(KC_1), S(KC_3), S(KC_EQL), KC_GRV, KC_HOME, \
  KC_TAB, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, S(KC_2), KC_BSLS, KC_BSPC, KC_PGUP, \
  KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT, KC_PGDN, \
  MO(2), KC_QUOT, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, MO(2), KC_UP, MO(3), \
  MO(3), KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT),


/* Programmer Dvorak Shift Layer */
[2] = LAYOUT_65_ansi_blocker_splitbs(
  KC_ESC, S(KC_7), KC_LBRC, S(KC_LBRC), S(KC_9), KC_EQL, S(KC_8), S(KC_0), S(KC_RBRC), KC_RBRC, S(KC_1), S(KC_3), S(KC_EQL), KC_GRV, KC_HOME, \
  KC_TAB, S(KC_SCLN), S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y), S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), S(KC_SLSH), S(KC_2), KC_BSLS, KC_BSPC, KC_PGUP, \
  KC_LCTL, S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), S(KC_MINS), KC_ENT, KC_PGDN, \
  KC_TRNS, S(KC_QUOT), S(KC_Q), S(KC_J), S(KC_K), S(KC_X), S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), MO(2), KC_UP, MO(3), \
  KC_TRNS, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

/* Fn Layer */
[3] = LAYOUT_65_ansi_blocker_splitbs(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,  KC_INS,  \
  KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
  KC_LCTL, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, \
  KC_LSFT, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_PGUP, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_0,                            KC_TRNS, KC_TRNS,                   KC_HOME, KC_PGDN, KC_END),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}
