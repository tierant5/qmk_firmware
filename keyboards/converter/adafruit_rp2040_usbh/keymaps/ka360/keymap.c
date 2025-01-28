/* Copyright 2021 Michael Stapelberg
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

#include "lkg_km_common.h"
//#include "lkg_tap_dances.h"
#include "lkg_combos.h"

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*

   Keymap: Default Layer in QWERTY
   Show only keys sent over USB (aka re-mappable by QMK)

   ,-------------------------------------------------------------------------------------------------------------------.
   | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8   |  9(  |  0)  | -_     |
   |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
   | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
   | Esc    |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
   | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,<  |  .>  |  /?  | Shift  |
   `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
            |  `~  | CAPS | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
            `---------------------------'                                         `---------------------------'
                                          ,-------------.         ,--------------.
                                          | CTRL | ALT  |         | GUI   | CTRL |
                                   ,------|------|------|         |-------+------+------.
                                   |      |      | HOME |         | PGUP  |      |      |
                                   | BSPC | DEL  |------|         |-------| ENTR | SPC  |
                                   |      |      | END  |         | PGDN  |      |      |
                                   `--------------------'         `---------------------'
 */

[0] = LAYOUT_ka360(
	    KC_EQL, KC_1,    KC_2,          KC_3,           KC_4,           KC_5,       KC_6,  KC_7,        KC_8,           KC_9,           KC_0,       KC_MINS,
LALT_T(KC_TAB), KC_Q,    KC_W,          KC_E,           KC_R,           KC_T,       KC_Y,  KC_U,        KC_I,           KC_O,           KC_P,       LALT_T(KC_BSLS),
LCTL_T(KC_ESC), KC_A,    LALT_T(KC_S),  LSFT_T(KC_D),   LCTL_T(KC_F),   KC_G,       KC_H,  LCTL_T(KC_J),LSFT_T(KC_K),   LALT_T(KC_L),   KC_SCLN,    LCTL_T(KC_QUOT),
	   KC_LSFT, KC_Z,    KC_X,          KC_C,           KC_V,           KC_B,       KC_N,  KC_M,        KC_COMM,        KC_DOT,         KC_SLSH,    KC_LSFT,

			      KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,

                           KC_NO,                    KC_NO,                                  KC_NO,                    KC_NO,
                           KC_NO,                    KC_NO,                                  KC_NO,                    KC_NO,
			             KC_BSPC,             LT(1,KC_DEL),                         LT(2,KC_ENTER),                   KC_SPC),

[1] = LAYOUT_ka360(
	     KC_NO,      KC_NO,     KC_NO,      KC_NO,      KC_NO,    KC_NO,           KC_NO,      KC_NO,      KC_NO,      KC_NO,           KC_NO,   KC_NO,
LALT_T(KC_TAB),    S(KC_1),   S(KC_2),    S(KC_3),    S(KC_4),  S(KC_5),         S(KC_6),    S(KC_7),    S(KC_8), S(KC_BSLS),         KC_BSLS, KC_TRNS,
LCTL_T(KC_ESC),     KC_GRV, S(KC_GRV), S(KC_MINS),     KC_EQL,  KC_MINS,       S(KC_EQL),    S(KC_9),    S(KC_0),    KC_LBRC, LGUI_T(KC_RBRC), KC_TRNS,
	   KC_TRNS, S(KC_SCLN),   KC_SCLN,    KC_QUOT, S(KC_QUOT),  KC_SLSH,         KC_COMM, S(KC_LBRC), S(KC_RBRC),     S(KC_COMM),      S(KC_DOT), KC_TRNS,

			      KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,

                           KC_NO,                    KC_NO,                            KC_NO,                    KC_NO,
                           KC_NO,                    KC_NO,                            KC_NO,                    KC_NO,
			             KC_TRNS,                  KC_TRNS,                   LT(3,KC_ENTER),                  KC_TRNS),

[2] = LAYOUT_ka360(
  KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,  KC_NO,    KC_NO,          KC_NO,          KC_NO,          KC_NO,           KC_NO,   KC_NO,
KC_TRNS,         KC_1,         KC_2,         KC_3,         KC_4,   KC_5,     KC_6,           KC_7,           KC_8,           KC_9,            KC_0, KC_TRNS,
KC_TRNS, LGUI_T(KC_B), LALT_T(KC_H), LSFT_T(KC_D), LCTL_T(KC_X), KC_F11,   KC_F12, LCTL_T(KC_SPC), LSFT_T(KC_ENT), LALT_T(KC_DOT), LGUI_T(KC_SCLN), KC_TRNS,
KC_TRNS,        KC_F1,        KC_F2,        KC_F3,        KC_F4,  KC_F5,    KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10, KC_TRNS,

			      KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,

                           KC_NO,                    KC_NO,                            KC_NO,                    KC_NO,
                           KC_NO,                    KC_NO,                            KC_NO,                    KC_NO,
			             KC_TRNS,             LT(3,KC_DEL),                          KC_TRNS,                 KC_TRNS),

[3] = LAYOUT_ka360(
  KC_NO,          KC_NO,          KC_NO,    KC_NO,          KC_NO,      KC_NO,      KC_NO,       KC_NO,   KC_NO,   KC_NO,          KC_NO,   KC_NO,
KC_TRNS,     KC_MS_LEFT,     KC_MS_DOWN, KC_MS_UP,    KC_MS_RIGHT, KC_MS_BTN1,    KC_MPRV, TD(DANCE_2), KC_VOLD, KC_VOLU,        KC_MNXT, KC_TRNS,
KC_TRNS, LGUI_T(KC_TAB), LALT_T(KC_ESC),  KC_LSFT, LCTL_T(KC_TAB), KC_MS_BTN2,    KC_LEFT,     KC_DOWN,   KC_UP, KC_RGHT, LGUI_T(KC_INS), KC_TRNS,
KC_TRNS,         KC_PWR,    TD(DANCE_1),  KC_BRID,        KC_BRIU, KC_MS_BTN3,    KC_HOME,     KC_PGDN, KC_PGUP,  KC_END,        KC_SCRL, KC_TRNS,

			      KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,

                           KC_NO,                    KC_NO,                            KC_NO,                    KC_NO,
                           KC_NO,                    KC_NO,                            KC_NO,                    KC_NO,
			             KC_TRNS,                  KC_TRNS,                          KC_TRNS,                 KC_TRNS)
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[3];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: layer_move(4); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: layer_move(4); break;
        case DOUBLE_SINGLE_TAP: layer_move(4); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SYSTEM_WAKE);
        tap_code16(KC_SYSTEM_WAKE);
        tap_code16(KC_SYSTEM_WAKE);
    }
    if(state->count > 3) {
        tap_code16(KC_SYSTEM_WAKE);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_SYSTEM_WAKE); break;
        case SINGLE_HOLD: register_code16(KC_SYSTEM_SLEEP); break;
        case DOUBLE_TAP: register_code16(KC_SYSTEM_WAKE); register_code16(KC_SYSTEM_WAKE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SYSTEM_WAKE); register_code16(KC_SYSTEM_WAKE);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_SYSTEM_WAKE); break;
        case SINGLE_HOLD: unregister_code16(KC_SYSTEM_SLEEP); break;
        case DOUBLE_TAP: unregister_code16(KC_SYSTEM_WAKE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SYSTEM_WAKE); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[2].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};

