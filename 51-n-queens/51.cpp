class Solution {
public:
    Solution() : n (0) { }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        used.resize(n);
        find(0);

        vector<vector<string>> ret;
        for (int i = 0; i < ans.size(); ++i) {
            ret.push_back(toString(ans[i]));
        }

        return ret;
    }
private:
    int n;
    vector<vector<int>> ans;
    vector<int> sets;
    vector<bool> used;

    // queens: [1,3,0,2]
    // return: [".Q..", "...Q","Q...","..Q."]
    vector<string> toString(const vector<int> &queens) {
        vector<string> ret;
        for (int i = 0; i < this->n; ++i) {
            string str;
            for (int j = 0; j < this->n; ++j) {
                if (queens[i] == j)
                    str += "Q";
                else
                    str += ".";
            }
            ret.push_back(str);
        }
        return ret;
    }
    // return: -1 invalid, 1 has queen, 0 has no queen
    int getXY(int x, int y) {
        if (x < 0 || x >= this->n)
            return -1;
        if (y < 0 || y >= this->n)
            return -1;

        return (sets[x] == y) ? 1 : 0;
    }

    // return: true has queen, false has no queen
    bool upperLeft(int x, int y) {
        --x;
        --y;
        while (x >= 0 && y >= 0) {
            if (getXY(x, y) == 1)
                return true;
            --x;
            --y;
        }
        return false;
    }

    bool upperRight(int x, int y) {
        ++x;
        --y;
        while (x < this->n && y >= 0) {
            if (getXY(x, y) == 1)
                return true;
            ++x;
            --y;
        }
        return false;
    }

    bool bottomLeft(int x, int y) {
        --x;
        --y;
        while (x >= 0 && y >= 0) {
            if (getXY(x, y) == 1)
                return true;
            --x;
            --y;
        }
        return false;
    }

    bool bottomRight(int x, int y) {
        ++x;
        ++y;
        while (x < this->n && y < this->n) {
            if (getXY(x, y) == 1)
                return true;
            ++x;
            ++y;
        }
        return false;
    }

    bool hasQueen() {
        for (int x = 0; x < this->n; ++x) {
            int y = sets[x];
            if (upperLeft(x, y) == true ||
                upperRight(x, y) == true ||
                bottomLeft(x, y) == true ||
                bottomRight(x, y) == true) {
                    return true;
            }
        }
        return false;
    }

    void find(int index) {
        if (index >= this->n) {
            if (hasQueen() == false)
                ans.push_back(sets);
            return;
        }

        for (int i = 0; i < this->n; ++i) {
            if (used[i] == false) {
                used[i] = true;
                sets.push_back(i);
                find(index + 1);
                sets.pop_back();
                used[i] = false;
            }
        }
    }
};
