BOOTMAGIC_ENABLE = no	# Virtual DIP switch configuration(+1000)
CASE_MODES_ENABLE = yes
COMBO_ENABLE = yes
EXTRAFLAGS += -flto     # Link time optimization. Incompatible with `NO_ACTION_MACRO` and `NO_ACTION_FUNCTION` in `config.h`
MOUSEKEY_ENABLE = yes	# Mouse keys(+4700)
RGBLIGHT_ENABLE = yes
TAP_DANCE_ENABLE = yes
VIA_ENABLE = yes
VIAL_ENABLE = yes
# Boot Section Size in *bytes*
OPT_DEFS += -DBOOTLOADER_SIZE=4096
