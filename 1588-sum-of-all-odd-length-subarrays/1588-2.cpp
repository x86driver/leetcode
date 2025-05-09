class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        for (int i = 0; i < arr.size(); ++i) {
            ans += arr[i];
            prefix_sum.push_back(prefix_sum[i] + arr[i]);
        }

        for (int diff = 3; diff <= arr.size(); diff += 2) {
            for (int i = 0; i <= arr.size() - diff; ++i) {
                int start = i;
                int end = i + diff;
                ans += prefix_sum[end] - prefix_sum[start];
            }
        }

        return ans;
    }
};
