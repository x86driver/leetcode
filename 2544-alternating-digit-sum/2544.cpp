class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0;
        int count = 0;
        bool pos = true;
        while (n) {
            int digit = n % 10;
            n /= 10;
            if (pos)
                ans += digit;
            else
                ans -= digit;
            pos = !pos;
            ++count;
        }
        if ((count % 2) == 0)
            return -ans;
        else
            return ans;
    }
};
