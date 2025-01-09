#include "../include/LRUCache.h"

LRUCache::LRUCache(int capacity) : capacity(capacity) {}

HockeyPlayer* LRUCache::getPlayer(int id) {
    if (cacheMap.find(id) != cacheMap.end()) {
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[id]);
        return &(*cacheList.begin());
    }
    return nullptr;
}

void LRUCache::addPlayer(HockeyPlayer& player) {
    if (cacheMap.find(player.id) != cacheMap.end()) {
        cacheList.erase(cacheMap[player.id]);
    } else if (cacheList.size() >= capacity) {
        cacheMap.erase(cacheList.back().id);
        cacheList.pop_back();
    }
    cacheList.push_front(player);
    cacheMap[player.id] = cacheList.begin();
}