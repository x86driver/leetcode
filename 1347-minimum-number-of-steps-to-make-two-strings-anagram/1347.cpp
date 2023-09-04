class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m;
        for (char c : s)
            ++m[c];

        int steps = 0;
        for (char c : t) {
            if (m.find(c) == m.end()) {
                ++steps;
                continue;
            }
            --m[c];
        }

        for (pair<char, int> p : m) {
            if (p.second < 0)
                steps -= p.second;
        }

        return steps;
    }
};
