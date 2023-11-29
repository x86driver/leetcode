class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        for (int i = 0; i < 32; ++i) {
            if (n % 2 == 1) {
                if (i % 2 == 1)
                    ++odd;
                else
                    ++even;
            }
            n >>= 1;
        }
        return {even, odd};
    }
};
