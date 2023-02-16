class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int max_size = 2*1000000;
        vector<int> front(seats.size(), max_size);
        vector<int> end(seats.size(), max_size);

        for (size_t i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                front[i] = 0;
            } else {
                if (i == 0 || front[i - 1] == max_size)
                    continue;
                front[i] = front[i - 1] + 1;
            }
        }

        for (int i = seats.size() - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                end[i] = 0;
            } else {
                if (i == seats.size() - 1) { // i == last and seats[i] == 0
                    end[i] = front[i];
                    continue;
                }
                if (end[i + 1] == max_size)
                    end[i] = front[i];
                else
                    end[i] = min(end[i + 1] + 1, front[i]);
            }
        }

        int ans = 0;
        for (int e : end) {
            ans = max(ans, e);
        }
        return ans;
    }
};
