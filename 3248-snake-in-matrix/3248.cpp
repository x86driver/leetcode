class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int loc = 0;
        for (const string& command : commands) {
            if (command == "UP") {
                loc -= n;
            } else if (command == "DOWN") {
                loc += n;
            } else if (command == "LEFT") {
                --loc;
            } else if (command == "RIGHT") {
                ++loc;
            }
        }
        return loc;
    }
};
