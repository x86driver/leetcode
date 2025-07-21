class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int w_count = 0;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W') {
                ++w_count;
            }
        }
        ans = min(ans, w_count);
        int start = 0;
        int end = k - 1;
        while (end < blocks.size() - 1) {
            if (blocks[start] == 'W') {
                --w_count;
            }
            ++start;
            ++end;
            if (blocks[end] == 'W') {
                ++w_count;
            }
            ans = min(ans, w_count);
        }
        return ans;
    }
};
