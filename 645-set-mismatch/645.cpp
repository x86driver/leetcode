class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> n(nums.size() + 1);
        for (int x : nums)
            ++n[x];
        int miss = 0;
        int redundant = 0;
        for (int i = 1; i < nums.size() + 1; ++i) {
            if (n[i] == 0)
                miss = i;
            if (n[i] > 1)
                redundant = i;
        }
        return {redundant, miss};
    }
};
