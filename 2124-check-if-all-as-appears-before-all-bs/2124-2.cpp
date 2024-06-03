class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        for (; i < s.size(); ++i) {
            if (s[i] == 'b') {
                break;
            }
        }

        for (; i < s.size(); ++i) {
            if (s[i] == 'a')
                return false;
        }
        return true;
    }
};
