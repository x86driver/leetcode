class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (const vector<int>& query : queries) {
            int count = 0;
            for (const vector<int>& point : points) {
                int h = query[0];
                int k = query[1];
                int r = query[2];
                int x = point[0];
                int y = point[1];
                if (pow(x - h, 2) + pow(y - k, 2) <= pow(r, 2))
                    ++count;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
