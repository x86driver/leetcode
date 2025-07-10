class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < s.size() - 1; ++i) {
            char ch = s[i];
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[j] == ch) {
                    int dist = j - i - 1;
                    int real_dist = distance[ch - 'a'];
                    if (real_dist != dist) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
