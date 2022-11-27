class Solution {
public:
    int secondHighest(string s) {
        set<int> digits;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                int n = c - '0';
                if (digits.find(n) == digits.end()) {
                    digits.insert(n);
                }
            }
        }

        if (digits.size() > 1) {
            auto it = digits.end();
            --it;
            int first = *it;
            --it;
            int second = *it;
            if (first == second) {
                return -1;
            } else {
                return second;
            }
        } else {
            return -1;
        }
    }
};
