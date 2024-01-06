class Solution {
public:
    int mostExpensiveItem(int primeOne, int primeTwo) {
        vector<bool> m(10e5 + 1);
        for (int j = 0; j <= primeTwo; j++) {
            for (int k = 0; k <= primeOne; ++k) {
                m[(j * primeOne) + (k * primeTwo)] = true;
            }
        }

        for (int i = primeOne * primeTwo - 1; i > 0; i--) {
            if (!m[i])
                return i;
        }
        return 1;
    }
};
