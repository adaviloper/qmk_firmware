 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
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
#include "adaviloper.h"
#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum lily58_keycodes {
    GIT_ACP = PERSONAL_SAFE_RANGE,
    KC_MAKE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* MAC
      * ,-----------------------------------------.                    ,-----------------------------------------.
      * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
      * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
      * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
      * `-----------------------------------------/       /     \      \-----------------------------------------'
      *                   | LAlt | LGUI |SYMBOL | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
      *                   |      |      |      |/       /         \      \ |      |      |      |
      *                   `----------------------------'           '------''--------------------'
      */
     [_MAC] = LAYOUT_wrapper(
          KC_ESC,  _________________NUMBER_L0_________________,                     _________________NUMBER_R0_________________, KC_BSPC,
          KC_TAB,  _________________MAC_L1____________________,                     _________________MAC_R1____________________, KC_NO,
          KC_DEL,  _________________MAC_L2____________________,                     _________________MAC_R2____________________, KC_QUOT,
          OSM_MEH, _________________MAC_L3____________________, KC_LBRC,   KC_RBRC, _________________MAC_R3____________________, TD_HYMH,
                                 OS_SNIP, SPOTLHT, LT_SMES, LT_SYEN,           LT_FUNC, RAISE,   KC_MAKE, ADJUST
    ),
     [_WINDOWS] = LAYOUT_wrapper(
          _______, _________________NUMBER_L0_________________,                     _________________NUMBER_R0_________________, _______,
          _______, _________________WINDOWS_L1________________,                     _________________WINDOWS_R1________________, _______,
          _______, _________________WINDOWS_L2________________,                     _________________WINDOWS_R2________________, _______,
          _______, _________________WINDOWS_L3________________, _______,   _______, _________________WINDOWS_R3________________, _______,
                                 _______, _______, _______, _______,           _______, _______, _______, _______
    ),
#ifdef GAMING_ENABLE
     [_GAMING] = LAYOUT_wrapper(
          KC_ESC,  _________________GAMING_L0_________________,                     _________________GAMING_R0_________________, _______,
          KC_TAB,  _________________GAMING_L1_________________,                     _________________GAMING_R1_________________, _______,
          KC_LCTL, _________________GAMING_L2_________________,                     _________________GAMING_R2_________________, _______,
          KC_LSFT, _________________GAMING_L3_________________, _______,   _______, _________________GAMING_R3_________________, _______,
                                 _______, KC_ENT,  KC_LALT, KC_SPC,            _______, _______, _______, _______
    ),
#endif
#ifdef GIT_ENABLE
     [_GIT] = LAYOUT_wrapper(
          _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, GIT_ACP, _______,                     _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_ENT,  KC_LALT, KC_SPC,            _______, _______, _______, _______
    ),
#endif
    [_SYMBOL] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_F1,   _________________SYMBOL_L1_________________,                   _________________SYMBOL_R1_________________, _______,
        KC_GRV,  _________________SYMBOL_L2_________________,                   _________________SYMBOL_R2_________________, TRIP_EQ,
        _______, _________________SYMBOL_L3_________________, _______, _______, _________________SYMBOL_R3_________________, DBL_EQ,
                                   _______, _______, _______, _______, _______,  _______, _______, _______
    ),
    [_RAISE] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_DLR,  KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ASTR,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  KC_SLSH,
                                   _______, _______, _______,  _______, _______,  _______, _______, _______
    ),
#ifdef ART_ENABLE
    [_ART] = LAYOUT_wrapper(
        KC_ESC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,  _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD_HYMH,
                                   _______, _______, KC_SPC,  ART2,     _______,  _______, _______, _______
    ),
    [_ART2] = LAYOUT_wrapper(
        _______, KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,                      KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_ESC,
        _______, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                        KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_LALT,
        _______, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,                        KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    KC_LSFT,
        _______, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    _______,  _______,  KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    KC_LCTL,
                                   _______, _______, KC_SPC,  _______,  _______,  _______, _______, _______
    ),
#endif
    [_SYSTEM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, OS_CTAB, _______, OS_RFRS, PR_TTLE,                     OS_REDO, _______, _______, _______, _______, _______,
        _______, OS_ALL,  OS_SAVE, _______, OS_FIND, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, OS_UNDO, OS_CUT,  OS_COPY, OS_PSTE, CST_CSE,  _______, _______,  _______, CAP_WRD, CAMEL,   SNAKE,   KEBAB,   _______,
                                   _______, _______, _______,  _______, _______,  _______, _______, _______
    ),
    [_FUNC] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, VI_BSPC,
        _______, _______, VI_WORD, _______, _______, _______,                     _______, KC_PGUP, _______, _______, _______, _______,
        VI_DEL,  _______, _______, KC_PGDN, _______, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, VI_BWRD,  _______, _______,  _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,  _______, _______,  _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        XXXXXXX, MAC,     WINDOWS, GAMING,  ART,     XXXXXXX,                   QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_R, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                                   _______, _______, _______, _______, _______,  _______, _______, _______
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user_adaviloper(keycode, record)) return false;
    switch (keycode) {
        case GIT_ACP:
            if (record->event.pressed) {
                SEND_STRING("gaa; gcmsg \"$(git_commit_prefix) \"; gpsup");
                register_code(KC_LALT);
                tap_code(KC_LEFT);
                clear_mods();
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
            }
            break;
        case KC_MAKE:
            if (record->event.pressed) {
                SEND_STRING("make lily58/light:adaviloper");
                tap_code(KC_ENT);
            }
            break;
    };
    return true;
    }
