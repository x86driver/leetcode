class Solution {
public:
    bool digitCount(string num) {
        vector<int> m(11);
        for (char c : num)
            ++m[c - '0'];

        for (int i = 0; i < num.size(); ++i) {
            int occur = num[i] - '0';
            if (m[i] != occur)
                return false;
        }
        return true;
    }
};
