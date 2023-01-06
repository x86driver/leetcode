uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 31; ++i) {
        if (n & 0x01)
            ans |= 1;
        ans <<= 1;
        n >>= 1;
    }
    if (n)
        ans |= 1;
    return ans;
}
