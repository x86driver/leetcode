class Solution {
public:
    bool isHappy(int n) {
        vector<int> tmp;
        do {
            tmp.clear();
            while (n > 0) {
                tmp.push_back(n % 10);
                n /= 10;
            }

            for (auto i : tmp) {
                n += i*i;
            }

            if (n == 1 || n == 7)
                return true;
        } while (n >= 10);
        return false;
    }
};
