class Solution {
private:
    bool isPrefix(const string& a, const string& b) {
        if (b.size() > a.size()) {
            return false;
        }
        int i = 0;
        int j = 0;
        while (j < b.size()) {
            if (a[i] != b[i]) {
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string token;
        int index = 1;
        while (iss >> token) {
            if (isPrefix(token, searchWord)) {
                return index;
            }
            ++index;

        }
        return -1;
    }
};
