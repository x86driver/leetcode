/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        vector<int> m(n + 1);
        for (int i = 0; i < n; ++i) {
            if (m[i] == 0)
                m[i] = i + 1;
            for (int j = i + 1; j < n; ++j) {
                if (m[j] == 0 && categoryHandler->haveSameCategory(i, j))
                    m[j] = i + 1;
            }
        }
        int count = 0;
        set<int> s;
        for (int x : m)
            s.insert(x);
        return s.size() - 1;
    }
};
