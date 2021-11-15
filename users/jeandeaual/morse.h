/*
 * Usage:
 *
 * Add to keymap.c:
 *
 * #include "morse.h"
 *
 * enum tap_dance_keycodes {
 *     // ...
 *     TD_MORSE,
 *     // ...
 * };
 *
 * uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
 *     switch (keycode) {
 *         // ...
 *         case TD(TD_MORSE):
 *             return MORSE_TIMEOUT_MS;
 *         // ...
 *         default:
 *             return TAPPING_TERM;
 *     }
 * }
 *
 * qk_tap_dance_action_t tap_dance_actions[] = {
 *     // ...
 *     [TD_MORSE] = ACTION_TAP_DANCE_FN_MORSE,
 *     // ...
 * };
 *
 * const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 *     // ...
 *     TD(TD_MORSE),
 *     // ...
 * };
 */

#pragma once

#include "quantum.h"

#define MORSE_LONG_PRESS_MS 500
#define MORSE_TIMEOUT_MS 1000
#define MORSE_PRESS_MAX_COUNT 6

typedef struct {
    uint16_t prev_timer;
    char     presses[MORSE_PRESS_MAX_COUNT + 1];
} morse_state_t;

void morse_each(qk_tap_dance_state_t *state, void *user_data);
void morse_finished(qk_tap_dance_state_t *state, void *user_data);
void morse_reset(qk_tap_dance_state_t *state, void *user_data);

#define ACTION_TAP_DANCE_FN_MORSE \
    { .fn = {morse_each, morse_finished, morse_reset}, .user_data = (void *)&((morse_state_t){.prev_timer = 0, .presses = ""}), }
