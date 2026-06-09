/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)return NULL;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* node1=list1;
        ListNode* node2 = list2;
        ListNode* newHead;
        ListNode* it;
        while(node1!=NULL && node2 !=NULL){
            if(node1==list1 && node2 ==list2){
                if(node1->val>node2->val){
                    newHead=node2;
                    it=node2;
                    node2=node2->next;
                }
                else{
                    newHead=node1;
                    it=node1;
                    node1=node1->next;
                }
            }

            else{
                if(node1->val>node2->val){
                    it->next=node2;
                    node2=node2->next;
                }
                else{
                    it->next=node1;
                    node1=node1->next;
                }
                it=it->next;
            }
        }
        while(node1!=NULL){
            it->next=node1;
            node1=node1->next;
            it=it->next;
        }
        while(node2!=NULL){
            it->next=node2;
            node2=node2->next;
            it=it->next;
        }


        return newHead;
    }
};