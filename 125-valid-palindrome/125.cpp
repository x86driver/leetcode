class Solution {
public:
    bool isPalindrome(string s) {
        auto end_iter = remove_if(s.begin(), s.end(),
                                  [](unsigned char c) { return !isalnum(c); });
        s.erase(end_iter, s.end());
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            if (tolower(s[head]) == tolower(s[tail])) {
                ++head;
                --tail;
            } else {
                return false;
            }
        }

        return true;
    }
};
