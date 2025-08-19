class Solution {
public:
    int minChanges(int n, int k) {
        int count = 0;
        while (n || k) {
            int bit_n = n & 0x01;
            int bit_k = k & 0x01;
            if (bit_n == 0 && bit_k == 1) {
                return -1;
            }
            if (bit_n == 1 && bit_k == 0) {
                ++count;
            }
            n >>= 1;
            k >>= 1;
        }
        return count;
    }
};
