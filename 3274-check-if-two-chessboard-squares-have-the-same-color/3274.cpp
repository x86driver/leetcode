class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int loc1_x = coordinate1[0] - 'a' + 1;
        int loc1_y = coordinate1[1] - '1' + 1;
        int loc2_x = coordinate2[0] - 'a' + 1;
        int loc2_y = coordinate2[1] - '1' + 1;

        return (loc1_x + loc1_y) % 2 == (loc2_x + loc2_y) % 2;
    }
};
