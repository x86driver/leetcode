class Solution {
private:
    void split(const string& str, map<string, int> &m) {
        istringstream iss(str);
        string token;
        set<string> s;
        while (iss >> token) {
            if (!token.empty()) {
                ++m[token];
            }
        }
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> m;
        vector<string> ans;
        split(s1, m);
        split(s2, m);
        for (const pair<string, int>& p : m) {
            if (p.second == 1)
                ans.push_back(p.first);
        }
        return ans;
    }
};
