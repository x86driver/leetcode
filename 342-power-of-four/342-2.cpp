class Solution {
public:
    bool isPowerOfFour(int n) {
        int start = 1;
        while (start <= n) {
            if (start == 0) {
                return false;
            }
            if (start == n) {
                return true;
            }
            start <<= 2;
        }
        return false;
    }
};
