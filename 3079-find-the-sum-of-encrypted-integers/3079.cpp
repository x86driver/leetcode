class Solution {
private:
    int encrypt(int num) {
        int largest = 0;
        int digits = 0;
        int n = 0;
        while (num) {
            largest = max(largest, num % 10);
            num /= 10;
            ++digits;
        }
        while (digits) {
            n = n * 10 + largest;
            --digits;
        }
        return n;
    }
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += encrypt(n);
        }
        return sum;
    }
};
