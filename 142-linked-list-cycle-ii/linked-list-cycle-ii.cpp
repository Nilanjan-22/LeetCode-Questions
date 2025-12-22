/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> mp;
        ListNode* it=head;
        int pos=0;
        while(it!=NULL && it->next!=NULL){
            if(mp.find(it)!=mp.end())return it;
            else mp[it]=pos;
            pos++;
            it=it->next;
        }
        return NULL;
    }
};