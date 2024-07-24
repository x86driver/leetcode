class LRUCache {
private:
    struct Node {
        Node *prev;
        Node *next;
        int key;
        int val;
    };
    Node *head;
    Node *tail;
    map<int, Node*> m;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node;
        tail = new Node;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node *node = m[key];
            removeNode(node);
            insertIntoHead(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node *node = m[key];
            node->val = value;
            removeNode(node);
            insertIntoHead(node);
            return;
        }
        if (m.size() >= capacity) {
            removeFromTail();
        }
        Node *node = new Node;
        node->key = key;
        node->val = value;
        insertIntoHead(node);
        m[key] = node;
    }

    void insertIntoHead(Node *node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void removeFromTail() {
        Node *node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        m.erase(node->key);
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
