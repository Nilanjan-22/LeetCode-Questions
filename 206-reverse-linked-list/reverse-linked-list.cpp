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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead=head;
        ListNode* prev=NULL;

        while(newHead!=NULL){
            ListNode* temp=newHead->next;
            newHead->next=prev;
            prev=newHead;
            newHead=temp;
        }
        return prev;


    }
};