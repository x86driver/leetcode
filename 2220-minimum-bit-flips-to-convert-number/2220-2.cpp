class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = 0;
        for (int i = 0; i < 32; ++i) {
            if ((start & 0x01) != (goal & 0x01)) {
                ++diff;
            }
            start >>= 1;
            goal >>= 1;
        }
        return diff;
    }
};
