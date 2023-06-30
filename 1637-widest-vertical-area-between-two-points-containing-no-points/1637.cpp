class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = points.size();
        vector<int> pts(n);
        for (int i = 0; i < n; ++i)
            pts[i] = points[i][0];
        sort(pts.begin(), pts.end());
        int area = 0;
        for (int i = 0; i < n - 1; ++i) {
            area = max(area, pts[i + 1] - pts[i]);
        }
        return area;
    }
};
