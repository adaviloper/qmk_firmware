#include "combos.h"

#include QMK_KEYBOARD_H

enum combo_events {
    COMBO_ENT_L,
    COMBO_ENT_R,
    COMBO_BACKSPACE,
    COMBO_SENTENCE,
    COMBO_QUESTION,
    COMBO_EXCLAMATION,
    COMBO_NEXT_FIELD,
    COMBO_PREV_FIELD,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM ent_l_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ent_r_combo[] = {KC_M, KC_COMM, COMBO_END};
#ifdef ART_ENABLE
const uint16_t PROGMEM bspc_combo[] = {KC_L, KC_SCLN, COMBO_END};
#endif
const uint16_t PROGMEM sentence_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM question_combo[] = {KC_COMM, KC_SLSH, COMBO_END};
const uint16_t PROGMEM exclamation_combo[] = {KC_Z, KC_COMM, COMBO_END};
const uint16_t PROGMEM prev_field_combo[] = {KC_COMM, KC_W, COMBO_END};
const uint16_t PROGMEM next_field_combo[] = {KC_COMM, KC_E, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ENT_L] = COMBO(ent_l_combo, KC_ENT),
    [COMBO_ENT_R] = COMBO(ent_r_combo, KC_ENT),
    [COMBO_NEXT_FIELD] = COMBO(next_field_combo, KC_TAB),
    [COMBO_PREV_FIELD] = COMBO(prev_field_combo, LSFT(KC_TAB)),
#ifdef ART_ENABLE
    [COMBO_BACKSPACE] = COMBO(bspc_combo, KC_BSPC),
#endif

// Complex combos
    [COMBO_SENTENCE] = COMBO_ACTION(sentence_combo),
    [COMBO_QUESTION] = COMBO_ACTION(question_combo),
    [COMBO_EXCLAMATION] = COMBO_ACTION(exclamation_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case COMBO_SENTENCE:
            if (pressed) {
                tap_code16(KC_DOT);
                tap_code16(KC_SPC);
                set_oneshot_mods(MOD_LSFT);
            }
            break;
        case COMBO_QUESTION:
            if (pressed) {
                tap_code16(KC_QUES);
                tap_code16(KC_SPC);
                set_oneshot_mods(MOD_LSFT);
            }
            break;
        case COMBO_EXCLAMATION:
            if (pressed) {
                tap_code16(KC_EXLM);
                tap_code16(KC_SPC);
                set_oneshot_mods(MOD_LSFT);
            }
            break;
    }
}
