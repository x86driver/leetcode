class Solution {
public:
    int minimumFlips(int n) {
        int count = 0;
        int flip = 0;
        int orig_n = n;
        while (n > 0) {
            flip *= 2;
            flip += n % 2;
            n /= 2;
        }
        n = orig_n;
        while (n > 0) {
            if ((n % 2) != (flip % 2)) {
                ++count;
            }
            n >>= 1;
            flip >>= 1;
        }
        return count;
    }
};
