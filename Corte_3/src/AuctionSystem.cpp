#include "AuctionSystem.h"
#include <unordered_map>

AuctionSystem::AuctionSystem() = default;

void AuctionSystem::addBid(int userId, int itemId, int bidAmount) {
    auto& p = highestBids[itemId];
    if (bidAmount > p.second) {
        p = {userId, bidAmount};
    }
}

void AuctionSystem::updateBid(int userId, int itemId, int newAmount) {
    auto it = highestBids.find(itemId);
    if (it != highestBids.end() && it->second.first == userId) {
        it->second.second = newAmount;
    }
}

void AuctionSystem::removeBid(int userId, int itemId) {
    auto it = highestBids.find(itemId);
    if (it != highestBids.end() && it->second.first == userId) {
        highestBids.erase(it);
    }
}

int AuctionSystem::getHighestBidder(int itemId) {
    auto it = highestBids.find(itemId);
    return (it != highestBids.end()) ? it->second.first : -1;
}