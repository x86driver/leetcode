class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for (const vector<string>& item : items) {
            if (ruleKey == "type") {
                if (item[0] == ruleValue) {
                    ++count;
                }
            } else if (ruleKey == "color") {
                if (item[1] == ruleValue) {
                    ++count;
                }
            } else if (ruleKey == "name") {
                if (item[2] == ruleValue) {
                    ++count;
                }
            }
        }
        return count;
    }
};
