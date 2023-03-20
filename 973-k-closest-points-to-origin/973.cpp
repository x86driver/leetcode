class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, unsigned long>> vec;
        for (size_t i = 0; i < points.size(); ++i) {
            vector<int>& point = points[i];
            unsigned long distance = point[0] * point[0] + point[1] * point[1];
            vec.push_back({i, distance});
        }

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        vector<vector<int>> ans;
        for (int i = 0; i < k; ++i) {
            int index = vec[i].first;
            ans.push_back(points[index]);
        }

        return ans;
    }
};
