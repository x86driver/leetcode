class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, bool> m;
        for (string& s : wordList)
            m[s] = false;

        const int L = beginWord.size();
        map<string, vector<string>> all_combo_dict;
        for (string& word : wordList) {
            for (int i = 0; i < L; ++i) {
                string index = word.substr(0, i) + "*" + word.substr(i+1);
                all_combo_dict[index].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        while (!q.empty()) {
            string currStr = q.front().first;
            int currDepth = q.front().second;
            q.pop();

            for (int i = 0; i < L; ++i) {
                string intermediate = currStr.substr(0, i) + "*" + currStr.substr(i+1);
                for (string& s : all_combo_dict[intermediate]) {
                    if (s == endWord)
                        return currDepth + 2;
                    if (m[s] == false) {
                        m[s] = true;
                        q.push({s, currDepth + 1});
                    }
                }
            }
        }

        return 0;
    }
};
