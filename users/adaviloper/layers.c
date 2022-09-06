#include "layers.h"

#include QMK_KEYBOARD_H

void set_default_layer(uint16_t layer) {
    current_default_layer_adaviloper = layer;
}

uint16_t get_current_default_layer() {
    return current_default_layer_adaviloper;
}

