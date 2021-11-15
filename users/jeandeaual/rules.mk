SRC += jeandeaual.c

ifeq ($(strip $(UNICODE_ENABLE)), yes)
    SRC += fancy_text.c
endif

ifeq ($(strip $(KANA_INPUT)), yes)
	SRC += kana_input.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	ifeq ($(strip $(MORSE_INPUT)), yes)
		SRC += morse.c
	endif
endif

# Always enable link-time optimization
LTO_ENABLE = yes

# Prevent VUSB boards from enabling NKRO, as they do not support it
ifeq ($(strip $(PROTOCOL)), VUSB)
    NKRO_ENABLE = no
endif
