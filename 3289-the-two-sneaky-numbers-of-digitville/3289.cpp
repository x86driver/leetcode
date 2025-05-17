class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<bool> m(101);
        for (int n : nums) {
            if (m[n]) {
                ans.push_back(n);
            }
            m[n] = true;
        }
        return ans;
    }
};
