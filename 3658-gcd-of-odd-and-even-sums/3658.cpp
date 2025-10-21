class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        for (int i = 1; i <= n; ++i) {
            sumOdd += (i * 2) - 1;
            sumEven += i * 2;
        }

        int gcd = 1;
        for (int i = 1; i < sumEven / 2; ++i) {
            if (sumOdd % i == 0 && sumEven % i == 0) {
                gcd = i;
            }
        }
        return gcd;
    }
};
