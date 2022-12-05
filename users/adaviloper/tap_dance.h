#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    FN_CTL,
    ENT_ESC,
    HYPR_MEH,
    CTL_NAV,
    DBL_DOT,
    TAB_NEW_OLD,
};

#define TD_FNCT TD(FN_CTL)
#define TD_DBDT TD(DBL_DOT)
#define TD_TAB  TD(TAB_NEW_OLD)

td_state_t cur_dance(qk_tap_dance_state_t *state, bool interruptable);

