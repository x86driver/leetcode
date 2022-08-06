class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<pair<int, int>> s;
        map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && s.top().second < nums[i]) {
                m[s.top().first] = nums[i];
                s.pop();
            }
            s.push({i, nums[i]});
        }

        if (!s.empty()) {
            for (int i = 0; i < nums.size(); ++i) {
                while (!s.empty() && s.top().second < nums[i]) {
                    if (m.find(s.top().first) == m.end()) {
                        m[s.top().first] = nums[i];
                    }
                    s.pop();
                }
                s.push({i, nums[i]});
            }
        }

        while (!s.empty()) {
            if (m.find(s.top().first) == m.end()) {
                m[s.top().first] = -1;
            }
            s.pop();
        }

        for (auto &a : m) {
            //cout << "[" << a.first << "] " << a.second << endl;
            ans[a.first] = a.second;
        }

        return ans;
    }
};
