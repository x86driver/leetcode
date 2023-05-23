class MyHashMap {
public:
    const int PRIME = 1000003;
    vector<int> hashmap;
    MyHashMap() {
        hashmap = vector<int>(PRIME + 1, -1);
    }

    void put(int key, int value) {
        int hash = key % PRIME;
        hashmap[hash] = value;
    }

    int get(int key) {
        int hash = key % PRIME;
        return hashmap[hash];
    }

    void remove(int key) {
        int hash = key % PRIME;
        hashmap[hash] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
