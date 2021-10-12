/* Copyright %YEAR% %YOUR_NAME% 
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

enum custom_keycodes {
    K_COPY = SAFE_RANGE,
    K_CUT, 
    K_PASTE,
    K_UNDO,
	K_REDO,
	ENDSTREAM,
	SCREEN,
	BEATSABER,
	START,
	NLINE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case K_COPY:
        if (record->event.pressed) {
            // when keycode K_COPY is pressed
            register_code16(C(KC_C));
        } else {
            unregister_code16(C(KC_C));
            // when keycode K_COPY is released
        }
        break;	
    case K_PASTE:
        if (record->event.pressed) {
            // when keycode K_PASTE is pressed
            register_code16(C(KC_V));
        } else {
            unregister_code16(C(KC_V));
            // when keycode K_PASTE is released
        }
        break;	
    case K_CUT:
        if (record->event.pressed) {
            // when keycode K_CUT is pressed
            register_code16(C(KC_X));
        } else {
            unregister_code16(C(KC_X));
            // when keycode K_CUT is released
        }
        break;
	case K_UNDO:
        if (record->event.pressed) {
            // when keycode K_UNDO is pressed
            register_code16(C(KC_Z));
        } else {
            unregister_code16(C(KC_Z));
            // when keycode K_UNDO is released
        }
        break;	
	case K_REDO:
        if (record->event.pressed) {
            // when keycode K_REDO is pressed
            register_code16(C(KC_Y));
        } else {
            unregister_code16(C(KC_Y));
            // when keycode K_REDO is released
        }
        break;
	case ENDSTREAM:
        if (record->event.pressed) {
            // when keycode ENDSTREAM is pressed
            register_code16(C(KC_F12));
        } else {
            unregister_code16(C(KC_F12));
            // when keycode ENDSTREAM is released
        }
        break;
	case SCREEN:
        if (record->event.pressed) {
            // when keycode SCREEN is pressed
            register_code16(C(KC_DOT));
        } else {
            unregister_code16(C(KC_DOT));
            // when keycode SCREEN is released
        }
        break;
	case BEATSABER:
        if (record->event.pressed) {
            // when keycode BEATSABER is pressed
            register_code16(C(KC_COMM));
        } else {
            unregister_code16(C(KC_COMM));
            // when keycode BEATSABER is released
        }
        break;
	case START:
        if (record->event.pressed) {
            // when keycode START is pressed
            register_code16(C(KC_BSLS));
        } else {
            unregister_code16(C(KC_BSLS));
            // when keycode START is released
        }
        break;
   case NLINE:
        if (record->event.pressed) {
            // when keycode NLINE is pressed
            register_code16(C(KC_ENT));
        } else {
            unregister_code16(C(KC_ENT));
            // when keycode NLINE is released
        }
        break;	
    }
    return true;
};

enum layers {
    layer0,
    layer1,
	layer2,
	layer3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[layer0] = LAYOUT(
                 TO(layer1),   TO(layer2),   TO(layer3), TO(layer0),
                 KC_PMNS,   KC_UP,   KC_PPLS, KC_F5,
        KC_NO, KC_LEFT,   KC_ESC,   KC_RGHT, KC_TAB,
        KC_NO,  KC_DEL, KC_DOWN, KC_BSPC, KC_ENT
    ),
	
    [layer1] = LAYOUT(
                 K_COPY,   K_CUT,   K_PASTE, TO(layer0),
                 K_UNDO,   K_REDO,   KC_PPLS, KC_BSPC,
        KC_NO, KC_MPRV,   KC_MPLY,   KC_MNXT, KC_MUTE,
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO
    ),
	
    [layer2] = LAYOUT(
                 KC_P7,   KC_P8,   KC_P9, TO(layer0), 
                 KC_P4,   KC_P5,   KC_P6, KC_PMNS,
        KC_NO, KC_P1,   KC_P2,   KC_P3, KC_PPLS,
        KC_NO,  KC_BSPC, KC_P0, KC_DOT, KC_ENT
    ),
	
    [layer3] = LAYOUT(
                 NLINE,   KC_NO,   KC_NO, TO(layer0),
                 KC_NO,   KC_NO,   KC_NO, KC_ENT,
        KC_NO, START,   SCREEN,   BEATSABER, ENDSTREAM,
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder below the controller */
    if (clockwise) {
      tap_code16(KC_VOLD); /*volume down*/
    } else {
      tap_code16(KC_VOLU); /*volume up*/
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code16(C(KC_PMNS)); /*ZOOM_OUT*/
    } else {
      tap_code16(C(KC_PPLS)); /*ZOOM_IN*/
    }
  }
    return true;
}
