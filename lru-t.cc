
#include <gtest/gtest.h>

#include "lru.h"

using namespace testing;

TEST(LRUCache, insertOne)
{
    LRUCache cache([](int a) -> int {return a * 2;}, 1);
    EXPECT_EQ(0, cache.size());
    int result = cache.get(2);
    EXPECT_EQ(4, result);
    EXPECT_EQ(1, cache.size());
}

TEST(LRUCache, computeTwiceUseCache)
{
    int count{0};
    LRUCache cache([&](int a) -> int {count++; return a * 2;}, 1);

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