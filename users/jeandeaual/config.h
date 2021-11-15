#pragma once

/* Set the USB polling rate to 1000 Hz */
#define USB_POLLING_INTERVAL_MS 1

#ifdef UNICODE_ENABLE
#    define UNICODE_SELECTED_MODES UC_LNX, UC_MAC, UC_WINC
#endif

/* Always enable n-key rollover */
#define FORCE_NKRO
