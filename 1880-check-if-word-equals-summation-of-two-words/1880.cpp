class Solution {
private:
    int toInt(string word) {
        int ret = 0;
        for (char c : word) {
            ret += (c - 'a');
            ret *= 10;
        }
        return ret / 10;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first = toInt(firstWord);
        int second = toInt(secondWord);
        int target = toInt(targetWord);

        return (first + second) == target;
    }
};
