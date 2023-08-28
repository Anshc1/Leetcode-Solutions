class Twitter {
public:
    map<int,set<int>>followers;
    vector<pair<int,int>>tweets ;
    Twitter() {
        tweets.clear(); 
        followers.clear(); 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId , tweetId}); 
    }
    
    vector<int> getNewsFeed(int user_Id) {
        vector<int>feeds ; 
        int ct =10 ; 
        for(int i = tweets.size()-1; i>= 0 && ct > 0   ; i--){
            if((followers[user_Id].find(tweets[i].first)!= followers[user_Id].end()) || user_Id == tweets[i].first){
                feeds.push_back(tweets[i].second); 
                ct--; 
            }
        }
        return feeds; 
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */