class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        stack<pair<int, int>> s;
        set<int> index;

        for (int i = 0; i < heights.size(); ++i) {
            int h = heights[i];
            while (!s.empty() && h >= s.top().second) {
                index.insert(s.top().first);
                s.pop();
            }
            s.push({i, h});
        }

        for (int i = 0; i < heights.size(); ++i) {
            if (index.find(i) == index.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
