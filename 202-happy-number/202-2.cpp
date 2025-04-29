class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        while (true) {
            int new_value = 0;
            while (n) {
                int r = n % 10;
                n /= 10;
                new_value += r * r;
            }
            if (new_value == 1) {
                return true;
            }
            if (s.find(new_value) == s.end()) {
                s.insert(new_value);
            } else {
                return false;
            }
            n = new_value;
        }
        return false;
    }
};
