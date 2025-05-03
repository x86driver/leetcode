class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) {
            return false;
        }
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += (n & 0x01);
            n >>= 1;
        }
        return count == 1;
    }
};
