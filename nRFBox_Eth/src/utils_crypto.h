/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#ifndef UTILS_CRYPTO_H
#define UTILS_CRYPTO_H

#include <Arduino.h>
#include <uECC.h>
#include "sha3.h"

void utils_crypto_setup();
void utils_crypto_loop();
void utils_crypto_public_key(const uint8_t *privateKey, uint8_t *publicKey);
void utils_crypto_keccak(const uint8_t *data, size_t len, uint8_t *hash);

#endif // UTILS_CRYPTO_H
