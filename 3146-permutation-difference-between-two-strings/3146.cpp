class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> m(26);
        for (int i = 0; i < t.size(); ++i)
            m[t[i] - 'a'] = i;
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            int t_index = m[c - 'a'];
            sum += abs(i - t_index);
        }
        return sum;
    }
};
