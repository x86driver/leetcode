class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) :
        persons(persons), times(times) {
        unordered_map<int, int> votes;
        int currLeading = -1;
        int currMaxVote = -1;
        for (auto i = 0; i < persons.size(); ++i) {
            ++votes[persons[i]];
            if (votes[persons[i]] >= currMaxVote) {
                currMaxVote = votes[persons[i]];
                currLeading = persons[i];
            }
            leading.push_back(currLeading);
        }
    }

    int q(int t) {
        int left = -1;
        int right = leading.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (times[mid] <= t)
                left = mid;
            else
                right = mid - 1;
        }

        return leading[right];
    }
private:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        }
    };
    const vector<int>& persons;
    const vector<int>& times;
    vector<int> leading;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
