#include "tap_dance.h"
#include "layers.h"
#include "keycodes.h"

#include QMK_KEYBOARD_H

td_state_t cur_dance(qk_tap_dance_state_t *state, bool interruptable) {
    bool can_be_interrupted = interruptable || false;
    if (state->count == 1) {
        if ((state->interrupted && can_be_interrupted) || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed) return TD_TRIPLE_HOLD;
        else return TD_TRIPLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    else {
        return TD_UNKNOWN;
    }
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t fntap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void fn_finished(qk_tap_dance_state_t *state, void *user_data) {
    fntap_state.state = cur_dance(state, true);
    switch (fntap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_FUNC);
            break;
        case TD_DOUBLE_TAP:
            register_code16(SPOTLHT);
            break;
        case TD_DOUBLE_HOLD:
        case TD_NONE:
        default:
            register_code(KC_NO);
            break;
    }
}

void fn_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (fntap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
             layer_off(_FUNC);
             break;
        case TD_DOUBLE_TAP:
             unregister_code16(SPOTLHT);
             break;
        case TD_DOUBLE_HOLD:
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    fntap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t ent_esc_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ent_esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    ent_esc_tap_state.state = cur_dance(state, false);
    switch (ent_esc_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
//            layer_on(_FUNC);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_ESC);
            break;
        case TD_NONE:
        default:
            register_code(KC_NO);
            break;
    }
}

void ent_esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ent_esc_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
//             layer_off(_FUNC);
             break;
        case TD_DOUBLE_TAP:
             unregister_code(KC_ESC);
             break;
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    ent_esc_tap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t hyper_mehtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void hyper_meh_finished(qk_tap_dance_state_t *state, void *user_data) {
    hyper_mehtap_state.state = cur_dance(state, true);
    switch (hyper_mehtap_state.state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_HYPR);
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            set_oneshot_mods(MOD_MEH);
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_NONE:
        default:
            register_code(KC_NO);
            break;
    }
}

void hyper_meh_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (hyper_mehtap_state.state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            break;
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    hyper_mehtap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t ctl_navtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ctl_nav_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint8_t default_layer = eeconfig_read_default_layer();
    ctl_navtap_state.state = cur_dance(state, false);
    switch (ctl_navtap_state.state) {
        case TD_SINGLE_TAP:
            layer_invert(_NAV_AND_MEDIA);
            break;
        case TD_SINGLE_HOLD:
            if (layer_state_cmp(default_layer, _MAC)) {
                register_mods(MOD_BIT(KC_LGUI));
            } else {
                register_mods(MOD_BIT(KC_LCTL));
            }
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_NONE:
        default:
            register_code(KC_NO);
            break;
    }
}

void ctl_nav_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint8_t default_layer = eeconfig_read_default_layer();
    switch (ctl_navtap_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            if (layer_state_cmp(default_layer, _MAC)) {
                unregister_mods(MOD_BIT(KC_LGUI));
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
            }
            break;
        case TD_DOUBLE_TAP:
             break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    ctl_navtap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t sentence_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void sentence_finished(qk_tap_dance_state_t *state, void *user_data) {
    sentence_tap_state.state = cur_dance(state, false);
    switch (sentence_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_DOT);
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_SPC);
            set_oneshot_mods(MOD_LSFT);
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("...");
            break;
        case TD_NONE:
        default:
            register_code(KC_NO);
            break;
    }
}

void sentence_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (sentence_tap_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
             break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    sentence_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [FN_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
    [ENT_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_esc_finished, ent_esc_reset),
    [HYPR_MEH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, hyper_meh_finished, hyper_meh_reset),
    [CTL_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_nav_finished, ctl_nav_reset),
    [DBL_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sentence_finished, sentence_reset),
};
