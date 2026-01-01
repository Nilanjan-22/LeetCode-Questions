class LRUCache {
public:
    class Node {
    public:
        int val;
        int key;
        Node* prev;
        Node* next;

        Node(int key, int val){
            this->val=val;
            this->key=key;
            this->prev=NULL;
            this->next=NULL;
        }
    };
    int capacity;
    unordered_map<int,Node*> mp; //key,node*
    Node* head= new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    void Delete(Node* nd){
        Node* bck=nd->prev;
        Node* frnt=nd->next;
        nd->prev=NULL;
        nd->next=NULL;
        frnt->prev=bck;
        bck->next=frnt;
    }

    void Insert(Node* lru){
        Node* frnt=head->next;
        lru->next=frnt;
        lru->prev=head;
        head->next=lru;
        frnt->prev=lru;
    }
    LRUCache(int capacity) {
        this->capacity=capacity;
        tail->prev=head;
        head->next=tail;
    }
    
    int get(int key) {

        if(mp.find(key)!=mp.end()){
            Node* lru= mp[key];
            Delete(lru);
            Insert(lru);
            return mp[key]->val;
        }
        else return -1;
    }
    
    void put(int k, int v) {
        Node* lru=new Node(k,v);
        if(mp.size()==capacity && mp.find(k)==mp.end()){
            lru=tail->prev;
            mp.erase(lru->key);
            Delete(lru);
            lru->key=k;
            lru->val=v;
        }
        else if(mp.find(k)!=mp.end()){
            lru=mp[k];
            Delete(lru);
            lru->val=v;
        }
        Insert(lru);
        mp[k]=lru;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */