class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        for (long i = 1; i < 2147483648; i <<= 1) {
            if (n == i)
                return true;
        }
        return false;
    }
};
