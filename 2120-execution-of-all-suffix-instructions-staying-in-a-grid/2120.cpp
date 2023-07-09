class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;

        for (int i = 0; i < s.size(); ++i) {
            int x = startPos[0];
            int y = startPos[1];
            int count = 0;
            for (int j = i; j < s.size(); ++j) {
                char act = s[j];
                if (act == 'R') {
                    if (y < n - 1)
                        ++y;
                    else
                        break;
                } else if (act == 'L') {
                    if (y > 0)
                        --y;
                    else
                        break;
                } else if (act == 'U') {
                    if (x > 0)
                        --x;
                    else
                        break;
                } else if (act == 'D') {
                    if (x < n - 1)
                        ++x;
                    else
                        break;
                }
                ++count;
            }
            ans.push_back(count);
        }

        return ans;
    }
};
