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

// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
//
// To flash splitography / planck firmware
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
//   Reset keyboard or press hw reset button on base
//
//   cd qmk_firmware/keyboards/<keyboard>
//   sudo make KEYMAP=<keymap> dfu
//
//   sudo make clean           (good practice before flashing)
//   sudo make KEYMAP=<keymap> (to compile check)
//
// Package requirements (for arch linux)
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
//   avr-gcc-atmel
//   avr-libc-atmel
//   dfu-programmer
//
// Notes
// ▔▔▔▔▔
//   ** E R G O   W I D E   S P L I T ** Layout
//
//   Autocompletion tap dance key pairs (),[],{} are available from the
//   number/symbol layer, as well as, numerous (un)shift key values
//
// Code
// ▔▔▔▔
//   This source is shamelessly based on the "default" planck layout
//
// Change history
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔
//   See http://thedarnedestthing.com/colophon

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_steno.h"

#include "config.h"
#include "splitography.h"

extern keymap_config_t keymap_config;

enum keyboard_layers {
    _BASE = 0,
    _SHIFT,
    _LSHIFT,
    _RSHIFT,
    _SYMBOL,
    _GUIFN,
    _PLOVER,
    _NUMBER,
    _FNCKEY,
    _MOUSE,
    _EDIT,
    _TTFNCKEY,
    _TTCAPS,
    _TTCURSOR,
    _TTMOUSE,
    _TTNUMBER,
    _TTREGEX,
    _END_LAYERS,
};

enum keyboard_keycodes {
    BASE = SAFE_RANGE,
    BASE1,
    BASE2,
    LT_I,  // pseudo LT   (_SYMBOL, KC_I)                for shifted key-codes, see process_record_user()
    ML_BSLS,
    ML_EQL,
    PLOVER,
    PLOEXIT,
    SA_DLR,   // pseudo ALT_T(S(KC_4))                      for shifted key-codes, see process_record_user()
    SC_RPRN,  // pseudo CTL_T(S(KC_0))                      for shifted key-codes, see process_record_user()
    SS_LPRN,  // pseudo SFT_T(S(KC_9))                      for shifted key-codes, see process_record_user()
    SA_PERC,  // pseudo ALT_T(S(KC_5))                      for shifted key-codes, see process_record_user()
    SG_TILD,  // pseudo GUI_T(S(KC_GRV))                    for shifted key-codes, see process_record_user()
    SL_I,     // pseudo LT   (_EDIT, S(KC_I))               for shifted key-codes, see process_record_user()
    SL_DEL,   // pseudo LT   (_EDIT, KC_DEL)                for shifted key-codes, see process_record_user()
    SL_BSPC,  // pseudo LT   (S(_MOUSE), KC_BSPC)
    SL_PIPE,  // pseudo LT   (_EDIT, S(KC_BSLS))            for shifted key-codes, see process_record_user()
    SL_TAB,   // pseudo LT   (S(_MOUSE), KC_TAB)
    SM_G,     // pseudo MT   (MOD_LGUI | MOD_LSFT, S(KC_G)) for shifted key-codes, see process_record_user()
    SM_H,     // pseudo MT   (MOD_LGUI | MOD_LSFT, S(KC_H)) for shifted key-codes, see process_record_user()
    SM_I,     // pseudo MT   (MOD_LSFT, S(KC_I))            for shifted key-codes, see process_record_user()
    SM_CIRC,  // pseudo GUI_T(S(KC_6))                      for shifted key-codes, see process_record_user()
    SM_DLR,   // pseudo SFT_T(S(KC_4))                      for shifted key-codes, see process_record_user()
    SM_PERC,  // pseudo ALT_T(S(KC_5))                      for shifted key-codes, see process_record_user()
    SM_LPRN,  // pseudo CTL_T(S(KC_9))                      for shifted key-codes, see process_record_user()
    SS_A,     // pseudo SFT_T(S(KC_A))
    SS_T,     // pseudo SFT_T(S(KC_T))
    TT_ESC,
#if defined(STENO_ENABLE)
    PS_STNA = STN_A,
    PS_STNO = STN_O,
    PS_STNE = STN_E,
    PS_STNU = STN_U,
#else
    LT_C = LT(_SYMBOL, KC_C),
    LT_V = LT(_NUMBER, KC_V),
    LT_N = LT(_FNCKEY, KC_N),
    LT_M = LT(_GUIFN, KC_M),
#endif
    PS_BASE,
};

