class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        const int orig_x = x;
        int reverse = 0;
        while (x) {
            if (reverse >= 214748364)
                return false;
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }
        return orig_x == reverse;
    }
};
