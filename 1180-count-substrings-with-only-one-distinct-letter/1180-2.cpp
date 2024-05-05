class Solution {
public:
    int countLetters(string s) {
        char curr = s[0];
        vector<int> count;
        int curr_count = 0;
        for (char c : s) {
            if (c != curr) {
                count.push_back(curr_count);
                curr_count = 1;
                curr = c;
            } else {
                ++curr_count;
            }
        }
        count.push_back(curr_count);

        int total = 0;
        for (int range : count) {
            total += ((1 + range) * range) / 2;
        }
        return total;
    }
};
