class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for (const vector<string>& item : items) {
            const string& type = item[0];
            const string& color = item[1];
            const string& name = item[2];
            if (ruleKey == "type" && ruleValue == type)
                ++count;
            else if (ruleKey == "color" && ruleValue == color)
                ++count;
            else if (ruleKey == "name" && ruleValue == name)
                ++count;
        }
        return count;
    }
};
