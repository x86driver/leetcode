class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        set<char> s;
        for (char b : brokenLetters)
            s.insert(b);
        bool canType = true;
        for (int i = 0; i < text.size(); ++i) {
            if (s.find(text[i]) != s.end())
                canType = false;
            if (text[i] == ' ') {
                if (canType)
                    ++ans;
                canType = true;
            }
        }
        if (canType)
            ++ans;
        return ans;
    }
};
