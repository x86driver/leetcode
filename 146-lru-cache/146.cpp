class LRUCache {
public:
  LRUCache(int capacity)
      : capacity(capacity),
        head(new ListNode),
        tail(new ListNode) {
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
  }

  int get(int key) {
      auto it = m.find(key);
      if (it == m.end()) {
        return -1;
      } else {
        ListNode *node = it->second;
        int ret = node->value;
        removeFromList(node);
        insertToBegin(node);
        return ret;
      }
  }

  void put(int key, int value) {
    auto it = m.find(key);
    if (it == m.end()) {
      if (m.size() >= capacity) {
        removeFromTail();
      }
      ListNode *node = new ListNode;
      node->key = key;
      node->value = value;
      insertToBegin(node);
      m[key] = node;
    } else {
      ListNode *node = it->second;
      node->value = value;
      removeFromList(node);
      insertToBegin(node);
    }
  }
private:
  struct ListNode {
    int key;
    int value;
    struct ListNode *prev;
    struct ListNode *next;
  };
  int capacity;
  unordered_map<int, ListNode*> m;
  ListNode *head;
  ListNode *tail;

  void removeFromList(ListNode *node) {
    ListNode *tmp = node->next;
    node->next->prev = node->prev;
    node->prev->next = tmp;
    // no need delete
  }

  void insertToBegin(ListNode *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }

  void removeFromTail() {
    ListNode *node = tail->prev;
    node->prev->next = tail;
    tail->prev = node->prev;
    m.erase(node->key);
    delete node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
