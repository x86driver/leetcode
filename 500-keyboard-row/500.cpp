class Solution {
private:
    set<char> first_set;
    set<char> second_set;
    set<char> third_set;
    bool find_set(string& word, set<char> &s) {
        for (char c : word) {
            if (s.find(c) == s.end()) {
                return false;
            }
        }
        return true;
    }
public:
    Solution() {
        string first = "qwertyuiopQWERTYUIOP";
        string second = "asdfghjklASDFGHJKL";
        string third = "zxcvbnmZXCVBNM";
        for (char c : first)
            first_set.insert(c);
        for (char c : second)
            second_set.insert(c);
        for (char c : third)
            third_set.insert(c);
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        for (string& word : words) {
            if (find_set(word, first_set)) {
                ans.push_back(word);
            } else if (find_set(word, second_set)) {
                ans.push_back(word);
            } else if (find_set(word, third_set)) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
