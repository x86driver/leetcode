class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> table(26);
        for (char c : allowed)
            table[c - 'a'] = true;
        int count = 0;
        for (const string& word : words) {
            bool consistent = true;
            for (char c : word) {
                if (table[c - 'a'] == false) {
                    consistent = false;
                    break;
                }
            }
            if (consistent)
                ++count;
        }
        return count;
    }
};

