#include "adaviloper.h"

#define LAYOUT_directional_wrapper(...)             LAYOUT_directional(__VA_ARGS__)
// For the x tap dance. Put it here so it can be used in any keymap
void fn_finished(qk_tap_dance_state_t *state, void *user_data);
void fn_reset(qk_tap_dance_state_t *state, void *user_data);

extern keymap_config_t keymap_config;

/*layout template
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |          |     |     |     |     |     |     |     |     |     |     |     |            |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |      |             |      |                 |     |     |     |     |     |
 * `-----------------------------------------------------------------------------------------'

 [LAYOUT] = LAYOUT_all(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______,
  _______, XX,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,           _______,        _______,           _______,         _______, _______, _______, _______, _______),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* MAC
 * ,-----------------------------------------------------------------------------------------.
 * | Esc | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   | -   | =   | BKSPC | ~ |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    | Q   | W   | E   | R   | T   | Y   | U   | I   | O   | P   | [   | ]   |  Del   |
 * |-----------------------------------------------------------------------------------------+
 * | Del      | A   | S   | D   | F   | G   | H   | J   | K   | L   | ;   | '   | Enter      |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     | Z   | X   | C   | V   | B   | N   | M   | ,   | .   | /   | Alt | Up  | Bl  |
 * |-----------------------------------------------------------------------------------------+
 * | Gui | Ctrl  | Alt  |    Enter    | Fn   |      Space      | Fn2 | App | Left| Down|Right|
 * `-----------------------------------------------------------------------------------------'
 */
[_MAC] = LAYOUT_directional_wrapper(
  KC_ESC,  _________________NUMBER_L0_________________, _________________NUMBER_R0_________________, KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
  KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS,
  KC_DEL,  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT, KC_ENT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, OSM(MOD_HYPR), KC_UP,  LIGHTS,
  TD(CTL_NAV), OS_SNIP,  KC_LALT,   LT(_NAV_AND_MEDIA, KC_ENT),    TD(FN_CTL),   KC_SPC,     FUNC2,  OSM(MOD_LGUI | MOD_LALT),  KC_LEFT,  KC_DOWN,   KC_RGHT),

/* Windows
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |          |     |     |     |     |     |     |     |     |     |     |     |            |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |      |             |      |                 |     |     |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */

 [_WINDOWS] = LAYOUT_directional_wrapper(
  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
  _______,             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,
  _______,             _______,  CTL_T(KC_S),  GUI_T(KC_D),  _______,  _______,  _______,  _______,  GUI_T(KC_K),  CTL_T(KC_L),  _______,  _______,              _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,     _______,
  _______,            _______,  _______,   _______,   _______,   _______,       _______,  _______,  _______,  _______,   _______
  ),

 [_NAV_AND_MEDIA] = LAYOUT_directional_wrapper(
  _______,          KC_MS_ACCEL0,  KC_MS_ACCEL1,  KC_MS_ACCEL2,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
  _______,             _______,  KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,  KC_MEDIA_PLAY_PAUSE,  KC_BRIGHTNESS_UP,  _______,  KC_MS_BTN1,  KC_MS_UP,  KC_MS_BTN2,  _______,  _______,  _______,      _______,
  _______,             _______,  KC_MEDIA_PREV_TRACK,  KC_AUDIO_VOL_DOWN,  KC_MEDIA_NEXT_TRACK,  KC_BRIGHTNESS_DOWN,  KC_H,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  _______,  _______,              _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______, _______,
  TG(_NAV_AND_MEDIA),            KC_LGUI,  KC_LALT,   KC_SPC,   TD(FN_CTL),   KC_SPC,       FUNC2,  KC_APP,  KC_LEFT,  KC_DOWN,   KC_RGHT),

 [_GAMING] = LAYOUT_directional_wrapper(
  KC_ESC,    _________________GAMING_L0_________________,  _________________GAMING_R0_________________,  KC_MINS,  KC_EQL,  KC_BSPC, KC_GRV,
  KC_TAB,    _________________GAMING_L1_________________,  _________________GAMING_R1_________________,  KC_LBRC,  KC_RBRC,      KC_BSLS,
  KC_CAPS,   _________________GAMING_L2_________________,  _________________GAMING_R2_________________,  KC_QUOT,              KC_ENT,
  KC_LSFT,   _________________GAMING_L3_________________,  _________________GAMING_R3_________________,  KC_RALT,  KC_UP,     LIGHTS,
  KC_LCTL,  KC_LGUI,  KC_LALT,   KC_SPC,   TD(FN_CTL),   KC_SPC,       FUNC2,  KC_APP,  KC_LEFT,  KC_DOWN,   KC_RGHT),

/* FUNC
 * ,-----------------------------------------------------------------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Bspc| Ins |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     | Home|     |     |     |     | Prnt   |
 * |-----------------------------------------------------------------------------------------+
 * |          |     |     |     | PgDn|     | Left| Down|  Up | Rght|     |     |            |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     | PgUp|     |     | End |     |     |     | PgUp|     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |      |             |      |                 |     |     | Home| PgDn| End |
 * `-----------------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_directional_wrapper(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_BSPC,  KC_INS,
  _______,          _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, _______, _______, _______, _______, KC_PSCR,
  KC_CAPS,      _______, _______, KC_PGDN, _______, _______,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,              _______,
  _______, CAP_WRD, CAMEL, SNAKE, KEBAB, _______, _______, _______, KC_END, _______, _______, _______, KC_PGUP, _______,
  _______, _______, _______,           _______,        _______,           _______,          _______, _______, KC_HOME, KC_PGDN, KC_END),

/* FUNC2
 * ,-----------------------------------------------------------------------------------------.
 * |     | MON1| MON2| MON3|     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |          |     |     |     |     |     |     |     |     |     |     |     |            |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |      |             |      |                 |     |     |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */
[_FUNC2] = LAYOUT_directional_wrapper(
  _______,      MAC, WINDOWS, GAMING, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,    _______, KC_7, KC_8, KC_9, KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,    _______, KC_4, KC_5, KC_6, _______, _______, _______, _______, _______, _______, _______,          _______,
  _______, KC_0, KC_1, KC_2, KC_3, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,           _______,        _______,           _______,         _______, _______, _______, _______, _______),

/* LIGHTS
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |          |     |     |     |     |     |     |     |     |     |     |     |            |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |     | Tog |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |      |             |      |                 |     |     |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */
[_LIGHTS] = LAYOUT_directional_wrapper(
  _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_TW, _______, _______, _______, _______, _______,
  _______,          _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,      RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,              _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______,
  _______, _______, _______,           _______,        _______,           _______,         _______, _______, _______, _______, _______),

/* Adjust (Func + Func2)
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |Reset|
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |          |     |     |     |     |     |     |     |     |     |     |     |            |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |      |     A     |      |                |     |     |Qwerty|      |      |
 * `-----------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_directional_wrapper(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   RESET,
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,          _______,        _______,           _______,         _______, _______,  _______, _______,  _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user_adaviloper(keycode, record)) return false;
    return true;
}
