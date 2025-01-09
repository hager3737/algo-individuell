#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <list>
#include <unordered_map>
#include "HockeyPlayer.h"

class LRUCache {
private:
    int capacity;
    std::list<HockeyPlayer> cacheList;
    std::unordered_map<int, std::list<HockeyPlayer>::iterator> cacheMap;

public:
    explicit LRUCache(int capacity);
    HockeyPlayer* getPlayer(int id);
    void addPlayer(HockeyPlayer& player);
};

#endif // LRU_CACHE_H