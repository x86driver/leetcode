class Solution {
private:
    bool kconstraint(const string& str, int k) {
        int one = 0;
        int zero = 0;
        for (char c : str) {
            if (c == '0') {
                ++zero;
            } else {
                ++one;
            }
        }
        return zero <= k || one <= k;
    }
public:
    int countKConstraintSubstrings(string s, int k) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int len = 1; i + len <= s.size(); ++len) {
                if (kconstraint(s.substr(i, len), k)) {
                    ++count;
                }
            }
        }
        return count;
    }
};
