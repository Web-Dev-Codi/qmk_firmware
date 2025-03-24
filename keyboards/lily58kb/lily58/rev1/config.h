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