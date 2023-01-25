class Twitter {
public:
    Twitter() {
        aging = 0;
    }

    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({tweetId, aging});
        ++aging;
    }

    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second < b.second;
        }
    };

    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        unordered_set<int> users = follows[userId];
        users.insert(userId);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

        for (int uid : users)
            for (pair<int, int> post : posts[uid])
                q.push(post);

        while (!q.empty()) {
            ret.push_back(q.top().first);
            q.pop();
            if (ret.size() == 10)
                break;
        }

        return ret;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }

private:
    int aging;
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> follows;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
