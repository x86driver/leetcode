class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int start = 0;
        int end = s.size() - 1;
        int left = 0;
        while (start < end) {
            if (s[start] == '[') {
                ++left;
            } else {
                --left;
            }
            if (left < 0) {
                while (end >= 0) {
                    if (s[end] == '[') {
                        swap(s[start], s[end]);
                        ++count;
                        break;
                    }
                    --end;
                }
                left += 2;
            }
            ++start;
        }
        return count;
    }
};
