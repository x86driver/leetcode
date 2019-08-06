#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
      unordered_map<char, size_t> map;
      size_t len = s.length();
      size_t maximum = 0;

      size_t start = 0, j = 0;
      for (j = 0; j < len; ++j) {
          char c = s[j];
          if (map.count(c)) {
              maximum = max(maximum, j - start);
              start = map[c] + 1;
              map.clear();
              for (auto k = start; k <= j; ++k) {
                  map[s[k]] = k;
              }
          } else {
              map[c] = j;
          }
      }

      maximum = max(maximum, j - start);
      return (int)maximum;
  }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (size_t i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
