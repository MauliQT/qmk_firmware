/* Copyright %2022% %MauliQT% 
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

enum {
    BASE = 0,
    PHOTOSHOP,
    NUMPAD,
    TEST   
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
                 TO(PHOTOSHOP),   TO(NUMPAD),   TO(NA), TO(BASE),
                 KC_PPLS,   KC_up,   KC_PMNS, KC_F5,
        KC_MUTE, KC_LEFT,   KC_ESC,   KC_RGHT, KC_TAB,
        KC_ESC,  KC_DEL, KC_down, KC_BSPC, KC_ENT
    ),
    [PHOTOSHOP] = LAYOUT(
                 CUT,   PASTE,   COPY, TO(BASE),
                 UNDO,   REDO,   KC_RGHT, KC_TAB,
        KC_MUTE, KC_MPRV,   KC_MPLY,   KC_MNXT, KC_MUTE,
        KC_ESC,  KC_DEL, KC_NO, KC_NO, KC_ENT
    ),
    [NUMPAD] = LAYOUT(
                 KC_P7,   KC_P8,   KC_P9, TO(BASE),
                 KC_P4,   KC_P5,   KC_P6, KC_PMNS,
        KC_MUTE, KC_P1,   KC_P2,   KC_P3, KC_PPLS,
        KC_ESC,  KC_DEL, KC_P0, KC_PDOT, KC_PENT
    ),  
    [TEST] = LAYOUT(
                 TEST,   TEST,   TEST, TO(BASE),
                 TEST,   TEST,   TEST, TEST,
        TEST, TEST,   TEST,   TEST, TEST,
        TEST,  TEST, TEST, TEST, TEST
              //Currently no purpose, feel free to edit
    ) 
};

enum custom_keycode16s {
    COPY = SAFE_RANGE, 
    CUT,               
    PASTE,            
    UNDO,              
    REDO,              
    TEST    
      //just some macros, feel free to edit
/};

bool process_record_user(uint16_t keycode16, keyrecord_t record) {
    switch (keycode16) {
    case COPY:
        if (record->event.pressed) {
            // when keycode16 COPY is pressed
            register_code16(KC_LCTL(C));
        } else {
          unregister_code16(KC_LCTL(C))
            // when keycode16 COPY is released
        }
        break;
    case PASTE:
        if (record->event.pressed) {
            // when keycode16 PASTE is pressed
            register_code16(KC_LCTL(V));
        } else {
            unregister_code16(KC_LCTL(V))
            // when keycode16 PASTE is released
        }
        break;
    case CUT:
        if (record->event.pressed) {
            // when keycode16 CUT is pressed
            register_code16(KC_LCTL(X));
        } else {
            unregister_code16(KC_LCTL(X))
            // when keycode16 CUT is released
        }
        break;
        case TEST:
        if (record->event.pressed) {
            // when keycode16 TEST is pressed
            SEND_STRING("TEST");
            register_code16(KC_PENT);
        } else {
            SEND_STRING("TEST");
            unregister_code16(KC_PENT)
            // when keycode16 TEST is released
        }
        break;
case UNDO:
        if (record->event.pressed) {
            // when keycode16 UNDO is pressed
            register_code16(KC_LCTL(Z))
        } else {
            unregister_code16(KC_LCTL(Z))
            // when keycode16 UNDO is released
        }
        break;
case REDO:
        if (record->event.pressed) {
            // when keycode16 REDO is pressed
            register_code16(KC_LCTL);
            register_code16(Y);
        } else {
            unregister_code16(KC_LCTL)
            unregister_code16(Y)
            // when keycode16 REDO is released
        }
        break;        
    }
   return true;
};

bool encode16r_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { / First encode16r below the controller /
    if (clockwise) {
      tap_code16(KC_VOLD); /volume down/
    } else {
      tap_code16(KC_VOLU); /volume up/
                 //Just plain audio controlle
    }
  } else if (index == 1) { / Second encode16r /
    if (clockwise) {
      tap_code16(C(KC_PMNS); /ZOOM IN/               
    } else {
      tap_code16(C(KC_PPLS); /ZOOM OUT*/                 //Photoshop zoom config
    }
  }
    return true;
}
