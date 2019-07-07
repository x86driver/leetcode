#include <string>
#include <gtest/gtest.h>

using namespace std;

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
  HashNode *node[4999];
} MyHashMap;

MyHashMap* myHashMapCreate();
void myHashMapPut(MyHashMap* obj, int key, int value);
int myHashMapGet(MyHashMap* obj, int key);
void myHashMapRemove(MyHashMap* obj, int key);
void myHashMapFree(MyHashMap* obj);

TEST(HashMap, CreateEmpty) {
    MyHashMap* h = myHashMapCreate();
    EXPECT_EQ(myHashMapGet(h, 1), -1);
    myHashMapFree(h);
}

TEST(HashMap, SameBucket) {
    MyHashMap* h = myHashMapCreate();
    myHashMapPut(h, 1, 1);
    myHashMapPut(h, 5000, 10);
    myHashMapPut(h, 9999, 20);
    EXPECT_EQ(myHashMapGet(h, 9999), 20);
    EXPECT_EQ(h->node[1]->size, 4);
    EXPECT_EQ(h->node[1]->elems, 3);
    myHashMapFree(h);
}

TEST(HashMap, Remove_1) {
    MyHashMap* h = myHashMapCreate();
    myHashMapPut(h, 1, 1);
    myHashMapRemove(h, 1);
    EXPECT_EQ(myHashMapGet(h, 1), -1);
    myHashMapFree(h);
}

TEST(HashMap, RemoveMedium) {
    MyHashMap* h = myHashMapCreate();
    myHashMapPut(h, 1, 1);
    myHashMapPut(h, 5000, 10);
    myHashMapPut(h, 9999, 20);
    myHashMapRemove(h, 5000);
    EXPECT_EQ(myHashMapGet(h, 9999), 20);
    EXPECT_EQ(h->node[1]->size, 4);
    EXPECT_EQ(h->node[1]->elems, 2);
    myHashMapFree(h);
}

TEST(HashMap, RemoveAndInsert) {
    MyHashMap* h = myHashMapCreate();
    myHashMapPut(h, 1, 1);
    myHashMapPut(h, 5000, 10);
    myHashMapPut(h, 9999, 20);
    myHashMapRemove(h, 5000);
    myHashMapPut(h, 14998, 30);
    EXPECT_EQ(myHashMapGet(h, 9999), 20);
    EXPECT_EQ(myHashMapGet(h, 14998), 30);
    EXPECT_EQ(h->node[1]->size, 4);
    EXPECT_EQ(h->node[1]->elems, 3);
    myHashMapFree(h);
}

int main() {
    testing::InitGoogleTest();
    printf("test: %d\n", RUN_ALL_TESTS());
    return 0;
}
