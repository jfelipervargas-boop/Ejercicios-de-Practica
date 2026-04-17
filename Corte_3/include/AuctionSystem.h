#ifndef AUCTION_SYSTEM_H
#define AUCTION_SYSTEM_H

class AuctionSystem {
public:
    AuctionSystem();
    void addBid(int userId, int itemId, int bidAmount);
    void updateBid(int userId, int itemId, int newAmount);
    void removeBid(int userId, int itemId);
    int getHighestBidder(int itemId);

private:
    std::unordered_map<int, std::pair<int, int>> highestBids; // itemId -> (userId, amount)
};

#endif