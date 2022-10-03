#include "adaviloper.h"
#include QMK_KEYBOARD_H

enum lulu_keycodes {
    KC_MAKE = PERSONAL_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_MAC] = LAYOUT_wrapper(
          KC_ESC,  _________________NUMBER_L0_________________,                     _________________NUMBER_R0_________________, KC_BSPC,
          KC_TAB,  _________________MAC_L1____________________,                     _________________MAC_R1____________________, KC_NO,
          KC_DEL,  _________________MAC_L2____________________,                     _________________MAC_R2____________________, KC_QUOT,
          OSM_MEH, _________________MAC_L3____________________, KC_LBRC,   KC_RBRC, _________________MAC_R3____________________, OSM_HYP,
                                 OS_SNIP, SPOTLHT, LT_SMES, LT_SYEN,           LT_FUNC, RAISE,   _______, ADJUST
    ),
    [_WINDOWS] = LAYOUT_wrapper(
          _______, _________________NUMBER_L0_________________,                     _________________NUMBER_R0_________________, _______,
          _______, _________________WINDOWS_L1________________,                     _________________WINDOWS_R1________________, _______,
          _______, _________________WINDOWS_L2________________,                     _________________WINDOWS_R2________________, _______,
          _______, _________________WINDOWS_L3________________, _______,   _______, _________________WINDOWS_R3________________, _______,
                                     _______, _______, _______, _______,   _______, _______, _______, _______
    ),
#ifdef GAMING_ENABLE
    [_GAMING] = LAYOUT_wrapper(
          KC_ESC,  _________________GAMING_L0_________________,                     _________________GAMING_R0_________________, _______,
          KC_TAB,  _________________GAMING_L1_________________,                     _________________GAMING_R1_________________, _______,
          KC_LCTL, _________________GAMING_L2_________________,                     _________________GAMING_R2_________________, _______,
          KC_LSFT, _________________GAMING_L3_________________, _______,   _______, _________________GAMING_R3_________________, _______,
                                     _______, KC_ENT,  KC_LALT, KC_SPC,    _______, _______, _______, _______
    ),
#endif
#ifdef GIT_ENABLE
    [_GIT] = LAYOUT_wrapper(
          _______, _________________GIT_L0____________________,                     _________________GIT_R0____________________, _______,
          _______, _________________GIT_L1____________________,                     _________________GIT_R1____________________, _______,
          _______, _________________GIT_L2____________________,                     _________________GIT_R2____________________, _______,
          _______, _________________GIT_L3____________________, _______,   _______, _________________GIT_R3____________________, _______,
                                     _______, KC_ENT,  KC_LALT, KC_SPC,    _______, _______, _______, _______
    ),
#endif
    [_SYMBOL] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _________________SYMBOL_L1_________________,                   _________________SYMBOL_R1_________________, _______,
        _______, _________________SYMBOL_L2_________________,                   _________________SYMBOL_R2_________________, TRIP_EQ,
        _______, _________________SYMBOL_L3_________________, _______, _______, _________________SYMBOL_R3_________________, DBL_EQ,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_GRV,  _________________NUMBER_L0_________________,                   _________________NUMBER_R0_________________, KC_COLN,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_DLR,  KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ASTR,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  KC_SLSH,
                                   _______, _______, _______,  _______, _______,  _______, _______, _______
    ),
#ifdef ART_ENABLE
    [_ART] = LAYOUT_wrapper(
        KC_ESC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,  _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_HYPR),
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
    [_SYSTEM] = LAYOUT_wrapper(
        _______, _________________SYSTEM_L0_________________,                     _________________SYSTEM_R0_________________, _______,
        _______, _________________SYSTEM_L1_________________,                     _________________SYSTEM_R1_________________, _______,
        _______, _________________SYSTEM_L2_________________,                     _________________SYSTEM_R2_________________, _______,
        _______, _________________SYSTEM_L3_________________,  _______, _______,  _________________SYSTEM_R3_________________, _______,
                                   QK_BOOT, _______, _______,  _______, _______,  _______, _______, QK_BOOT
    ),
    [_FUNC] = LAYOUT_wrapper(
        _______, _________________FUNC_L0___________________,                     _________________FUNC_R0___________________, VI_BSPC,
        _______, _________________FUNC_L1___________________,                     _________________FUNC_R1___________________, _______,
        VI_DEL,  _________________FUNC_L2___________________,                     _________________FUNC_R2___________________, _______,
        _______, _________________FUNC_L3___________________,  _______, _______,  _________________FUNC_R3___________________, _______,
                                   QK_BOOT, _______, _______,  _______, _______,  _______, KC_MAKE, QK_BOOT
    ),
    [_ADJUST] = LAYOUT_wrapper(
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
        case KC_MAKE:
            if (record->event.pressed) {
                SEND_STRING("make boardsource/lulu/rp2040:adaviloper");
                tap_code(KC_ENT);
            }
            return false;
    };
    return true;
}
