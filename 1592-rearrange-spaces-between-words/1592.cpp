class Solution {
public:
    string reorderSpaces(string text) {
        string ret;
        vector<string> words;
        stringstream ss(text);

        int spaces = 0;
        for (auto c : text) {
            if (isspace(c)) {
                ++spaces;
            }
        }

        while (ss.good()) {
            string substr;
            getline(ss, substr, ' ');
            if (substr.size() > 0 && !isspace(substr[0])) {
                words.push_back(substr);
            }
        }

        if (spaces == 0) {
            return text;
        }

        int divide = 0;
        int remain = 0;
        if (words.size() == 1) {
            divide = 0;
            remain = spaces;
        } else {
            divide = int(spaces / (words.size() - 1));
            remain = int(spaces % (words.size() - 1));
        }

        for (size_t i = 0; i < words.size() - 1; ++i) {
            ret += words[i];
            for (int d = 0; d < divide; ++d) {
                ret += ' ';
            }
        }

        ret += words[words.size() - 1];
        for (int r = 0; r < remain; ++r) {
            ret += ' ';
        }

        return ret;
    }
};
