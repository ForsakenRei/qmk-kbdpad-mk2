/* Copyright 2022 Shigure
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

void matrix_init_user(void)
{   
	rgblight_setrgb(0, 0, 0);
}

layer_state_t layer_state_set_user(layer_state_t layer_state) {
    switch (get_highest_layer(layer_state)) {
        case 1:
            {rgblight_setrgb(170, 204, 17);}
            break;
        case 2: 
            {rgblight_setrgb(255, 153, 0);}
            break;
        case 3:
            {rgblight_setrgb(238, 0, 119);}
            break;
        default:
            {rgblight_setrgb(0, 0, 0);}
            break;
    }
    return layer_state;
}

enum custom_keycodes {
  DS_MUTE = SAFE_RANGE,
  DS_DEAF
};

#define DS_MUTE C(S(KC_M))
#define DS_DEAF C(S(KC_D))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_6x4( /* Base */
    KC_ESC,  KC_CALC, TO(1),   KC_BSPC,
    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    KC_P0,   KC_P0,   KC_PDOT, KC_PENT
  ),
  [1] = LAYOUT_ortho_6x4(
    _______, TG(2),   TG(3),   TO(0),
    KC_F10,  KC_F11,  KC_F12,  KC_PSCR,
    KC_F7,   KC_F8,   KC_F9,   KC_TAB,
    KC_F4,   KC_F5,   KC_F6,   KC_TAB,
    KC_F1,   KC_F2,   KC_F3,   KC_PENT,
    KC_COPY, KC_COPY, KC_PSTE, KC_PENT
  ),
  [2] = LAYOUT_ortho_6x4(
    _______, TO(1),   TG(3),  TO(0),
    KC_F22,  KC_F23,  KC_F24,  KC_RGUI,
    KC_F19,  KC_F20,  KC_F21,  DS_DEAF,
    KC_F16,  KC_F17,  KC_F18,  DS_DEAF,
    KC_F13,  KC_F14,  KC_F15,  DS_MUTE,
    KC_MUTE, KC_MUTE, KC_MUTE, DS_MUTE
  ),
  [3] = LAYOUT_ortho_6x4(
    QK_BOOT, TO(1),   TO(2),   TO(0),
    _______, _______, _______, _______,
    KC_WH_D, KC_MS_U, KC_WH_U, DS_DEAF,
    KC_MS_L, KC_BTN1, KC_MS_R, DS_DEAF,
    KC_WH_L, KC_MS_D, KC_WH_R, DS_MUTE,
    KC_MUTE, KC_MUTE, _______, DS_MUTE
  ),
};
