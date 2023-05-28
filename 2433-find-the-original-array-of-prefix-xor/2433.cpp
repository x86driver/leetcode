class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref[0]);
        int n = pref[0];
        int accu = pref[0];
        for (int i = 1; i < pref.size(); ++i) {
            n = accu ^ pref[i];
            accu ^= n;
            ans.push_back(n);
        }
        return ans;
    }
};
