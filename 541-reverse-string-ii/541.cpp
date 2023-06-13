class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.size()) {
            if ((i + k) > s.size()) {
                for (int j = i; j < (i + s.size()) / 2; ++j) {
                    swap(s[j], s[i + s.size() - j - 1]);
                }
                break;
            }
            for (int j = i; j < (i + i + k) / 2; ++j) {
                swap(s[j], s[i + i + k - j - 1]);
            }
            i += k * 2;
        }
        return s;
    }
};
