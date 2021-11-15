#include QMK_KEYBOARD_H

#include "jeandeaual.h"

enum layer_names {
    _QWERTY,
    _DVORAK,
    _TRON,
    _TRONL,
    _TRONR,
    _TRONB,
    _FN
};

enum keyboard_keycodes {
    TEST = NEW_SAFE_RANGE,
    TT,
};

enum tap_dance_keycodes {
    TD_ESC_LAYOUT,
    TD_RESET,
    TD_MORSE,
};

void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        // Reset the keyboard if you tap the key more than three times
        reset_keyboard();
        reset_tap_dance(state);
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef MORSE_INPUT
        case TD(TD_MORSE):
            return MORSE_TIMEOUT_MS;
#endif
        default:
            return TAPPING_TERM;
    }
}

/* Tap Dance definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_LAYOUT] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ESC, _DVORAK),
    [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset),
#ifdef MORSE_INPUT
    [TD_MORSE] = ACTION_TAP_DANCE_FN_MORSE,
#endif
};

#define ESC TD(TD_ESC_LAYOUT)
#define RESET TD(TD_RESET)
#ifdef KANA_INPUT
#define FN_L LT(_FN, KANA_INPUT_OFF)
#define FN_R LT(_FN, KANA_INPUT_ON)
#define LTHUMB OSL(_TRONL)
#define RTHUMB OSL(_TRONR)
#define BTHUMB OSL(_TRONB)
#else
#define FN_L MO(_FN)
#define FN_R MO(_FN)
#endif
#ifdef MORSE_INPUT
#define MID_KEY TD(TD_MORSE)
#else
#define MID_KEY KC_RALT
#endif

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | CAP LK | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | `      | A      | S      | D      | F      | G      | TAB    | DEL    | ENTER  | H      | J      | K      | L      | '      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LCTRL  | Z      | X      | C      | V      | B      | END    | UP     | DEL    | N      | M      | ,      | .      | /      | RCTRL  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LALT   | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RALT   |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x15(
        ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_CAPS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  TG(_TRON), KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
        KC_LALT, KC_LGUI, KC_LALT, FN_L,    KC_SPC,  KC_LSPO, KC_SPC,  MID_KEY, KC_BSPC, KC_RSPC, KC_SPC,  FN_R,    KC_RALT, KC_RGUI, KC_RALT
    ),

    /* Dvorak
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | \      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | CAP LK | '      | ,      | .      | P      | Y      | [      | \      | ]      | F      | G      | C      | R      | L      | /      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | `      | A      | O      | E      | U      | I      | TAB    | DEL    | ENTER  | D      | H      | T      | N      | S      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LCTRL  | ;      | Q      | J      | K      | X      | END    | UP     | PG DN  | B      | M      | W      | V      | Z      | RCTRL  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LALT   | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | RALT   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RALT   |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______, _______, _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______, _______, _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
        _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    _______, _______, _______, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

#ifdef KANA_INPUT
    /*
     * Japanese TRON layout
     */
    [_TRON] = LAYOUT_ortho_5x15(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KN_RA,   KN_RU,   KN_KO,   KN_HA,   KN_XYO,  _______, _______, _______, KN_KI,   KN_NO,   KN_KU,   KN_A,    KN_RE,   KC_SLSH,
        _______, KN_TA,   KN_TO,   KN_KA,   KN_TE,   KN_MO,   _______, _______, _______, KN_WO,   KN_I,    KN_U,    KN_SI,   KN_N,    KC_ENT,
        _______, KN_MA,   KN_RI,   KN_NI,   KN_SA,   KN_NA,   _______, _______, _______, KN_SU,   KN_TU,   KN_KTEN, KN_TTEN, KN_XTU,  KC_RCTL,
        _______, _______, _______, _______, _______, LTHUMB,  _______, _______, _______, RTHUMB,  _______, _______, _______, _______, _______
    ),

    /*
     * Japanese TRON layout (left shift)
     */
    [_TRONL] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KN_HI,   KN_SO,   KN_NKGR, KN_XYA,  KN_HO,   _______, _______, _______, KN_GI,   KN_GE,   KN_GU,   KN_QUES, KN_WYI,  _______,
        KN_STEN, KN_NU,   KN_NE,   KN_XYU,  KN_YO,   KN_FU,   _______, _______, _______, KN_DKT,  KN_DI,   KN_VU,   KN_ZI,   KN_WYE,  _______,
        _______, KN_XE,   KN_XO,   KN_SE,   KN_YU,   KN_HE,   _______, _______, _______, KN_ZU,   KN_DU,   KC_COMM, KC_DOT,  KN_XWA,  _______,
        _______, _______, _______, _______, _______, LTHUMB,  _______, _______, _______, BTHUMB,  _______, _______, _______, _______, _______
    ),

    /*
     * Japanese TRON layout (right shift)
     */
    [_TRONR] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KN_BI,   KN_ZO,   KN_GO,   KN_BA,   KN_BO,   _______, _______, _______, KN_E,    KN_KE,   KN_ME,   KN_MU,   KN_RO,   _______,
        KC_GRV,  KN_DA,   KN_DO,   KN_GA,   KN_DE,   KN_BU,   _______, _______, _______, KN_O,    KN_TI,   KN_CHON, KN_MI,   KN_YA,   _______,
        _______, KN_XKA,  KN_XKE,  KN_ZE,   KN_ZA,   KN_BE,   _______, _______, _______, KN_WA,   KN_XI,   KN_XA,   KN_HDKT, KN_XU,   _______,
        _______, _______, _______, _______, _______, BTHUMB,  _______, _______, _______, RTHUMB,  _______, _______, _______, _______, _______
    ),

    /*
     * Japanese TRON layout (both shift)
     */
    [_TRONB] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KN_PI,   _______, _______, KN_PA,   KN_PO,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_GRV,  _______, _______, _______, _______, KN_PU,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KN_PE,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, BTHUMB,  _______, _______, _______, BTHUMB,  _______, _______, _______, _______, _______
    ),
#endif

    /* Function
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        | SMCAPS | KN_KA  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | ALTSHFT| ZALGO  | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     | CURSIVE| GOTHIC | UC_MOD |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x15(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, SMCAPS,  _______,
        ALTSHFT, ZALGO,   RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), CURSIVE, GOTHIC,  UC_MOD
    )
};
/* clang-format on */

void keyboard_post_init_user(void) {
    debug_enable = true;
    // capslock_led_on();
    // gp100_led_on();
    // gp103_led_on();
    // set_unicode_input_mode(UC_WINC);
    // set_unicode_input_mode(UC_LNX);
    // set_unicode_input_mode(UC_MAC);
}

bool led_update_user(led_t led_state) {
    static bool caps_lock_state = false;
    static bool num_lock_state = false;
    static bool scroll_lock_state = false;

    if (led_state.caps_lock != caps_lock_state) {
        led_state.caps_lock ? capslock_led_on() : capslock_led_off();
        caps_lock_state = led_state.caps_lock;
    }

    if (led_state.num_lock != num_lock_state) {
        led_state.num_lock ? gp100_led_on() : gp100_led_off();
        num_lock_state = led_state.num_lock;
    }

    if (led_state.scroll_lock != scroll_lock_state) {
        led_state.scroll_lock ? gp103_led_on() : gp103_led_off();
        scroll_lock_state = led_state.scroll_lock;
    }

    return true;
}
