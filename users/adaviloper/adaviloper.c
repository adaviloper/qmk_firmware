#include "adaviloper.h"

#include QMK_KEYBOARD_H

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    set_default_layer(default_layer);
    default_layer_set(default_layer);
}

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user_adaviloper(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    //  uint8_t default_layer = eeconfig_read_default_layer();
#ifdef CASE_MODES_ENABLE
    if (!process_case_modes(keycode, record)) { return false; }
#endif
    if (!process_os_commands_adaviloper(keycode, record)) { return false; };
    if (!process_vi_commands_adaviloper(keycode, record)) { return false; };
    mod_state = get_mods();
    switch (keycode) {
        case MAC:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_MAC);
            }
            return false;
            break;
        case WINDOWS:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_WINDOWS);
            }
            return false;
            break;
#ifdef ART_ENABLE
        case ART:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_ART);
            }
            return false;
            break;
        case ART2:
            if (record->event.pressed) {
                layer_on(_ART2);
            } else {
                layer_off(_ART2);
            }
            return false;
            break;
#endif
#ifdef GAMING_ENABLE
        case GAMING:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_GAMING);
            }
            return false;
            break;
#endif
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
            }
            return false;
            break;
        case FUNC:
            if (record->event.pressed) {
                layer_on(_FUNC);
                update_tri_layer(_FUNC, _FUNC2, _ADJUST);
            } else {
                layer_off(_FUNC);
                update_tri_layer(_FUNC, _FUNC2, _ADJUST);
            }
            return false;
            break;
        case FUNC2:
            if (record->event.pressed) {
                layer_on(_FUNC2);
                update_tri_layer(_FUNC, _FUNC2, _ADJUST);
            } else {
                layer_off(_FUNC2);
                update_tri_layer(_FUNC, _FUNC2, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
#ifdef RGBLIGHT_ENABLE
        case LIGHTS:
            if (record->event.pressed) {
                layer_on(_LIGHTS);
            } else {
                layer_off(_LIGHTS);
            }
            return false;
            break;
#endif
        case PR_TTLE:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
                register_code(KC_LALT);
                tap_code(KC_DEL);
                tap_code(KC_DEL);
                tap_code(KC_DEL);
                unregister_code(KC_LALT);
                tap_code(KC_DEL);
                SEND_STRING("[GN-");
                register_code(KC_LALT);
                tap_code(KC_RGHT);
                tap_code(KC_DEL);
                unregister_code(KC_LALT);
                SEND_STRING("] - ");
            }
            // Task/gn XXXXX/some description
            return false;
            break;
#ifdef CASE_MODES_ENABLE
        case CAP_WRD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
            break;
        case CAMEL:
            if (record->event.pressed) {
                enable_xcase_with(OSM(MOD_LSFT));
            }
            return false;
            break;
        case SNAKE:
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            return false;
            break;
        case KEBAB:
            if (record->event.pressed) {
                enable_xcase_with(KC_MINS);
            }
            return false;
            break;
        case CST_CSE:
            if (record->event.pressed) {
                enable_xcase();
            }
            return false;
            break;
#endif // CASE_MODES_ENABLE
        case DBL_EQ:
            if (record->event.pressed) {
                SEND_STRING("==");
            }
            return false;
            break;
        case TRIP_EQ:
            if (record->event.pressed) {
                SEND_STRING("===");
            }
            return false;
            break;
        case DBL_CLN:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
            break;
    }
    return true;
}
