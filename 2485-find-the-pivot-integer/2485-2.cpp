class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix_sum(n + 1);
        prefix_sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + i;
        }

        int last = prefix_sum[n];
        for (int i = 0; i < n; ++i) {
            if (last - prefix_sum[i] == prefix_sum[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};
