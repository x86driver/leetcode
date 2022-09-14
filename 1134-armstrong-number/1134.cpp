class Solution {
public:
    bool isArmstrong(int n) {
        vector<int> numbers;
        int tmp = n;
        while (tmp > 0) {
            numbers.push_back(tmp % 10);
            tmp /= 10;
        }

        int result = 0;
        for (auto n : numbers) {
            result += pow(n, numbers.size());
        }

        return result == n;
    }
};
