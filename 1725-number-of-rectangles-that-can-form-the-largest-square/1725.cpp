class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int, int> m;
        int maximum = 0;
        for (const vector<int>& rec : rectangles) {
            int small = min(rec[0], rec[1]);
            ++m[small];
            maximum = max(maximum, small);
        }

        return m[maximum];
    }
};
