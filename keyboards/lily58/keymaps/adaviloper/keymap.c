#include "adaviloper.h"
#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum lily58_keycodes {
    KC_MAKE = PERSONAL_SAFE_RANGE,
};

#define LAYOUT_lulu_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_lulu_base_mac( \
        k00, k01, k02, k03, k04, k05,           k08, k09, k0a, k0b, k0c, k0d, \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, k21, k22, k23, k24, k25,           k28, k29, k2a, k2b, k2c, k2d, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45, k46, k47, k48, k49, k4a \
    ) \
    LAYOUT_lulu_wrapper( \
        k00, k01, k02, k03, k04, k05,           k08, k09, k0a, k0b, k0c, k0d, \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, SFT_T(k21), GUI_T(k22), CTL_T(k23), ALT_T(k24), LT(_GIT, k25),   LT(_GIT, k28), ALT_T(k29), CTL_T(k2a), GUI_T(k2b), SFT_T(k2c), k2d, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45, k46, k47, k48, k49, k4a \
    )
#define LAYOUT_lulu_base_win( \
        k00, k01, k02, k03, k04, k05,           k08, k09, k0a, k0b, k0c, k0d, \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, k21, k22, k23, k24, k25,           k28, k29, k2a, k2b, k2c, k2d, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45, k46, k47, k48, k49, k4a \
    ) \
    LAYOUT_lulu_wrapper( \
        k00, k01, k02, k03, k04, k05,           k08, k09, k0a, k0b, k0c, k0d, \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, SFT_T(k21), CTL_T(k22), GUI_T(k23), ALT_T(k24), LT(_GIT, k25),   LT(_GIT, k28), ALT_T(k29), GUI_T(k2a), CTL_T(k2b), SFT_T(k2c), k2d, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45, k46, k47, k48, k49, k4a \
    )
#define LAYOUT_base_mac_wrapper(...) LAYOUT_lulu_base_mac(__VA_ARGS__)
#define LAYOUT_base_win_wrapper(...) LAYOUT_lulu_base_win(__VA_ARGS__)

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
     [_MAC] = LAYOUT_base_mac_wrapper(
          KC_ESC,  _________________NUMBER_L0_________________,                     _________________NUMBER_R0_________________, KC_BSPC,
          KC_TAB,  _________________MAC_L1____________________,                     _________________MAC_R1____________________, KC_NO,
          KC_DEL,  _________________MAC_L2____________________,                     _________________MAC_R2____________________, KC_QUOT,
          OSM_MEH, _________________MAC_L3____________________, KC_LBRC,   KC_RBRC, _________________MAC_R3____________________, OSM_HYP,
                                     OS_SNIP, SPOTLHT, LT_SMES, LT_SYEN,   LT_FUNC, RAISE,   KC_MAKE, ADJUST
    ),
     [_WINDOWS] = LAYOUT_base_win_wrapper(
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
          _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
          _______, _________________GIT_L1____________________,                     _________________GIT_R1____________________, _______,
          _______, _________________GIT_L2____________________,                     _________________GIT_R2____________________, _______,
          _______, _________________GIT_L3____________________, _______,   _______, _________________GIT_R3____________________, _______,
                                     _______, _______, _______, _______,   _______, _______, _______, _______
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
        case KC_MAKE:
            if (record->event.pressed) {
                SEND_STRING("make lily58/light:adaviloper");
                tap_code(KC_ENT);
            }
            break;
    };
    return true;
}
