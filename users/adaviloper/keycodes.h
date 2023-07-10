#pragma once

#include QMK_KEYBOARD_H

#define XX KC_NO
#define SPOTLHT LGUI(KC_SPC)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_HYP OSM(MOD_HYPR)
#define LT_SMES LT(_SYMBOL, KC_ESC)
#define TAB_NXT C(KC_TAB)
#define TAB_PRV C(S(KC_TAB))
#define MT_SFSP SFT_T(KC_SPC)
#define LT_FUNC LT(_FUNC, KC_SPC)
#define LT_SYEN LT(_SYSTEM, KC_ENT)
#define LT_REP  LT(_SYSTEM, KC_F1)

enum keycodes {
  MAC = SAFE_RANGE,
  M_ALT,
  WINDOWS,
  W_ALT,
#ifdef GAMING_ENABLE
  GAMING,
#endif
  RAISE,
#ifdef ART_ENABLE
  ART,
  ART2,
#endif
  FUNC,
  FUNC2,
#ifdef RGBLIGHT_LAYERS
  LIGHTS,
#endif
  ADJUST,
  PR_TLE1,
  PR_TLE2,
#ifdef CASE_MODES_ENABLE
  KC_MOCK,
  CAP_WRD,
  CAMEL,
  SNAKE,
  KEBAB,
  CST_CSE,
#endif
#ifdef GIT_ENABLE
  GIT_ACP,
  GIT_BCK,
  GIT_GCP,
  GIT_HRD,
  GIT_RST,
  GIT_SFT,
#endif
  RE_PEAT,
  DBL_EQ,
  TRIP_EQ,
  DBL_CLN,
  OS_ALL,  // A
  OS_COPY, // C
  OS_FIND, // F
  OS_NAPP, // F
  OS_SPEC, // Inspector
  OS_URL,  // L
  OS_RFRS, // R
  OS_SAVE, // S
  OS_CTAB, // W
  OS_PSTE, // V
  OS_CUT,  // X
  OS_REDO, // Y
  OS_UNDO, // Z
  OS_SNIP,
  VI_BWRD, // B
  VI_WORD, // W
  VI_BSPC, // Backspace
  VI_DEL,  // Delete
  PERSONAL_SAFE_RANGE,
};

