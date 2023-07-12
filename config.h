/*
Copyright 2022 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define EE_HANDS
#define SPLIT_LAYER_STATE_ENABLE
#define RGB_MATRIX_KEYPRESSES
#define USB_MAX_POWER_CONSUMPTION 500


/* Set tapping term for tapdance */
#define TAPPING_TERM 150
#define CAPS_WORD_IDLE_TIMEOUT 10000

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { B1, F0, F5, B4, D7 }
#define MATRIX_COL_PINS { F1, F4, B5, C7, D4, D6 }
#define MATRIX_ROW_PINS_RIGHT { B1, F0, F5, B4, B5 }
#define MATRIX_COL_PINS_RIGHT { D4, D6, D7, C7, F1, F4 }
#define SPLIT_HAND_PIN D5

#define ENCODERS_PAD_A { B3, F6 }
#define ENCODERS_PAD_B { B2, F7 }
#define ENCODERS_PAD_A_RIGHT { B3, F6 }
#define ENCODERS_PAD_B_RIGHT { B2, F7 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* ws2812 RGB LED */
#define RGB_DI_PIN E6
#ifdef RGB_DI_PIN
#   define RGBLED_NUM 68
#   define RGBLED_SPLIT { 34, 34 }
#   define RGBLIGHT_HUE_STEP 8
#   define RGBLIGHT_SAT_STEP 8
#   define RGBLIGHT_VAL_STEP 8
#   define RGBLIGHT_EFFECT_RGB_TEST
#   define RGBLIGHT_LAYERS_RETAIN_VAL

#   define RGBLIGHT_SLEEP         /* If defined, the RGB lighting will be switched off when the host goes to sleep */

#   define RGBLIGHT_DEFAULT_VAL 130
#   define RGBLIGHT_LIMIT_VAL 130

#   define RGB_MATRIX_LAYERS_RETAIN_VAL
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 130
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#   define RGB_MATRIX_DEFAULT_HUE 30
#   define RGB_MATRIX_DEFAULT_SAT 25
#   define RGB_MATRIX_DEFAULT_VAL 100


// RGB Matrix
//#    ifdef RGB_MATRIX_ENABLE
#   define ENABLE_RGB_MATRIX_ALPHAS_MODS
 
#   define RGB_MATRIX_LED_COUNT RGBLED_NUM
#   define RGB_MATRIX_SPLIT { 34, 34 }
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true
#   define RGB_MATRIX_KEYPRESSES
#   define RGB_MATRIX_TIMEOUT 600000
//#    endif
#endif

