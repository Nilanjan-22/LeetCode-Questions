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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1=0,size2=0;
        ListNode* it1=headA;
        ListNode* it2=headB;
        while(it1!=NULL){
            it1=it1->next;
            size1++;
        }
        while(it2!=NULL){
            it2=it2->next;
            size2++;
        }
        it1=headA;
        it2=headB;
        if(size1>size2){
            int iterations=size1-size2;
            while(iterations>0){
                it1=it1->next;
                iterations--;
            }
        }
        else{
            int iterations=size2-size1;
            while(iterations>0){
                it2=it2->next;
                iterations--;
            }
        }

        while(it1!=NULL){
            if(it1==it2)return it1;
            it1=it1->next;
            it2=it2->next;
        }

        return NULL;
    }
};