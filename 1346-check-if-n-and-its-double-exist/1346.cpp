class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> m;
        for (int i = 0; i < arr.size(); ++i)
            m[arr[i] * 2] = i;

        for (int i = 0; i < arr.size(); ++i) {
            if (m.find(arr[i]) != m.end()) {
                if (m[arr[i]] != i)
                    return true;
            }
        }

        return false;
    }
};
