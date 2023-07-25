class Solution {
public:
    string removeTrailingZeros(string num) {
        string ans;
        reverse(num.begin(), num.end());
        int i = 0;
        for (i = 0; i < num.size(); ++i) {
            if (num[i] == '0')
                continue;
            else
                break;
        }
        ans = num.substr(i);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
