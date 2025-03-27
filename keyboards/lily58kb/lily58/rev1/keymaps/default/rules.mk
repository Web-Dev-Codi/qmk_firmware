# Configuration settings for Lily58KB with KB2040 MCU
WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor

# Split keyboard settings
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable NKRO
SPLIT_KEYBOARD = yes        # Split keyboard support

SPLIT_WATCHDOG_ENABLE=yes
SPLIT_WATCHDOG_TIMEOUT=2000



# Define correct I2C pins for RP2040
I2C1_SDA_PIN = GP2
I2C1_SCL_PIN = GP3

OPT_DEFS += -DHAL_USE_SPI=TRUE
