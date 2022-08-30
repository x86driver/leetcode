class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m;

        for (auto &n : nums) {
            if (m.find(n) == m.end()) {
                m[n] = 1;
            } else {
                ++m[n];
            }
        }

        vector<pair<int, int>> tmp(m.size());
        copy(m.begin(), m.end(), tmp.begin());
        sort(tmp.begin(), tmp.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) {
                 return b.second < a.second;
             });

        for (int i = 0; i < k; ++i) {
            ans.push_back(tmp[i].first);
        }

        return ans;
    }
};
