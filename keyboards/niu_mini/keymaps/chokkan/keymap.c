/* Copyright 2015-2017 Jack Humbert
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

#include "niu_mini.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

//Helpful defines
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layers
#define _QWERT 0   // QWERTY
#define _FUN1 1      // Function layer 1
#define _FUN2 2      // Function layer 2
#define _RGB_MAC 3 // Function layer 3

enum custom_keycodes{
  QWERT = SAFE_RANGE,
  FUN1,      // Symbols and arrows
  FUN2,      // Numbers and F row
  RGB_MAC, // LED control and macros.
};

// Macros
enum {
  M_EMAIL = SAFE_RANGE,
  M_YT,
  M_TWIT,
  M_WANT,
};

//Tap Dance Declarations
enum {
  TD_SPC_ENT = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERT Default layer
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Tab  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ?  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | J<>E | FUN1 | Space / ENT | FUN2 |  Alt | GUI  | Ctrl | FN3  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERT] = {
  {KC_ESC,        KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TAB},
  {KC_BSPC,       KC_A,           KC_S,           KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {OSM(MOD_LSFT), KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES, OSM(MOD_RSFT) },
  {CTL_T(KC_UNDO), GUI_T(KC_COPY) , ALT_T(KC_PASTE), LALT(KC_LSFT), MO(_FUN1),  TD(TD_SPC_ENT), XXXXXXX,  MO(_FUN2), RALT_T(KC_CAPS), RGUI_T(KC_WBAK), RCTL_T(KC_WFWD), MO(_RGB_MAC)}
},

/* 1 First function layer
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   ¥  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |      |      | Lft  | Up   | PgUp | PgDn | Tab  | Rgt  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      | Dwn  | Home |  End |      |      |      |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      | FUN1 |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN1] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN,  KC_JYEN},
  {KC_BSPC, XXXXXXX, KC_LSFT, KC_LEFT, KC_UP,   KC_PGUP, KC_PGDN, KC_TAB, KC_RIGHT, KC_LCBR, KC_RCBR,  KC_PIPE},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, KC_HOME, KC_END, XXXXXXX, XXXXXXX,   XXXXXXX, KC_SLSH,  XXXXXXX},
  {_______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,  _______, _______,  _______}
},


/* 2 Second function layer
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   -  |  =   |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN2] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {KC_BSPC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MINUS, KC_EQL, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______}
},


/* RGB_MAC RGB Effects (Brea = breathing)
 * ,-----------------------------------------------------------------------------------.
 * | email|  YT | twit  | want |       |      |      |     | Prev | Play | Next | Mute |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |RGBTog|Plain | Brea |  HUI |  HUD |      |      |      |      |  Up  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |RGBSa+|RGBSa-|RGBVa+|RGBVa-|      |      |      | Left | Down | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |      |      |      |             |      |      |      |      | FN3  |
 * `-----------------------------------------------------------------------------------'
 */
[_RGB_MAC] = {
  {M_EMAIL,    M_YT,    M_TWIT,    M_WANT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE},
  {RGB_TOG, RGB_M_P, RGB_M_B, RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX},
  {XXXXXXX, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX},
  {RESET  , _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______}
}

};




//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
   //Tap for Space, double tap for Enter
  [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT)
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_ONESHOT(MOD_LSFT),
    [1] = ACTION_MODS_ONESHOT(MOD_LALT),
    [2] = ACTION_MODS_ONESHOT(MOD_LCTL)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case M_EMAIL:
                SEND_STRING("chokkanletsplay@gmail.com");
                return false; break;
            case M_YT:
                SEND_STRING("https://www.youtube.com/channel/UCtLJJRsmtUgCWLj_Ud9URfA");
                return false; break;
            case M_TWIT:
                SEND_STRING("https://twitter.com/Chokkan");
                return false; break;
            case M_WANT:
                SEND_STRING("I really want that keyboard.");
                return false; break;
        }
    }
    return true;
};

