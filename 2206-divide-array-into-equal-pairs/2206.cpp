class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> numbers(501);
        for (int n : nums)
            ++numbers[n];
        for (int i = 1; i < 501; ++i) {
            if (numbers[i] % 2 != 0)
                return false;
        }
        return true;
    }
};
