class Solution {
private:
    int divisors(int num) {
        int count = 2;
        int sum = 1 + num;
        for (int i = 2; i <= num / 2; ++i) {
            if ((num % i) == 0) {
                ++count;
                sum += i;
            }
        }
        if (count == 4) {
            return sum;
        } else {
            return 0;
        }
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> m;
        for (int n : nums) {
            if (m.find(n) == m.end()) {
                m[n] = divisors(n);
            }
            sum += m[n];
        }
        return sum;
    }
};
