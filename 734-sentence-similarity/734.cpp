class Solution {
private:
    multimap<string, string> m;

    bool isSimilar(string &a, string &b) {
        for (auto it = m.find(b); it != m.end(); ++it) {
            if (it->second == a)
                return true;
        }
        return false;
    }

public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size())
            return false;

        for (vector<string>& pairs : similarPairs)
            m.insert({pairs[0], pairs[1]});

        for (size_t i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i])
                continue;
            if (!isSimilar(sentence1[i], sentence2[i]) &&
                !isSimilar(sentence2[i], sentence1[i]))
                return false;
        }

        return true;
    }
};
