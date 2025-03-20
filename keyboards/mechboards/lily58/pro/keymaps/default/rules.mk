WS2812_DRIVER = vendor
# Split keyboard settings
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable NKRO

# Define correct I2C pins for RP2040
I2C1_SDA_PIN = GP2
I2C1_SCL_PIN = GP3

OPT_DEFS += -DHAL_USE_SPI=TRUE
