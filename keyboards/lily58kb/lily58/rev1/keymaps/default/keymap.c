/* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
  * Copyright 2025 Web-Dev-Codi (https://github.com/web-dev-codi)
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

#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum layers {
    _QWERTZ,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTZ
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   {  |   }  |   (  |   )  |  [   |                    |   ]  |   $  |   %  |   &  |   |  |   #  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;: |  ""  |
 * |------+------+------+------+------+------|KC_DOWN|    | KC_UP |------+------+------+------+------+------|
 * |LCTRL|   Y  |   X  |   C  |   V  |   B   |-------|    |-------|   N  |   M   |  ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTZ] = LAYOUT(
  KC_ESC ,KC_LCBR,KC_RCBR,KC_LPRN,KC_RPRN,KC_LBRC,                     KC_RBRC,KC_DLR ,KC_PERC,KC_AMPR,KC_PIPE,KC_HASH,
  KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                     KC_Z   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_MINS,
  KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                     KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
  KC_LCTL,KC_Y   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_DOWN,      KC_UP ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                          KC_LALT,KC_LGUI,LOWER  ,KC_SPC ,      KC_ENT,RAISE  ,KC_BSPC,KC_RCTL
),
/* LOWER                                                                Music Controls
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  ""  |      |      |      |  /   |                    | VOLUP| VOLDN| PREV | NEXT | STOP | PLAY |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| MENU |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT(
  _______,KC_QUOTE,_______,_______,_______,KC_SLSH,                    KC_VOLU,KC_VOLD,KC_MPRV,KC_MNXT,KC_MSTP,KC_MPLY,
  KC_F1  ,KC_F2   ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                    KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
  KC_GRV ,KC_EXLM ,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                    KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_TILD,
  _______,_______ ,_______,_______,_______,_______,KC_LBRC,    KC_RBRC,KC_MENU,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,
                           _______,_______,_______,KC_SPC ,    KC_ENT ,_______,_______,_______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |   1  |   2  |  3   |PSCRN |  Up  |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |      |      |LST+LT|LSF+LA|                    |   4  |   5  |  6   | Left |      | Right|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  WM1 |  WM2 |  WM3 |  WM4 |  WM5 | WM6  |-------.    ,-------|   7  |   8  |  9   |      | Down |      |
 * |------+------+------+------+------+------|KC_DOWN|    | KC_UP |------+------+------+------+------+------|
 * |  WM7 |  WM8  |     |      |      |      |-------|    |-------|   +  |   0  |  =   |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

// LGUI(KC_1) to LGUI(KC_8) are used for the workspace management in hyprland. Each workspace is assigned to a key, totalled 8 workspaces.
// LGUI(KC_LSFT(KC_1)) to LGUI(KC_LSFT(KC_8)) are used for moving focused window to KC number that is specified.

[_RAISE] = LAYOUT(
  LGUI(KC_1)         ,LGUI(KC_2)         ,LGUI(KC_3)         ,LGUI(KC_4)         ,LGUI(KC_5)         ,LGUI(KC_6),                                   KC_1   ,KC_2   ,KC_3   ,KC_PSCR,KC_UP  ,KC_DEL  ,
  LGUI(KC_7)         ,LGUI(KC_8)         ,_______            ,_______            ,LSFT(KC_LALT)      ,LCTL(KC_D),                                   KC_4   ,KC_5   ,KC_6   ,KC_LEFT,_______,KC_RIGHT,
  LGUI(KC_LSFT(KC_1)),LGUI(KC_LSFT(KC_2)),LGUI(KC_LSFT(KC_3)),LGUI(KC_LSFT(KC_4)),LGUI(KC_LSFT(KC_5)),LGUI(KC_LSFT(KC_6)),                          KC_7   ,KC_8   ,KC_9   ,_______,KC_DOWN,XXXXXXX ,
  LGUI(KC_LSFT(KC_7)),LGUI(KC_LSFT(KC_8)),_______            ,_______            ,_______            ,_______            ,KC_DOWN,           KC_UP ,KC_PLUS,KC_P0  ,KC_PEQL,KC_LBRC,KC_RBRC,KC_BSLS ,
                                                                                  _______            ,_______            ,_______,KC_SPC,    KC_ENT,_______,_______,_______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | BOOT |CLREPM|      |      | MS_UP|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | MS_LT|      | MS_RT|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | MS_DW|      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |KC_PWR|SLEEP |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_ADJUST] = LAYOUT(
  QK_BOOT,EE_CLR ,XXXXXXX,XXXXXXX,MS_UP  ,XXXXXXX,                    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,LSFT(LCTL(KC_3))   ,
  XXXXXXX,XXXXXXX,XXXXXXX,MS_LEFT,XXXXXXX,MS_RGHT,                    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,LSFT(LCTL(KC_MINS)),
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,MS_DOWN,XXXXXXX,                    XXXXXXX,XXXXXXX,UG_TOGG,UG_HUEU,UG_SATU,UG_VALU            ,
  KC_PWR ,KC_SLEP,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,UG_NEXT,UG_HUED,UG_SATD,UG_VALD            ,
                          _______,_______,_______,_______,    _______,_______,_______,_______
  )
};
