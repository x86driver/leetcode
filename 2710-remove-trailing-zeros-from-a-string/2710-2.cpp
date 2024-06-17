class Solution {
public:
    string removeTrailingZeros(string num) {
        vector<char> v(num.begin(), num.end());
        int i = v.size() - 1;
        while (i >= 0) {
            if (v[i] == '0')
                --i;
            else
                break;
        }
        string ans(v.begin(), v.begin() + i + 1);
        return ans;
    }
};
