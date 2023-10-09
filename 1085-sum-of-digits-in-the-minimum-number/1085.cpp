class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int n = *min_element(nums.begin(), nums.end());
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }

        return !(sum % 2);
    }
};
