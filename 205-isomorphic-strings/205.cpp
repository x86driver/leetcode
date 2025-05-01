class Solution {
private:
    bool _isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        for (int i = 0; i < s.size(); ++i) {
            char s0 = s[i];
            char t0 = t[i];
            if (m.find(s0) == m.end()) {
                m[s0] = t0;
            } else {
                if (m[s0] != t0) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return _isIsomorphic(s, t) && _isIsomorphic(t, s);
    }
};
