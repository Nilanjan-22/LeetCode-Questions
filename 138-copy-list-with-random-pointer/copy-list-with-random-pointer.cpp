/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mappedNodes;
        Node* it=head;
        while(it!=NULL){
            mappedNodes[it]=new Node(it->val);
            it=it->next;
        }

        it=head;
        while(it!=NULL){
            Node* copy=mappedNodes[it];
            Node* next=it->next;
            Node* random=it->random;

            if(next==NULL)copy->next=NULL;
            else copy->next=mappedNodes[next];

            if(random==NULL)copy->random=NULL;
            else copy->random=mappedNodes[random];

            it=it->next;
        }
        return mappedNodes[head];
    }
};