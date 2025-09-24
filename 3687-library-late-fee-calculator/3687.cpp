class Solution {
public:
    int lateFee(vector<int>& daysLate) {
        int penalty = 0;
        for (int n : daysLate) {
            if (n == 1) {
                ++penalty;
            } else if (2 <= n && n <= 5) {
                penalty += 2 * n;
            } else {
                penalty += 3 * n;
            }
        }
        return penalty;
    }
};
