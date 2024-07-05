# Build Options
#   change yes to no to disable
#
LEADER_ENABLE = yes
#BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
#MOUSEKEY_ENABLE = yes       # Mouse keys
#EXTRAKEY_ENABLE = yes       # Audio control and System control
#CONSOLE_ENABLE = no         # Console for debug
#COMMAND_ENABLE = yes        # Commands for debug and configuration
#NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
# SPLIT_KEYBOARD = yes
TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
SRC += features/layer_lock.c # LLOCK
# for RP2040
#MCU = RP2040
#BOOTLOADER = rp2040
DYNAMIC_MACRO_ENABLE = yes
PIN_COMPATIBLE = promicro
