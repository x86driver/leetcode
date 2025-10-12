class Solution {
public:
    int maxDistance(vector<string>& words) {
        int i = 0;
        int j = words.size() - 1;
        int rightmost = 0;
        int leftmost = 0;
        const string& first = words.front();
        const string& last = words.back();
        while (j > i) {
            if (first != words[j]) {
                rightmost = j - i;
                break;
            }
            --j;
        }
        j = words.size() - 1;
        while (i < j) {
            if (last != words[i]) {
                leftmost = j - i;
                break;
            }
            ++i;
        }
        int ans = max(leftmost, rightmost);
        if (ans == 0) {
            return 0;
        } else {
            return ans + 1;
        }
    }
};
