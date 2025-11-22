class Solution {
public:
    int maxDistance(vector<string>& words) {
        int distance = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[i] != words[j]) {
                    distance = max(distance, j - i + 1);
                }
            }
        }
        return distance;
    }
};
