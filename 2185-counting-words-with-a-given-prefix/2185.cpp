class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const string& word : words) {
            if (word.size() < pref.size())
                continue;
            bool same = true;
            for (size_t i = 0; i < pref.size(); ++i) {
                if (pref[i] != word[i]) {
                    same = false;
                    break;
                }
            }
            if (same)
                ++count;
        }
        return count;
    }
};
