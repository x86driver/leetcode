class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
             });
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& interval = intervals[i];
            if (interval[0] <= end) {
                end = max(end, interval[1]);
            } else {
                ans.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
        }

        ans.push_back({start, end});
        return ans;
    }
};
