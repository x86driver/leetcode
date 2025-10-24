class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int> freq(101);
        for (int n : nums) {
            ++freq[n];
        }
        int sum = 0;
        for (int i = 1; i < freq.size(); ++i) {
            if (freq[i] && freq[i] % k == 0) {
                sum += i * freq[i];
            }
        }
        return sum;
    }
};
