class Solution {
public:
    bool digitCount(string num) {
        vector<int> m(10);
        for (char c : num) {
            ++m[c - '0'];
        }
        for (int i = 0; i < num.size(); ++i) {
            if ((num[i] - '0') != m[i])
                return false;
        }
        return true;
    }
};
