class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (int i = s[0] - 'A'; i <= s[3] - 'A'; ++i) {
            for (int j = s[1] - '0'; j <= s[4] - '0'; ++j) {
                char col = 'A' + i;
                char row = '0' + j;
                char str[3] = {col, row, '\0'};
                ans.push_back(str);
            }
        }
        return ans;
    }
};
