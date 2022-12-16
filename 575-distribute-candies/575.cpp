class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> types;
        for (auto &c : candyType) {
            types.insert(c);
        }

        return min(candyType.size() / 2, types.size());
    }
};
