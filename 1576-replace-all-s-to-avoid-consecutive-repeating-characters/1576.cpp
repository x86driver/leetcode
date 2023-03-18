class Solution {
public:
    string modifyString(string s) {
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == '?') {
                char c = 'a';
                // in the end, i+1 will be '\0', so we are safe
                while (c == s[i+1] || c == s[i-1]) {
                    if (c == 'z')
                        c = 'a';
                    else
                        ++c;
                }
                s[i] = c;
            }
        }

        if (s[0] == '?') {
            char c = 'a';
            while (c == s[1]) {
                if (c == 'z')
                    c = 'a';
                else
                    ++c;
            }
            s[0] = c;
        }

        return s;
    }
};
