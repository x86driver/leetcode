#include <gtest/gtest.h>
#include "lib/queue.h"
#include "lib/hashmap.h"

using namespace std;

typedef struct {
  int capacity;
  int elems;
  Queue *queue;
  HashMap *hashmap;
} LRUCache;

extern "C" {
  LRUCache* lRUCacheCreate(int capacity);
  int lRUCacheGet(LRUCache* obj, int key);
  void lRUCachePut(LRUCache* obj, int key, int value);
  void lRUCacheFree(LRUCache* obj);
}

TEST(LRUCache, test1) {
    LRUCache* obj = lRUCacheCreate(2);
    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 2);
    EXPECT_EQ(lRUCacheGet(obj, 1), 1);
    lRUCachePut(obj, 3, 3);
    EXPECT_EQ(lRUCacheGet(obj, 2), -1);
    lRUCachePut(obj, 4, 4);
    EXPECT_EQ(lRUCacheGet(obj, 1), -1);
    EXPECT_EQ(lRUCacheGet(obj, 3), 3);
    EXPECT_EQ(lRUCacheGet(obj, 4), 4);
    lRUCacheFree(obj);
}

TEST(LRUCache, test2) {
    LRUCache* obj = lRUCacheCreate(2);
    EXPECT_EQ(lRUCacheGet(obj, 2), -1);
    lRUCachePut(obj, 2, 6);
    EXPECT_EQ(lRUCacheGet(obj, 1), -1);
    lRUCachePut(obj, 1, 5);
    lRUCachePut(obj, 1, 2);
    EXPECT_EQ(lRUCacheGet(obj, 1), 2);
    EXPECT_EQ(lRUCacheGet(obj, 2), 6);
    lRUCacheFree(obj);
}

TEST(LRUCache, test3) {
    LRUCache* obj = lRUCacheCreate(2);
    lRUCachePut(obj, 2, 1);
    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 3);
    lRUCachePut(obj, 4, 1);
    EXPECT_EQ(lRUCacheGet(obj, 1), -1);
    EXPECT_EQ(lRUCacheGet(obj, 2), 3);
    lRUCacheFree(obj);
}

int main() {
    testing::InitGoogleTest();
    printf("test: %d\n", RUN_ALL_TESTS());
    return 0;
}
