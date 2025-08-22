class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        set<string> visited;
        visited.insert("0,0");
        for (char c : path) {
            if (c == 'N') {
                ++y;
            } else if (c == 'S') {
                --y;
            } else if (c == 'E') {
                ++x;
            } else if (c == 'W') {
                --x;
            } else {
                return false;
            }
            string loc = to_string(x) + ',' + to_string(y);
            if (visited.find(loc) != visited.end()) {
                return true;
            }
            visited.insert(loc);
        }
        return false;
    }
};
