/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

// #include "keycodes.h" // Remove this before compiling
// #include "quantum_keycodes.h"
#include "gpio.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h" //Force load combos.def

#define CAPSLOCK_LED A3


enum layers{
    BASE,
    BASE_QWERTY,
    BASE_GAMING,
    BASE_PROGRAMMING,
    NAV,
    FN,
};

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        writePin(CAPSLOCK_LED, 1);
    } else {
        // Do something when Caps Word deactivates.
        writePin(CAPSLOCK_LED, 0);
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // check if layer masked on top of base layer is gaming. Disable combos if so
    if (layer_state_cmp(default_layer_state|layer_state,BASE_GAMING)) {
        return false;
    }
    /* Disable combos on layer `NAV` */
    // switch (combo_index) {
        // case HOME:
        // case NEXT_WORD:
        // case PREV_WORD:
        // case END:
            // if (!layer_state_is(3)) {
                // return false;
            // }}

    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_tkl_ansi(
        KC_ESC,                        KC_F1,        KC_F2,        KC_F3,        KC_F4,    KC_F5,    KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,   KC_F11,      KC_F12,                KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,          KC_1,         KC_2,         KC_3,         KC_4,         KC_5,     KC_6,     KC_7,         KC_8,         KC_9,         KC_0,         KC_MINS,  KC_EQL,      KC_BSPC,               KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,          KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,     KC_J,     KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_LBRC,  KC_RBRC,     KC_BSLS,               KC_DEL,   KC_END,   KC_PGDN,
        MO(NAV),   LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,     KC_M,     RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O), KC_QUOT,               RSFT_T(KC_ENT),
        KC_LSFT,                       KC_X,         KC_C,         KC_D,         KC_V,     KC_Z,     KC_K,         KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,               KC_RSFT,                         KC_UP,
        KC_LCTL,         KC_LWIN,      KC_LALT,                                            LT(BASE_PROGRAMMING,KC_SPC),                         KC_RALT,      MO(FN),   KC_LWIN,     KC_RCTL,              KC_LEFT,  KC_DOWN,  KC_RGHT),

    [BASE_QWERTY] = LAYOUT_tkl_ansi(
        _______,             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,    _______,  _______,  _______,  _______,
        _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,    _______,  _______,  _______,  _______,
        _______,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  _______,           _______,    _______,  _______,  _______,  _______,
        _______,   LGUI_T(KC_A),     LALT_T(KC_S),     LSFT_T(KC_D),     LCTL_T(KC_F),     KC_G,   KC_H,   RCTL_T(KC_J),     RSFT_T(KC_K),     LALT_T(KC_L),     RGUI_T(KC_SCLN),     _______,                       _______,
        _______,             KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                       _______,            _______,
        _______,   _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [BASE_GAMING] = LAYOUT_tkl_ansi(
        _______,             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,    _______,  _______,  _______,  _______,
        _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,    _______,  _______,  _______,  _______,
        _______,   KC_ESC, KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  _______,           _______,    _______,  _______,  _______,
        _______,   KC_LSFT, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,   KC_H,   KC_J,     KC_K,     KC_L,     KC_SCLN,     _______,
        _______,             KC_LCTL, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                       _______,
        _______,   _______,  _______,                                KC_SPC,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [BASE_PROGRAMMING] = LAYOUT_tkl_ansi(
        _______,             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,    _______,  _______,  _______,  _______,
        _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,    _______,  _______,  _______,  _______,
        _______,   LSFT_T(KC_1),     LSFT_T(KC_2),     LSFT_T(KC_3),     LSFT_T(KC_4),     LSFT_T(KC_5),     LSFT_T(KC_GRV),  LSFT_T(KC_QUOT),  LSFT_T(KC_COMM),     LSFT_T(KC_DOT),    LSFT_T(KC_NUBS),  _______,           _______,    _______,  _______,  _______,  _______,
        _______,   LGUI_T(KC_6),     LALT_T(KC_7),     LSFT_T(KC_8),     LCTL_T(KC_9),     KC_0,             KC_LBRC,         RCTL_T(KC_RBRC),  RSFT_T(KC_MINS),     LALT_T(KC_EQL),    RGUI_T(KC_SCLN),     LSFT_T(KC_GRV),                       _______,
        _______,   LSFT_T(KC_DOT),   LSFT_T(KC_MINS),  LSFT_T(KC_PPLS),  LSFT_T(KC_PAST),  LSFT_T(KC_GRV),  LSFT_T(KC_SLSH),  LSFT_T(KC_QUOT),  LSFT_T(KC_COMM),     LSFT_T(KC_DOT),    LSFT_T(KC_SLSH),                       _______,            _______,
        _______,   _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______
    ),

    [NAV] = LAYOUT_tkl_ansi(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  KC_HOME,  KC_UP,    KC_END,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [FN] = LAYOUT_tkl_ansi(
        _______,            KC_BRID,  KC_BRIU,  _______,  _______,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  DF(BASE_GAMING),  DF(BASE_QWERTY),  DF(BASE),
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

};
