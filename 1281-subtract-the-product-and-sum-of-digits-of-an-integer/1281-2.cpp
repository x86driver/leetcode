class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n) {
            int remain = n % 10;
            product *= remain;
            sum += remain;
            n /= 10;
        }
        return product - sum;
    }
};
