/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#ifndef ETH_CLIENT_H
#define ETH_CLIENT_H

#include <Arduino.h>
#include <ArduinoJson.h>

void eth_client_setup();
void eth_client_loop();
void eth_client_parseBalance(const char *json);

#endif // ETH_CLIENT_H
