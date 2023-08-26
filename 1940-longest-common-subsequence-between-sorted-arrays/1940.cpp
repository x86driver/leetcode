class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> numbers(101);
        for (const vector<int>& a : arrays)
            for (int n : a)
                ++numbers[n];
        vector<int> ans;
        for (int i = 1; i < numbers.size(); ++i)
            if (numbers[i] == arrays.size())
                ans.push_back(i);

        return ans;
    }
};
