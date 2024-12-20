class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        ans.reserve(candies.size());
        for (int candy : candies) {
            if ((candy + extraCandies) >= maximum) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
