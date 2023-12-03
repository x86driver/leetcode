class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end(), greater<char>());
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s.back() == '0' && s[i] == '1') {
                s.back() = '1';
                s[i] = '0';
                break;
            }
        }
        return s;

    }
};
