class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
        
            Node(int key,int val){
                this->key=key;
                this->val=val;
                prev=NULL;
                next=NULL;
            }
    };

    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    int cap;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    unordered_map <int, Node*>mp;

    void deleteNode(Node* node){
        Node* nextnode= node->next;
        Node* prevnode=node->prev;
        prevnode->next=nextnode;
        nextnode->prev= prevnode;
    }

    void addNode(Node* newnode){
        Node* headnext= head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=headnext;
        headnext->prev=newnode;         
        
    }

    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
            Node* ansnode=mp[key];
            deleteNode(ansnode);
            addNode(ansnode);
            return ansnode->val;
        }
        
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(mp.find(key)==mp.end()){
            Node* newnode= new Node(key,value);
            if(mp.size()==cap){
                Node* delnode=tail->prev;
                mp.erase(delnode->key);
                deleteNode(delnode);
                delete(delnode);
            }
            addNode(newnode);
            mp[key]= newnode;
        }else{
            Node* oldnode=mp[key];
            oldnode->val=value;
            deleteNode(oldnode);
            addNode(oldnode);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */