class Solution {
public:
    int findClosest(int x, int y, int z) {
        int move_x = abs(x - z);
        int move_y = abs(y - z);
        if (move_x == move_y) {
            return 0;
        } else if (move_x < move_y) {
            return 1;
        } else {
            return 2;
        }
    }
};
