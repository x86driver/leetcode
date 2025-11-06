class Solution {
private:
    long long mulmod(long long a, long long b, long long mod) {
        long long r = 0;
        a %= mod;
        while (b > 0) {
            if (b & 1) r = (r + a) % mod; // 只做加法
            a = (a + a) % mod;            // 反覆倍增
            b >>= 1;
        }
        return r;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int p = 1;
        while (n) {
            if (n & 0x01) {
                powers.push_back(p);
            }
            p <<= 1;
            n >>= 1;
        }

        vector<int> ans;
        for (const vector<int>& query : queries) {
            int start = query[0];
            int end = query[1];
            uint64_t tmp = 1;
            for (int i = start; i <= end; ++i) {
                tmp = mulmod(tmp, powers[i], 1000000007);
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};
