#include "cospad.h"
#include "led.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _TL 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 

[_BL] = KEYMAP(
  KC_PPLS,  KC_PMNS,  KC_PENT,   KC_RIGHT, \
  KC_PAST,  KC_PSLS,  KC_UP,   KC_DOWN, \
  TG(2),    KC_PGUP,    KC_PGDN,     KC_LEFT,  \
  KC_P9,    KC_P6,    KC_P3,     KC_PDOT, \
  KC_P8,    KC_P5,    KC_P2,     KC_P0, \
  KC_P7,    KC_P4,    KC_P1,   TG(1)),

[_FL] = KEYMAP(
  KC_VOLU,  KC_VOLD,   KC_TRNS,   KC_MNXT, \
  KC_TRNS,  KC_MUTE,  KC_MSTP,   KC_MPLY, \
  KC_TRNS, KC_TRNS, KC_TRNS,     KC_MPRV, \
  KC_F21, KC_F18, KC_F15, KC_TRNS,   \
  KC_F20, KC_F17, KC_F14, KC_TRNS, \
  KC_F19, KC_F16, KC_F3, KC_TRNS,

[_TL] = KEYMAP(
  RESET, KC_POWER, KC_SLEP, KC_WAKE, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  BL_OFF, RGB_M_P, RGB_VAI, RGB_VAD, \
  BL_ON, RGB_MOD, RGB_SAI, RGB_SAD, \
  BL_TOGG, RGB_TOG,RGB_HUI, RGB_HUD,
 
};


const uint16_t PROGMEM fn_actions[] = {
    [0] = MO(_FL),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case BL_TOGG:
         if (record->event.pressed) {
            cospad_bl_led_togg();
         }
         return false;
      case BL_ON:
         if (record->event.pressed) {
            cospad_bl_led_on();
         }
         return false;
      case BL_OFF:
         if(record->event.pressed) {
            cospad_bl_led_off();
         }
         return false;
      default:
         return true;
   }
}
