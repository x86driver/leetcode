class Solution {
private:
    int shortest(const string& s, char c, int index) {
        int before = 0;
        int after = 0;
        bool before_found = false;
        bool after_found = false;
        for (int i = index - 1; i >= 0; --i) {
            ++before;
            if (s[i] == c) {
                before_found = true;
                break;
            }
        }
        for (int i = index + 1; i < s.size(); ++i) {
            ++after;
            if (s[i] == c) {
                after_found = true;
                break;
            }
        }
        if (before_found && after_found)
            return min(before, after);
        if (!before_found)
            return after;
        else
            return before;
    }
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c)
                ans[i] = 0;
            else
                ans[i] = shortest(s, c, i);
        }
        return ans;
    }
};
