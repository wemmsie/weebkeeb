#include QMK_KEYBOARD_H

#define _MAIN 0
#define _L2 1

enum custom_keycodes {
    MAIN = SAFE_RANGE,
    L2,
    PWRD,
    SCRNSHOT,
};

// Tap Dance declarations
enum {
 TD_LSFT_CAPS,
};


/*#####################################
############## TAP DANCE ##############
#####################################*/

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

// TD(TD_LSFT_CAPS)
// LSFT_T(KC_CAPS)

/*#####################################
############## MATRIX ##############
#####################################*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                            KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                            KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
      KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G,                           KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
      TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCTL,         KC_ENTER, KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH, _______,
      TT(1), KC_LWIN, KC_SPC,                                          KC_ENTER, KC_SPC, _______
  ),

  [_L2] = LAYOUT(
      KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
      KC_BACKSLASH, _______, _______, KC_UP, _______, KC_MEDIA_NEXT_TRACK,               KC_AUDIO_VOL_UP, KC_KP_7, KC_KP_8, KC_KP_9, LSFT(KC_EQUAL), KC_EQUAL,
      LSFT(KC_BACKSLASH), _______, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_MEDIA_PLAY_PAUSE,           KC_AUDIO_MUTE, KC_KP_4, KC_KP_5, KC_KP_6, LSFT(KC_LEFT_BRACKET), LSFT(KC_RIGHT_BRACKET),
      KC_LSFT, _______,KC_HOME, _______, KC_END, KC_MEDIA_PREV_TRACK, PWRD,       KC_SPC, KC_AUDIO_VOL_DOWN, KC_KP_1, KC_KP_2, KC_KP_3, KC_LEFT_BRACKET, KC_RIGHT_BRACKET,
      _______, _______, SCRNSHOT,                                                   KC_SPC, KC_ENTER, KC_KP_0
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case PWRD:
          if (record->event.pressed) {
              SEND_STRING("Pickles84!" SS_TAP(X_ENTER));
          }
          return false;
          break;
          
      case SCRNSHOT: // Screenshot on Mac that will create crosshairs; click-drag required to complete screenshot
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            tap_code(KC_4);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
          }
          return false;
          break;
  }
  return true;
};

/*#####################################
############ RGB LED SETUP ############
#####################################*/

uint8_t min(uint8_t a, uint8_t b) {
   if (a < b) {
      return a;
   }
   return b;
}

uint8_t max(uint8_t a, uint8_t b) {
   if (a > b) {
       return a;
   }
    return b;
}

void set_range(uint8_t start, uint8_t stop, uint8_t led_min, uint8_t led_max, uint8_t red, uint8_t green, uint8_t blue) {
    if (stop < led_min || led_max < start) {
        // Out of range
        return;
   }
    for(uint8_t i=max(start, led_min); i < min(stop, led_max); i++) {
        rgb_matrix_set_color(i, red, blue, green);
   }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (get_highest_layer(layer_state) > 0) {

        for (uint8_t i = led_min; i < led_max; i++) {
            
            if ((i >= 41 && i <= 43) || (i >= 48 && i <= 50) || (i >= 53 && i <= 55) || i == 58) {
                // numpad
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 250, 55, 55);
            }
            else if (i == 8 || (i >= 14 && i <= 16)) {
                // arrow keys
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 250, 55, 55);
            }
            else if ((i >= 44 && i <= 45)) {
                // plus equal
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 198 ,107, 250);
            }
            else if ((i >= 46 && i <= 47)) {
                // curly brackets
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 107, 129, 250);
            }
            else if ((i >= 56 && i <= 57)) {
                 // brackets
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 107, 191, 250);
            }
            else if ( i == 0 || (i >= 11 && i <= 12)) {
                // left modifiers
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 245, 221, 66);
            }
        }
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(23, 217, 33, 33);
    }
    return true;
}