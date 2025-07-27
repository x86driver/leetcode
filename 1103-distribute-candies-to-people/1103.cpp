class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans;
        ans.resize(num_people);
        int turn = 1;
        while (candies) {
            for (int i = 0; i < num_people; ++i) {
                int distribute = min(turn, candies);
                ans[i] += distribute;
                candies -= distribute;
                if (candies == 0) {
                    break;
                }
                ++turn;
            }
        }
        return ans;
    }
};
