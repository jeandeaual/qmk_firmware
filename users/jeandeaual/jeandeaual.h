#pragma once

#include "quantum.h"
#if defined(UNICODE_ENABLE)
#    include "fancy_text.h"
#endif
#if defined(MORSE_INPUT)
#    include "morse.h"
#endif

enum custom_keycodes {
    ALTSHFT = SAFE_RANGE,
    CURSIVE,
    GOTHIC,
    SMCAPS,
    ZALGO,

#if defined(KANA_INPUT)
    KANA_INPUT_ON,
    KANA_INPUT_OFF,
    KANA_INPUT_TOGGLE,

    /* Kana */
    KN_KA,
    KN_KI,
    KN_KU,
    KN_KE,
    KN_KO,
    KN_KY,

    KN_SA,
    KN_SI,
    KN_SU,
    KN_SE,
    KN_SO,
    KN_SY,

    KN_TA,
    KN_TI,
    KN_TU,
    KN_TE,
    KN_TO,
    KN_TY,

    KN_NA,
    KN_NI,
    KN_NU,
    KN_NE,
    KN_NO,
    KN_NY,

    KN_HA,
    KN_HI,
    KN_HU,
    KN_HE,
    KN_HO,
    KN_HY,

    KN_MA,
    KN_MI,
    KN_MU,
    KN_ME,
    KN_MO,
    KN_MY,

    KN_RA,
    KN_RI,
    KN_RU,
    KN_RE,
    KN_RO,
    KN_RY,

    KN_PA,
    KN_PI,
    KN_PU,
    KN_PE,
    KN_PO,
    KN_PY,

    KN_GA,
    KN_GI,
    KN_GU,
    KN_GE,
    KN_GO,
    KN_GY,

    KN_ZA,
    KN_ZI,
    KN_ZU,
    KN_ZE,
    KN_ZO,
    KN_ZY,

    KN_DA,
    KN_DI,
    KN_DU,
    KN_DE,
    KN_DO,
    KN_DY,

    KN_BA,
    KN_BI,
    KN_BU,
    KN_BE,
    KN_BO,
    KN_BY,

    KN_YA,
    KN_YU = KN_YA + 2,
    KN_YO = KN_YU + 2,

    KN_WA = KN_YO + 2,
    KN_WO = KN_WA + 4,

    KN_XA = KN_WO + 2,
    KN_XI,
    KN_XU,
    KN_XE,
    KN_XO,

    KN_XKA = KN_XO + 2,
    KN_XKE = KN_XKA + 3,

    KN_XTU = KN_XKE + 5,

    KN_XYA = KN_XTU + 4,
    KN_XYU = KN_XYA + 2,
    KN_XYO = KN_XYU + 2,

    KN_XWA = KN_XYO + 2,

    KN_WYI = KN_XWA + 12,
    KN_WYE = KN_WYI + 2,

    KN_VU = KN_WYE + 5,

    KN_N,

    KN_DAKUTEN,
    KN_HANDAKU,

    /* M-type */
    KN_ANN,
    KN_AKU,
    KN_ATU,
    KN_AI,
    KN_INN,
    KN_IKU,
    KN_ITU,
    KN_UNN,
    KN_UKU,
    KN_UTU,
    KN_ENN,
    KN_EKI,
    KN_ETU,
    KN_EI,
    KN_ONN,
    KN_OKU,
    KN_OTU,
    KN_OU,

    /* Punctuation */
    KN_LWCB,     /* 『 */
    KN_RWCB,     /* 』 */
    KN_LSB,      /* [ */
    KN_RSB,      /* ] */
    KN_NAKAGURO, /* ・ */
    KN_SANTEN,   /* ・・・ */
#endif

    NEW_SAFE_RANGE,
};

#if defined(KANA_INPUT)
#    define KN_ON KANA_INPUT_ON
#    define KN_OFF KANA_INPUT_OFF
#    define KN_TOG KANA_INPUT_TOGGLE
#    define KN_A KC_A
#    define KN_E KC_E
#    define KN_I KC_I
#    define KN_O KC_O
#    define KN_U KC_U
#    define KN_FU KN_HU
#    define KN_TSU KN_TU
#    define KN_QUESTION KC_QUESTION /* ？ */
#    define KN_QUES KN_QUESTION
#    define KN_CHOUON KC_MINUS /* ー */
#    define KN_CHON KN_CHOUON
#    define KN_TOUTEN KC_COMMA /* 、 */
#    define KN_TTEN KN_TOUTEN
#    define KN_KUTEN KC_DOT /* 。 */
#    define KN_KTEN KN_KUTEN
#    define KN_LABK KC_LEFT_ANGLE_BRACKET  /* < */
#    define KN_RABK KC_RIGHT_ANGLE_BRACKET /* > */
#    define KN_LCBK KC_LBRACKET            /* 「 */
#    define KN_RCBK KC_RBRACKET            /* 」 */
#    define KN_NAMI KC_TILDE               /* 〜 */
#    define KN_SLASH KC_SLASH              /* ／ */
#    define KN_DKT KN_DAKUTEN
#    define KN_HDKT KN_HANDAKU
#    define KN_NKGR KN_NAKAGURO /* ・ */
#    define KN_STEN KN_SANTEN   /* ・・・ */
#endif
