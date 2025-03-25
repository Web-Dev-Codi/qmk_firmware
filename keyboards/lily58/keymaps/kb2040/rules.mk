# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes        # Split keyboard support
OLED_ENABLE = yes           # Enable OLED display
#OLED_DRIVER = SSD1306       # OLED driver
WPM_ENABLE = yes            # Enable WPM counter





# Serial driver
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

# Enable link-time optimization to reduce firmware size
LTO_ENABLE = yes

# Include additional source files for OLED display
SRC += lib/rgb_state_reader.c \
       lib/layer_state_reader.c \
       lib/logo_reader.c \
       lib/keylogger.c