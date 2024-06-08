class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int pos = 0;
        int count = 0;
        for (int n : nums) {
            pos += n;
            if (pos == 0)
                ++count;
        }
        return count;
    }
};
