#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <vector>
#include <list>
#include <functional>
#include <unordered_map>

class LRUCache
{
public:
    LRUCache(std::function<int(int)> cachedFunction, int size)
        : size_(size)
         , f_(cachedFunction) {};
    int get(int key);
    int size() {return cache_.size();}
    bool hasKey(int key) {return cache_.find(key) != cache_.end();}
private:
    unsigned int const size_{};
    std::unordered_map<int, int> cache_{};
    std::list<int> keys_{};
    std::function<int(int)> f_;
};

#endif