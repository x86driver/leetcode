class Solution {
public:
    int maxDistinct(string s) {
        set<char> distinct;
        int count = 0;
        for (char c : s) {
            if (distinct.find(c) == distinct.end()) {
                distinct.insert(c);
                ++count;
            }
        }
        return count;
    }
};
