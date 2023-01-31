class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> output;
        unordered_map<int, int> m;
        for (int a : arr1)
            ++m[a];

        for (int a : arr2) {
            for (int i = 0; i < m[a]; ++i)
                output.push_back(a);
            m[a] = 0;
        }

        int start = output.size();
        for (pair<int, int> p : m)
            for (int i = 0; i < p.second; ++i)
                output.push_back(p.first);

        sort(output.begin() + start, output.end());
        return output;
    }
};
