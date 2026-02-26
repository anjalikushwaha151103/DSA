class LFUCache {
    
    class Node {
    public:
        int key, val, freq;
        Node* prev;
        Node* next;
        
        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = next = NULL;
        }
    };
    
    class List {
    public:
        Node* head;
        Node* tail;
        int size;
        
        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        
        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }
        
        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        
        Node* removeLast() {
            if(size == 0) return NULL;
            Node* node = tail->prev;
            removeNode(node);
            return node;
        }
    };
    
    unordered_map<int, Node*> keyMap;
    unordered_map<int, List*> freqMap;
    int capacity;
    int minFreq;
    
public:
    
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyMap.find(key) == keyMap.end())
            return -1;
        
        Node* node = keyMap[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        
        if(keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->val = value;
            updateFreq(node);
        } else {
            
            if(keyMap.size() == capacity) {
                List* list = freqMap[minFreq];
                Node* nodeToRemove = list->removeLast();
                keyMap.erase(nodeToRemove->key);
            }
            
            Node* newNode = new Node(key, value);
            minFreq = 1;
            
            if(freqMap.find(1) == freqMap.end())
                freqMap[1] = new List();
            
            freqMap[1]->addFront(newNode);
            keyMap[key] = newNode;
        }
    }
    
private:
    
    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqMap[oldFreq]->removeNode(node);
        
        if(oldFreq == minFreq && freqMap[oldFreq]->size == 0)
            minFreq++;
        
        node->freq++;
        
        if(freqMap.find(node->freq) == freqMap.end())
            freqMap[node->freq] = new List();
        
        freqMap[node->freq]->addFront(node);
    }
};