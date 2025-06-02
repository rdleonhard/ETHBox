/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#include "wallet.h"
#include "utils_crypto.h"
#include "rlp.h"
#include <string.h>

void wallet_setup() {
    // TODO: initialize wallet
}

void wallet_loop() {
    // TODO: implement wallet runtime logic
}

size_t wallet_signTransaction(const EthTransaction *tx, const uint8_t *privateKey, uint8_t *out) {
    uint8_t buf[256];
    size_t p = 0;
    p += rlp_encode_uint64(tx->nonce, buf + p);
    p += rlp_encode_uint64(tx->gasPrice, buf + p);
    p += rlp_encode_uint64(tx->gasLimit, buf + p);
    p += rlp_encode_bytes(tx->to, sizeof(tx->to), buf + p);
    p += rlp_encode_uint64(tx->value, buf + p);
    p += rlp_encode_bytes(tx->data, tx->dataLen, buf + p);
    p += rlp_encode_uint64(tx->chainId, buf + p);
    p += rlp_encode_uint64(0, buf + p);
    p += rlp_encode_uint64(0, buf + p);

    uint8_t tmp[300];
    size_t listLen = rlp_encode_list(buf, p, tmp);

    uint8_t hash[32];
    utils_crypto_keccak(tmp, listLen, hash);

    uint8_t sig[64];
    if (!utils_crypto_sign(hash, privateKey, sig)) {
        return 0;
    }

    p = 0;
    p += rlp_encode_uint64(tx->nonce, buf + p);
    p += rlp_encode_uint64(tx->gasPrice, buf + p);
    p += rlp_encode_uint64(tx->gasLimit, buf + p);
    p += rlp_encode_bytes(tx->to, sizeof(tx->to), buf + p);
    p += rlp_encode_uint64(tx->value, buf + p);
    p += rlp_encode_bytes(tx->data, tx->dataLen, buf + p);
    uint64_t v = (uint64_t)tx->chainId * 2 + 35;
    p += rlp_encode_uint64(v, buf + p);
    p += rlp_encode_bigint(sig, 32, buf + p);
    p += rlp_encode_bigint(sig + 32, 32, buf + p);

    return rlp_encode_list(buf, p, out);
}

