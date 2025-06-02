/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#ifndef RLP_H
#define RLP_H

#include <Arduino.h>

size_t rlp_encode_uint64(uint64_t value, uint8_t *out);
size_t rlp_encode_bytes(const uint8_t *data, size_t len, uint8_t *out);
size_t rlp_encode_bigint(const uint8_t *data, size_t len, uint8_t *out);
size_t rlp_encode_list(const uint8_t *data, size_t len, uint8_t *out);

#endif // RLP_H
