#define PRIME 100003


typedef struct {
    bool *table;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* s = (MyHashSet*)calloc(1, sizeof(MyHashSet));
    s->table = (bool*)calloc(1, sizeof(bool)*PRIME);
    return s;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index = key % PRIME;
    obj->table[index] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = key % PRIME;
    obj->table[index] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int index = key % PRIME;
    return obj->table[index];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->table);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/
