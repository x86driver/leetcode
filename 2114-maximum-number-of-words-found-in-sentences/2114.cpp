class Solution {
private:
    int countWords(const string& sentence) {
        int count = 0;
        istringstream iss(sentence);
        string token;
        while (iss >> token)
            ++count;
        return count;
    }
public:
    int mostWordsFound(vector<string>& sentences) {
        int count = 0;
        for (const string& sentence: sentences) {
            count = max(count, countWords(sentence));
        }
        return count;
    }
};
