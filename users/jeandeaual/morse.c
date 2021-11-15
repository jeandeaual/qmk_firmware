#include "morse.h"
#if defined(CONSOLE_ENABLE)
#    include "print.h"
#endif

typedef struct {
    char    *key;
    uint16_t value;
} morse_lookup_t;

static const morse_lookup_t morse_lookup_table[] = {
    /* Letters */
    {".-", KC_A},
    {"-...", KC_B},
    {"-.-.", KC_C},
    {"-..", KC_D},
    {".", KC_E},
    {"..-.", KC_F},
    {"--.", KC_G},
    {"....", KC_H},
    {"..", KC_I},
    {".---", KC_J},
    {"-.-", KC_K},
    {".-..", KC_L},
    {"--", KC_M},
    {"-.", KC_N},
    {"---", KC_O},
    {".--.", KC_P},
    {"--.-", KC_Q},
    {".-.", KC_R},
    {"...", KC_S},
    {"-", KC_T},
    {"..-", KC_U},
    {"...-", KC_V},
    {".--", KC_W},
    {"-..-", KC_X},
    {"-.--", KC_Y},
    {"--..", KC_Z},
    /* Numbers */
    {".----", KC_1},
    {"..---", KC_2},
    {"...--", KC_3},
    {"....-", KC_4},
    {".....", KC_5},
    {"-....", KC_6},
    {"--...", KC_7},
    {"---..", KC_8},
    {"----.", KC_9},
    {"-----", KC_0},
    /* Punctuation */
    {".-.-.-", KC_DOT},
    {"..--..--", KC_COMMA},
    {"..−−..", KC_QUESTION},
    {".−−−−.", KC_QUOTE},
    {"−.−.−−", KC_EXCLAIM},
    {"−..−.", KC_SLASH},
    {"−.−−.", KC_LEFT_PAREN},
    {"−.−−.−", KC_RIGHT_PAREN},
    {".−...", KC_AMPERSAND},
    {"−−−...", KC_COLON},
    {"−.−.−.", KC_SCOLON},
    {"−...−", KC_EQUAL},
    {".−.−.", KC_PLUS},
    {"−....−", KC_MINUS},
    {"..−−.−", KC_UNDERSCORE},
    {".−..−.", KC_DOUBLE_QUOTE},
    {"...−..", KC_DOLLAR},
    {".−−.−.", KC_AT},
};

void morse_each(qk_tap_dance_state_t *state, void *user_data) {
    morse_state_t *morse_state = (morse_state_t *)user_data;
    uint16_t       diff        = 0;

    if (state->count > 1 && state->count <= MORSE_PRESS_MAX_COUNT) {
        diff                                   = state->timer - morse_state->prev_timer;
        morse_state->presses[state->count - 2] = diff > MORSE_LONG_PRESS_MS ? '-' : '.';
    }

#if defined(CONSOLE_ENABLE)
    dprintf("Morse press count: %d\n", state->count);
    dprintf("Morse timer diff: %d\n", diff);
#endif

    morse_state->prev_timer = state->timer;

    if (state->count == MORSE_PRESS_MAX_COUNT) {
        reset_tap_dance(state);
    }

    if (state->count > MORSE_PRESS_MAX_COUNT) {
        memset(morse_state->presses, 0, sizeof(morse_state->presses));
    }
}

void morse_finished(qk_tap_dance_state_t *state, void *user_data) {
    morse_state_t *morse_state = (morse_state_t *)user_data;
    const uint16_t last_count  = state->count > MORSE_PRESS_MAX_COUNT ? MORSE_PRESS_MAX_COUNT : state->count;

    morse_state->presses[last_count - 1] = state->pressed ? '-' : '.';

#if defined(CONSOLE_ENABLE)
    dprintf("Morse press count (finished): %d\n", state->count);
#endif
}

void morse_reset(qk_tap_dance_state_t *state, void *user_data) {
    morse_state_t *morse_state = (morse_state_t *)user_data;

#if defined(CONSOLE_ENABLE)
    bool found = false;
    dprintf("Morse state: %s\n", morse_state->presses);
#endif

    // Print the value
    for (unsigned int i = 0; i < sizeof(morse_lookup_table) / sizeof(morse_lookup_table[0]); ++i) {
        const morse_lookup_t entry = morse_lookup_table[i];

#if defined(CONSOLE_ENABLE)
        dprintf("Checking %s (%d)\n", entry.key, entry.value);
#endif

        if (strcmp(entry.key, morse_state->presses) == 0) {
#if defined(CONSOLE_ENABLE)
            found = true;
            dprint("Found\n");
#endif
            tap_code(entry.value);
            break;
        }
    }

#if defined(CONSOLE_ENABLE)
    if (!found) {
        dprint("Not found\n");
    }
#endif

    // Reset the user data
    morse_state->prev_timer = 0;
    memset(morse_state->presses, 0, sizeof(morse_state->presses));
}
