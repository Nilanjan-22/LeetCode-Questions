class Listnode {
    public:
    int val;
    int key;
    Listnode* next;
    Listnode* prev;

    Listnode(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
class LFUCache {
public:
    unordered_map<int, pair<Listnode*,int>> addressMap;
    map<int,pair<Listnode*,Listnode*>> freq;
    int capacity;
    LFUCache(int capacity) {
        this->capacity=capacity;
    }
    void addNode(int key, int val){
        Listnode* newNode = new Listnode(key,val);
        if(freq.find(1)==freq.end()){
            freq[1].first=newNode;
            freq[1].second=newNode;
        }
        else{
            Listnode* lastNode =freq[1].second;
            lastNode->next=newNode;
            newNode->prev=lastNode;
            freq[1].second=newNode;
        }
        addressMap[key].first=newNode;
        addressMap[key].second=1;
    }
    void deleteNode(){
        int minFreq=freq.begin()->first;
        Listnode* firstNode = freq[minFreq].first;
        int key=firstNode->key;
        if(firstNode==freq[minFreq].second){
            freq.erase(minFreq);
        }
        else{
            Listnode* nextNode=firstNode->next;
            nextNode->prev=NULL;
            freq[minFreq].first=nextNode;
        }
        addressMap.erase(key);
    }

    void moveNode(Listnode*& curNode, int f){
        if(curNode->next==NULL && curNode->prev==NULL)freq.erase(f);
        else{
            Listnode* prevNode=curNode->prev;
            Listnode* nextNode=curNode->next;
            if(prevNode!=NULL)prevNode->next=nextNode;
            if(nextNode!=NULL)nextNode->prev=prevNode;

            if(curNode==freq[f].first)freq[f].first=nextNode;
            else if(curNode==freq[f].second)freq[f].second=prevNode;
        }


        if(freq.find(f+1)==freq.end()){
            curNode->prev=NULL;
            curNode->next=NULL;
            freq[f+1].first=curNode;
            freq[f+1].second=curNode;
        }
        else{
            Listnode* lastNode =freq[f+1].second;
            lastNode->next=curNode;
            curNode->prev=lastNode;
            curNode->next=NULL;
            freq[f+1].second=curNode;
        }
        int key=curNode->key;
        addressMap[key].second=f+1;
    }
    int get(int key) {
        if(addressMap.find(key)==addressMap.end())return -1;
        Listnode* curNode=addressMap[key].first;
        int f=addressMap[key].second;
        moveNode(curNode, f);
        return curNode->val;
    }
    
    void put(int key, int value) {
        if(addressMap.find(key)!=addressMap.end()){
            Listnode* curNode=addressMap[key].first;
            int f=addressMap[key].second;
            curNode->val=value;
            moveNode(curNode,f);
            return;
        }
        if(addressMap.size()==capacity)deleteNode();
        addNode(key,value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */