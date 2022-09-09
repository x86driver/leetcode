class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int size = std::min(num1.size(), num2.size());
        int i = 0;
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (i = 0; i < size; ++i) {
            int res = num1[i] - '0' + num2[i] - '0' + carry;
            if (res >= 10) {
                carry = 1;
                res -= 10;
            } else {
                carry = 0;
            }
            ans.push_back(res + '0');
        }

        if (num1.size() > num2.size()) {
            for (; i < num1.size(); ++i) {
                int res = num1[i] - '0' + carry;
                if (res >= 10) {
                    carry = 1;
                    res -= 10;
                } else {
                    carry = 0;
                }
                ans.push_back(res + '0');
            }
        } else {
            for (; i < num2.size(); ++i) {
                int res = num2[i] - '0' + carry;
                if (res >= 10) {
                    carry = 1;
                    res -= 10;
                } else {
                    carry = 0;
                }
                ans.push_back(res + '0');
            }
        }

        if (carry) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
