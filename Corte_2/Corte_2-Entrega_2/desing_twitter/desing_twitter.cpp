#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

class Twitter {
private:
    int time = 0;
    std::unordered_map<int, std::vector<std::pair<int,int>>> tweets;
    std::unordered_map<int, std::set<int>> follows;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::vector<std::pair<int,int>> all;

        for(auto& t : tweets[userId]) all.push_back(t);
        for(int f : follows[userId])
            for(auto& t : tweets[f]) all.push_back(t);

        std::sort(all.begin(), all.end(), [](auto& a, auto& b){ return a.first > b.first; });

        std::vector<int> res;
        for(int i = 0; i < all.size() && i < 10; ++i)
            res.push_back(all[i].second);

        return res;
    }

    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};