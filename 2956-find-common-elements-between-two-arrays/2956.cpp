class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for (int n : nums1) {
            ++m1[n];
        }
        for (int n : nums2) {
            ++m2[n];
        }
        int answer1 = 0, answer2 = 0;
        for (auto p1 : m1) {
            if (m2.find(p1.first) != m2.end()) {
                answer1 += p1.second;
            }
        }
        for (auto p2 : m2) {
            if (m1.find(p2.first) != m1.end()) {
                answer2 += p2.second;
            }
        }

        return {answer1, answer2};
    }
};
