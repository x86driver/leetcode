class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans;
        if (a.size() > b.size()) {
            int diff = a.size() - b.size();
            for (int i = 0; i < diff; ++i) {
                b = '0' + b;
            }
        } else if (b.size() > a.size()) {
            int diff = b.size() - a.size();
            for (int i = 0; i < diff; ++i) {
                a = '0' + a;
            }
        }

        int ptr = a.size() - 1;
        for (ptr; ptr >= 0; --ptr) {
            int result = (a[ptr] - '0') + (b[ptr] - '0') + carry;
            if (result >= 2) {
                result -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans += (result + '0');
        }

        if (carry) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
        return ans;

    }
};
