#pragma once

#include "rows.h"
#include "layers.h"
#include "keycodes.h"
#include "os_commands.h"
#include "vi_commands.h"

#ifdef AUTO_SHIFT_ENABLE
    #include "auto_shift.h"
#endif
#ifdef CASE_MODES_ENABLE
    #include "case_modes.h"
    #include "caps_mock.h"
#endif
#ifdef COMBO_ENABLE
    #include "combos.h"
#endif
#ifdef ENCODER_ENABLE
#ifdef WPM_ENABLE
    #include "encoders.h"
#endif
#endif
#ifdef GIT_ENABLE
    #include "git.h"
#endif
#ifdef OLED_ENABLE
    #include "oled.h"
#endif
#ifdef RGBLIGHT_LAYERS
    #include "rgblight_layers.h"
#endif
#ifdef TAP_DANCE_ENABLE
    #include "tap_dance.h"
#endif

bool process_record_user_adaviloper(uint16_t keycode, keyrecord_t *record);
