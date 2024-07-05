class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int count = 0;
        int maxLen = 0;
        vector<int> lens;
        for (const vector<int>& rectangle : rectangles) {
            maxLen = max(maxLen, min(rectangle[0], rectangle[1]));
            lens.push_back(min(rectangle[0], rectangle[1]));
        }
        for (int l : lens)
            if (l == maxLen)
                ++count;
        return count;
    }
};
