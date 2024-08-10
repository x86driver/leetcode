class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;
        for (int n : nums) {
            switch (n) {
                case 0:
                    ++red;
                    break;
                case 1:
                    ++white;
                    break;
                case 2:
                    ++blue;
                    break;
            }
        }
        int i = 0;
        for (; i < red; ++i) {
            nums[i] = 0;
        }
        for (; i < red + white; ++i) {
            nums[i] = 1;
        }
        for (; i < red + white + blue; ++i) {
            nums[i] = 2;
        }
    }
};