// modifier keys
#define AT_B ALT_T(KC_B)
#define GT_C GUI_T(KC_C)
#define MT_E MT(MOD_LCTL | MOD_LALT, KC_E)
#define ST_A SFT_T(KC_A)
#define ST_SPC SFT_T(KC_SPC)

#define HOME_Q GUI_T(KC_Q)
#define HOME_H CTL_T(KC_H)
#define HOME_E ALT_T(KC_E)
#define HOME_A SFT_T(KC_A)
#define HOME_T SFT_T(KC_T)
#define HOME_R ALT_T(KC_R)
#define HOME_S CTL_T(KC_S)
#define HOME_W GUI_T(KC_W)

#include "common/tapdance.inc"

// keycodes
#define ___x___ KC_TRNS
#define ___fn__ KC_TRNS
#if defined(_______)
#    undef _______
#endif
#define _______ KC_NO

#if defined(HASKELL)
#    define HS_COLN TD_COLN
#    define HS_LT TD_LT
#    define HS_GT TD_GT
#    define HS_EQL TD_EQL
#else
#    define HS_COLN KC_COLN
#    define HS_LT KC_LT
#    define HS_GT KC_GT
#    define HS_EQL KC_EQL
#endif

#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define EOT LCTL(KC_D)
#define NAK LCTL(KC_U)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)
#define TMCOPY LCTL(LSFT(KC_C))
#define TMPASTE LCTL(LSFT(KC_V))

#define LT_BSPC LT(_GUIFN, KC_BSPC)  // see process_record_user() for extended handling
#define TT_BSPC LT(_TTCURSOR, KC_BSPC)
#define LT_ESC LT(_NUMBER, KC_ESC)
#define LT_I LT(_LSHIFT, KC_I)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_GUI OSM(MOD_LGUI)
#define OS_SFT OSM(MOD_LSFT)

#define CNTR_TL TT(_TTFNCKEY)
#define CNTR_TR TT(_TTCAPS)  // pseudo capslock to avoid TT key_timer conflicts
#define CNTR_HL TT(_TTCURSOR)
#define CNTR_HR TT(_TTMOUSE)
#define CNTR_BL TT(_TTNUMBER)
#define CNTR_BR TT(_TTREGEX)

// ........................................................ Default Alpha Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#include "base_layout.inc"
#include "common/steno_layout.inc"

// ...................................................... Number / Function Keys

#include "common/number_fkey_layout.inc"

// ......................................................... Symbol / Navigation

#include "common/symbol_guifn_layout.inc"

// ............................................................... Toggle Layers

#include "common/toggle_layout.inc"

// ......................................................... Short Cuts / Adjust

#include "common/chord_layout.inc"

};

// User Keycode Trap
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔

#include "common/keycode_functions.inc"

#define BASE_1 1
#define BASE_2 2
#define BASE_12 3
static uint8_t base_n = 0;

