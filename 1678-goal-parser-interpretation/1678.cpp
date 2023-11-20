class Solution {
public:
    string interpret(string command) {
        string ans;
        int i = 0;
        while (i < command.size()) {
            if (command[i] == 'G') {
                ans += 'G';
                ++i;
            } else if (command[i] == '(' && command[i + 1] == 'a') {
                ans += "al";
                i += 4;
            } else {
                ans += "o";
                i += 2;
            }
        }
        return ans;
    }
};
