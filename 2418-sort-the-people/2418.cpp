class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> m(1e5 + 1, -1);
        vector<string> ans;
        for (int i = 0; i < names.size(); ++i) {
            m[heights[i]] = i;
        }
        for (int i = 1e5; i > 0; --i) {
            if (m[i] >= 0)
                ans.push_back(names[m[i]]);
        }
        return ans;
    }
};
