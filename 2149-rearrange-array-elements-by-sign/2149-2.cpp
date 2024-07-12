class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> num1, num2;
        for (int n : nums)
            if (n > 0)
                num1.push_back(n);
            else
                num2.push_back(n);
        int i = 0;
        int j = 0;
        while (i < num1.size()) {
            nums[i + j] = num1[i];
            ++i;
            nums[i + j] = num2[j];
            ++j;
        }
        return nums;
    }
};
