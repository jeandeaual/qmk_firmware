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
// .................................................................. BEAKL HIEA

// ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │   Q  │   Y  │   O  │   U  │   Z  │  Fn  │ Caps │   G  │   D  │   N  │   M  │   X  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   H  │   I  │   E  │   A  │   .  │Cursor│ Mouse│   C  │   T  │   R  │   S  │   W  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   J  │   ;  │   "  │   K  │   ,  │  Num │ Regex│   B  │   P  │   L  │   F  │   V  │
// └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
//                             │  Esc │ Space│  Ent │ Bksp │
//                             └──────┴──────┴──────┴──────┘

[_BASE] = LAYOUT(
    KC_Q,    KC_Y,    KC_O,    KC_U,    KC_Z,    CNTR_TL, CNTR_TR, KC_G,    KC_D,    KC_N,    KC_M,    KC_X   ,
    HOME_H,  HOME_I,  HOME_E,  HOME_A,  KC_DOT,  CNTR_HL, CNTR_HR, KC_C,    HOME_T,  HOME_R,  HOME_S,  HOME_W ,
    KC_J,    KC_SCLN, TD_QUOT, KC_K,    KC_COMM, CNTR_BL, CNTR_BR, KC_B,    KC_P,    KC_L,    KC_F,    KC_V   ,
                                        LT_ESC,  TD_SPC,  TD_ENT,  LT_BSPC
),

[_SHIFT] = LAYOUT(
    S(KC_Q), S(KC_Y), S(KC_O), S(KC_U), S(KC_Z), CNTR_TL, CNTR_TR, S(KC_G), S(KC_D), S(KC_N), S(KC_M), S(KC_X),
    S(KC_H), S(KC_I), S(KC_E), S(KC_A), KC_DOT,  CNTR_HL, CNTR_HR, S(KC_C), S(KC_T), S(KC_R), S(KC_S), S(KC_W),
    S(KC_J), KC_SCLN, TD_QUOT, S(KC_K), KC_COMM, CNTR_BL, CNTR_BR, S(KC_B), S(KC_P), S(KC_L), S(KC_F), S(KC_V),
                                        LT_ESC,  TD_SPC,  TD_ENT,  LT_BSPC
),

// ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │   Q  │   Y  │   O  │   U  │   Z  │  Fn  │ Caps │   G  │   D  │   N  │   M  │   X  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   H  │   I  │   E  │  f() │   ~  │Cursor│ Mouse│   C  │   T  │   R  │   S  │   W  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   J  │   :  │   "  │   K  │   `  │  Num │ Regex│   B  │   P  │   L  │   F  │   V  │
// └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
//                             │  Esc │ Space│   _  │  Del │
//                             └──────┴──────┴──────┴──────┘

[_LSHIFT] = LAYOUT(
    S(KC_Q), S(KC_Y), S(KC_O), S(KC_U), S(KC_Z), CNTR_TL, CNTR_TR, S(KC_G), S(KC_D), S(KC_N), S(KC_M), S(KC_X),
    S(KC_H), S(KC_I), S(KC_E), ___fn__, TD_TILD, CNTR_HL, CNTR_HR, S(KC_C), S(KC_T), S(KC_R), S(KC_S), S(KC_W),
    S(KC_J), TD_COLN, TD_DQOT, S(KC_K), TD_GRV,  CNTR_BL, CNTR_BR, S(KC_B), S(KC_P), S(KC_L), S(KC_F), S(KC_V),
                                        LT_ESC,  TD_SPC,  KC_UNDS, SL_DEL
),

// ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │   Q  │   Y  │   O  │   U  │   Z  │  Fn  │ Caps │   G  │   D  │   N  │   M  │   X  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   H  │   I  │   E  │   A  │   ~  │Cursor│ Mouse│   C  │  f() │   R  │   S  │   W  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   J  │   :  │   "  │   K  │   `  │  Num │ Regex│   B  │   P  │   L  │   F  │   V  │
// └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
//                             │ ↑Tab │   -  │  Ent │ Bksp │
//                             └──────┴──────┴──────┴──────┘

[_RSHIFT] = LAYOUT(
    S(KC_Q), S(KC_Y), S(KC_O), S(KC_U), S(KC_Z), CNTR_TL, CNTR_TR, S(KC_G), S(KC_D), S(KC_N), S(KC_M), S(KC_X),
    S(KC_H), S(KC_I), S(KC_E), S(KC_A), TD_TILD, CNTR_HL, CNTR_HR, S(KC_C), ___fn__, S(KC_R), S(KC_S), S(KC_W),
    S(KC_J), TD_COLN, TD_DQOT, S(KC_K), TD_GRV,  CNTR_BL, CNTR_BR, S(KC_B), S(KC_P), S(KC_L), S(KC_F), S(KC_V),
                                        S_TAB,   KC_MINS, TD_ENT,  LT_BSPC
),

// ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │   Q  │   Y  │   O  │   U  │   Z  │  Fn  │ Caps │   `  │   [  │   ^  │   ]  │   X  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   H  │   I  │   E  │   A  │   .  │Cursor│ Mouse│   │  │   (  │   $  │   )  │   W  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   J  │   ;  │   "  │   K  │   ,  │  Num │ Regex│   \  │   {  │   #  │   }  │   V  │
// └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
//                             │  Esc │  f() │   +  │  Del |
//                             └──────┴──────┴──────┴──────┘

[_LSYMBOL] = LAYOUT(
    KC_Q,    KC_Y,    KC_O,    KC_U,    KC_Z,    CNTR_TL, CNTR_TR, TD_GRV,  KC_LBRC, KC_CIRC, KC_RBRC, KC_X   ,
    HOME_H,  HOME_I,  HOME_E,  HOME_A,  KC_DOT,  CNTR_HL, CNTR_HR, KC_PIPE, KC_LPRN, KC_DLR,  KC_RPRN, HOME_W ,
    KC_J,    KC_SCLN, TD_QUOT, KC_K,    KC_COMM, CNTR_BL, CNTR_BR, KC_BSLS, KC_LCBR, KC_HASH, KC_RCBR, KC_V   ,
                                        LT_ESC,  ___fn__, KC_PLUS, SL_DEL
),

// ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
// │   Q  │   .  │   *  │   &  │   ~  │  Fn  │ Caps │   G  │   D  │   N  │   M  │   X  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   H  │   <  │   %  │   >  │   ?  │Cursor│ Mouse│   C  │   T  │   R  │   S  │   W  │
// ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
// │   J  │   :  │   @  │   !  │   /  │  Num │ Regex│   B  │   P  │   L  │   F  │   V  │
// └──────┴──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┴──────┘
//                             │  Tab │   =  │  f() │ Bksp │
//                             └──────┴──────┴──────┴──────┘

[_RSYMBOL] = LAYOUT(
    KC_Q,    KC_DOT,  KC_ASTR, KC_AMPR, TD_TILD, CNTR_TL, CNTR_TR, KC_G,    KC_D,    KC_N,    KC_M,    KC_X   ,
    HOME_H,  TD_LT,   KC_PERC, TD_GT,   KC_QUES, CNTR_HL, CNTR_HR, KC_C,    HOME_T,  HOME_R,  HOME_S,  HOME_W ,
    KC_J,    TD_COLN, KC_AT,   KC_EXLM, KC_SLSH, CNTR_BL, CNTR_BR, KC_B,    KC_P,    KC_L,    KC_F,    KC_V   ,
                                        KC_TAB,  TD_EQL,  ___fn__, LT_BSPC
),
