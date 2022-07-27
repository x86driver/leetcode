class Solution {
public:
    string rotate(string s) {
        string ret(s.begin()+1, s.end());
        ret += s[0];
        return ret;
    }
    bool rotateString(string s, string goal) {
        string r = s;
        for (auto i = 0; i < s.size(); ++i) {
            if (r == goal) {
                return true;
            }
            r = rotate(r);
        }
        return false;
    }
};
