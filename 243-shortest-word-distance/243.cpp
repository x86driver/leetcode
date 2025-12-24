class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> word1_index, word2_index;
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                word1_index.push_back(i);
            } else if (wordsDict[i] == word2) {
                word2_index.push_back(i);
            }
        }
        int distance = INT_MAX;
        for (int w1 : word1_index) {
            for (int w2 : word2_index) {
                int d = abs(w1 - w2);
                if (d == 1) {
                    return 1;
                }
                distance = min(distance, d);
            }
        }
        return distance;
    }
};
