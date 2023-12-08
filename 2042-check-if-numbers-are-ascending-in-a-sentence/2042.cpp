class Solution {
private:
    vector<int> split(const string& s) {
        istringstream iss(s);
        vector<int> tokens;
        string token;
        while (iss >> token) {
            if (token.empty()) {
                continue;
            }
            bool digit = true;
            for (char c : token) {
                if (!isdigit(c)) {
                    digit = false;
                    break;
                }
            }
            if (digit)
                tokens.push_back(stoi(token));
        }
        return tokens;
    }
public:
    bool areNumbersAscending(string s) {
        vector<int> digits = split(s);
        for (int i = 0; i < digits.size() - 1; ++i) {
            if (digits[i] >= digits[i + 1])
                return false;
        }
        return true;
    }
};
