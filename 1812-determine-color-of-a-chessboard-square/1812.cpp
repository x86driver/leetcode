class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int first = coordinates[0] - 'a';
        int second = coordinates[1] - '0';
        return (first + second) % 2 == 0;
    }
};
