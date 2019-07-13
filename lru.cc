#include "lru.h"

int LRUCache::get(int key)
{
    auto it = cache_.find(key);
    if (it != cache_.end())
    {
        // Move the key to the end of the queue, meaning it's the most recently used value.
        keys_.remove(key);
        keys_.push_back(key);
        return cache_[key];   
    }
    else if (cache_.size() < size_)
    {
        auto result = f_(key);
        cache_[key] = result;
        keys_.push_back(key);
        return result;
    }
    else
    {
        auto LRUKey = keys_.front();
        keys_.pop_front();
        cache_.erase(LRUKey);

        auto result = f_(key);
        cache_[key] = result;
        keys_.push_back(key);
        return result;
    }
}

