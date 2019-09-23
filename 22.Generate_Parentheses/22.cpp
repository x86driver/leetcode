#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> answer;
  bool isValidParenth(const string &str) {
      int left = 0;
      for (auto &s : str) {
          if (s == '(') {
              ++left;
          } else { // assume ')'
              --left;
          }
          if (left < 0) {
              return false;
          }
      }
      return left == 0;
  }

  void generateAll(string &str, size_t pos) {
      if (str.length() == pos) {
          if (isValidParenth(str)) {
              answer.push_back(str);
          }
          return;
      } else {
          str[pos] = '(';
          generateAll(str, pos+1);
          str[pos] = ')';
          generateAll(str, pos+1);
      }
  }

  vector<string> generateParenthesis(int n) {
      string str;
      str.resize(n * 2);
      generateAll(str, 0);
      return answer;
  }
};

int main() {
    Solution sol;
    vector<string> answer = sol.generateParenthesis(3);
    for (auto &ans : answer) {
        cout << ans << endl;
    }
    return 0;
}
