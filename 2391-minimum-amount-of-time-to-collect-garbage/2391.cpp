class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int maxm = -1;
        int maxp = -1;
        int maxg = -1;
        for (int i = 0; i < garbage.size(); ++i) {
            for (char c : garbage[i]) {
                if (c == 'M')
                    maxm = i;
                else if (c == 'P')
                    maxp = i;
                else if (c == 'G')
                    maxg = i;
            }
        }

        int minutes = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            minutes += garbage[i].size();
        }
        for (int i = 0; i < maxm; ++i) {
            minutes += travel[i];
        }
        for (int i = 0; i < maxp; ++i) {
            minutes += travel[i];
        }
        for (int i = 0; i < maxg; ++i) {
            minutes += travel[i];
        }
        return minutes;
    }
};
