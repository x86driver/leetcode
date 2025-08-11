class Solution {
public:
    bool checkDivisibility(int n) {
        const int num = n;
        int sum = 0;
        int product = 1;
        while (n) {
            int r = n % 10;
            sum += r;
            product *= r;
            n /= 10;
        }
        return (num % (sum + product) == 0);
    }
};
