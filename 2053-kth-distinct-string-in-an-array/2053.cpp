class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> m;
        vector<bool> distinct(arr.size());

        for (int i = 0; i < arr.size(); ++i) {
            const string &s = arr[i];
            if (m.find(s) == m.end()) {
                m[s] = i;
                distinct[i] = true;
            } else {
                if (m[s] >= 0)
                    distinct[m[s]] = false;
                m[s] = -1;
                distinct[i] = false;
            }
        }

        for (int i = 0; i < distinct.size(); ++i) {
            if (distinct[i] == true)
                --k;
            if (k == 0)
                return arr[i];

        }

        return "";
    }
};
