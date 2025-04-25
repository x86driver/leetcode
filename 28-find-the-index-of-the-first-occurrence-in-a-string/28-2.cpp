class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        int ptr1 = 0;
        while (ptr1 < haystack.size()) {
            if (haystack.size() - ptr1 < needle.size()) {
                return -1;
            }
            if (haystack.substr(ptr1, needle.size()) == needle) {
                return ptr1;
            }
            ++ptr1;
        }
        return -1;
    }
};
