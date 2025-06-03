# nRFBOX

nRFBOX is a portable toolkit for experimenting with Bluetooth Low Energy (BLE) and other 2.4&nbsp;GHz wireless protocols.  It combines an ESP32 Wroom32U, NRF24 modules and a small OLED display into a single device that can scan, spoof and test wireless devices.

## Features
- **BLE spoofer** for generating custom advertisements.
- **BLE scanner** to discover nearby devices.
- **Sour Apple** attack demonstration.
- Secure key storage using ESP32's NVS with optional PIN protection.

## Hardware
- ESP32 Wroom32U module
- NRF24 GTmini transceivers
- 0.96" OLED display
- Buttons and NeoPixel for user feedback

## Building from Source
1. Install the Arduino IDE (version 1.8 or later).
2. Install the ESP32 board package (tested with 2.0.11).
3. Open `nRFBox_V2/nRFBox_V2.ino` and select the *ESP32 Dev Module* board.
4. Compile and upload the sketch to your ESP32.

## Flashing the Precompiled Binary
1. Download the binary from the [`precompiled  bin`](precompiled%20%20bin) directory.
2. Use the [ESP32 Flash Download Tool](https://www.espressif.com/sites/default/files/tools/flash_download_tool_3.9.7_2.zip).
3. Add the binary with start address `0x10000`, select the correct COM port and baud rate, then start the flash process.

## Documentation
Full documentation, tutorials and hardware details are available on the [project page](https://cifertech.net/nrfbox-your-all-in-one-gadget-for-ble-and-2-4ghz-networks/).

## License
nRFBOX is distributed under the MIT License. See [LICENCE](LICENCE) for details.

## Contact
CiferTech – [Twitter](https://twitter.com/techcifer) · [Instagram](https://www.instagram.com/cifertech/) · [YouTube](https://www.youtube.com/@techcifer)

Support the project on [Patreon](https://www.patreon.com/cifertech).

## Acknowledgements
This project makes use of several open source libraries and ideas, including:
- [Poor Man's 2.4 GHz Scanner](https://forum.arduino.cc/t/poor-mans-2-4-ghz-scanner/54846)
- [arduino_oled_menu](https://github.com/upiir/arduino_oled_menu)
- [nRF24L01-WiFi-Jammer](https://github.com/hugorezende/nRF24L01-WiFi-Jammer)
- [Universal-RC-system](https://github.com/alexbeliaev/Universal-RC-system/tree/master)
- [AppleJuice](https://github.com/ECTO-1A/AppleJuice)
- [ESP32-Sour-Apple](https://github.com/RapierXbox/ESP32-Sour-Apple)
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
- [micro-ecc](https://github.com/kmackay/micro-ecc)
- [TinySHA3](https://github.com/techninethrop/TinySHA3)
- [ESP32 Preferences](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/preferences.html)

Thanks to everyone in the community who contributes improvements and ideas!
