#include "kana_input.h"
#include "quantum.h"
#if defined(CONSOLE_ENABLE)
#    include "print.h"
#endif
#include "jeandeaual.h"

#if defined(CONSOLE_ENABLE)
const char *get_ime_name(ime_t var) {
    switch (var) {
        case IME_WIN:
            return "Windows";
        case IME_MOZC:
            return "Mozc";
        case IME_MAC:
            return "macOS";
        default:
            return "unknown";
    }
}

const char *get_ime_switch_mode_name(ime_switch_mode_t var) {
    switch (var) {
        case IME_SWITCH_WIN:
            return "Windows";
        case IME_SWITCH_MAC:
            return "macOS";
        case IME_SWITCH_109:
            return "109";
        default:
            return "unknown";
    }
}
#endif

void turn_on_kana_input(ime_switch_mode_t mode) {
    switch (mode) {
        case IME_SWITCH_WIN:
            tap_code16(A(KC_GRV));
            break;
        case IME_SWITCH_MAC:
            tap_code(KC_KANA);
            break;
        case IME_SWITCH_109:
            tap_code(KC_HENK);
            break;
    }
}

void turn_off_kana_input(ime_switch_mode_t mode) {
    switch (mode) {
        case IME_SWITCH_WIN:
            tap_code16(A(KC_GRV));
            break;
        case IME_SWITCH_MAC:
            tap_code(KC_RO);
            break;
        case IME_SWITCH_109:
            tap_code(KC_MHEN);
            break;
        default:
#if defined(CONSOLE_ENABLE)
            uprintf("Unknown IME switch mode: %s\n", get_ime_switch_mode_name(mode));
#endif
            break;
    }
}

#define MAX_CONSONANT_COUNT 2

/* clang-format off */
static const uint8_t consonants[][MAX_CONSONANT_COUNT] = {
    {KC_K},
    {KC_S},
    {KC_T},
    {KC_N},
    {KC_H},
    {KC_M},
    {KC_R},
    {KC_P},
    {KC_G},
    {KC_Z},
    {KC_D},
    {KC_B},
    {KC_Y},
    {KC_W},
    {KC_X},
    {KC_X, KC_K},
    {KC_X, KC_T},
    {KC_X, KC_Y},
    {KC_X, KC_W},
    {KC_X, KC_Y},
    {KC_V},
};
/* clang-format on */

/* clang-format off */
static const uint8_t vowels[] = {
    KC_A,
    KC_I,
    KC_U,
    KC_E,
    KC_O,
    KC_Y,
};
/* clang-format on */

#define MAX_CODE_COUNT 3

/* Codes for KN_LWCB - KN_SANTEN (IME-dependant) */
static const uint16_t codes_win[][MAX_CODE_COUNT] = {
    {KC_LBRC},                      /* 『 */
    {KC_RBRC},                      /* 』 */
    {KC_LBRC},                      /* [ */
    {KC_RBRC},                      /* ] */
    {KC_SLASH},                     /* ・ */
    {KC_SLASH, KC_SLASH, KC_SLASH}, /* ・・・ */
};

static const uint16_t codes_mozc[][MAX_CODE_COUNT] = {
    {KC_Z, KC_LBRC},  /* 『 */
    {KC_Z, KC_RBRC},  /* 』 */
    {KC_LBRC},        /* [ */
    {KC_RBRC},        /* ] */
    {KC_Z, KC_SLASH}, /* ・ */
    {KC_Z, KC_DOT},   /* ・・・ */
};

static const uint16_t codes_mac[][MAX_CODE_COUNT] = {
    {S(KC_LBRC)},                   /* 『 */
    {S(KC_RBRC)},                   /* 』 */
    {A(S(KC_9))},                   /* [ */
    {A(S(KC_0))},                   /* ] */
    {KC_SLASH},                     /* ・ */
    {KC_SLASH, KC_SLASH, KC_SLASH}, /* ・・・ */
};

static uint8_t const dakuon_conversion[][2] = {
    {KC_K, KC_G},
    {KC_S, KC_Z},
    {KC_T, KC_D},
    {KC_H, KC_B},
};

void process_romaji(uint16_t keycode, ime_t ime, uint8_t *last_consonant, uint8_t *last_vowel) {
    if (keycode < KN_N) {
        static const size_t vowel_count = sizeof(vowels) / sizeof(vowels[0]);
        const unsigned int  pos         = keycode - KN_KA;

        for (unsigned int i = 0; i < MAX_CONSONANT_COUNT; ++i) {
            const uint8_t consonant = consonants[pos / vowel_count][i];
            if (consonant != KC_NO) {
                tap_code(consonant);
                if (i == 0) {
                    *last_consonant = consonant;
                }
            }
        }

        const uint8_t vowel = vowels[pos % vowel_count];
        tap_code(vowel);
        *last_vowel = vowel;
    } else if (keycode < KN_LWCB) {
        switch (keycode) {
            case KN_N:
                SEND_STRING("nn");
                break;
            case KN_DAKUTEN:
                for (unsigned int i = 0; i < sizeof(dakuon_conversion) / sizeof(dakuon_conversion[0]); ++i) {
                    if (*last_consonant == dakuon_conversion[i][0]) {
                        tap_code(KC_BSPACE);
                        tap_code(dakuon_conversion[i][1]);
                        tap_code(*last_vowel);
                        break;
                    }
                }
                break;
            case KN_HANDAKU:
                if (*last_consonant == KC_H) {
                    tap_code(KC_BSPACE);
                    tap_code(KC_P);
                    tap_code(*last_vowel);
                }
                break;
            /* M-type */
            case KN_ANN:
                SEND_STRING("ann");
                break;
            case KN_AKU:
                SEND_STRING("aku");
                break;
            case KN_ATU:
                SEND_STRING("atu");
                break;
            case KN_AI:
                SEND_STRING("ai");
                break;
            case KN_INN:
                SEND_STRING("inn");
                break;
            case KN_IKU:
                SEND_STRING("iku");
                break;
            case KN_ITU:
                SEND_STRING("itu");
                break;
            case KN_UNN:
                SEND_STRING("unn");
                break;
            case KN_UKU:
                SEND_STRING("uku");
                break;
            case KN_UTU:
                SEND_STRING("utu");
                break;
            case KN_ENN:
                SEND_STRING("enn");
                break;
            case KN_EKI:
                SEND_STRING("eki");
                break;
            case KN_ETU:
                SEND_STRING("etu");
                break;
            case KN_EI:
                SEND_STRING("ei");
                break;
            case KN_ONN:
                SEND_STRING("onn");
                break;
            case KN_OKU:
                SEND_STRING("oku");
                break;
            case KN_OTU:
                SEND_STRING("otu");
                break;
            case KN_OU:
                SEND_STRING("ou");
                break;
        }
    } else {
        const unsigned int pos = keycode - KN_LWCB;
        const uint16_t    *codes;

        switch (ime) {
            case IME_WIN:
                codes = codes_win[pos];
                break;
            case IME_MOZC:
                codes = codes_mozc[pos];
                break;
            case IME_MAC:
                codes = codes_mac[pos];
                break;
            default:
#if defined(CONSOLE_ENABLE)
                uprintf("Unknown IME: %s\n", get_ime_name(ime));
#endif
                return;
        }

        for (unsigned int i = 0; i < MAX_CODE_COUNT; ++i) {
            if (codes[i] != KC_NO) {
                tap_code(codes[i]);
            }
        }
    }
}
