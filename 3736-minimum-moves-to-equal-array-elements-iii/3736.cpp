class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maximum = INT_MIN;
        int moves = 0;
        int sum = 0;
        for (int n : nums) {
            maximum = max(maximum, n);
            sum += n;
        }
        return (maximum * nums.size()) - sum;
    }
};
