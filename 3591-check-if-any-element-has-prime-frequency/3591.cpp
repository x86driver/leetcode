class Solution {
private:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> m(101);
        for (int n : nums) {
            ++m[n];
        }
        for (int i = 0; i < m.size(); ++i) {
            if (isPrime(m[i])) {
                return true;
            }
        }
        return false;
    }
};
