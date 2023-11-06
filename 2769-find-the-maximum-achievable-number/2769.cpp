class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        // (x-t) = (num+t)
        // x-num = 2t
        // x = 2t+num
        return 2 * t + num;
    }
};
