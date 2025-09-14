class Solution {
private:
    bool isParity(int a, int b) {
        int ra = a % 2;
        int rb = b % 2;
        return ((ra == 0 && rb == 0) || (ra == 1 && rb == 1));
    }
public:
    string getSmallestString(string s) {
        int index = 0;
        int diff = 0;
        for (int i = 1; i < s.size(); ++i) {
            int a = s[i - 1] - '0';
            int b = s[i] - '0';
            bool parity = isParity(a, b);
            if (a > b && parity) {
                diff = a - b;
                index = i;
                break;
            }
        }
        if (diff != 0) {
            swap(s[index - 1], s[index]);
        }
        return s;
    }
};
