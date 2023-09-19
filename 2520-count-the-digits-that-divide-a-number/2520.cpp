class Solution {
public:
    int countDigits(int num) {
        vector<int> v;
        int n = num;
        while (n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }
        int count = 0;
        for (int x : v)
            if (num % x == 0)
                ++count;

        return count;
    }
};
