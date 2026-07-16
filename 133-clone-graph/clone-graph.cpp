/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        Node* firstNode = new Node (node->val);
        queue<pair<Node*,Node*>> q;
        q.push({node,firstNode});
        map<int,Node*> mp;
        mp[1]=firstNode;
        while(!q.empty()){
            Node* n1 = q.front().first;
            Node* n2 = q.front().second;
            q.pop();
            for(auto n: n1->neighbors){
                if(mp.find(n->val)==mp.end()){
                    Node* newNode = new Node(n->val);
                    n2->neighbors.push_back(newNode);
                    q.push({n,newNode});
                    mp[n->val]=newNode;
                }
                else {
                    n2->neighbors.push_back(mp[n->val]);
                }
            }
        }

        return firstNode;
    }
};