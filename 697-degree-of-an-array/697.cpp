class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maximum = 0;
        int max_num = 0;
        for (int n: nums) {
            if (m.find(n) == m.end()) {
                m[n] = 1;
            } else {
                ++m[n];
            }
            if (m[n] >= maximum) {
                maximum = m[n];
                max_num = n;
            }
        }

        vector<pair<int, int>> tmp(m.begin(), m.end());
        std::sort(tmp.begin(), tmp.end(),
              [=](pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; });
        int len = nums.size();
        for (auto i: tmp) {
            if (i.second == maximum) {
                len = std::min(len, findLength(nums, i.first));
            } else {
                break;
            }
        }
        return len;
    }
private:
    map<int, int> m;
    int findLength(vector<int> &nums, int num) {
        int start = 0;
        int end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == num) {
                start = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == num) {
                end = i;
                break;
            }
        }
        return end-start+1;
    }
};
