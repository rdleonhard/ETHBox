/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */


#include "display_eth.h"

// The main U8g2 object lives in main.cpp or another module.
// Declare it here so the display helpers can use it.
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;

void display_eth_setup() {
    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 10, "ETH Firmware");
    u8g2.sendBuffer();
}

void display_drawAddress(const char *address) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 10, "Address:");
    u8g2.setFont(u8g2_font_5x8_tf);
    u8g2.drawStr(0, 25, address);
    u8g2.sendBuffer();
}

void display_drawBalance(const char *balance) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 10, "Balance:");
    u8g2.setFont(u8g2_font_6x12_tf);
    u8g2.drawStr(0, 25, balance);
    u8g2.sendBuffer();
}

void display_drawTxStatus(const char *status) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 10, "TX Status:");
    u8g2.setFont(u8g2_font_6x12_tf);
    u8g2.drawStr(0, 25, status);
    u8g2.sendBuffer();
}

void display_drawSettings(bool neoPixelEnabled, uint8_t brightness) {
    char buf[20];

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 10, "Settings");

    u8g2.drawStr(0, 25, neoPixelEnabled ? "NeoPixel: On" : "NeoPixel: Off");

    snprintf(buf, sizeof(buf), "Bright: %u", brightness);
    u8g2.drawStr(0, 40, buf);

    u8g2.sendBuffer();
}

void display_eth_loop() {
    // This firmware is under heavy development.
    // Nothing to update continuously yet.
}

