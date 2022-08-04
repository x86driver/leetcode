class Solution {
private:
    bool isBanned(const string &s, vector<string>& banned) {
        for (auto &b : banned) {
            if (s == b) {
                return true;
            }
        }
        return false;
    }

public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words;
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
                 [](char c) {
                     if (!std::isalpha(c)) {
                         return (int)' ';
                     }
                     return std::tolower(c);
                 });
        istringstream iss(paragraph);
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));
        unordered_map<string, int> map;

        for (auto &w : words) {
            if (map.find(w) != map.end()) {
                ++map[w];
            } else if (!isBanned(w, banned)) {
                map[w] = 1;
            }
        }

        vector<pair<string, int>> vec;
        copy(map.begin(), map.end(), back_inserter<vector<pair<string, int>>>(vec));
        sort(vec.begin(), vec.end(),
            [](const pair<string, int> &l, const pair<string, int> &r) {
                return l.second > r.second;
            });

        return vec[0].first;
    }
};
