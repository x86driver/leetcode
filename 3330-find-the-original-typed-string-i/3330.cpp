class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0;
        int start = 0;
        int end = 1;
        int repeat = 0;
        while (end < word.size()) {
            if (word[end] == word[start]) {
                ++repeat;
                ++end;
            } else {
                if (repeat) {
                    count += repeat;
                    repeat = 0;
                }
                start = end;
                end = start + 1;
            }
        }
        if (repeat) {
            count += repeat;
        }
        return count + 1;
    }
};
