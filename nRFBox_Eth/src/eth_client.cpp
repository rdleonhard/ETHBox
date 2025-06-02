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

String eth_client_wrapGetBalance(const String &address) {
    DynamicJsonDocument doc(128);
    doc["jsonrpc"] = "2.0";
    doc["method"] = "eth_getBalance";
    JsonArray params = doc.createNestedArray("params");
    params.add(address);
    params.add("latest");
    doc["id"] = 1;
    String out;
    serializeJson(doc, out);
    return out;
}

String eth_client_wrapSendRawTransaction(const String &rawTx) {
    DynamicJsonDocument doc(128);
    doc["jsonrpc"] = "2.0";
    doc["method"] = "eth_sendRawTransaction";
    JsonArray params = doc.createNestedArray("params");
    params.add(rawTx);
    doc["id"] = 1;
    String out;
    serializeJson(doc, out);
    return out;
}

String eth_client_wrapGetTransactionCount(const String &address) {
    DynamicJsonDocument doc(128);
    doc["jsonrpc"] = "2.0";
    doc["method"] = "eth_getTransactionCount";
    JsonArray params = doc.createNestedArray("params");
    params.add(address);
    params.add("latest");
    doc["id"] = 1;
    String out;
    serializeJson(doc, out);
    return out;
}

