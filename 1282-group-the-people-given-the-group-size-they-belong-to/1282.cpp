class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        vector<int> picked(groupSizes.size(), false);

        for (int i = 0; i < groupSizes.size(); ++i) {
            if (picked[i])
                continue;
            vector<int> group;
            int size = groupSizes[i];
            group.push_back(i);
            picked[i] = true;
            for (int j = i + 1; j < groupSizes.size(); ++j) {
            if (group.size() == size)
                break;
            if (groupSizes[j] == size && !picked[j]) {
                    group.push_back(j);
                    picked[j] = true;
                }
            }
            ans.push_back(group);
        }

        return ans;
    }
};
