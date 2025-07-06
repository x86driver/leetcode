class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int score = 0;
        int ans = 0;
        int i = 0;
        for (const vector<int>& team : grid) {
            int tmp = accumulate(team.begin(), team.end(), 0);
            if (tmp > score) {
                score = tmp;
                ans = i;
            }
            ++i;
        }
        return ans;
    }
};
