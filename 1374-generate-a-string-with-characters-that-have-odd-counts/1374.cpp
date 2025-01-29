class Solution {
public:
    string generateTheString(int n) {
        if (n == 1) {
            return "a";
        }
        string ans;
        if (n % 2 == 0) {
            for (int i = 0; i < n - 1; ++i) {
                ans += 'a';
            }
            ans += 'b';
        } else {
            ans = "ab";
            for (int i = 0; i < n - 2; ++i) {
                ans += 'c';
            }
        }
        return ans;
    }
};
