class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> m(101, vector<int>());
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]].push_back(i);
        }
        int distance = INT_MAX;
        for (const vector<int>& v : m) {
            if (v.size() < 3) {
                continue;
            }
            for (int i = 0; i < v.size() - 2; ++i) {
                for (int j = i + 1; j < v.size() - 1; ++j) {
                    for (int k = j + 1; k < v.size(); ++k) {
                        int dist = abs(v[i] - v[j]) + abs(v[j] - v[k]) + abs(v[k] - v[i]);
                        distance = min(distance, dist);
                    }
                }
            }
        }
        if (distance == INT_MAX) {
            return -1;
        } else {
            return distance;
        }
        return 0;
    }
};
