class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        const int orig = n;
        while (n) {
            int d = n % 10;
            n /= 10;
            rev *= 10;
            rev += d;
        }
        return abs(orig - rev);
    }
};
