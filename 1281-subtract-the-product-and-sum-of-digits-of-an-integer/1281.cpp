class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int product = 1;
        int sum = 0;
        for (int n : digits) {
            product *= n;
            sum += n;
        }
        return product - sum;
    }
};
