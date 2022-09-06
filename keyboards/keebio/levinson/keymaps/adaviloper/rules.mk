AUTO_SHIFT_ENABLE = yes
BOOTMAGIC_ENABLE = no	# Virtual DIP switch configuration(+1000)
CASE_MODES_ENABLE = yes
COMBO_ENABLE = yes
EXTRAFLAGS += -flto     # Link time optimization. Incompatible with `NO_ACTION_MACRO` and `NO_ACTION_FUNCTION` in `config.h`
TAP_DANCE_ENABLE = yes

# Boot Section Size in *bytes*
OPT_DEFS += -DBOOTLOADER_SIZE=4096
