SRC += adaviloper.c

ifdef CASE_MODES_ENABLE
  SRC += case_modes.c
  SRC += caps_mock.c
endif
ifdef ENCODER_ENABLE
  SRC += encoders.c
endif
ifdef GIT_ENABLE
  SRC += git.c
endif
ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled.c
endif
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += rgblight_layers.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dance.c
endif
SRC += os_commands.c
SRC += vi_commands.c
SRC += repeat_keys.c
LTO_ENABLE = yes
