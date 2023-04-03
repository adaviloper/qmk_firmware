/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "adaviloper.h"

enum ferris_keycodes {
    KC_MAKE = PERSONAL_SAFE_RANGE,
};

#define LAYOUT_ferris_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_ferris_base_mac( \
        k00, k01, k02, k03, k04,            k07, k08, k09, k0a, k0b, \
        k10, k11, k12, k13, k14,            k17, k18, k19, k1a, k1b, \
        k20, k21, k22, k23, k24,            k27, k28, k29, k2a, k2b, \
                       k33, k34, k35,  k36, k37, k38 \
    ) \
    LAYOUT_ferris_wrapper( \
        k00, k01, k02, k03, k04,            k07, k08, k09, k0a, k0b, \
        SFT_T(k10), GUI_T(k11), CTL_T(k12), ALT_T(k13), LT(_GIT, k14),   LT(_GIT, k17), ALT_T(k18), CTL_T(k19), GUI_T(k1a), SFT_T(k1b), \
        k20, k21, k22, k23, k24,            k27, k28, k29, k2a, k2b, \
                       k33, k34, k35,  k36, k37, k38 \
    )
#define LAYOUT_ferris_base_win( \
        k00, k01, k02, k03, k04,            k07, k08, k09, k0a, k0b, \
        k10, k11, k12, k13, k14,            k17, k18, k19, k1a, k1b, \
        k20, k21, k22, k23, k24,            k27, k28, k29, k2a, k2b, \
                       k33, k34, k35,  k36, k37, k38 \
    ) \
    LAYOUT_ferris_wrapper( \
        k00, k01, k02, k03, k04,            k07, k08, k09, k0a, k0b, \
        SFT_T(k10), CTL_T(k11), GUI_T(k12), ALT_T(k13), LT(_GIT, k14),   LT(_GIT, k17), ALT_T(k18), GUI_T(k19), CTL_T(k1a), SFT_T(k1b), \
        k20, k21, k22, k23, k24,            k27, k28, k29, k2a, k2b, \
                       k33, k34, k35,  k36, k37, k38 \
    )
#define LAYOUT_base_mac_wrapper(...) LAYOUT_ferris_base_mac(__VA_ARGS__)
#define LAYOUT_base_win_wrapper(...) LAYOUT_ferris_base_win(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAC] = LAYOUT_base_mac_wrapper(
      _________________LAYOUT_L1_________________,                       _________________LAYOUT_R1_________________,
      _________________LAYOUT_L2_________________,                       _________________LAYOUT_R2_________________,
      _________________LAYOUT_L3_________________,                       _________________LAYOUT_R3_________________,
                                   OS_SNIP, LT_SMES, LT_REP,    LT_FUNC, RAISE,   ADJUST
  ),

  [_WINDOWS] = LAYOUT_base_win_wrapper(
      _________________LAYOUT_L1_________________,                       _________________LAYOUT_R1_________________,
      _________________LAYOUT_L2_________________,                       _________________LAYOUT_R2_________________,
      _________________LAYOUT_L3_________________,                       _________________LAYOUT_R3_________________,
                                 _______, _______, _______,     _______, _______, _______
  ),

#ifdef GIT_ENABLE
    [_GIT] = LAYOUT_ferris_wrapper(
        _________________GIT_L1____________________,                     _________________GIT_R1____________________,
        _________________GIT_L2____________________,                     _________________GIT_R2____________________,
        _________________GIT_L3____________________,                     _________________GIT_R3____________________,
                                   _______, _______, _______,   _______, _______, _______
    ),
#endif

    [_SYMBOL] = LAYOUT_ferris_wrapper(
        _________________SYMBOL_L1_________________,                     _________________SYMBOL_R1_________________,
        _________________SYMBOL_L2_________________,                     _________________SYMBOL_R2_________________,
        _________________SYMBOL_L3_________________,                     _________________SYMBOL_R3_________________,
                                   _______, _______, _______,   _______, _______, _______
    ),

    [_RAISE] = LAYOUT_ferris_wrapper(
        _________________NUMBER_L0_________________,                     _________________NUMBER_R0_________________,
        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_DLR,  KC_4,    KC_5,    KC_6,    KC_PLUS,
        KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                      KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,
                                   _______, _______, _______,   _______, KC_COLN, _______
    ),

    [_FUNC] = LAYOUT_ferris_wrapper(
        _________________FUNC_L1___________________,                     _________________FUNC_R1___________________,
        _________________FUNC_L2___________________,                     _________________FUNC_R2___________________,
        _________________FUNC_L3___________________,                     _________________FUNC_R3___________________,
                                   QK_BOOT, _______, _______,   _______, KC_MAKE, QK_BOOT
    ),

    [_ADJUST] = LAYOUT_ferris_wrapper(
        MAC,     WINDOWS, XXXXXXX, XXXXXXX, XXXXXXX,                     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        M_ALT,   W_ALT,   XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______,   _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user_adaviloper(keycode, record)) return false;
    switch (keycode) {
        case KC_MAKE:
            if (record->event.pressed) {
                SEND_STRING("make crkbd:adaviloper");
                tap_code(KC_ENT);
            }
            return false;
    };
    return true;
}
