class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> m;
        char c = 'a';
        m[' '] = ' ';
        for (char k : key) {
            if (k != ' ' && m.find(k) == m.end()) {
                m[k] = c++;
            }
        }

        string ans;
        for (char msg : message) {
            ans += m[msg];
        }

        return ans;
    }
};
