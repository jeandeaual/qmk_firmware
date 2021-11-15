#pragma once

typedef enum {
    IME_WIN,
    IME_MOZC,
    IME_MAC,
} ime_t;

typedef enum {
    IME_SWITCH_WIN,
    IME_SWITCH_MAC,
    IME_SWITCH_109,
} ime_switch_mode_t;

#if defined(CONSOLE_ENABLE)
const char *get_ime_name(ime_t var);
const char *get_ime_switch_mode_name(ime_switch_mode_t var);
#endif
void turn_on_kana_input(ime_switch_mode_t mode);
void turn_off_kana_input(ime_switch_mode_t mode);
void process_romaji(uint16_t keycode, ime_t ime, uint8_t *last_consonant, uint8_t *last_vowel);
