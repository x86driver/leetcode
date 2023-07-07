class Solution {
private:
    int m;
    int n;
    vector<int> get(vector<vector<int>>& mat, int x, int y) {
        vector<int> vec;
        while (x < m && y < n) {
            vec.push_back(mat[x][y]);
            ++x;
            ++y;
        }

        return vec;
    }
    vector<pair<int, int>> find(vector<vector<int>>& mat) {
        vector<pair<int, int>> vec;
        int x = m - 1;
        int y = 0;

        while (x > 0) {
            vec.push_back({x, y});
            --x;
        }

        while (y < n) {
            vec.push_back({x, y});
            ++y;
        }

        return vec;
    }
    void fill(vector<vector<int>>& mat, vector<int> data, int x, int y) {
        int i = 0;
        while (x < m && y < n) {
            mat[x][y] = data[i];
            ++x;
            ++y;
            ++i;
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        this->m = mat.size();
        this->n = mat[0].size();
        vector<pair<int, int>> coords = find(mat);
        for (pair<int, int>& p : coords) {
            vector<int> data = get(mat, p.first, p.second);
            sort(data.begin(), data.end());
            fill(mat, data, p.first, p.second);
        }
        return mat;
    }
};
