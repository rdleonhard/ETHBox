/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#ifndef DISPLAY_ETH_H
#define DISPLAY_ETH_H

#include <U8g2lib.h>

// Basic OLED UI helpers for the Ethereum firmware

void display_eth_setup();
void display_eth_loop();

void display_drawAddress(const char *address);
void display_drawBalance(const char *balance);
void display_drawTxStatus(const char *status);
void display_drawSettings(bool neoPixelEnabled, uint8_t brightness);

#endif // DISPLAY_ETH_H
