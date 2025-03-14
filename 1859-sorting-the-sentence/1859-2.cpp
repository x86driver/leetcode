class Solution {
public:
    string sortSentence(string s) {
        vector<string> m(10);
        istringstream iss(s);
        string word;
        while (iss >> word) {
            int num = word.back() - '0';
            word.pop_back();
            m[num] = word;
        }
        string ans;
        for (string &str : m) {
            if (str.size() > 0) {
                ans += move(str) + " ";
            }
        }
        ans.pop_back();
        return ans;
    }
};
