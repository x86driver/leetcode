class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            ans += x % 10;
            x /= 10;
            if (x) {
                if (ans < 214748365 &&  ans >= -214748364)
                    ans *= 10;
                else
                    return 0;
            }
        }
        return ans;
    }
};
