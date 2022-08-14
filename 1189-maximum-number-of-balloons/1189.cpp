class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int minimum = text.size();
        unordered_map<char, int> map;

        for (char c : text) {
            if (map.find(c) == map.end()) {
                map[c] = 1;
            } else {
                ++map[c];
            }
        }

        char balloon[] = {'b', 'a', 'l', 'o', 'n'};
        for (char b : balloon) {
            if (map.find(b) == map.end()) {
                return 0;
            } else {
                if (b == 'l' || b == 'o') {
                    minimum = std::min(minimum, map[b] / 2);
                } else {
                    minimum = std::min(minimum, map[b]);
                }
            }
        }

        return minimum;
    }
};
