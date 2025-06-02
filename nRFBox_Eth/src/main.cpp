// Placeholder main.cpp
// Drop your refactored nRFBox Ethereum firmware here (e.g. menu_eth, wallet, etc.)

#include <Arduino.h>
#include "storage_manager.h"
#include "utils_crypto.h"
#include "eth_client.h"

void setup() {
  Serial.begin(115200);

  storage_manager_setup();
  utils_crypto_setup();
  eth_client_setup();

  uint32_t counter = storage_manager_loadCounter();
  Serial.printf("Stored counter: %u\n", counter);
  counter++;
  storage_manager_saveCounter(counter);

  const char *json = "{\"jsonrpc\":\"2.0\",\"result\":\"0x1\",\"id\":1}";
  eth_client_parseBalance(json);

  uint8_t priv[32] = {1};
  uint8_t pub[64];
  utils_crypto_public_key(priv, pub);

  const char *msg = "hello";
  uint8_t hash[32];
  utils_crypto_keccak((const uint8_t *)msg, strlen(msg), hash);
  Serial.println("Crypto demo complete");
}

void loop() {
  delay(1000);
}
