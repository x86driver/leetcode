class Solution {
private:
    stack<char> buildStack(string s) {
        stack<char> ss;
        for (char c : s) {
            if (c == '#') {
                if(!ss.empty())
                    ss.pop();
            } else {
                ss.push(c);
            }
        }
        return ss;
    }
public:
    bool backspaceCompare(string s, string t) {
        return buildStack(s) == buildStack(t);
    }
};
