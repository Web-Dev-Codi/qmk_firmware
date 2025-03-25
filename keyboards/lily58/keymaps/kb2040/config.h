/*
 * Copyright 2023
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once



// Use the lily version to get the Lily58 logo instead of the qmk logo
#define OLED_FONT_H "lib/glcdfont_lily.c"

// RP2040 specific configuration for KB2040
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED 17  // Using pin number directly instead of GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// OLED Configuration
#define OLED_DISPLAY_128X32
#define OLED_TIMEOUT 120000
#define OLED_BRIGHTNESS 128

// I2C Configuration for RP2040


// Split keyboard settings
// Use USB detection instead of pin detection for RP2040
#define SPLIT_HAND_PIN_LOW
#define MASTER_LEFT
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_TRANSACTION_IDS_KB SYNC_WPM

// Serial configuration for split keyboard
#define SERIAL_DRIVER vendor
#define SERIAL_PIN GP20  // Using pin number directly instead of GP20
#define SERIAL_PIO_USE_PIO1
// We don't need to redefine SERIAL_USART_TX_PIN as it will use SERIAL_PIN

// RGB configuration
#define RGB_DI_PIN GP16  // Using pin number directly instead of GP16

#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE

// Tapping settings
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2
#define PERMISSIVE_HOLD