class Solution {
private:
    string toBase(int n, int base) {
        string ret;
        while (n > 0) {
            ret += to_string(n % base);
            n /= base;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    bool isPalindromic(const string& str) {
        for (int i = 0; i < str.size() / 2; ++i) {
            if (str[i] != str[str.size() - i - 1])
                return false;
        }
        return true;
    }
public:
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; ++i) {
            string a = toBase(n, i);
            if (!isPalindromic(a))
                return false;
        }

        return true;
    }
};
