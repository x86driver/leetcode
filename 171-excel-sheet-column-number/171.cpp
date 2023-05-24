class Solution {
public:
    int titleToNumber(string columnTitle) {
        int exp = columnTitle.size() - 1;
        int count = 0;
        for (int i = 0; i < columnTitle.size(); ++i) {
            char c = columnTitle[i];
            int n = c - 'A' + 1;
            count += pow(26, exp) * n;
            --exp;
        }
        return count;
    }
};
