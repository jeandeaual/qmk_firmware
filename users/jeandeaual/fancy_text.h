#pragma once

#include "quantum.h"

typedef enum {
    FT_NONE,
    FT_CURSIVE,
    FT_GOTHIC,
    FT_SMALL_CAPS,
    FT_ZALGO,
} fancy_text_state_t;

#if defined(CONSOLE_ENABLE)
const char *get_fancy_text_name(fancy_text_state_t var);
#endif
bool cursive_text(uint16_t keycode);
bool gothic_text(uint16_t keycode);
bool small_caps_text(uint16_t keycode);
void zalgo_text(uint16_t keycode);
