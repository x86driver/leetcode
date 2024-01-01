class Solution {
public:
    int minPartitions(string n) {
        int ans = INT_MIN;
        for (char c : n) {
            int val = c - '0';
            ans = max(ans, val);
        }
        return ans;
    }
};
