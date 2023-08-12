class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<multiset<char>> texts;
        for (char c : s) {
            int merged = -1;
            for (int i = 0; i < texts.size(); ++i) {
                multiset<char>& sets = texts[i];
                if (sets.find(c) != sets.end()) {
                    sets.insert(c);
                    merged = i;
                    break;
                }
            }
            if (merged == -1) {
                texts.push_back({c});
            } else {
                int sum = 0;
                for (int i = merged + 1; i < texts.size(); ++i) {
                    sum += texts[i].size();
                    texts[merged].insert(texts[i].begin(), texts[i].end());
                }
                texts.erase(texts.begin() + merged + 1, texts.end());
            }
        }

        vector<int> ans;
        for (const multiset<char>& sets : texts) {
            ans.push_back(sets.size());
        }
        return ans;
    }
};
