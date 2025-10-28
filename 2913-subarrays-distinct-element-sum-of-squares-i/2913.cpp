class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j <= nums.size(); ++j) {
                int k = i;
                set<int> s;
                while (k < j && k < nums.size()) {
                    s.insert(nums[k]);
                    ++k;
                }
                sum += s.size() * s.size();
            }
        }
        return sum;
    }
};
