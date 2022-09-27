#include "layers.h"
#include "keycodes.h"
#include "vi_commands.h"

#include QMK_KEYBOARD_H

bool process_vi_commands_adaviloper(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VI_BWRD:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC) {
                    tap_code16(A(KC_LEFT));
                } else {
                    tap_code16(C(KC_LEFT));
                }
            }
            return false;
        case VI_VIS:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC) {
                    tap_code16(A(KC_RGHT));
                } else {
                    tap_code16(C(KC_RGHT));
                }
            }
            return false;
        case VI_WORD:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC) {
                    tap_code16(A(KC_RGHT));
                } else {
                    tap_code16(C(KC_RGHT));
                }
            }
            return false;
        case VI_BSPC:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC) {
                    tap_code16(A(KC_BSPC));
                } else {
                    tap_code16(C(KC_BSPC));
                }
            }
            return false;
        case VI_DEL:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC) {
                    tap_code16(A(KC_DEL));
                } else {
                    tap_code16(C(KC_DEL));
                }
            }
            return false;
    }

    return true;
};
