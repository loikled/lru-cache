
#include <gtest/gtest.h>

#include "lru.h"

using namespace testing;

TEST(LRUCache, insertOne)
{
    LRUCache<int, int> cache([](int a) -> int {return a * 2;}, 1);
    EXPECT_EQ(0, cache.size());
    int result = cache.get(2);
    EXPECT_EQ(4, result);
    EXPECT_EQ(1, cache.size());
}

TEST(LRUCache, computeTwiceUseCache)
{
    int count{0};
    LRUCache<int, int> cache([&](int a) -> int {count++; return a * 2;}, 1);

    // Function is called because result is not in cache
    EXPECT_EQ(0, cache.size());
    int result = cache.get(2);
    EXPECT_EQ(1, count);
    EXPECT_EQ(4, result);
    EXPECT_EQ(1, cache.size());

    // Result is in cache, function should not be called twice.
    int result2 = cache.get(2);
    EXPECT_EQ(1, count);
    EXPECT_EQ(4, result2);
    EXPECT_EQ(1, cache.size());
}


TEST(LRUCache, fullCache)
{
    int count{0};
    LRUCache<int, int> cache([&](int a) -> int {count++; return a * 2;}, 2);

    // Function is called because result is not in cache
    EXPECT_EQ(0, cache.size());
    int result = cache.get(2);
    EXPECT_EQ(1, count);
    EXPECT_EQ(4, result);
    EXPECT_EQ(1, cache.size());
    EXPECT_TRUE(cache.hasKey(2));

    // Add another entry in the cache, it's now full
    int result2 = cache.get(3);
    EXPECT_EQ(2, count);
    EXPECT_EQ(6, result2);
    EXPECT_EQ(2, cache.size());
    EXPECT_TRUE(cache.hasKey(3));

    // Add a new key, the least recently used key must now be gone.
    int result3 = cache.get(4);
    EXPECT_EQ(3, count);
    EXPECT_EQ(8, result3);
    EXPECT_EQ(2, cache.size());
    EXPECT_TRUE(cache.hasKey(4));
    EXPECT_FALSE(cache.hasKey(2));
}
