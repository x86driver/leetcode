class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        --ones;
        string ans;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (ones) {
                ans += '1';
                --ones;
            } else {
                ans += '0';
            }
        }
        ans += '1';
        return ans;
    }
};
