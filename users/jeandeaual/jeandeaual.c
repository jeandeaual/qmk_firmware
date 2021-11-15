#include "jeandeaual.h"
#if defined(CONSOLE_ENABLE)
#    include "print.h"
#endif
#if defined(KANA_INPUT)
#    include "kana_input.h"
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    /* Indicate that the key press we just processed should continue to be processed as normal */
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if defined(ALTSHIFT)
    static bool alt_shift_enabled = false;
    static bool alt_shift_state   = false;
#endif
#if defined(FANCY_TEXT) && defined(UNICODE_ENABLE)
    static fancy_text_state_t fancy_text_state = FT_NONE;
#endif
#if defined(KANA_INPUT)
    static bool              kana_input          = false;
    static ime_t             ime                 = IME_WIN;
    static ime_switch_mode_t ime_switch_mode     = IME_SWITCH_WIN;
    static uint8_t           last_kana_consonant = KC_NO;
    static uint8_t           last_kana_vowel     = KC_NO;
#endif

    switch (keycode) {
#if defined(ALTSHIFT)
        /* https://www.reddit.com/r/olkb/comments/ja4c4q/qmk_how_do_i_use_process_record_user_to_change_an/ */
        case ALTSHFT:
            if (record->event.pressed) {
                alt_shift_enabled = !alt_shift_enabled;
                alt_shift_state   = false;

#    if defined(CONSOLE_ENABLE)
                dprintf("Alt-Shift mode %s\n", alt_shift_enabled ? "enabled" : "disabled");
#    endif

                return false;
            }

            break;
#endif
#if defined(FANCY_TEXT) && defined(UNICODE_ENABLE)
        case CURSIVE:
            /* Toggle cursive text mode */
            if (record->event.pressed) {
                if (fancy_text_state == FT_CURSIVE) {
                    fancy_text_state = FT_NONE;
                } else {
                    fancy_text_state = FT_CURSIVE;
                }

#    if defined(CONSOLE_ENABLE)
                dprintf("Fancy text state: %s\n", get_fancy_text_name(fancy_text_state));
#    endif

                return false;
            }

            break;
        case GOTHIC:
            /* Toggle gothic text mode */
            if (record->event.pressed) {
                if (fancy_text_state == FT_GOTHIC) {
                    fancy_text_state = FT_NONE;
                } else {
                    fancy_text_state = FT_GOTHIC;
                }

#    if defined(CONSOLE_ENABLE)
                dprintf("Fancy text state: %s\n", get_fancy_text_name(fancy_text_state));
#    endif

                return false;
            }

            break;
        case SMCAPS:
            /* Toggle gothic text mode */
            if (record->event.pressed) {
                if (fancy_text_state == FT_SMALL_CAPS) {
                    fancy_text_state = FT_NONE;
                } else {
                    fancy_text_state = FT_SMALL_CAPS;
                }

#    if defined(CONSOLE_ENABLE)
                dprintf("Fancy text state: %s\n", get_fancy_text_name(fancy_text_state));
#    endif

                return false;
            }

            break;
        /* https://en.wikipedia.org/wiki/Zalgo_text */
        case ZALGO:
            /* Toggle Zalgo text mode */
            if (record->event.pressed) {
                if (fancy_text_state == FT_ZALGO) {
                    fancy_text_state = FT_NONE;
                } else {
                    fancy_text_state = FT_ZALGO;
                }

#    if defined(CONSOLE_ENABLE)
                dprintf("Fancy text state: %s\n", get_fancy_text_name(fancy_text_state));
#    endif

                return false;
            }

            break;
#endif
#if defined(KANA_INPUT)
        case KANA_INPUT_ON:
            if (record->event.pressed) {
                turn_on_kana_input(ime_switch_mode);
                kana_input          = true;
                last_kana_consonant = KC_NO;
                last_kana_vowel     = KC_NO;
                return false;
            }
            break;
        case KANA_INPUT_OFF:
            if (record->event.pressed) {
                turn_off_kana_input(ime_switch_mode);
                kana_input          = false;
                last_kana_consonant = KC_NO;
                last_kana_vowel     = KC_NO;
                return false;
            }
            break;
        case KANA_INPUT_TOGGLE:
            if (record->event.pressed) {
                if (kana_input) {
                    turn_off_kana_input(ime_switch_mode);
                } else {
                    turn_on_kana_input(ime_switch_mode);
                }
                kana_input          = !kana_input;
                last_kana_consonant = KC_NO;
                last_kana_vowel     = KC_NO;
                return false;
            }
            break;
        case KN_KA ... KN_SANTEN:
            if (record->event.pressed) {
                process_romaji(keycode, ime, &last_kana_consonant, &last_kana_vowel);
                return false;
            }
            break;
#endif
        default:
#if defined(ALTSHIFT)
            if (alt_shift_enabled &&
                /* Only process ASCII text */
                keycode >= KC_A && keycode <= KC_Z && record->event.pressed && !get_mods()) {
                if (alt_shift_state) {
                    set_oneshot_mods(get_oneshot_mods() | MOD_MASK_SHIFT);
                }

                alt_shift_state = !alt_shift_state;
            }

#endif
#if defined(FANCY_TEXT) && defined(UNICODE_ENABLE)
            // if (fancy_text_state == FT_CURSIVE &&
            //     /* Only process ASCII text */
            //     keycode >= KC_A && keycode <= KC_Z && record->event.pressed) {
            if (fancy_text_state == FT_CURSIVE && record->event.pressed) {
                if (cursive_text(keycode)) {
                    return false;
                }
            }

            // if (fancy_text_state == FT_GOTHIC &&
            //     /* Only process ASCII text */
            //     keycode >= KC_A && keycode <= KC_Z && record->event.pressed) {
            if (fancy_text_state == FT_GOTHIC && record->event.pressed) {
                if (gothic_text(keycode)) {
                    return false;
                }
            }

            // if (fancy_text_state == FT_SMALL_CAPS &&
            //     /* Only process ASCII text */
            //     keycode >= KC_A && keycode <= KC_Z && keycode != KC_X && record->event.pressed) {
            if (fancy_text_state == FT_SMALL_CAPS && record->event.pressed) {
                if (small_caps_text(keycode)) {
                    return false;
                }
            }

            if (fancy_text_state == FT_ZALGO &&
                /* Only process ASCII text and punctuation, excluding numbers and spaces */
                !(keycode < KC_A || (keycode > KC_0 && keycode < KC_MINUS) || keycode > KC_SLASH) && record->event.pressed) {
                zalgo_text(keycode);

                return false;
            }

#endif
            break;
    }

    return process_record_keymap(keycode, record);
};
