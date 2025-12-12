class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0;
        vector<int> bits;
        while (n > 0) {
            int bit = 1 - (n % 2);
            bits.push_back(bit);
            n /= 2;
        }
        reverse(bits.begin(), bits.end());
        for (int bit : bits) {
            ans *= 2;
            ans += bit;
        }
        return ans;
    }
};
