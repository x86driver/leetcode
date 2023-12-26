class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<unordered_map<char, int>> word(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i])
                ++word[i][c];
        }
        for (int i = 0; i < words[0].size(); ++i) {
            char ch = words[0][i];
            bool match = true;
            for (int j = 1; j < words.size(); ++j) {
                unordered_map<char, int> &m = word[j];
                if (m.find(ch) != m.end()) {
                    if (m[ch] > 0) {
                        --m[ch];
                    } else {
                        match = false;
                        break;
                    }
                } else {
                    match = false;
                    break;
                }
            }
            if (match) {
                ans.push_back(string(1, ch));
            }
        }
        return ans;
    }
};
