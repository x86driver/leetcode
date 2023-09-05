class Solution {
private:
    bool isPrefix(const string& t, const string& s) {
        if (t.size() > s.size())
            return false;
        int i = 0;
        int j = 0;
        while (i < t.size()) {
            if (t[i] == s[j]) {
                ++i;
                ++j;
                continue;
            }
            return false;
        }
        return true;
    }
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (const string& t : words) {
            if (isPrefix(t, s))
                ++count;
        }
        return count;
    }
};
