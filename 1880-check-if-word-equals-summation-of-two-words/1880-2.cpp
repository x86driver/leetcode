class Solution {
private:
    int wordSum(const string &word) {
        int ret = 0;
        for (char c : word) {
            ret *= 10;
            ret += c - 'a';
        }
        return ret;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return wordSum(firstWord) + wordSum(secondWord) == wordSum(targetWord);
    }
};
