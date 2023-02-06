class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = -100000;
        vector<int> prefixSum;
        vector<int> prefixMin;
        prefixSum.push_back(0);
        prefixMin.push_back(0);

        for (int i = 0; i < nums.size(); ++i) {
            int sum = prefixSum[i] + nums[i];
            prefixSum.push_back(sum);
            prefixMin.push_back(min(prefixMin[i], sum));
        }

        for (int i = 1; i < prefixSum.size(); ++i)
            maximum = max(maximum, prefixSum[i] - prefixMin[i - 1]);

        return maximum;
    }
};
