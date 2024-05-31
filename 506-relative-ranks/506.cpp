class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> m(10e6 + 1, -1);
        for (int i = 0; i < score.size(); ++i)
            m[score[i]] = i;
        vector<string> ans(score.size());
        int rank = 1;
        for (int i = m.size() - 1; i >= 0; --i) {
            if (m[i] >= 0) {
                switch (rank) {
                    case 1:
                        ans[m[i]] = "Gold Medal";
                        break;
                    case 2:
                        ans[m[i]] = "Silver Medal";
                        break;
                    case 3:
                        ans[m[i]] = "Bronze Medal";
                        break;
                    default:
                        ans[m[i]] = to_string(rank);
                        break;
                }
                ++rank;
            }
        }
        return ans;
    }
};
