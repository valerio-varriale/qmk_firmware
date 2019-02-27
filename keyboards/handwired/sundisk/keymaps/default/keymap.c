/* Copyright 2019 REPLACE_WITH_YOUR_NAME
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

void user_payload(void);

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  A2INCIPIT = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case A2INCIPIT:
      if (record->event.pressed) {
        //SEND_STRING("A Nefertiti, la grande regina.");
        user_payload();
      } else {
        //SEND_STRING(SS_TAP(X_ENTER));
        reset_keyboard();
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = {
    {A2INCIPIT}
  }
};

void matrix_init_user(void) {
    
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {

}

void keyboard_post_init_user(void) {

}


void user_payload(void) {

/*
 * https://www.hak5.org/gear/duck/what-is-the-best-security-awareness-payload-for-the-usb-rubber-ducky
DELAY 1000
ALT F2
DELAY 50
GUI SPACE
DELAY 50
GUI r
DELAY 50
BACKSPACE
DELAY 100
STRING http://example.com
ENTER
*/
    _delay_ms(1000);
    SEND_STRING( SS_LALT(SS_TAP(X_F2)) );
    _delay_ms(100);
    SEND_STRING( SS_LGUI(SS_TAP(X_SPACE)) );
    _delay_ms(100);
    SEND_STRING( SS_LGUI("r") );
    _delay_ms(100);
    SEND_STRING( SS_TAP(X_BSPACE) );
    _delay_ms(100);
    SEND_STRING( "https://www.us-cert.gov/ncas/tips/ST08-001" );
    _delay_ms(100);
    SEND_STRING( SS_TAP(X_ENTER) );

}
