class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> s_map, target_map;
        for (char c : s) {
            ++s_map[c];
        }
        for (char c : target) {
            ++target_map[c];
        }
        int count = INT_MAX;
        for (const pair<char, int>& p : target_map) {
            int s_occur = s_map[p.first];
            int copies = s_occur / p.second;
            count = min(count, copies);
        }
        return count;
    }
};
