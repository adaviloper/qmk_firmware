#pragma once

#include "adaviloper.h"

#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)              LAYOUT_ortho_4x12(__VA_ARGS__)

#define _________________NUMBER_L0_________________                   KC_1, KC_2, KC_3, KC_4, KC_5
#define _________________NUMBER_R0_________________                   KC_6, KC_7, KC_8, KC_9, KC_0

#define _________________QWERTY_L1_________________                   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________                   KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________                   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________FUNC_L0___________________                   _______, _______, _______, _______, _______
#define _________________FUNC_L1___________________                   _______, VI_WORD, _______, _______, _______
#define _________________FUNC_L2___________________                   _______, _______, KC_PGDN, _______, _______
#define _________________FUNC_L3___________________                   _______, _______, _______, _______, VI_BWRD

#define _________________FUNC_R0___________________                   _______, _______, _______, _______, _______
#define _________________FUNC_R1___________________                   _______, KC_PGUP, _______, _______, _______
#define _________________FUNC_R2___________________                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________FUNC_R3___________________                   _______, _______, _______, _______, _______

#ifdef GAMING_ENABLE
#define _________________GAMING_L0_________________                   _________________NUMBER_L0_________________
#define _________________GAMING_L1_________________                   _________________QWERTY_L1_________________
#define _________________GAMING_L2_________________                   _________________QWERTY_L2_________________
#define _________________GAMING_L3_________________                   _________________QWERTY_L3_________________

#define _________________GAMING_R0_________________                   _________________NUMBER_R0_________________
#define _________________GAMING_R1_________________                   _________________QWERTY_R1_________________
#define _________________GAMING_R2_________________                   _________________QWERTY_R2_________________
#define _________________GAMING_R3_________________                   _________________QWERTY_R3_________________
#endif

#ifdef GIT_ENABLE
#define _________________GIT_L0____________________                   _______, _______, _______, _______, _______
#define _________________GIT_L1____________________                   _______, _______, _______, _______, _______
#define _________________GIT_L2____________________                   _______, GIT_SFT, _______, GIT_ACP, GIT_GCP
#define _________________GIT_L3____________________                   _______, _______, _______, _______, GIT_BCK

#define _________________GIT_R0____________________                   _______, _______, _______, _______, _______
#define _________________GIT_R1____________________                   _______, _______, _______, _______, _______
#define _________________GIT_R2____________________                   GIT_HRD, _______, _______, _______, _______
#define _________________GIT_R3____________________                   _______, _______, _______, _______, _______
#endif

#define _________________SYMBOL_L1_________________                   KC_GRV,  KC_LABK, KC_RABK, KC_DQUO, KC_PERC
#define _________________SYMBOL_L2_________________                   KC_HASH, KC_MINS, KC_PLUS, KC_EQL,  KC_CIRC
#define _________________SYMBOL_L3_________________                   KC_EXLM, KC_SLSH, KC_ASTR, KC_BSLS, KC_TILD

#define _________________SYMBOL_R1_________________                   KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_DOT
#define _________________SYMBOL_R2_________________                   KC_DLR,  KC_COLN, KC_LPRN, KC_RPRN, KC_PIPE
#define _________________SYMBOL_R3_________________                   DBL_CLN, KC_AT,   KC_LCBR, KC_RCBR, KC_QUES

#define _________________SYSTEM_L0_________________                   _______, _______, _______, _______, _______
#define _________________SYSTEM_L1_________________                   _______, OS_CTAB, OS_SPEC, OS_RFRS, OS_TAB
#define _________________SYSTEM_L2_________________                   OS_ALL,  OS_SAVE, OS_URL,  OS_FIND, PR_TTLE
#define _________________SYSTEM_L3_________________                   OS_UNDO, OS_CUT,  OS_COPY, OS_PSTE, CST_CSE

#define _________________SYSTEM_R0_________________                   _______, _______, _______, _______, _______
#define _________________SYSTEM_R1_________________                   OS_REDO, _______, _______, _______, _______
#define _________________SYSTEM_R2_________________                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________SYSTEM_R3_________________                   _______, CAP_WRD, CAMEL,   SNAKE,   KEBAB

#define _________________MAC_L1____________________                   _________________QWERTY_L1_________________
#define _________________MAC_L2____________________                   SFT_T(KC_A),  GUI_T(KC_S),  CTL_T(KC_D),  ALT_T(KC_F),  LT(_GIT, KC_G)
#define _________________MAC_L3____________________                   _________________QWERTY_L3_________________

#define _________________MAC_R1____________________                   _________________QWERTY_R1_________________
#define _________________MAC_R2____________________                   LT(_GIT, KC_H),  ALT_T(KC_J),  CTL_T(KC_K),  GUI_T(KC_L),  SFT_T(KC_SCLN)
#define _________________MAC_R3____________________                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________WINDOWS_L1________________                   _________________MAC_L1____________________
#define _________________WINDOWS_L2________________                   SFT_T(KC_A),  CTL_T(KC_S),  GUI_T(KC_D),  ALT_T(KC_F),  KC_G
#define _________________WINDOWS_L3________________                   _________________MAC_L3____________________

#define _________________WINDOWS_R1________________                   _________________MAC_R1____________________
#define _________________WINDOWS_R2________________                   KC_H,  ALT_T(KC_J),  GUI_T(KC_K),  CTL_T(KC_L),  SFT_T(KC_SCLN)
#define _________________WINDOWS_R3________________                   _________________MAC_R3____________________
