class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_digit = 0;
        int double_digit = 0;
        for (int n : nums) {
            if (n >= 10) {
                double_digit += n;
            } else {
                single_digit += n;
            }
        }
        return single_digit != double_digit;
    }
};

