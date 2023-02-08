class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> m;
        for (size_t i = 0; i < keyboard.size(); ++i)
            m[keyboard[i]] = i;

        int ans = 0;
        int prev = 0;
        for (char c : word) {
            ans += abs(m[c] - prev);
            prev = m[c];
        }

        return ans;
    }
};
