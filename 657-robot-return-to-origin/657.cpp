class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;
        for (char c : moves) {
            if (c == 'U') {
                ++up;
            } else if (c == 'D') {
                ++down;
            } else if (c == 'L') {
                ++left;
            } else if (c == 'R') {
                ++right;
            }
        }
        return up == down && left == right;
    }
};
