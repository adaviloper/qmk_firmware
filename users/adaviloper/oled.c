#include "oled.h"
#include "layers.h"

#include QMK_KEYBOARD_H

//bool oled_task_user(void) {
//  if (is_keyboard_master()) {
//    // If you want to change the display of OLED, you need to change here
//    oled_write_ln(read_layer_state(), false);
//    oled_write_ln(read_keylog(), false);
//    oled_write_ln(read_keylogs(), false);
//    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
//    //oled_write_ln(read_host_led_state(), false);
//    //oled_write_ln(read_timelog(), false);
//  } else {
//    oled_write(read_logo(), false);
//  }
//    return false;
//}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _MAC:
            oled_write_P(PSTR("Mac\n"), false);
            break;
        case _WINDOWS:
            oled_write_P(PSTR("Windows\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Vim\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _SYSTEM:
            oled_write_P(PSTR("System\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
