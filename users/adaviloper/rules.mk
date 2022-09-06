SRC += adaviloper.c
SRC += layers.c

ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
    SRC += auto_shift.c
endif
ifdef CASE_MODES_ENABLE
  SRC += case_modes.c
endif
ifdef COMBO_ENABLE
  SRC += combos.c
endif
ifdef ENCODER_ENABLE
  SRC += encoders.c
endif
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += rgblight_layers.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dance.c
endif
SRC += os_commands.c
SRC += vi_commands.c
LTO_ENABLE = yes
