class Solution {
private:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 2; i <= num; ++i) {
            if (digitSum(i) % 2 == 0)
                ++ans;
        }
        return ans;
    }
};
