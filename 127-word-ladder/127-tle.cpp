class Solution {
private:
    bool diffOne(const string& a, const string& b) {
        bool diff = false;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (diff)
                    return false;
                else
                    diff = true;
            }
        }
        return diff;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, bool> m;
        for (string& s : wordList)
            m[s] = false;

        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        while (!q.empty()) {
            string currStr = q.front().first;
            int currDepth = q.front().second;
            q.pop();

            for (string& s : wordList) {
                if (m[s] == false && diffOne(currStr, s)) {
                    if (s == endWord)
                        return currDepth + 2;
                    m[s] = true;
                    q.push({s, currDepth + 1});
                }
            }
        }

        return 0;
    }
};
