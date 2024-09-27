class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            vector<int> tmp;
            while (n) {
                tmp.push_back(n % 10);
                n /= 10;
            }
            ans.insert(ans.end(), tmp.rbegin(), tmp.rend());
        }
        return ans;
    }
};
