class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> m1(26, -1), m2(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int index = s[i] - 'a';
            if (m1[index] == -1) {
                m1[index] = i;
            } else {
                m2[index] = i;
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < m1.size(); ++i) {
            ans = max(ans, m2[i] - m1[i]);
        }
        return ans - 1;
    }
};
