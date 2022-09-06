enum layers {
  _MAC,
  _WINDOWS,
#ifdef GAMING_ENABLE
  _GAMING,
#endif
#ifdef GIT_ENABLE
  _GIT,
#endif
#ifdef ART_ENABLE
  _ART,
  _ART2,
#endif
  _SYSTEM,
  _FUNC,
  _NAV_AND_MEDIA,
  _SYMBOL,
  _RAISE,
  _FUNC2,
  _ADJUST,
#ifdef RGBLIGHT_LAYERS
  _LIGHTS
#endif
};

uint16_t current_default_layer_adaviloper;

uint16_t get_current_default_layer(void);
void set_default_layer(uint16_t layer);

