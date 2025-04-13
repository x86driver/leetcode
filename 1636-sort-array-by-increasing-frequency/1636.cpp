class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) {
            ++m[n];
        }

        vector<int> ans;
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int ,int>& p2) {
            if (p1.second != p2.second) {
                return p1.second < p2.second;
            }
            return p2.first < p1.first;
        });
        for (pair<int, int>& p : v) {
            for (int i = 0; i < p.second; ++i) {
                ans.push_back(p.first);
            }
        }

        return ans;

    }
};
