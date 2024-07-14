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
        int groups = n;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (categoryHandler->haveSameCategory(i, j)) {
                    --groups;
                    break;
                }
            }
        }
        return groups;
    }
};
