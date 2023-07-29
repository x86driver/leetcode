class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        int last = 0;
        string ans;
        while (i < chars.size()) {
            char curr = chars[i];
            while (j < chars.size()) {
                if (chars[j] == curr) {
                    ++j;
                    continue;
                } else {
                    break;
                }
            }
            if (j - i == 1)
                ans += curr;
            else
                ans += curr + to_string(j - i);
            i = j;
        }

        chars.assign(ans.begin(), ans.end());
        return ans.size();
    }
};
