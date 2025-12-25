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
        //traverse two linked list at the same time and if anyone of them turns null send it to the head of the other linked list until the intersection is found.
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){
            if(temp1==NULL)temp1=headB;
            if(temp2==NULL)temp2=headA;
            if(temp1==temp2)return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
};