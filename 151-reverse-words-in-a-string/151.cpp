class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string ans;
        for (string &str : words)
            ans += str + " ";

        ans.pop_back();
        return ans;
    }
};
