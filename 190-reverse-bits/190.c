uint32_t reverseBits(uint32_t n) {
    uint32_t val = 0;
    for (int i = 0; i < 32; ++i) {
        uint32_t tmp = n & 0x01;
        n >>= 1;
        val |= (tmp << (31 - i));
    }

    return val;
}
