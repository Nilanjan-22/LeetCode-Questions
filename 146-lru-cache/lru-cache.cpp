class Listnode {
    public: 
    int val;
    int key;
    Listnode* next;
    Listnode* prev;

    Listnode(int val,int key){
        this->val=val;
        this->key=key;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int,Listnode*> addressMap;
    Listnode* lastNode=NULL;
    Listnode* firstNode=NULL;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    void moveNode(Listnode* & curNode){
        Listnode* prevNode=curNode->prev;
        Listnode* nextNode = curNode->next;
        if(prevNode!=NULL)prevNode->next=nextNode;
        else{
            firstNode=nextNode;
        }
        nextNode->prev=prevNode;
        lastNode->next=curNode;
        curNode->prev=lastNode;
        curNode->next=NULL;
        lastNode=curNode;
    }
    void addNode(int val, int key){
        Listnode* newNode = new Listnode(val,key);
        if (lastNode!=NULL)lastNode->next=newNode;
        else{
            firstNode=newNode;
        }
        newNode->prev=lastNode;
        lastNode=newNode;
        addressMap[key]=newNode;
    }

    void deleteNode(){
        int key=firstNode->key;
        addressMap.erase(key);
        Listnode* nextNode=firstNode->next;
        nextNode->prev=NULL;
        firstNode=nextNode;
    }
    int get(int key) {
        if(addressMap.find(key)==addressMap.end())return -1;
        Listnode* curNode=addressMap[key];
        if(lastNode!=curNode){
            moveNode(curNode);
        }
        return curNode->val;
        
    }
    
    void put(int key, int value) {
        if(addressMap.find(key)!=addressMap.end()){
            Listnode* curNode=addressMap[key];
            curNode->val=value;
            if(curNode!=lastNode)moveNode(curNode);
            return;
        }
        else{
            addNode(value,key);
            if(addressMap.size()>capacity)deleteNode();
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */