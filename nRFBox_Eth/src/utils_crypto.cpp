/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#include "utils_crypto.h"

void utils_crypto_setup() {
    // nothing to initialize
}

void utils_crypto_loop() {
    // nothing yet
}

void utils_crypto_public_key(const uint8_t *privateKey, uint8_t *publicKey) {
    uECC_compute_public_key(privateKey, publicKey, uECC_secp256k1());
}

void utils_crypto_keccak(const uint8_t *data, size_t len, uint8_t *hash) {
    sha3_ctx_t ctx;
    keccak_init(&ctx, 256);
    sha3_update(&ctx, data, len);
    keccak_final(hash, &ctx);
}

