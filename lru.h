#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <vector>
#include <list>
#include <functional>
#include <unordered_map>

template<typename KeyType, typename ValueType>
class LRUCache
{
public:
    LRUCache(std::function<ValueType(KeyType)> cachedFunction, int size)
        : size_(size)
        , f_(cachedFunction) {};
    ValueType get(KeyType key);
    int size() {return cache_.size();}
    bool hasKey(KeyType key) {return cache_.find(key) != cache_.end();}
private:
    unsigned int const size_{};
    std::unordered_map<KeyType, ValueType> cache_{};
    std::list<KeyType> keys_{};
    std::function<ValueType(KeyType)> f_;
};

#include "lru.tpp"

#endif