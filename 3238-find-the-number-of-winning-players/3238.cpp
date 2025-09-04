class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<unordered_map<int, int>> games(n);
        for (const vector<int>& p : pick) {
            ++games[p[0]][p[1]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (const pair<int, int>& balls : games[i]) {
                if (balls.second > i) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
