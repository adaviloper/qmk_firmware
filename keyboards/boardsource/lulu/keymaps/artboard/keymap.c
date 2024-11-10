#include QMK_HEADER_H

enum lulu_layers {
    _BASE,
    _SYMBOL,
    _RAISE,
    _ADJUST,
};

enum lulu_keycodes {
    KC_MAKE = SAFE_RANGE,
    LT_BASE,
    ENC_TOG,
};

enum encoder_action {
    BRUSH_SIZE = 0,
    ROTATE_CANVAS,
    END_ENCODER_ACTION,
};

static enum encoder_action encoder_state = BRUSH_SIZE;

#define LAYOUT_lulu_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_base_mac_wrapper(
        KC_ESC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                      KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        OSM_MEH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ENC_TOG,   KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_HYP,
                                   OS_SNIP, KC_NO,   LT_SMES, LT_REP,    ______, _______, ________, _______
    ),

    [_SYMBOL] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _________________SYMBOL_L1_________________,                     _________________SYMBOL_R1_________________, _______,
        _______, _________________SYMBOL_L2_________________,                     _________________SYMBOL_R2_________________, TRIP_EQ,
        _______, _________________SYMBOL_L3_________________, _______,   _______, _________________SYMBOL_R3_________________, DBL_EQ,
                                   _______, _______, _______, _______,   _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _________________RAISE_L1__________________,                     _________________RAISE_R1__________________, KC_MINS,
        _______, _________________RAISE_L2__________________,                     _________________RAISE_R2__________________, KC_ASTR,
        _______, _________________RAISE_L3__________________, _______,   _______, _________________RAISE_R3__________________, KC_SLSH,
                                   _______, _______, _______, _______,   _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, RGB_M_R, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                                   QK_BOOT, _______, _______, _______,   _______, _______, _______, QK_BOOT
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
        case OS_SNIP:
            if (record->event.pressed) {
                tap_code16(G(S(C(KC_4))));
            }
            return false;
        case ENC_TOG:
            if (record->event.pressed) {
                if (encoder_state == ROTATE_CANVAS) {
                    encoder_state += 1;
                }
                if (encoder_state == END_ENCODER_ACTION) {
                    encoder_state = BRUSH_SIZE;
                }
            }
            return false;
    };
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint16_t highest_layer = get_highest_layer(layer_state|default_layer_state);
    if (index == 0) { // Encoder on master side
        if (highest_layer == _RAISE) { // on Raise layer
            // Cursor control
            if (clockwise) {
                tap_code(KC_MPRV);
            } else {
                tap_code(KC_MNXT);
            }
        }
        if (highest_layer == _GAMING) { // on Raise layer
            // Cursor control
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        }
#ifdef ART_ENABLE
        else if (highest_layer == _ART) {
            if (clockwise) {
                tap_code(KC_LBRC);
            } else {
                tap_code(KC_RBRC);
            }
        }
#endif
        else {
            if (clockwise) {
                tap_code(KC_KB_VOLUME_DOWN);
            } else {
                tap_code(KC_KB_VOLUME_UP);
            }
        }
    }
    else if (index == 1) { // Encoder on slave side
        if(IS_LAYER_ON(_SYMBOL)) { // on Lower layer
            //
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        else {
            if (clockwise) {
                tap_code16(C(KC_TAB));
            } else {
                tap_code16(C(S(KC_TAB)));
            }
        }
    }
    return true;
}
