/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#include "eth_client.h"

void eth_client_setup() {
    // nothing to init
}

void eth_client_loop() {
    // nothing for now
}

void eth_client_parseBalance(const char *json) {
    DynamicJsonDocument doc(256);
    DeserializationError err = deserializeJson(doc, json);
    if (err) {
        Serial.println("JSON parse failed");
        return;
    }
    const char *result = doc["result"];
    Serial.print("Balance: ");
    Serial.println(result ? result : "null");
}

