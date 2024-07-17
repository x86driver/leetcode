class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> m;
        int index = 0;
        for (int i = 0; i < key.size(); ++i) {
            if (key[i] == ' ')
                continue;
            if (m.find(key[i]) == m.end()) {
                m[key[i]] = 'a' + index;
                ++index;
            }
        }
        string ans;
        for (int i = 0; i < message.size(); ++i) {
            if (message[i] == ' ') {
                ans += ' ';
                continue;
            }
            ans += m[message[i]];
        }
        return ans;
    }
};
