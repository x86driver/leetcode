class Solution {
public:
    int partitionString(string s) {
        set<char> set;
        int count = 0;
        for (char c : s) {
            if (set.find(c) != set.end()) {
                ++count;
                set.clear();
            }
            set.insert(c);
        }

        return count + 1;
    }
};
