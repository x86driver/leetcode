class Solution {
public:
    int sumOfBlocks(int n) {
        uint64_t sum = 1;
        uint64_t num = 2;
        uint64_t mod = 1000000007;
        for (int i = 2; i <= n; ++i) {
            uint64_t local = 1;
            for (int j = 0; j < i; ++j) {
                local *= num;
                local %= mod;
                ++num;
            }
            sum += local;
        }
        return sum % mod;
    }
};
