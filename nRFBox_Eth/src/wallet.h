/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#ifndef WALLET_H
#define WALLET_H

// Simple Ethereum wallet utilities

typedef struct {
    uint32_t nonce;
    uint64_t gasPrice;
    uint64_t gasLimit;
    uint8_t to[20];
    uint64_t value;
    const uint8_t *data;
    size_t dataLen;
    uint32_t chainId;
} EthTransaction;

void wallet_setup();
void wallet_loop();
size_t wallet_signTransaction(const EthTransaction *tx, const uint8_t *privateKey, uint8_t *out);

#endif // WALLET_H
