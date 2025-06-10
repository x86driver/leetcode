class Solution {
public:
    bool isArmstrong(int n) {
        int orig = n;
        int sum = 0;
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        for (int d : digits) {
            sum += pow(d, digits.size());
        }
        return sum == orig;
    }
};
