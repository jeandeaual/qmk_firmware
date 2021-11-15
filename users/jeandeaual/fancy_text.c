#include "fancy_text.h"
#if defined(CONSOLE_ENABLE)
#    include "print.h"
#endif

bool is_shift_pressed(void) { return get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT; }

#if defined(CONSOLE_ENABLE)
const char *get_fancy_text_name(fancy_text_state_t var) {
    switch (var) {
        case FT_NONE:
            return "none";
        case FT_CURSIVE:
            return "cursive";
        case FT_GOTHIC:
            return "gothic";
        case FT_ZALGO:
            return "zalgo";
        default:
            return "unknown";
    }
}
#endif

bool cursive_text(uint16_t keycode) {
    switch (keycode) {
        case KC_A:
            is_shift_pressed() ? send_unicode_string("𝒜") : send_unicode_string("𝒶");
            return true;
        case KC_B:
            is_shift_pressed() ? send_unicode_string("𝐵") : send_unicode_string("𝒷");
            return true;
        case KC_C:
            is_shift_pressed() ? send_unicode_string("𝒞") : send_unicode_string("𝒸");
            return true;
        case KC_D:
            is_shift_pressed() ? send_unicode_string("𝒟") : send_unicode_string("𝒹");
            return true;
        case KC_E:
            is_shift_pressed() ? send_unicode_string("𝐸") : send_unicode_string("𝑒");
            return true;
        case KC_F:
            is_shift_pressed() ? send_unicode_string("𝐹") : send_unicode_string("𝒻");
            return true;
        case KC_G:
            is_shift_pressed() ? send_unicode_string("𝒢") : send_unicode_string("𝑔");
            return true;
        case KC_H:
            is_shift_pressed() ? send_unicode_string("𝐻") : send_unicode_string("𝒽");
            return true;
        case KC_I:
            is_shift_pressed() ? send_unicode_string("𝐼") : send_unicode_string("𝒾");
            return true;
        case KC_J:
            is_shift_pressed() ? send_unicode_string("𝒥") : send_unicode_string("𝒿");
            return true;
        case KC_K:
            is_shift_pressed() ? send_unicode_string("𝒦") : send_unicode_string("𝓀");
            return true;
        case KC_L:
            is_shift_pressed() ? send_unicode_string("𝐿") : send_unicode_string("𝓁");
            return true;
        case KC_M:
            is_shift_pressed() ? send_unicode_string("𝑀") : send_unicode_string("𝓂");
            return true;
        case KC_N:
            is_shift_pressed() ? send_unicode_string("𝓝") : send_unicode_string("𝓃");
            return true;
        case KC_O:
            is_shift_pressed() ? send_unicode_string("𝒪") : send_unicode_string("𝑜");
            return true;
        case KC_P:
            is_shift_pressed() ? send_unicode_string("𝒫") : send_unicode_string("𝓅");
            return true;
        case KC_Q:
            is_shift_pressed() ? send_unicode_string("𝒬") : send_unicode_string("𝓆");
            return true;
        case KC_R:
            is_shift_pressed() ? send_unicode_string("𝑅") : send_unicode_string("𝓇");
            return true;
        case KC_S:
            is_shift_pressed() ? send_unicode_string("𝒮") : send_unicode_string("𝓈");
            return true;
        case KC_T:
            is_shift_pressed() ? send_unicode_string("𝒯") : send_unicode_string("𝓉");
            return true;
        case KC_U:
            is_shift_pressed() ? send_unicode_string("𝒰") : send_unicode_string("𝓊");
            return true;
        case KC_V:
            is_shift_pressed() ? send_unicode_string("𝒱") : send_unicode_string("𝓋");
            return true;
        case KC_W:
            is_shift_pressed() ? send_unicode_string("𝒲") : send_unicode_string("𝓌");
            return true;
        case KC_X:
            is_shift_pressed() ? send_unicode_string("𝒳") : send_unicode_string("𝓍");
            return true;
        case KC_Y:
            is_shift_pressed() ? send_unicode_string("𝒴") : send_unicode_string("𝓎");
            return true;
        case KC_Z:
            is_shift_pressed() ? send_unicode_string("𝒵") : send_unicode_string("𝓏");
            return true;
    }

    return false;
}

