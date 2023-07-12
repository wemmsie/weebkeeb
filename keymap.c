#include QMK_KEYBOARD_H

#define _MAIN 0
#define _L2 1

enum custom_keycodes {
    MAIN = SAFE_RANGE,
    L2,
    PWRD,
    EMDASH,
    SCRNSHOT,
};

// Tap Dance declarations
enum {
    TD_LSFT_CAPS,
};

const key_override_t one_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P1, KC_EXLM);  // Shift 1 is !
const key_override_t two_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P2, KC_AT); // Shift 2 is @
const key_override_t three_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P3, KC_HASH);  // Shift 3 is #
const key_override_t four_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P4, KC_DLR); // Shift 4 is $
const key_override_t five_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P5, KC_PERC); // Shift 5 is %
const key_override_t six_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P6, KC_CIRC); // Shift 6 is ^
const key_override_t seven_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P7, KC_AMPR); // Shift 7 is &
const key_override_t eight_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P8, KC_ASTR); // Shift 8 is *
const key_override_t nine_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P9, KC_LPRN); // Shift 9 is (
const key_override_t zero_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_P0, KC_RPRN); // Shift 0 is )

const key_override_t** key_overrides = (const key_override_t*[]){
    &one_key_override,
    &two_key_override,
    &three_key_override,
    &four_key_override,
    &five_key_override,
    &six_key_override,
    &seven_key_override,
    &eight_key_override,
    &nine_key_override,
    &zero_key_override,
    NULL
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
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                                           KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                           KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G,                                          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, QK_CAPS_WORD_TOGGLE,            KC_ENTER, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQUAL,
        TT(1), KC_LWIN, KC_SPC,                                                         KC_ENTER, KC_SPC, KC_LCTL
    ),

    [_L2] = LAYOUT(
        KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL,
        KC_BACKSLASH, LGUI(LSFT(KC_4)), _______, KC_UP, _______, KC_AUDIO_VOL_UP,       KC_MEDIA_NEXT_TRACK, KC_KP_7, KC_KP_8, KC_KP_9, _______, EMDASH,
        LSFT(KC_BACKSLASH), _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MEDIA_PLAY_PAUSE,   KC_AUDIO_MUTE, KC_KP_4, KC_KP_5, KC_KP_6, LSFT(KC_LEFT_BRACKET), LSFT(KC_RIGHT_BRACKET),
        KC_LSFT, _______,KC_HOME, _______, KC_END, KC_AUDIO_VOL_DOWN, KC_SLEP,          KC_ENTER, KC_MEDIA_PREV_TRACK, KC_KP_1, KC_KP_2, KC_KP_3, KC_LEFT_BRACKET, KC_RIGHT_BRACKET,
        _______, _______, PWRD,                                                         KC_ENTER, KC_SPC, KC_KP_0
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PWRD:
            if (record->event.pressed) {
                // SEND_STRING("Pickles84!" SS_TAP(X_ENTER));
                send_string_with_delay("Pickles84!" SS_TAP(X_ENTER), 40);
            }
            return false;
            break;
        case EMDASH:
            if (record->event.pressed) {
                send_string_with_delay(KC_LALT KC_KP_0 KC_KP_1 KC_KP_5 KC_KP_1, 40);
            }
            return false;
            break;
    }
    return true;
}

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

    for (uint8_t i = led_min; i < led_max; i++) {

        if ((i >= 28 && i <= 33) || (i >= 62 && i <= 67)) {
            // underglow
            RGB_MATRIX_INDICATOR_SET_COLOR(i, 50, 50, 50);
        }

        if (get_highest_layer(layer_state) > 0) {

            if ((i >= 41 && i <= 43) || (i >= 48 && i <= 50) || (i >= 53 && i <= 55) || i == 58 || i == 8 || (i >= 14 && i <= 16)) {
                // numpad
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 115, 7, 7);
            }
            else if ((i >= 44 && i <= 45) || i == 10) {
                // plus equal and screnshot key
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 133, 119, 0);
            }
            else if ((i >= 56 && i <= 57) || i == 21 || i == 19) {
                // brackets and home / end
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 17, 59, 100);
            }
            else if ( i == 0 || (i >= 11 && i <= 12) || (i >= 46 && i <= 47)) {
                // left modifiers and curly brackets
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 110, 4);
            }
        }
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(23, 133, 7, 7);
    }
    return true;
}

void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}