class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        gain.insert(gain.begin(), 0);

        for (size_t i = 1; i < gain.size(); ++i) {
            gain[i] += gain[i - 1];
            ans = max(ans, gain[i]);
        }

        return ans;
    }
};
