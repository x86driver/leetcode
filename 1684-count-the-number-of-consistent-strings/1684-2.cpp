class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowed_chars(26);
        for (char c : allowed) {
            allowed_chars[c - 'a'] = true;
        }
        int count = 0;
        for (const string& str : words) {
            bool allow = true;
            for (char c : str) {
                if (allowed_chars[c - 'a'] == false) {
                    allow = false;
                    break;
                }
            }
            if (allow) {
                ++count;
            }
        }
        return count;
    }
};
