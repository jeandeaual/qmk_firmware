/* Copyright 2021 Alexis Jeandeau
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

#pragma once

// clang-format off
// ................................................................... Dvorak MU

// ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │   "  │   ,  │   .  │   P  │   Y  │  Fn  │ Caps │   F  │   G  │   C  │   R  │   L  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   A  │   O  │   E  │   U  │   I  │Cursor│ Mouse│   D  │   H  │   T  │   N  │   S  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   ;  │   Q  │   J  │   K  │   X  │  Num │ Regex│   B  │   M  │   W  │   V  │   Z  │
// └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
//                             │  Esc │ Space│  Ent │ Bksp │
//                             └──────┴──────┴──────┴──────┘

[_BASE] = LAYOUT(
    TD_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    CNTR_TL, CNTR_TR, KC_F,    KC_G,    KC_C,    KC_R,    KC_L   ,
    HOME_A,  HOME_O,  HOME_E,  HOME_U,  KC_I,    CNTR_HL, CNTR_HR, KC_D,    HOME_H,  HOME_T,  HOME_N,  HOME_S ,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    CNTR_BL, CNTR_BR, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z   ,
                                        LT_ESC,  TD_SPC,  TD_ENT,  LT_BSPC
),

[_SHIFT] = LAYOUT(
    TD_QUOT, KC_COMM, KC_DOT,  S(KC_P), S(KC_Y), CNTR_TL, CNTR_TR, S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L),
    S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), CNTR_HL, CNTR_HR, S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S),
    KC_SCLN, S(KC_Q), S(KC_J), S(KC_K), S(KC_X), CNTR_BL, CNTR_BR, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z),
                                        LT_ESC,  TD_SPC,  TD_ENT,  LT_BSPC
),

// ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │   "  │   ,  │   [  │   ]  │   Y  │  Fn  │ Caps │   F  │   G  │   C  │   R  │   L  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   A  │   ^  │   <  │   >  │   ~  │Cursor│ Mouse│   D  │   H  │   T  │   N  │   S  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   :  │   Q  │   !  │   =  │   `  │  Num │ Regex│   B  │   M  │   W  │   V  │   Z  │
// └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
//                             │ ↑Tab │  f() │   _  │  Del │
//                             └──────┴──────┴──────┴──────┘

[_LSHIFT] = LAYOUT(
    TD_DQOT, KC_COMM, KC_LBRC, KC_RBRC, S(KC_Y), CNTR_TL, CNTR_TR, S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L),
    S(KC_A), KC_CIRC, TD_LT,   TD_GT,   TD_TILD, CNTR_HL, CNTR_HR, S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S),
    TD_COLN, S(KC_Q), KC_EXLM, TD_EQL,  TD_GRV,  CNTR_BL, CNTR_BR, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z),
                                        S_TAB,   ___fn__, KC_UNDS, SL_DEL
),

// ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │   "  │   /  │   ?  │   P  │   Y  │  Fn  │ Caps │   F  │   {  │   }  │   R  │   L  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   A  │   O  │   E  │   U  │   I  │Cursor│ Mouse│   │  │   (  │   )  │   $  │   S  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   :  │   Q  │   J  │   K  │   X  │  Num │ Regex│   \  │   *  │   .  │   V  │   Z  │
// └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
//                             │  Tab │   -  │  f() │ Bksp |
//                             └──────┴──────┴──────┴──────┘

[_RSHIFT] = LAYOUT(
    TD_DQOT, KC_SLSH, KC_QUES, S(KC_P), S(KC_Y), CNTR_TL, CNTR_TR, S(KC_F), KC_LCBR, KC_RCBR, S(KC_R), S(KC_L),
    S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), CNTR_HL, CNTR_HR, KC_PIPE, KC_LPRN, KC_RPRN, KC_DLR,  S(KC_S),
    TD_COLN, S(KC_Q), S(KC_J), S(KC_K), S(KC_X), CNTR_BL, CNTR_BR, KC_BSLS, KC_ASTR, KC_DOT,  S(KC_V), S(KC_Z),
                                        KC_TAB,  KC_MINS, ___fn__, LT_BSPC
),
