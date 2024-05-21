class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> m(26);
        for (char c : s) {
            int index = c - 'a';
            ++m[index];
            if (m[index] == 2)
                return c;
        }
        return 'a';
    }
};
