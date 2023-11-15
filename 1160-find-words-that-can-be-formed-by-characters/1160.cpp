class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> m(26);
        for (char c : chars)
            ++m[c - 'a'];
        for (const string& word : words) {
            vector<int> copied = m;
            for (char c : word) {
                --copied[c - 'a'];
            }
            bool valid = true;
            for (int i = 0; i < 26; ++i) {
                if (copied[i] < 0) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans += word.size();
        }
        return ans;
    }
};
