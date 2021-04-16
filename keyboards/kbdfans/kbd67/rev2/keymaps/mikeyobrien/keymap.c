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

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// tap dance enums
enum {
    X_CTL
};

enum combo_events {
    ZC_TEST
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM test_combo[] = {KC_LCTL, KC_AMPR, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [ZC_TEST] = COMBO_ACTION(test_combo),
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
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC, MO(5),  \
  LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,    MO(4), \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   OSL(3), \
  OSL(4), KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RALT, KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RGHT),

/* Programmer Dvorak Layer */
[1] = LAYOUT_65_ansi_blocker_splitbs(
  KC_ESC, KC_AMPR, KC_LBRC, KC_LCBR, KC_LPRN, KC_EQL, KC_ASTR, KC_RPRN, KC_RCBR, KC_RBRC, KC_EXLM, KC_HASH, KC_PLUS, KC_BSLS, KC_DLR, KC_HOME, \
  KC_TAB, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_AT, KC_BSPC, MO(5), \
  LCTL_T(KC_ESC), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT, MO(4), \
  MO(2), KC_QUOT, KC_Q, KC_J, KC_K, TD(X_CTL), KC_B, KC_M, KC_W, KC_V, KC_Z, MO(2), KC_UP, OSL(3), \
  OSL(4), KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

/* Programmer Dvorak Shift Layer */
[2] = LAYOUT_65_ansi_blocker_splitbs(
  KC_ESC, KC_9, KC_7, KC_5, KC_3, KC_1, KC_0, KC_2, KC_4, KC_6, KC_8, KC_GRV, KC_PERC, KC_PIPE, KC_TILD, KC_HOME,\
  KC_TAB, KC_COLN, KC_LT, KC_GT, S(KC_P), S(KC_Y), S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), KC_QUES, KC_CIRC, KC_BSPC, KC_PGUP, \
  KC_LCTL, S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), KC_UNDS, KC_ENT, KC_PGDN, \
  KC_TRNS, KC_DQUO, S(KC_Q), S(KC_J), S(KC_K), S(KC_X), S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), MO(2), KC_UP, MO(3), \
  KC_TRNS, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

/* Fn Layer */
[3] = LAYOUT_65_ansi_blocker_splitbs(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,  KC_INS,  \
  KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
  KC_LCTL, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, \
  KC_LSFT, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_PGUP, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_0,                            KC_TRNS, KC_TRNS,                   KC_HOME, KC_PGDN, KC_END),

/* Emacs layer */
[4] = LAYOUT_65_ansi_blocker_splitbs(
  KC_GRV, C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5), C(KC_6), C(KC_7), C(KC_8), C(KC_9), KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL, KC_INS,  \
  KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
  KC_LCTL, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, \
  KC_LSFT, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_PGUP, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_0,                            KC_TRNS, KC_TRNS,                   KC_HOME, KC_PGDN, KC_END),

[5] = LAYOUT_65_ansi_blocker_splitbs(
  KC_GRV,  DF(0),   DF(1),   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,  KC_INS,  \
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
        SEND_STRING("&");
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

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case ZC_TEST:
            if (pressed) {
                tap_code16(LCTL(KC_1));
            }
            break;
    }
}

 td_state_t cur_dance(qk_tap_dance_state_t *state) {
     if (state->count == 1) {
         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
         else return TD_SINGLE_HOLD;
     } else if (state->count == 2) {
         if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
         else if (state->pressed) return TD_DOUBLE_HOLD;
         else return TD_DOUBLE_TAP;
     }

     if (state->count == 3) {
         if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
         else return TD_TRIPLE_HOLD;
     } else return TD_UNKNOWN;
 }

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_X); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTRL); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
        default:
            break;
    }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_X); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTRL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT);
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X);
        default:
            break;
    }
    xtap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [X_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};


