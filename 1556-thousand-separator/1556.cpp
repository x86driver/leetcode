class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0)
            return "0";
        string ans;
        int count = 0;
        while (n > 0) {
            ans += to_string(n % 10);
            n /= 10;
            ++count;
            if (count % 3 == 0)
                ans += ".";
        }
        reverse(ans.begin(), ans.end());
        if (ans[0] == '.')
            return ans.substr(1);
        else
            return ans;
    }
};
