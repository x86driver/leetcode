#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib/queue.h"
#include "lib/hashmap.h"

typedef struct {
  int capacity;
  int elems;
  Queue *queue;
  HashMap *hashmap;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache*)calloc(1, sizeof(*cache));
    if (!cache) {
        perror("LRUCache calloc");
    }
    cache->capacity = capacity;
    cache->queue = QueueCreate(capacity);
    cache->hashmap = HashMapCreate();
    return cache;
}

bool lRUCacheFull(LRUCache* obj) {
    return (obj && obj->capacity == obj->elems);
}

int lRUCacheGet(LRUCache* obj, int key) {
    int value = HashMapGet(obj->hashmap, key);
    if (value != -1) {
        //QueueDeQueue(obj->queue);
        QueueRemove(obj->queue, key);
        QueueEnQueue(obj->queue, key);
    }
    return value;
}

static void lRUCacheEvict(LRUCache* obj) {
    int front = QueueFront(obj->queue);
    HashMapRemove(obj->hashmap, front);
    QueueDeQueue(obj->queue);
    --obj->elems;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    int val = lRUCacheGet(obj, key);
    if (val != -1) {
        HashMapPut(obj->hashmap, key, value);
        return;
    }

    if (lRUCacheFull(obj)) {
        lRUCacheEvict(obj);
    }

    QueueEnQueue(obj->queue, key);
    HashMapPut(obj->hashmap, key, value);
    ++obj->elems;
}

void lRUCacheFree(LRUCache* obj) {
    QueueFree(obj->queue);
    HashMapFree(obj->hashmap);
    free(obj);
}

#ifdef _MAIN_
int main() {
    LRUCache* obj = lRUCacheCreate(2);
    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 2);
    printf("get 1: %d\n", lRUCacheGet(obj, 1));
    lRUCachePut(obj, 3, 3);
    printf("get 2: %d\n", lRUCacheGet(obj, 2));
    lRUCachePut(obj, 4, 4);
    printf("get 1: %d\n", lRUCacheGet(obj, 1));
    printf("get 3: %d\n", lRUCacheGet(obj, 3));
    printf("get 4: %d\n", lRUCacheGet(obj, 4));
    return 0;
}
#endif
