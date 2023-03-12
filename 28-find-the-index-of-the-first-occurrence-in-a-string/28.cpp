class Solution {
public:
    int strStr(string haystack, string needle) {
        for (size_t i = 0; i < haystack.size(); ++i) {
            string sub = haystack.substr(i, needle.size());
            if (sub == needle)
                return i;
        }

        return -1;
    }
};
