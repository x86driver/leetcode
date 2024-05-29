class Solution {
private:
    bool isSymmetric(int val) {
        vector<int> digits;
        while (val > 0) {
            digits.push_back(val % 10);
            val /= 10;
        }
        if (digits.size() % 2 != 0)
            return false;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < digits.size() / 2; ++i) {
            sum1 += digits[i];
            sum2 += digits[i + digits.size() / 2];
        }
        return sum1 == sum2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i)
            if (isSymmetric(i))
                ++count;
        return count;
    }
};