bool gothic_text(uint16_t keycode) {
    switch (keycode) {
        case KC_A:
            is_shift_pressed() ? send_unicode_string("𝔄") : send_unicode_string("𝔞");
            return true;
        case KC_B:
            is_shift_pressed() ? send_unicode_string("𝔅") : send_unicode_string("𝔟");
            return true;
        case KC_C:
            is_shift_pressed() ? send_unicode_string("ℭ") : send_unicode_string("𝔠");
            return true;
        case KC_D:
            is_shift_pressed() ? send_unicode_string("𝔇") : send_unicode_string("𝔡");
            return true;
        case KC_E:
            is_shift_pressed() ? send_unicode_string("𝔈") : send_unicode_string("𝔢");
            return true;
        case KC_F:
            is_shift_pressed() ? send_unicode_string("𝔉") : send_unicode_string("𝔣");
            return true;
        case KC_G:
            is_shift_pressed() ? send_unicode_string("𝔊") : send_unicode_string("𝔤");
            return true;
        case KC_H:
            is_shift_pressed() ? send_unicode_string("ℌ") : send_unicode_string("𝔥");
            return true;
        case KC_I:
            is_shift_pressed() ? send_unicode_string("ℑ") : send_unicode_string("𝔦");
            return true;
        case KC_J:
            is_shift_pressed() ? send_unicode_string("𝔍") : send_unicode_string("𝔧");
            return true;
        case KC_K:
            is_shift_pressed() ? send_unicode_string("𝔎") : send_unicode_string("𝔨");
            return true;
        case KC_L:
            is_shift_pressed() ? send_unicode_string("𝔏") : send_unicode_string("𝔩");
            return true;
        case KC_M:
            is_shift_pressed() ? send_unicode_string("𝔐") : send_unicode_string("𝔪");
            return true;
        case KC_N:
            is_shift_pressed() ? send_unicode_string("𝔑") : send_unicode_string("𝔫");
            return true;
        case KC_O:
            is_shift_pressed() ? send_unicode_string("𝔒") : send_unicode_string("𝔬");
            return true;
        case KC_P:
            is_shift_pressed() ? send_unicode_string("𝔓") : send_unicode_string("𝔭");
            return true;
        case KC_Q:
            is_shift_pressed() ? send_unicode_string("𝔔") : send_unicode_string("𝔮");
            return true;
        case KC_R:
            is_shift_pressed() ? send_unicode_string("ℜ") : send_unicode_string("𝔯");
            return true;
        case KC_S:
            is_shift_pressed() ? send_unicode_string("𝔖") : send_unicode_string("𝔰");
            return true;
        case KC_T:
            is_shift_pressed() ? send_unicode_string("𝔗") : send_unicode_string("𝔱");
            return true;
        case KC_U:
            is_shift_pressed() ? send_unicode_string("𝔘") : send_unicode_string("𝔲");
            return true;
        case KC_V:
            is_shift_pressed() ? send_unicode_string("𝔙") : send_unicode_string("𝔳");
            return true;
        case KC_W:
            is_shift_pressed() ? send_unicode_string("𝔚") : send_unicode_string("𝔴");
            return true;
        case KC_X:
            is_shift_pressed() ? send_unicode_string("𝔛") : send_unicode_string("𝔵");
            return true;
        case KC_Y:
            is_shift_pressed() ? send_unicode_string("𝔜") : send_unicode_string("𝔶");
            return true;
        case KC_Z:
            is_shift_pressed() ? send_unicode_string("ℨ") : send_unicode_string("𝔷");
            return true;
    }

    return false;
}

bool small_caps_text(uint16_t keycode) {
    if (!is_shift_pressed()) {
        return false;
    }

    switch (keycode) {
        case KC_A:
            send_unicode_string("ᴀ");
            return true;
        case KC_B:
            send_unicode_string("ʙ");
            return true;
        case KC_C:
            send_unicode_string("ᴄ");
            return true;
        case KC_D:
            send_unicode_string("ᴅ");
            return true;
        case KC_E:
            send_unicode_string("ᴇ");
            return true;
        case KC_F:
            send_unicode_string("ꜰ");
            return true;
        case KC_G:
            send_unicode_string("ɢ");
            return true;
        case KC_H:
            send_unicode_string("ʜ");
            return true;
        case KC_I:
            send_unicode_string("ɪ");
            return true;
        case KC_J:
            send_unicode_string("ᴊ");
            return true;
        case KC_K:
            send_unicode_string("ᴋ");
            return true;
        case KC_L:
            send_unicode_string("ʟ");
            return true;
        case KC_M:
            send_unicode_string("ᴍ");
            return true;
        case KC_N:
            send_unicode_string("ɴ");
            return true;
        case KC_O:
            send_unicode_string("ᴏ");
            return true;
        case KC_P:
            send_unicode_string("ᴘ");
            return true;
        case KC_Q:
            send_unicode_string("ꞯ");
            return true;
        case KC_R:
            send_unicode_string("ʀ");
            return true;
        case KC_S:
            send_unicode_string("ꜱ");
            return true;
        case KC_T:
            send_unicode_string("ᴛ");
            return true;
        case KC_U:
            send_unicode_string("ᴜ");
            return true;
        case KC_V:
            send_unicode_string("ᴠ");
            return true;
        case KC_W:
            send_unicode_string("ᴡ");
            return true;
        /* There is no SMALL CAPITAL X */
        case KC_Y:
            send_unicode_string("ʏ");
            return true;
        case KC_Z:
            send_unicode_string("ᴢ");
            return true;
    }

    return false;
}

void zalgo_text(uint16_t keycode) {
    static bool seeded = false;

    if (seeded == false) {
        srand(timer_read32());
#if defined(CONSOLE_ENABLE)
        dprint("Seeded the pseudo-random number generator\n");
#endif
        seeded = true;
    }

    const unsigned int min_diacritic_count   = 2;
    const unsigned int max_diacritic_count   = 8;
    const uint16_t     comb_char_block_start = 0x0300;
    const uint16_t     comb_char_block_end   = 0x036F;

    /* Add up to 8 diacritical marks to the inputted character */
    unsigned int diacritic_count = rand() % (max_diacritic_count + 1 - min_diacritic_count) + min_diacritic_count;

    tap_code(keycode);

    for (unsigned int i = 0; i < diacritic_count; ++i) {
        /* https://en.wikipedia.org/wiki/Combining_character */
        uint16_t diacritic_hex = rand() % (comb_char_block_end + 1 - comb_char_block_start) + comb_char_block_start;

        unicode_input_start();

        register_hex(diacritic_hex);

        unicode_input_finish();
    }
}
