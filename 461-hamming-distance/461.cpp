class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += (x & 0x1) ^ (y & 0x1);
            x >>= 1;
            y >>= 1;
        }
        return count;
    }
};
