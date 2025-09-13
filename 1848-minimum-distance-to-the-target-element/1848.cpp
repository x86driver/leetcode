class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<int> pos;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                pos.push_back(i);
            }
        }
        int dist = INT_MAX;
        for (int p : pos) {
            dist = min(dist, abs(p - start));
        }
        return dist;
    }
};
