struct Node {
    int val;
    Node* next;
    Node* prev;
};

class LRUCache {
private:
    // doubly linked list, front is LRU and back is most recently used
    // store pointers to each element in seperate map
    // when element used, remove from position and add to back
    Node* first = nullptr;
    Node* last = nullptr;
    unordered_map<int, int> keyValueStore;
    unordered_map<int, Node*> keyPointerStore;
    int capacity;
    int size;

public:
    LRUCache(int capacity) : capacity(capacity), size(0) { }

    ~LRUCache() {
        Node* curr = first;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    
    int get(int key) {
        if (!keyValueStore.contains(key)) return -1;
        use(key);
        return keyValueStore[key];
    }

    Node* pushBack(int key) {
        Node* toPush = new Node();
        toPush->val = key;
        toPush->next = nullptr;
        toPush->prev = last;
        if (!first) {
            first = toPush;
            last = toPush;
        } else {
            last->next = toPush;
            last = toPush;
        }
        size++;
        return toPush;
    }

    void popFront() {
        if (!first) return;
        keyValueStore.erase(first->val);
        keyPointerStore.erase(first->val);
        Node* temp = first;
        first = first->next;
        if (first) first->prev = nullptr;
        delete temp;
        size--;
    }

    void use(int key) {
        Node* keyPtr = keyPointerStore[key];
        if (keyPtr == last) return;
        if (keyPtr == first) {
            first = keyPtr->next;
            if (keyPtr->next) keyPtr->next->prev = nullptr;
            keyPtr->next = nullptr;
            keyPtr->prev = last;
            if (last) last->next = keyPtr;
            last = keyPtr;
        } else {
            keyPtr->prev->next = keyPtr->next;
            keyPtr->next->prev = keyPtr->prev;
            keyPtr->prev = last;
            last->next = keyPtr;
            last = keyPtr;
            keyPtr->next = nullptr;
        }      
    }
    
    void put(int key, int value) {
        if (keyValueStore.contains(key)) {
            keyValueStore[key] = value;
            use(key);
            return;
        }
        keyValueStore[key] = value;
        keyPointerStore[key] = pushBack(key);
        if (size > capacity) popFront();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */