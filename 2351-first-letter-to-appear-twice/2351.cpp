class Solution {
public:
    char repeatedCharacter(string s) {
        map<char, int> m;
        for (char c : s) {
            ++m[c];
            if (m[c] > 1)
                return c;
        }
        return NULL;
    }
};
