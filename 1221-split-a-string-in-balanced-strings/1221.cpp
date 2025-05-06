class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int i = 0;
        while (i < s.size()) {
            int balance = 0;
            for (int j = i; j < s.size(); ++j) {
                if (s[j] == 'R') {
                    ++balance;
                } else {
                    --balance;
                }
                if (balance == 0) {
                    ++count;
                    i = j + 1;
                }
            }
        }
        return count;
    }
};
