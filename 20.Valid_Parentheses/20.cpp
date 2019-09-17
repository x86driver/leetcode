#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parenth_stack;
        bool isPop = false;
        for (auto &c : s) {
            char parenth = '\0';
            isPop = false;
            switch (c) {
                case '{':
                case '[':
                case '(':
                    parenth_stack.push(c);
                    break;
                case '}':
                case ']':
                case ')':
                    if (parenth_stack.empty()) {
                        return false;
                    }
                    parenth = parenth_stack.top();
                    parenth_stack.pop();
                    isPop = true;
                    break;
            }
            if (isPop) {
                if ((parenth == '{' && c == '}') ||
                    (parenth == '[' && c == ']') ||
                    (parenth == '(' && c == ')')) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        if (parenth_stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    string str = "[";
    cout << str << ": " << s.isValid(str) << endl;
    return 0;
}
