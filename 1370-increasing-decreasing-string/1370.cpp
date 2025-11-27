class Solution {
public:
    string sortString(string s) {
        string ans;
        map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        while (m.size() > 0) {
            for (auto it = m.begin(); it != m.end();) {
                ans += it->first;
                --it->second;
                if (it->second == 0) {
                    it = m.erase(it);
                } else {
                    ++it;
                }
            }
            for (auto it = m.end(); it != m.begin();) {
                auto cur = prev(it);
                ans += cur->first;
                --(cur->second);
                if (cur->second == 0) {
                    it = m.erase(cur);
                } else {
                    it = cur;
                }
            }
        }

        return ans;
    }
};
