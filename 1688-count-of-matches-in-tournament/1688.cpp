class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while (n >= 2) {
            matches += n / 2;
            if ((n % 2) == 0) {
                n /= 2;
            } else {
                n = (n + 1) / 2;
            }
        }
        return matches;
    }
};
