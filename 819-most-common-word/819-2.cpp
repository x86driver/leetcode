class Solution {
private:
    vector<string> splitString(const string& input) {
        std::regex delimiter("[,\\s\\.!\?;:']+"); // Matches comma, space, and dot
        std::sregex_token_iterator start(input.begin(), input.end(), delimiter, -1);
        std::sregex_token_iterator end;
        std::vector<std::string> tokens(start, end);
        return tokens;
    }

    std::string to_lowercase(const std::string& input) {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(),
                    [](unsigned char c) { return std::tolower(c); });
        return result;
    }

public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> ban(banned.begin(), banned.end());
        vector<string> tokens = splitString(paragraph);
        unordered_map<string, int> m;
        for (string& token : tokens) {
            token = to_lowercase(token);
            if (ban.find(token) == ban.end())
                ++m[token];
        }

        int maximum = 0;
        string ans;
        for (const auto& entry : m) {
            if (entry.second > maximum) {
                maximum = entry.second;
                ans = entry.first;
            }
        }

        return ans;
    }
};
