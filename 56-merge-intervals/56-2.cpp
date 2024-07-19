class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int i = 0;
        while (i < intervals.size()) {
            vector<int> interval = intervals[i];
            int j = i + 1;
            while (j < intervals.size()) {
                if (intervals[j][0] <= interval[1]) {
                    interval[1] = max(interval[1], intervals[j][1]);
                } else {
                    break;
                }
                ++j;
            }
            ans.push_back(interval);
            i = j;
        }
        return ans;
    }
};
