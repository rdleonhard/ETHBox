import unittest

mask = (1 << 64) - 1
ROTATION_OFFSETS = [
    [0, 36, 3, 41, 18],
    [1, 44, 10, 45, 2],
    [62, 6, 43, 15, 61],
    [28, 55, 25, 21, 56],
    [27, 20, 39, 8, 14]
]
RC = [
    0x0000000000000001, 0x0000000000008082, 0x800000000000808A,
    0x8000000080008000, 0x000000000000808B, 0x0000000080000001,
    0x8000000080008081, 0x8000000000008009, 0x000000000000008A,
    0x0000000000000088, 0x0000000080008009, 0x000000008000000A,
    0x000000008000808B, 0x800000000000008B, 0x8000000000008089,
    0x8000000000008003, 0x8000000000008002, 0x8000000000000080,
    0x000000000000800A, 0x800000008000000A, 0x8000000080008081,
    0x8000000000008080, 0x0000000080000001, 0x8000000080008008
]

def _rotl(x, n):
    return ((x << n) & mask) | ((x >> (64 - n)) & mask)

def _keccak_f(state):
    for rc in RC:
        C = [state[x] ^ state[x+5] ^ state[x+10] ^ state[x+15] ^ state[x+20] for x in range(5)]
        D = [C[(x-1)%5] ^ _rotl(C[(x+1)%5], 1) for x in range(5)]
        for x in range(5):
            for y in range(5):
                state[x + 5*y] ^= D[x]
        B = [0]*25
        for x in range(5):
            for y in range(5):
                B[y + 5*((2*x + 3*y) % 5)] = _rotl(state[x + 5*y], ROTATION_OFFSETS[x][y])
        for x in range(5):
            for y in range(5):
                state[x + 5*y] = B[x + 5*y] ^ ((~B[(x+1)%5 + 5*y]) & B[(x+2)%5 + 5*y])
        state[0] ^= rc

def keccak256(data: bytes) -> bytes:
    rate = 136
    state = [0]*25
    padded = data + b'\x01'
    padlen = (-len(padded) - 1) % rate
    padded += b'\x00' * padlen + b'\x80'
    for i in range(0, len(padded), rate):
        block = padded[i:i+rate]
        for j in range(rate // 8):
            state[j] ^= int.from_bytes(block[j*8:(j+1)*8], 'little')
        _keccak_f(state)
    out = bytearray()
    while len(out) < 32:
        for j in range(rate // 8):
            out.extend(state[j].to_bytes(8, 'little'))
        if len(out) >= 32:
            break
        _keccak_f(state)
    return bytes(out[:32])

# secp256k1 parameters
p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F
Gx = 0x79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798
Gy = 0x483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8
G = (Gx, Gy)

def _inv(n):
    return pow(n, p-2, p)

def _add(P, Q):
    if P is None:
        return Q
    if Q is None:
        return P
    x1, y1 = P
    x2, y2 = Q
    if x1 == x2 and y1 != y2:
        return None
    if P == Q:
        m = (3*x1*x1) * _inv(2*y1) % p
    else:
        m = (y2 - y1) * _inv(x2 - x1) % p
    x3 = (m*m - x1 - x2) % p
    y3 = (m*(x1 - x3) - y1) % p
    return (x3, y3)

def _mul(k, P):
    R = None
    N = P
    while k:
        if k & 1:
            R = _add(R, N)
        N = _add(N, N)
        k >>= 1
    return R

def priv_to_addr(priv_hex: str) -> str:
    priv = int(priv_hex, 16)
    pub = _mul(priv, G)
    pub_bytes = pub[0].to_bytes(32, 'big') + pub[1].to_bytes(32, 'big')
    addr = keccak256(pub_bytes)[-20:]
    return '0x' + addr.hex()

class TestAddressDerivation(unittest.TestCase):
    def test_known_vector(self):
        priv = '4646464646464646464646464646464646464646464646464646464646464646'
        expected = '0x9d8a62f656a8d1615c1294fd71e9cfb3e4855a4f'
        self.assertEqual(priv_to_addr(priv), expected)

if __name__ == '__main__':
    unittest.main()
