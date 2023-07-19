class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            vector<int> tmp;
            while (num > 0) {
                tmp.push_back(num % 10);
                num /= 10;
            }
            ans.insert(ans.end(), tmp.rbegin(), tmp.rend());
        }
        return ans;
    }
};
