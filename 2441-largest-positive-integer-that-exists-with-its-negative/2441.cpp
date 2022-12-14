class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s;
        int currMax = -1001;
        for (auto n : nums) {
            if (n < 0) {
                s.insert(n);
            }
        }

        for (auto n : nums) {
            if (n > 0) {
                if (s.find(-n) != s.end()) {
                    currMax = max(currMax, n);
                }
            }
        }

        if (currMax == -1001)
            return -1;
        else
            return currMax;
    }
};
