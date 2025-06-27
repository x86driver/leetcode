class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groups(40);
        int largest = 0;
        for (int i = 1; i <= n; ++i) {
            int n = i;
            int sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            ++groups[sum];
            largest = max(largest, groups[sum]);
        }

        int ans = 0;
        for (int i = 0; i < groups.size(); ++i) {
            if (groups[i] == largest) {
                ++ans;
            }
        }
        return ans;
    }
};
