class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int ans1 = 0;
        int ans2 = 0;

        if (destination < start) {
            int tmp = start;
            start = destination;
            destination = tmp;
        }

        for (int i = start; i < destination; ++i) {
            ans1 += distance[i];
        }

        int i = start;
        while (i != destination) {
            --i;
            if (i < 0) {
                i = distance.size() - 1;
            }
            ans2 += distance[i];
        }

        return min(ans1, ans2);
    }
};
