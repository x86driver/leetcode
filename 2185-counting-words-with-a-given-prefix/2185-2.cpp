class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const string &word : words) {
            string sub(word, 0, pref.size());
            if (sub == pref)
                ++count;
        }
        return count;
    }
};
