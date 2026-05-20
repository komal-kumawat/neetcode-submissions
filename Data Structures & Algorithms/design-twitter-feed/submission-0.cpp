class Twitter {
public:

    int timeStamp;

    unordered_map<int, set<int>> followMap;

    unordered_map<int,
        vector<pair<int,int>>> tweetMap;

    Twitter() {

        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {

        tweetMap[userId].push_back(
            {timeStamp++, tweetId}
        );
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        // user should follow himself
        followMap[userId].insert(userId);

        // collect tweets
        for(int followee : followMap[userId]) {

            for(auto &tweet : tweetMap[followee]) {

                pq.push(tweet);
            }
        }

        vector<int> ans;

        int cnt = 10;

        while(!pq.empty() && cnt--) {

            ans.push_back(pq.top().second);

            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        // cannot unfollow self
        if(followerId != followeeId) {

            followMap[followerId].erase(followeeId);
        }
    }
};