class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (string &str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            um[sorted].push_back(str);
        }
        vector<vector<string>> ans;

        for (const pair<string, vector<string>>& p : um) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
