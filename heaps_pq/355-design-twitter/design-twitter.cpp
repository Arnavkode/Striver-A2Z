class Twitter {
public:
// Use Set to prevent duplicate follows and make unfollow O(1)
    unordered_map<int, unordered_set<int>> followers; //should be named following
    unordered_map<int, vector<pair<int,int>>> tweets;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> maxheap;
        for(int user : followers[userId]){
            for(auto twt : tweets[user]){maxheap.push(twt);}
        }
        for(auto twt : tweets[userId]){maxheap.push(twt);}

        while(!maxheap.empty() && ans.size() < 10){
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
if(followerId != followeeId)
            followers[followerId].erase(followeeId);    }
};

// twitter obj has to be made
// okay so the latest tweet would have a larger tweet id, so i might need a maxheap
// so maxheap is being used for sorting and not storing

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */