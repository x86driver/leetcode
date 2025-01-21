class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd, even;
        odd.reserve(nums.size());
        even.reserve(nums.size());
        for (int n : nums) {
            if (n % 2 == 0) {
                even.push_back(n);
            } else {
                odd.push_back(n);
            }
        }
        even.insert(even.end(),
            make_move_iterator(odd.begin()),
            make_move_iterator(odd.end()));
        return even;
    }
};
