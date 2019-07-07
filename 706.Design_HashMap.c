#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PRIME 4997
#define FACTOR 2

typedef struct {
  int key;
  int val;
} HashKV;

typedef struct {
  int size;
  int elems;
  HashKV *kv;
} HashNode;

typedef struct {
  HashNode *node[PRIME];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap *hash = (MyHashMap*)calloc(1, sizeof(*hash));
    return hash;
}

const int Hash(int key) {
    return key % PRIME;
}

HashNode *getHashNode(MyHashMap* obj, int key) {
    int pos = Hash(key);
    return obj->node[pos];
}

void setHashNode(MyHashMap* obj, int key, HashNode *node) {
    int pos = Hash(key);
    assert(obj->node[pos] == NULL);
    obj->node[pos] = node;
}

HashKV *searchKV(MyHashMap* obj, int key) {
    HashNode *node = getHashNode(obj, key);
    if (!node) {
        return NULL;
    }
    for (int i = 0; i < node->elems; ++i) {
        if (node->kv[i].key == key) {
            return node->kv + i;
        }
    }
    return NULL;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    HashNode *node = getHashNode(obj, key);
    if (node == NULL) {
        node = (HashNode*)calloc(1, sizeof(HashNode));
        node->size = 2;
        node->kv = (HashKV*)calloc(2, sizeof(HashKV));
        if (!node->kv) {
            perror("calloc HashKV");
            return;
        }
        setHashNode(obj, key, node);
    } else if (node->size == node->elems) {
        // full
        HashKV *new_array = (HashKV*)realloc(node->kv, node->size * FACTOR * sizeof(HashKV));
        if (new_array) {
            node->kv = new_array;
            node->size *= FACTOR;
        } else {
            perror("reallocarray HashKV");
            return;
        }
    }

    HashKV *kv = searchKV(obj, key);
    if (kv) {
        kv->val = value;
    } else {
        node->kv[node->elems++] = (HashKV){.key = key, .val = value};
    }
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    HashNode *node = getHashNode(obj, key);
    if (node == NULL || node->size == 0) {
        return -1;
    }

    HashKV *kv = searchKV(obj, key);
    if (kv == NULL) {
        return -1;
    }
    return kv->val;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    HashNode *node = getHashNode(obj, key);
    if (node == NULL || node->size == 0) {
        return;
    }

    HashKV *new_kv = (HashKV*)calloc(node->size, sizeof(HashKV));
    if (!new_kv) {
        perror("HashKV calloc in remove");
    }

    HashKV *new_kv_iter = new_kv;
    int elems = node->elems;
    for (int i = 0; i < elems; ++i) {
        HashKV kv = node->kv[i];
        if (kv.key == key) {
            --node->elems;
            continue;
        }
        *new_kv_iter++ = node->kv[i];
    }
    free(node->kv);
    node->kv = new_kv;
}

void myHashMapFree(MyHashMap* obj) {
    if (!obj) {
        return;
    }

    for (int i = 0; i < PRIME; ++i) {
        HashNode *node = obj->node[i];
        if (node) {
            if (node->kv) {
                free(node->kv);
            }
            free(node);
        }
    }
    free(obj);
}

#ifndef GOOGLE_TEST
int main() {
    MyHashMap *obj = myHashMapCreate();
    myHashMapPut(obj, 1, 100);
    printf("val: %d\n", myHashMapGet(obj, 1));
    myHashMapPut(obj, 5000, 200);
    printf("val: %d\n", myHashMapGet(obj, 5000));
    myHashMapPut(obj, 9999, 300);
    printf("val: %d\n", myHashMapGet(obj, 9999));
    myHashMapFree(obj);
    return 0;
}
#endif
