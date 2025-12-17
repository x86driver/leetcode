class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26);
        for (char c : s) {
            int index = c - 'a';
            ++freq[index];
        }
        vector<vector<int>> groups(101, vector<int>());
        size_t max_group = 0;
        int loc = 0;
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] <= 0) {
                continue;
            }
            groups[freq[i]].push_back(i);
            max_group = max(max_group, groups[freq[i]].size());
        }

        vector<vector<int>> candidate;
        int max_freq = 0;
        for (const vector<int>& group : groups) {
            if (group.size() == max_group) {
                max_freq = max(max_freq, freq[group[0]]);
                candidate.push_back(group);
            }
        }
        vector<vector<int>> candidate2;
        string ans;
        for (const vector<int>& can : candidate) {
            if (freq[can[0]] == max_freq) {
                for (int c : can) {
                    ans += c + 'a';
                }
            }
        }
        return ans;
    }
};
