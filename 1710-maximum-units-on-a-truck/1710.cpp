class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return b[1] < a[1];
             });
        int units = 0;
        for (int i = 0; i < boxTypes.size(); ++i) {
            if (truckSize >= boxTypes[i][0]) {
                units += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else if (truckSize != 0) {
                units += truckSize * boxTypes[i][1];
                truckSize = 0;
            } else {
                break;
            }
        }
        return units;
    }
};