#if defined(CURSOR_ENTER)
static uint8_t cursor_rule = 0;  // (0) nop (1) delete -> enter, shift backspace -> delete
#endif
static uint8_t down_rule = 0;  // (1) substitute keycode (2) keycode + shift, see cap_lt()
static uint8_t repeating = 0;  // rolling key repeat mode, see thumb_roll()

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // rolling key pre-process
    switch (keycode) {
        case SL_TAB:
            repeating += record->event.pressed ? 0 : 1;
            break;
        default:
            repeating = 0;
    }

    // ........................................................ Home Row Modifiers

    switch (keycode) {
        case HOME_Q:
        case HOME_W:
            tap_mods(record, KC_LGUI);
            break;

        case HOME_H:
        case HOME_S:
            tap_mods(record, KC_LCTL);
            break;

        case HOME_E:
        case HOME_R:
            tap_mods(record, KC_LALT);
            break;

        case HOME_A:
            tap_mods(record, KC_LSFT);
            break;

        case HOME_T:
            tap_mods(record, KC_RSFT);  // note: SFT_T actually uses KC_LSFT
            break;

        case OS_ALT:
            tap_mods(record, KC_LALT);
            break;

        case OS_CTL:
            tap_mods(record, KC_LCTL);
            break;

        case OS_GUI:
            tap_mods(record, KC_LGUI);
            break;

            // ...................................................... Center Toggle Layers

        case CNTR_TL:
        case CNTR_TR:
        case CNTR_HL:
        case CNTR_HR:
        case CNTR_BL:
        case CNTR_BR:
            // return to base layer first if different TT layer selected
            if (tt_keycode != keycode && tt_keycode) {
                tt_clear();
            }
            tt_escape(record, keycode);
            break;

        case TT_ESC:
            if (map_shift(record, KC_LSFT, NOSHIFT, KC_TAB)) {
                return false;
            }
            tt_clear();  // exit TT layer
            return false;

            // ................................................................ Thumb Keys

        case LT_ESC:
            if (raise_layer(record, _FNCKEY, LEFT, ONDOWN)) {
                return false;
            }
            if (map_shift(record, KC_LSFT, SHIFT, KC_TAB)) {
                return false;
            }
            if (map_shift(record, KC_RSFT, NOSHIFT, KC_TAB)) {
                return false;
            }
            if (tt_keycode) {
                tt_clear();
                return false;
            }
            tap_layer(record, _NUMBER);
            thumb_roll(record, LEFT, 0, 0, 0, _NUMBER, _GUIFN);
            break;

        case SL_TAB:
            down_rule = key_event(record, 1);  // tab + enter thumb roll, see cap_lt()
            thumb_roll(record, LEFT, SHIFT, KC_TAB, repeating, _MOUSE, _GUIFN);
            break;

        case KC_TAB:
            if (raise_layer(record, _FNCKEY, LEFT, ONDOWN)) {
                return false;
            }
            down_rule = key_event(record, 1);  // dot + tab + enter thumb roll, see cap_lt()
            break;

        case LT_I:
            if (raise_layer(record, _FNCKEY, RIGHT, ONDOWN)) {
                return false;
            }
            tap_layer(record, _LSHIFT);
            break;

        case SL_I:
            lt_shift(record, SHIFT, KC_I, _EDIT);
            break;

        case SM_I:
            mt_shift(record, KC_LSFT, 0, KC_I);
            tap_mods(record, KC_RSFT);  // note: SFT_T actually uses KC_LSFT, see ST_SPC
            break;

        case ST_SPC:
            if (map_shift(record, KC_RSFT, NOSHIFT, KC_ENT)) {
                return false;
            }
            tap_mods(record, KC_LSFT);  // note: SFT_T actually uses KC_LSFT, see ST_SPC
            break;

        case TD_SPC:
            if (raise_layer(record, _SYMBOL, LEFT, ONDOWN)) {
                return false;
            }
            if (record->event.pressed) {
                tap_rule = down_rule;
            }  // down_rule persistance for cap_lt()
            if (map_shift(record, KC_LSFT, NOSHIFT, KC_ENT)) {
                return false;
            }
            if (map_shift(record, KC_RSFT, NOSHIFT, KC_ENT)) {
                return false;
            }
            tap_layer(record, _RSHIFT);
            break;

        case KC_BSPC:
            if (raise_layer(record, _SYMBOL, RIGHT, ONDOWN)) {
                return false;
            }
            break;

        case TT_BSPC:
            if (map_shift(record, KC_RSFT, NOSHIFT, KC_DEL)) {
                return false;
            }
            break;

        case TD_BSPC:
            if (raise_layer(record, _SYMBOL, RIGHT, ONDOWN)) {
                return false;
            }
            if (cursor_rule && map_shift(record, KC_LSFT, NOSHIFT, KC_DEL)) {
                return false;
            }
            if (record->event.pressed) {
                tap_rule = down_rule;
            }  // down_rule persistance for cap_lt()
            tap_layer(record, _GUIFN);
            break;

#if defined(CURSOR_ENTER)
        case KC_DEL:
            if (cursor_rule) {
                trigger_key(record, KC_ENT);
                return false;
            }
            break;
#endif
        case SL_DEL:
            thumb_roll(record, RIGHT, NOSHIFT, KC_DEL, 0, _MOUSE, _NUMBER);
            break;

            // .............................................................. Special Keys

        case KC_BSLS:
            if (down_rule) {
                tap_code(KC_ENT);
                return false;
            }  // down_rule persistance for cap_lt()
            break;

        case KC_COLN:
        case TD_COLM:
            if (map_shift(record, KC_LSFT, SHIFT, KC_2)) {
                return false;
            }
            if (map_shift(record, KC_RSFT, SHIFT, KC_7)) {
                return false;
            }
            break;

        case KC_COMM:
            if (map_shift(record, KC_LSFT, SHIFT, KC_1)) {
                return false;
            }
            if (map_shift(record, KC_RSFT, SHIFT, KC_5)) {
                return false;
            }
            break;

        // special shift layer mappings
        case KC_DOT:
            down_rule = key_event(record, 2);  // dot + space/enter + shift shortcut, see cap_lt()
            if (map_shift(record, KC_LSFT, SHIFT, KC_SLSH)) {
                return false;
            }
            if (map_shift(record, KC_RSFT, SHIFT, KC_1)) {
                down_rule = key_event(record, 2);
                return false;
            }  // exlm + space/enter + shift shortcut, see cap_lt()
            break;

        case SA_DLR:
            mt_shift(record, KC_LALT, 0, KC_4);
            break;

        case SS_LPRN:
            mt_shift(record, KC_LSFT, 0, KC_9);
            break;

        case KC_MINS:
            if (map_shift(record, KC_RSFT, SHIFT, KC_COMM)) {
                return false;
            }
            break;

        case KC_QUOT:
            if (map_shift(record, KC_RSFT, SHIFT, KC_DOT)) {
                return false;
            }
            break;

        case SC_RPRN:
            mt_shift(record, KC_LCTL, 0, KC_0);
            break;

        case SM_G:
            mt_shift(record, KC_LALT, KC_LSFT, KC_G);
            break;

        case KC_QUES:
            // down_rule = 0;                       // trap layer switching timimg issue between . and ?
            down_rule = key_event(record, 2);  // ques + space/enter + shift shortcut, see cap_lt()
            break;

            // ............................................................... Cursor Keys

#if defined(CURSOR_ENTER)
        case KC_HOME:
        case KC_END:
        case KC_LEFT:
        case KC_RIGHT:
        case KC_PGUP:
        case KC_PGDN:
        case KC_UP:
        case KC_DOWN:
            cursor_rule = 1;
            break;
#endif
            // ................................................................ Steno Keys

        case PLOVER:
            steno(record);
            return false;
        case BASE1:
            if (record->event.pressed) {
                base_n = base_n | BASE_1;
                if (base_n == BASE_12) {
                    base_layer(0);
                }
            } else {
                base_n = base_n & ~BASE_1;
            }
            return false;
        case BASE2:
            if (record->event.pressed) {
                base_n = base_n | BASE_2;
                if (base_n == BASE_12) {
                    base_layer(0);
                }
            } else {
                base_n = base_n & ~BASE_2;
            }
            return false;

            // ................................................................ Other Keys

        default:
            key_timer = 0;  // regular keycode, clear timer in custom/keycode_functions.h
    }

        // rolling key post-process
#if defined(CURSOR_ENTER)
    switch (keycode) {
        case KC_HOME:
        case KC_END:
        case KC_LEFT:
        case KC_RIGHT:
        case KC_PGUP:
        case KC_PGDN:
        case KC_UP:
        case KC_DOWN:
        case KC_DEL:
        case TD_BSPC:
            break;
        default:
            if (!record->event.pressed) {
                cursor_rule = 0;
            }
    }
#endif

    return true;
}

#include "common/init.inc"
