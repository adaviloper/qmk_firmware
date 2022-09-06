#include "encoders.h"
#include "layers.h"

#include QMK_KEYBOARD_H

bool encoder_update_user(uint8_t index, bool clockwise) {
  uint16_t highest_layer = get_highest_layer(layer_state|default_layer_state);
  if (index == 0) { // Encoder on master side
    if (highest_layer == _RAISE) { // on Raise layer
      // Cursor control
      if (clockwise) {
          tap_code(KC_MNXT);
      } else {
          tap_code(KC_MPRV);
      }
    }
#ifdef ART_ENABLE
    else if (highest_layer == _ART) {
      if (clockwise) {
          tap_code(KC_RBRC);
      } else {
          tap_code(KC_LBRC);
      }
    }
#endif
    else {
      if (clockwise) {
          tap_code(KC_KB_VOLUME_UP);
      } else {
          tap_code(KC_KB_VOLUME_DOWN);
      }
    }
  }
  else if (index == 1) { // Encoder on slave side
    if(IS_LAYER_ON(_SYMBOL)) { // on Lower layer
      //
      if (clockwise) {
          tap_code(KC_VOLD);
      } else {
          tap_code(KC_VOLU);
      }
    }
    else {
      if (clockwise) {
          register_code(KC_LCTL);
          tap_code(KC_TAB);
          unregister_code(KC_LCTL);
      } else {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          tap_code(KC_TAB);
          unregister_code(KC_LCTL);
          unregister_code(KC_LSFT);
      }
    }
  }
    return true;
}
