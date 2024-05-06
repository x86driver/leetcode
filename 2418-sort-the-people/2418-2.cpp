class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> m(10e5 + 1);
        for (int i = 0; i < names.size(); ++i) {
            m[heights[i]] = names[i];
        }
        vector<string> ans;
        for (int i = m.size() - 1; i >= 0; --i) {
            const string& name = m[i];
            if (name.size() > 0) {
                ans.push_back(name);
            }
        }

        return ans;
    }
};
