class Solution {
public:
    int distinctIntegers(int n) {
        set<int> board;
        board.insert(n);
        int prev = 0;
        for (int day = 0; day < 10e9; ++day) {
            for (int num : board) {
                vector<int> tmp;
                for (int i = 2; i < num; ++i) {
                    if (num % i == 1) {
                        tmp.push_back(i);
                    }
                }
                for (int t : tmp) {
                    board.insert(t);
                }
            }
            if (prev != board.size()) {
                prev = board.size();
            } else {
                break;
            }
        }
        return board.size();
    }
};
