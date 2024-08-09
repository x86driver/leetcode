class Solution {
private:
    vector<string> ans;
    string tmp;
    void bt(string &digits, int digitsIndex) {
        const vector<string> maps = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        if (digitsIndex >= digits.size()) {
            ans.push_back(tmp);
            return;
        }

        int index = digits[digitsIndex] - '0';
        for (int i = 0; i < maps[index].size(); ++i) {
            tmp.push_back(maps[index][i]);
            bt(digits, digitsIndex + 1);
            tmp.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        bt(digits, 0);
        return ans;
    }
};
