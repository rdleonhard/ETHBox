/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#include "storage_manager.h"
#include <string.h>

static const char *NVS_NAMESPACE = "nrfbox";
static const char *KEY_COUNTER = "counter";
static const char *KEY_PRIVKEY = "privkey";

static void xor_data(uint8_t *data, size_t len, const uint8_t *key, size_t klen) {
    for (size_t i = 0; i < len; ++i) {
        data[i] ^= key[i % klen];
    }
}

Preferences prefs;

void storage_manager_setup() {
    prefs.begin(NVS_NAMESPACE, false);
}

void storage_manager_saveCounter(uint32_t counter) {
    prefs.putUInt(KEY_COUNTER, counter);
}

uint32_t storage_manager_loadCounter() {
    return prefs.getUInt(KEY_COUNTER, 0);
}

void storage_manager_savePrivateKey(const uint8_t *key, size_t len, const char *pin) {
    uint8_t buffer[64];
    if (len > sizeof(buffer)) len = sizeof(buffer);
    memcpy(buffer, key, len);
    if (pin && pin[0]) {
        uint8_t hash[32];
        utils_crypto_keccak(reinterpret_cast<const uint8_t*>(pin), strlen(pin), hash);
        xor_data(buffer, len, hash, 16);
    }
    prefs.putBytes(KEY_PRIVKEY, buffer, len);
}

bool storage_manager_loadPrivateKey(uint8_t *key, size_t len, const char *pin) {
    size_t stored = prefs.getBytesLength(KEY_PRIVKEY);
    if (stored == 0 || stored > len) return false;
    prefs.getBytes(KEY_PRIVKEY, key, stored);
    if (pin && pin[0]) {
        uint8_t hash[32];
        utils_crypto_keccak(reinterpret_cast<const uint8_t*>(pin), strlen(pin), hash);
        xor_data(key, stored, hash, 16);
    }
    return true;
}

void storage_manager_loop() {
    // nothing for now
}

