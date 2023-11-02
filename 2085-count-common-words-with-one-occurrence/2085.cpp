class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int count = 0;
        map<string, int> w1;
        for (const string& word : words1)
            ++w1[word];
        map<string, int> w2;
        for (const string& word : words2)
            ++w2[word];
        for (const string& word : words1) {
            if (w1[word] == 1 && w2[word] == 1)
                ++count;
        }
        return count;
    }
};
