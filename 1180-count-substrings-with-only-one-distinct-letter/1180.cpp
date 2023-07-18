class Solution {
public:
    int countLetters(string s) {
        int count = 0;
        int i = 0;
        while (i < s.size()) {
            char curr = s[i];
            int j = i + 1;
            for (; j < s.size(); ++j) {
                if (curr != s[j])
                    break;
            }
            int contiguous = j - i;
            count += (1 + contiguous) * contiguous / 2;
            i = j;
        }

        return count;
    }
};
