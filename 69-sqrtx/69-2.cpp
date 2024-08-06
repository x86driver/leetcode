class Solution {
public:
    int mySqrt(int x) {
        for (uint32_t i = 1; i <= x / 2 + 1; ++i) {
            uint32_t tmp = i * i;
            if (tmp == x)
                return i;
            else if (tmp > x)
                return i - 1;
        }
        return x;
    }
};
