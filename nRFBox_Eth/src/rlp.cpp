/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#include "rlp.h"
#include <string.h>

static size_t rlp_encode_length(size_t len, uint8_t offset, uint8_t *out) {
    if (len < 56) {
        out[0] = offset + len;
        return 1;
    }
    size_t l = len;
    uint8_t tmp[8];
    int idx = 0;
    while (l > 0) {
        tmp[idx++] = l & 0xFF;
        l >>= 8;
    }
    out[0] = offset + 55 + idx;
    for (int i = 0; i < idx; ++i) {
        out[1 + i] = tmp[idx - 1 - i];
    }
    return 1 + idx;
}

size_t rlp_encode_bytes(const uint8_t *data, size_t len, uint8_t *out) {
    if (len == 1 && data[0] < 0x80) {
        out[0] = data[0];
        return 1;
    }
    size_t p = rlp_encode_length(len, 0x80, out);
    memcpy(out + p, data, len);
    return p + len;
}

size_t rlp_encode_uint64(uint64_t value, uint8_t *out) {
    if (value == 0) {
        out[0] = 0x80;
        return 1;
    }
    uint8_t buf[8];
    int len = 0;
    while (value > 0) {
        buf[7 - len] = value & 0xFF;
        value >>= 8;
        len++;
    }
    return rlp_encode_bytes(buf + 8 - len, len, out);
}

size_t rlp_encode_bigint(const uint8_t *data, size_t len, uint8_t *out) {
    while (len > 0 && *data == 0) {
        ++data;
        --len;
    }
    if (len == 0) {
        out[0] = 0x80;
        return 1;
    }
    return rlp_encode_bytes(data, len, out);
}

size_t rlp_encode_list(const uint8_t *data, size_t len, uint8_t *out) {
    size_t p = rlp_encode_length(len, 0xC0, out);
    memcpy(out + p, data, len);
    return p + len;
}

