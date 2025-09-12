class Solution {
private:
    bool isValid(int num) {
        while (num) {
            if (num % 10 == 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            int a = i;
            int b = n - i;
            if (isValid(a) && isValid(b)) {
                return {a, b};
            }
        }
        return {1, n - 1};
    }
};
