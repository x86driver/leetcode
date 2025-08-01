class Solution {
public:
    bool isSubstringPresent(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        set<string> hash;
        for (int i = 0; i < s.size() - 1; ++i) {
            hash.insert(s.substr(i, 2));
        }
        for (int i = 0; i < rev.size() - 1; ++i) {
            string sub = rev.substr(i, 2);
            if (hash.find(sub) != hash.end()) {
                return true;
            }
        }
        return false;
    }
};
