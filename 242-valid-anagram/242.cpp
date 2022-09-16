class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;
        for (char c : s) {
            if (ms.find(c) == ms.end()) {
                ms[c] = 1;
            } else {
                ++ms[c];
            }
        }

        for (char c : t) {
            if (mt.find(c) == mt.end()) {
                mt[c] = 1;
            } else {
                ++mt[c];
            }
        }

        for (auto m : mt) {
            if (ms[m.first] != m.second) {
                return false;
            }
            ms[m.first] = 0;
        }

        for (auto m : ms) {
            if (m.second != 0) {
                return false;
            }
        }

        return true;
    }
};
