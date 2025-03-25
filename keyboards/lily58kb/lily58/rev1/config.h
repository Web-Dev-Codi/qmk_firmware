// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// USB and Power Management Configuration
#define USB_SUSPEND_WAKEUP_DELAY 0
#define NO_USB_SUSPEND_ENABLE
#define USB_SUSPEND_CLEAR_KEYBOARD 1
#define USB_POLLING_INTERVAL_MS 10   // Increased from 1ms to reduce chattering

// Debounce configuration
#define DEBOUNCE 8
#define DEBOUNCE_TYPE SYM_DEFER_G

#define FORCE_BOOT_PROTOCOL    // Forces boot protocol instead of NKRO
#define NO_USB_STARTUP_CHECK   // Disables USB suspend check after keyboard startup

// Split keyboard settings
// Use USB detection instead of pin detection for RP2040
#define SPLIT_HAND_PIN_LOW
#define MASTER_LEFT
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_TRANSACTION_IDS_KB SYNC_WPM

// Tapping settings
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2
#define PERMISSIVE_HOLD