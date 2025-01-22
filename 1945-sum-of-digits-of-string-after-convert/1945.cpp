class Solution {
public:
    int getLucky(string s, int k) {
        int transform = 0;
        for (char c : s) {
            int val = c - 'a' + 1;
            transform += val / 10;
            transform += val % 10;
        }

        while (--k) {
            int tmp = 0;
            while (transform) {
                tmp += transform % 10;
                transform /= 10;
            }
            transform = tmp;
        }
        return transform;
    }
};
