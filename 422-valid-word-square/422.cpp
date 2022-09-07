class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string col;
            int size = std::min(words[i].size(), words.size());
            for (int j = 0; j < size; ++j) {
                col += words[j][i];
            }
            if (col != words[i]) {
                return false;
            }
        }

        return true;
    }
};
