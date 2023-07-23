class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        for (int i = 0; i < bank.size() - 1;) {
            int curr = 0;
            for (int j = 0; j < bank[i].size(); ++j)
                if (bank[i][j] == '1')
                    ++curr;

            int row2 = i + 1;
            int row2_num = 0;
            while (row2 < bank.size()) {
                row2_num = 0;
                for (int j = 0; j < bank[row2].size(); ++j)
                    if (bank[row2][j] == '1')
                        ++row2_num;
                if (row2_num == 0)
                    ++row2;
                else
                    break;
            }

            if (row2_num) {
                ans += curr * row2_num;
                i = row2;
            } else {
                break;
            }
        }

        return ans;
    }
};
