class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(intervals.begin(), intervals.end());
        pq.push(intervals[0][1]);

        for (size_t i = 1; i < intervals.size(); ++i) {
            int ending = pq.top();
            if (intervals[i][0] >= ending)
                pq.pop();

            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};
