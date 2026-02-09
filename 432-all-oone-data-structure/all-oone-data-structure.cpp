class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node *prev, *next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    Node *head, *tail;
    unordered_map<string, Node*> keyNode;

    void insertAfter(Node* prev, Node* node) {
        node->next = prev->next;
        node->prev = prev;
        prev->next->prev = node;
        prev->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (!keyNode.count(key)) {
            // new key → count = 1
            Node* first = head->next;
            if (first == tail || first->count != 1) {
                Node* node = new Node(1);
                insertAfter(head, node);
                first = node;
            }
            first->keys.insert(key);
            keyNode[key] = first;
        } else {
            Node* curr = keyNode[key];
            Node* nextNode = curr->next;
            int newCount = curr->count + 1;

            if (nextNode == tail || nextNode->count != newCount) {
                Node* node = new Node(newCount);
                insertAfter(curr, node);
                nextNode = node;
            }

            nextNode->keys.insert(key);
            keyNode[key] = nextNode;

            curr->keys.erase(key);
            if (curr->keys.empty())
                removeNode(curr);
        }
    }

    void dec(string key) {
        Node* curr = keyNode[key];
        int newCount = curr->count - 1;

        if (newCount == 0) {
            keyNode.erase(key);
        } else {
            Node* prevNode = curr->prev;
            if (prevNode == head || prevNode->count != newCount) {
                Node* node = new Node(newCount);
                insertAfter(prevNode, node);
                prevNode = node;
            }
            prevNode->keys.insert(key);
            keyNode[key] = prevNode;
        }

        curr->keys.erase(key);
        if (curr->keys.empty())
            removeNode(curr);
    }

    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */