class Solution {
private:
    bool isSimilar(const string& a, const string &b) {
      set<char> seta, setb;
      for (char c : a)
          seta.insert(c);
      for (char c : b)
          setb.insert(c);
      return seta == setb;
    }
public:
    int similarPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (isSimilar(words[i], words[j]))
                    ++count;
            }
        }
        return count;
    }
};
