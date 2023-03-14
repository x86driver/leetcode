class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int length = 0;
        while (i >= 0) {
            if (s[i] != ' ')
                break;
            --i;
        }
        while (i >= 0) {
            if (s[i] == ' ')
                break;
            ++length;
            --i;
        }

        return length;
    }
};
