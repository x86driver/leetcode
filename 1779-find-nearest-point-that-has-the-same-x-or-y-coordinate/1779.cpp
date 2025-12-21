class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int distance = INT_MAX;
        int ans = -1;
        for (int i = 0; i < points.size(); ++i) {
            const vector<int>& point = points[i];
            if (point[0] == x || point[1] == y) {
                int d = abs(point[0] - x) + abs(point[1] - y);
                if (d < distance) {
                    ans = i;
                    distance = d;
                }
            }
        }
        return ans;
    }
};
