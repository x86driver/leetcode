#pragma once

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
} HashMap;

HashMap* HashMapCreate();
void HashMapPut(HashMap* obj, int key, int value);
int HashMapGet(HashMap* obj, int key);
void HashMapRemove(HashMap* obj, int key);
void HashMapFree(HashMap* obj);
