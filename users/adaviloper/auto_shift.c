#include "auto_shift.h"

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_1:
        case KC_2:
        case KC_3:
        case KC_4:
        case KC_5:
        case KC_6:
        case KC_7:
        case KC_8:
        case KC_9:
        case KC_0:
        case KC_LBRC:
        case KC_RBRC:
        case KC_BSLS:
        case KC_EQL:
        case KC_GRV:
        case KC_MINS:
        case KC_QUOT:
            return true;
        default:
            return false;
    }
}
