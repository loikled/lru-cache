
template<typename KeyType, typename ValueType>
ValueType LRUCache<KeyType, ValueType>::get(KeyType key)
{
    auto it = cache_.find(key);
    if (it != cache_.end())
    {
        // Cache hit,
        // Move the key to the end of the queue, meaning it's the most recently used value.
        // Remove does a search here which is O(size_), this is a naive approach
        keys_.remove(key);
        keys_.push_back(key);
        return cache_[key];   # O(1)
    }
    else if (cache_.size() < size_)
    {
        // Cache miss, but cache is not full.
        auto result = f_(key);
        cache_[key] = result;
        keys_.push_back(key);
        return result;
    }
    else
    {
        // Cache miss and cache is full,
        // delete least recently used entry
        auto LRUKey = keys_.front();
        keys_.pop_front();
        cache_.erase(LRUKey);

        auto result = f_(key);
        cache_[key] = result;
        keys_.push_back(key);
        return result;
    }
}
