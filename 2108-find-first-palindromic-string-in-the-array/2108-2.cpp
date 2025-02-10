class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& str : words) {
            int i = 0;
            int j = str.size() - 1;
            bool plaindromic = true;
            while (i < j) {
                if (str[i] != str[j]) {
                    plaindromic = false;
                    break;
                }
                ++i;
                --j;
            }
            if (plaindromic) {
                return str;
            }
        }
        return "";
    }
};
